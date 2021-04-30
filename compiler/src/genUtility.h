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

namespace classicBasic{
    class CodeGenVisitor;
    class StackFrame;
    class TypeTable;
    class CodeGenerator;
    class JIT;
    class StructureVisitor;

    string strToLower(string str);

    class GenerateUnit{
        friend CodeGenVisitor;
        friend JIT;
        friend StructureVisitor;
        llvm::Module mod;
        list<StackFrame> frame;
        LLVMContext& context;
        Reporter reporter;
        BasicErrorListener errorListener;
        CodeGenerator& gen;
        istream& in;
        ostream& out;
        tree::ParseTree *tree = nullptr;

    public:

        GenerateUnit(CodeGenerator& gen,string path,string name,istream& in,ostream& out);
        void scan();
        void generate();
        void printIR();
        Value * findVariable(Token* id);
        Function* findFunction(Token* id);
        void addVariableInStack(Token* id, Value* variable);
    };

    class CodeGenerator{
        friend GenerateUnit;
        friend StackFrame;
        friend TypeTable;
        friend CodeGenVisitor;
        LLVMContext context;
        list<GenerateUnit*> units;
        Reporter* reporter=nullptr;
    public:
        CodeGenerator();
        ~CodeGenerator(){
            for(auto u:units)delete u;
        }
        GenerateUnit* CreateUnit(string path,istream& in,ostream& out){
            auto unit=new GenerateUnit(*this,path,path,in,out);
            units.push_back(unit);
            return unit;
        }
    };

    class TypeTable{
        static CodeGenerator* gen;
        static map<string,llvm::Type*> builtInTypes;
        static map<string,llvm::Type*> builtInTypesPtr;
        static map<string,Value*> defaultValue;
    public:
        static void SetGenerator(CodeGenerator* gen);
        static Type* find(Token* type,bool ptr=false);
        static Type* find(BasicParser::TypeLocationContext* type,bool ptr=false);
        static Value* getDefaultValue(Token* type);
    };

    namespace structure{
        class Info{
        public:
            enum Enum{Argument,Variable,Function,Type,Property,Module_,Enum_,Namespace};
            virtual Enum getType()=0;
            template<typename T>
            T* as(Enum t){return (T*)this;}
        };

        class ParameterInfo: public Info{
        public:
            bool byval=false;
            bool array=false;
            bool paramArray=false;
            BasicParser::ExpContext* initial=nullptr;
            llvm::Type* type;
            std::string name;
            virtual Enum getType()override{return Info::Argument;}
        };

        class VariableInfo:public Info{
        public:
            llvm::GlobalVariable* variable;
            llvm::Type* type;
            std::string name;
            virtual Enum getType()override{return Info::Variable;}
        };

        class FunctionInfo:public Info{
        public:
            std::string name;
            llvm::Function* function;
            std::list<ParameterInfo*> parameterInfoList;
            ParameterInfo* retInfo=nullptr;
            virtual Enum getType()override{return Info::Function;}
        };

        class TypeInfo:public Info{
        public:
            std::string name;
            llvm::StructType* structure;
            std::map<std::string,llvm::Type*> memberInfoList;
            virtual Enum getType()override{return Info::Type;}
        };

        class EnumInfo:public Info{
        public:
            std::string name;
            std::map<std::string,Value*> memberList;
            virtual Enum getType()override{return Info::Enum_;}
        };

        class PropertyInfo:public Info{
        public:
            FunctionInfo *getter=nullptr,*setter=nullptr,*let=nullptr;
            ParameterInfo* valueInfo;
            virtual Enum getType()override{return Info::Property;}
        };

        class Scope:public Info{
        public:
            std::string name;
            Scope* parent=nullptr;
            std::map<std::string,Scope*> childScope;
            std::map<std::string,Info*> memberInfoList;

            virtual Enum getType()override{return Info::Namespace;}
            //动作类似using namespace scope
            void extend(Scope* scope);
        };

        Scope globalScope;
    }


//class ParameterInfo{
//public:
//    string name;
//    Type* type;
//    Token* token;
//    bool byref;
//    Argument* argument;
//    antlr4::tree::ParseTree* initial=nullptr;
//    ParameterInfo(BasicParser::NecessaryParameterContext *ctx,TypeTable& typeTable){
//        name=strToLower(ctx->name->getText());
//        this->token=ctx->name;
//        byref = ctx->passFlag == nullptr || strToLower(ctx->passFlag->getText()) == "byref";
//        type=typeTable.find(ctx->type->ID()->getSymbol(),true);//TODO 支持数组
//    }
//    ParameterInfo(BasicParser::OptionalParameterContext *ctx,TypeTable& typeTable){
//        name=strToLower(ctx->name->getText());
//        this->token=ctx->name;
//        byref = ctx->passFlag == nullptr || strToLower(ctx->passFlag->getText()) == "byref";
//        type=typeTable.find(ctx->type->ID()->getSymbol(),true);//TODO 支持数组
//        initial=ctx->initial;
//    }
//};

//class VariableInfo{
//public:
//    string name;
//    Type* type;
//    Token* token;
//    antlr4::tree::ParseTree* initial;
//    VariableInfo(BasicParser::VariableContext *ctx, TypeTable& typeTable){
//        token=ctx->name;
//        name=strToLower(ctx->name->getText());
//        type=typeTable.find(ctx->type->ID()->getSymbol());
//        initial=ctx->initial;
//    }
//};

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
}


#include "structureGen.h"
#include "codeGen.h"

#endif //CLASSICBASIC_GENUTILITY_H


