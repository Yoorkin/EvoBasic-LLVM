//
// Created by yorkin on 4/27/21.
//

#ifndef CLASSICBASIC_GENUTILITY_H
#define CLASSICBASIC_GENUTILITY_H

#include"errorListener.h"

#include<map>
#include<string>
#include<stack>
#include<list>
#include<iostream>

#include<antlr4-runtime/antlr4-runtime.h>
#include"../antlr/BasicLexer.h"
#include"../antlr/BasicParser.h"
#include"../antlr/BasicBaseVisitor.h"

#include<llvm/IR/DerivedTypes.h>
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/Function.h>
#include<llvm/IR/InstrTypes.h>
#include<llvm/IR/Instruction.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>
#include<llvm/IR/Verifier.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Target/TargetMachine.h>
#include<llvm/ExecutionEngine/JITSymbol.h>
#include<llvm/ExecutionEngine/Orc/LLJIT.h>
#include<llvm/ExecutionEngine/Orc/CompileUtils.h>
#include<llvm/ExecutionEngine/Orc/Core.h>
#include<llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h>
#include<llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include<llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include<llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include<llvm/ExecutionEngine/SectionMemoryManager.h>
#include<llvm/IR/DataLayout.h>
#include<llvm/ExecutionEngine/ExecutionEngine.h>
using namespace llvm;
using namespace std;
using namespace antlr4;

class Visitor;
class StackFrame;
class TypeTable;
class CodeGenerator;
class JIT;
class ArgumentInfo;
class VariableInfo;

string strToLower(string str);

//namespace classicBasic{
    namespace declarationInfo{
        class Info{
        public:
            enum Enum{Argument,Variable,Function,Type,Property,Module_,Enum_};
            virtual Enum getType()=0;
            template<typename T>
            T* as(Enum t){return (T*)this;}
        };

        class ArgumentInfo:public Info{
        public:
            bool byval=false;
            bool optional=false;
            bool array=false;
            bool paramArray=false;
            std::string typeName;
            virtual Enum getType()override{return Info::Argument;}

        };

        class VariableInfo:public Info{
        public:
            llvm::Value* variable;
            virtual Enum getType()override{return Info::Variable;}
        };

        class FunctionInfo:public Info{
        public:
            llvm::Function* function;
            std::map<std::string,ArgumentInfo*> argumentInfoList;
            ArgumentInfo* retInfo=nullptr;
            virtual Enum getType()override{return Info::Function;}
        };

        class TypeInfo:public Info{
        public:
            llvm::StructType* structure;
            std::map<std::string,llvm::Type*> memberInfoList;
            virtual Enum getType()override{return Info::Type;}
        };

        class EnumInfo:public Info{
        public:
            std::map<std::string,Value*> memberList;
            virtual Enum getType()override{return Info::Enum_;}
        };

        class PropertyInfo:public Info{
        public:
            FunctionInfo *getter=nullptr,*setter=nullptr,*let=nullptr;
            ArgumentInfo* valueInfo;
            virtual Enum getType()override{return Info::Property;}
        };

        class ModuleInfo:public Info{
        public:
            llvm::Module* module_;
            std::map<std::string,Info*> memberInfoList;
            virtual Enum getType()override{return Info::Module_;}
        };
    }
//}

class GenerateUnit{
    friend Visitor;
    friend JIT;
    llvm::Module mod;
    Visitor* visitor;
    list<StackFrame> frame;
    LLVMContext& context;
    Reporter reporter;
    BasicErrorListener errorListener;
    CodeGenerator& gen;
    istream& in;
    ostream& out;
public:

    GenerateUnit(CodeGenerator& gen,string path,string name,istream& in,ostream& out);
    void generate();
    void printIR();
    Value * findVariable(Token* id);
    Function* findFunction(Token* id);
    void addVariableInStack(Token* id, Value* variable);
    ~GenerateUnit(){
        delete visitor;
    }
};

class CodeGenerator{
    friend GenerateUnit;
    friend StackFrame;
    friend TypeTable;
    friend Visitor;
    LLVMContext context;
    TypeTable* typeTable;
    list<GenerateUnit*> units;
    Reporter* reporter=nullptr;
public:
    CodeGenerator();
    ~CodeGenerator(){
        delete typeTable;
        for(auto u:units)delete u;
    }
    GenerateUnit* CreateUnit(string path,istream& in,ostream& out){
        auto unit=new GenerateUnit(*this,path,path,in,out);
        units.push_back(unit);
        return unit;
    }
};


class TypeTable{
    CodeGenerator& gen;
    map<string,llvm::Type*> builtInTypes;
    map<string,llvm::Type*> builtInTypesPtr;
    map<string,Value*> defaultValue;
public:
    explicit TypeTable(CodeGenerator& generator);
    Type* find(Token* type,bool ptr=false);
    Value* getDefaultValue(Token* type);
};

class ParameterInfo{
public:
    string name;
    Type* type;
    Token* token;
    bool byref;
    Argument* argument;
    antlr4::tree::ParseTree* initial=nullptr;
    ParameterInfo(BasicParser::NecessaryParameterContext *ctx,TypeTable& typeTable){
        name=strToLower(ctx->name->getText());
        this->token=ctx->name;
        byref = ctx->passFlag == nullptr || strToLower(ctx->passFlag->getText()) == "byref";
        type=typeTable.find(ctx->type->ID()->getSymbol(),true);//TODO 支持数组
    }
    ParameterInfo(BasicParser::OptionalParameterContext *ctx,TypeTable& typeTable){
        name=strToLower(ctx->name->getText());
        this->token=ctx->name;
        byref = ctx->passFlag == nullptr || strToLower(ctx->passFlag->getText()) == "byref";
        type=typeTable.find(ctx->type->ID()->getSymbol(),true);//TODO 支持数组
        initial=ctx->initial;
    }
};

class VariableInfo{
public:
    string name;
    Type* type;
    Token* token;
    antlr4::tree::ParseTree* initial;
    VariableInfo(BasicParser::VariableContext *ctx, TypeTable& typeTable){
        token=ctx->name;
        name=strToLower(ctx->name->getText());
        type=typeTable.find(ctx->type->ID()->getSymbol());
        initial=ctx->initial;
    }
};

class StackFrame{
    friend GenerateUnit;
    int index=0;
    stack<string> layers;
    map<string,Value*> varTable;
public:
    enum Enum{BasicFunction,BasicSub,BasicLoop};
    stack<Enum> stmtState;//标记当前所在语句，用于语法检查
    BasicBlock* afterBlock=nullptr; //当前状态下跳出语句（函数、过程、循环）所需要最后执行的block
    llvm::Function* function;
    StackFrame(llvm::Function* function,bool isSub){
        this->function=function;
        stmtState.push(isSub?BasicSub:BasicFunction);
        layers.push("");
    }
    void BeginLayer(string prefix){
        layers.push(prefix + "_" + std::to_string(index) + "_");
        index++;
    }
    string getBlockName(string suffix){
        return layers.top()+suffix;
    }
    void EndLayer(){
        layers.pop();
    }

};


#endif //CLASSICBASIC_GENUTILITY_H
