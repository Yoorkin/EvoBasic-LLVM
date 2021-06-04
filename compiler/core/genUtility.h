//
// Created by yorkin on 4/27/21.
//

#ifndef CLASSICBASIC_GENUTILITY_H
#define CLASSICBASIC_GENUTILITY_H

#include"errorListener.h"
#include"basicTypeDef.h"

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
#include<llvm/IR/AssemblyAnnotationWriter.h>
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
    class StructureScan;
    class Log;
    namespace structure{
        class Scope;
        class Info;
    }
    namespace constExpCompute{
        class ConstExpVisitor;
    }


    string strToLower(string str);

    class Unit{
    protected:
        Unit(LLVMContext& context):builder(context){}
    public:
        CodeGenerator* gen=nullptr;
        structure::Scope* scope=nullptr;
        IRBuilder<> builder;
        virtual void generate()=0;
        virtual string getPath()=0;
        virtual string operator[](int line)=0;
    };

    class SourceUnit:public Unit{
        ANTLRInputStream* input;
        BasicLexer* lexer;
        CommonTokenStream* tokens;
        BasicParser* parser;
    public:
        SourceUnit(CodeGenerator* gen,const string& path,istream& stream);
        ~SourceUnit();
        virtual void generate()override;
        virtual string getPath()override;
        virtual string operator[](int line)override;
    };

    class LibraryUnit:public Unit{
    public:
        LibraryUnit(CodeGenerator* gen, const string& path);
        virtual void generate()override;
        virtual string getPath()override;
        virtual string operator[](int line)override;
    };

    class CodeGenerator{
        friend SourceUnit;
        friend StackFrame;
        friend TypeTable;
        friend CodeGenVisitor;
        BasicErrorListener errorListener;
        list<Unit*> units;
        LLVMContext* context;
        llvm::Module* mod;
        Reporter* reporter;
        Log* logger;
        structure::Scope* global;
    public:
        Log& log;
        LLVMContext& getContext(){return *context;}
        Module& getModule(){return *mod;}
        structure::Scope* getGlobalScope(){return global;}

        CodeGenerator(ostream& output,string name);
        ~CodeGenerator();
        list<string> linkTargetPaths;
        Unit* createUnitFromStream(istream& stream);
        Unit* createUnitFromFile(const string& path);
        Unit* createUnitFromIBL(string path);
        void printLLVMIR(llvm::raw_ostream& stream);
        Reporter& getReporter(){
            return *reporter;
        }
    };

    class Log{
        ostream& out;
        Unit* unit=nullptr;
        Token* token=nullptr;
        int errorCount=0;
        int warningCount=0;
    public:
        void handling(Unit* u);
        void handling(Token* t);
        Token* getHandlingToken();
        Unit* getHandlingUnit();
        static const string Red;
        static const string Yellow;
        static const string ColorEnd;
        static const char endl;
        enum Enum{endMsg,Position,TokenMark};
        Log(ostream& output):out(output){}

        template<typename T>
        Log& operator<<(const T t){
            out<<t;
        }
        void stop();
        void error(string msg);
        void warning(string msg);

        Log& operator<<(const Enum e);
    };

    namespace structure{
        /*
         * 这些类用于在代码生成前扫描时存储用户定义符号/内建变量类型，以方便引用，特别是向后引用
         * 允许向后引用的类型：
         * Type
         * Enum
         * Function/Sub/Property
         * Class
         * 不允许向后引用的类型：
         * Variable
         *
         * 合法：
         * class A{
         *  void FuncA(Enum myEnum,B b){FuncB();}
         *  void FuncB(){}
         *  enum Enum{}
         *  struct B{}
         * }
         *
         * 不合法：
         * class B{
         *  int a=b;
         *  int b=1;
         * }
         */

        class Info{
        protected:
            llvm::Type* type=nullptr;
        public:
            Info* parent=nullptr;
            std::string name;
            enum Enum{Parameter,Variable,Function,Type,Property,Module_,
                    BuiltIn,Enum_,Scope,Class,Module,TypeMember,TypeArrayMember};
            virtual Enum getKind()=0;
            virtual void load(BasicBaseVisitor* visitor)=0;
            void setType(llvm::Type* t){type=t;}
            llvm::Type* getType(BasicBaseVisitor* visitor);
            virtual string mangling();
            template<typename T>
            T* as(){return (T*)this;}
            static Info* handling;
        };

        class ParameterInfo: public Info{
        public:
            BasicParser::NecessaryParameterContext* necessaryParameterCtx=nullptr;
            BasicParser::ParamArrayParameterContext* paramArrayParameterCtx=nullptr;
            BasicParser::OptionalParameterContext* optionalParameterCtx=nullptr;
            BasicParser::TypeLocationContext* returnCtx=nullptr;
            BasicParser::NameTypePairContext* typeMember=nullptr;

            ParameterInfo(BasicParser::NecessaryParameterContext* ctx):necessaryParameterCtx(ctx){}
            ParameterInfo(BasicParser::ParamArrayParameterContext* ctx):paramArrayParameterCtx(ctx){}
            ParameterInfo(BasicParser::OptionalParameterContext* ctx):optionalParameterCtx(ctx){}
            ParameterInfo(BasicParser::TypeLocationContext* ctx):returnCtx(ctx){}
            ParameterInfo(BasicParser::NameTypePairContext* ctx):typeMember(ctx){}

            virtual void load(BasicBaseVisitor* visitor)override;
            bool byval=false;
            bool array=false;
            bool paramArray=false;
            u32 arraySize=0;
            BasicParser::ConstExpContext* initial=nullptr;
            virtual Enum getKind()override{return Info::Parameter;}
        };

        class FunctionInfo:public Info{
        public:
            BasicParser::ExternalFunctionContext* externalFunctionCtx=nullptr;
            BasicParser::ExternalSubContext* externalSubCtx=nullptr;
            BasicParser::FunctionDeclContext* functionDeclCtx=nullptr;
            BasicParser::SubDeclContext* subDeclCtx=nullptr;
            BasicParser::PropertyGetContext* propertyGetCtx=nullptr;
            BasicParser::PropertySetContext* propertySetCtx=nullptr;
            BasicParser::PropertyLetContext* propertyLetCtx=nullptr;

            llvm::Function* function;
            std::list<ParameterInfo*> parameterInfoList;
            ParameterInfo* retInfo=nullptr;

            FunctionInfo(BasicParser::ExternalFunctionContext* ctx):externalFunctionCtx(ctx){}
            FunctionInfo(BasicParser::ExternalSubContext* ctx):externalSubCtx(ctx){}
            FunctionInfo(BasicParser::FunctionDeclContext* ctx):functionDeclCtx(ctx){}
            FunctionInfo(BasicParser::SubDeclContext* ctx):subDeclCtx(ctx){}
            FunctionInfo(BasicParser::PropertyGetContext* ctx):propertyGetCtx(ctx){}
            FunctionInfo(BasicParser::PropertySetContext* ctx):propertySetCtx(ctx){}
            FunctionInfo(BasicParser::PropertyLetContext* ctx):propertyLetCtx(ctx){}

            virtual void load(BasicBaseVisitor* visitor)override;
            virtual Enum getKind()override{return Info::Function;}
        };

        class TypeInfo:public Info{
        public:
            BasicParser::TypeDeclContext *ctx=nullptr;
            std::map<std::string,ParameterInfo*> memberInfoList;
            TypeInfo(BasicParser::TypeDeclContext *ctx):ctx(ctx){}
            virtual void load(BasicBaseVisitor* visitor)override;
            virtual Enum getKind()override{return Info::Type;}
        };

        class EnumInfo:public Info{
        public:
            BasicParser::EnumDeclContext* ctx=nullptr;
            std::map<std::string,ConstantInt*> memberList;
            EnumInfo(BasicParser::EnumDeclContext* ctx):ctx(ctx){}
            virtual void load(BasicBaseVisitor* visitor)override;
            virtual Enum getKind()override{return Info::Enum_;}
        };

        class VariableInfo:public Info{
        public:
            virtual void load(BasicBaseVisitor* visitor)override{}
            virtual Enum getKind()override{return Info::Variable;}
            llvm::Value* value;
        };

        class BuiltInType:public Info{
        public:
            BuiltInType(llvm::Type* type){this->type=type;}
            virtual void load(BasicBaseVisitor* visitor)override{
                cout<<"loading bulitin"<<endl;//TODO 这tm是干嘛用的？
            }
            virtual Enum getKind()override{return Info::BuiltIn;}
        };

        class LambdaInfo:public Info{

        };

        class Scope:public Info{
        public:
            Scope* getParent(){return (Scope*)parent;}
            std::map<std::string,Scope*> childScope;
            std::map<std::string,Info*> memberInfoList;
            virtual void load(BasicBaseVisitor* visitor)override{}
            virtual Enum getKind()override{return Info::Scope;}
            //动作类似using namespace scope
            void extend(Scope* scope);
            Info* lookUp(vector<string>& path);
            Info* lookUp(string name);
        };

        class ClassInfo: public Scope{
        public:
            ClassInfo(string name, Scope* parent){
                this->parent=parent;
                this->name=strToLower(name);
                parent->childScope.insert(make_pair(strToLower(name),this));
                parent->memberInfoList.insert(make_pair(this->name,this));
            }
            virtual Enum getKind()override{return Info::Class;}
        };

        class ModuleInfo: public Scope{
        public:
            ModuleInfo(string name, Scope* parent){
                this->parent=parent;
                this->name=strToLower(name);
                parent->childScope.insert(make_pair(this->name,this));
                parent->memberInfoList.insert(make_pair(this->name,this));
            }
            virtual Enum getKind()override{return Info::Module;}
        };

    }
}

#endif //CLASSICBASIC_GENUTILITY_H

#include "structureGen.h"
#include "codeGen.h"
