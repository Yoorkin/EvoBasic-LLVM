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
    class StructureScan;
    namespace structure{
        class Scope;
        class Info;
    }
    string strToLower(string str);

    class GenerateUnit{
        friend CodeGenVisitor;
        friend JIT;
        friend StructureScan;
        istream& in;
        ostream& out;
        ANTLRInputStream input;
        BasicLexer lexer;
        CommonTokenStream tokens;
        BasicParser parser;
        tree::ParseTree *tree = nullptr;
    public:
        CodeGenerator& gen;
        /*
         * 未能识别的
         * ParameterInfo
         * VariableInfo
         */
//        list<pair<BasicParser::TypeLocationContext*,structure::Info*>> unrecognized;
        llvm::Module mod;
        structure::Scope* scope;
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
        BasicErrorListener errorListener;
        list<GenerateUnit*> units;
    public:
        LLVMContext context;
        CodeGenerator();
        ~CodeGenerator(){
            for(auto u:units)delete u;
        }
        GenerateUnit* CreateUnit(string path,istream& in,ostream& out);
        list<string> linkTargetPaths;
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
            std::string name;
            enum Enum{Parameter,Variable,Function,Type,Property,Module_,
                    BuiltIn,Enum_,Scope,Class,Module,TypeMember,TypeArrayMember};
            virtual Enum getKind()=0;
            virtual void load(BasicBaseVisitor* visitor)=0;
            void setType(llvm::Type* t){type=t;}
            llvm::Type* getType(BasicBaseVisitor* visitor){
                if(type==nullptr)load(visitor);
                if(type==nullptr)throw "";
                return type;
            };
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

            virtual void load(BasicBaseVisitor* visitor)override{
                Info::handling=this;
                if(necessaryParameterCtx!=nullptr)visitor->visit(necessaryParameterCtx);
                else if(paramArrayParameterCtx!=nullptr)visitor->visit(paramArrayParameterCtx);
                else if(optionalParameterCtx!=nullptr)visitor->visit(optionalParameterCtx);
                else if(returnCtx!=nullptr)visitor->visit(returnCtx);
                else if(typeMember!=nullptr)visitor->visit(typeMember);
                Info::handling=nullptr;
            }

            bool byval=false;
            bool array=false;
            bool paramArray=false;
            uint64_t arraySize=0;
            BasicParser::ExpContext* initial=nullptr;
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

            virtual void load(BasicBaseVisitor* visitor)override{
                Info::handling=this;
                if(externalFunctionCtx!=nullptr)visitor->visit(externalFunctionCtx);
                else if(externalSubCtx!=nullptr)visitor->visit(externalSubCtx);
                else if(functionDeclCtx!=nullptr)visitor->visit(functionDeclCtx);
                else if(subDeclCtx!=nullptr)visitor->visit(subDeclCtx);
                else if(propertyGetCtx!=nullptr)visitor->visit(propertyGetCtx);
                else if(propertySetCtx!=nullptr)visitor->visit(propertySetCtx);
                else if(propertyLetCtx!=nullptr)visitor->visit(propertyLetCtx);
                Info::handling=nullptr;
            }
            virtual Enum getKind()override{return Info::Function;}
        };

        class TypeInfo:public Info{
        public:
            BasicParser::TypeDeclContext *ctx=nullptr;

            std::map<std::string,ParameterInfo*> memberInfoList;

            TypeInfo(BasicParser::TypeDeclContext *ctx):ctx(ctx){}
            virtual void load(BasicBaseVisitor* visitor)override{
                Info::handling=this;
                visitor->visit(ctx);
                Info::handling=nullptr;
            }
            virtual Enum getKind()override{return Info::Type;}
        };

//        class TypeMemberInfo:public Info{
//            BasicParser::NormalNameTypePairContext* context;
//        public:
//            virtual Enum getKind()override{return Info::TypeMember;}
//            virtual void load(BasicBaseVisitor* visitor)override{
//                Info::handling=this;
//                visitor->visit(context);
//                Info::handling=nullptr;
//            }
//            TypeMemberInfo(BasicParser::NormalNameTypePairContext* ctx):context(ctx){}
//        };
//
//        class TypeArrayMemberInfo:public Info{
//            BasicParser::ArrayNameTypePairContext* context;
//        public:
//            int lbound=0,ubound=0;
//            virtual Enum getKind()override{return Info::TypeArrayMember;}
//            virtual void load(BasicBaseVisitor* visitor)override{
//                Info::handling=this;
//                visitor->visit(context);
//                Info::handling=nullptr;
//            }
//            int getSize(){return ubound-lbound;}
//            TypeArrayMemberInfo(BasicParser::ArrayNameTypePairContext* ctx):context(ctx){}
//        };

        class EnumInfo:public Info{
        public:
            BasicParser::EnumDeclContext* ctx=nullptr;

            std::map<std::string,ConstantInt*> memberList;

            EnumInfo(BasicParser::EnumDeclContext* ctx):ctx(ctx){}
            virtual void load(BasicBaseVisitor* visitor)override {
                Info::handling=this;
                visitor->visit(ctx);
                Info::handling=nullptr;
            }
            virtual Enum getKind()override{return Info::Enum_;}
        };

//        class PropertyInfo:public Info{
//        public:
//            FunctionInfo *getter=nullptr,*setter=nullptr,*let=nullptr;
//            ParameterInfo* valueInfo;
//            virtual Enum getKind()override{return Info::Property;}
//        };

        class VariableInfo:public Info{
        public:
            llvm::GlobalVariable* variable;
            virtual void load(BasicBaseVisitor* visitor)override{}
            virtual Enum getKind()override{return Info::Variable;}
        };

        class BuiltInType:public Info{
        public:
            BuiltInType(llvm::Type* type){this->type=type;}
            virtual void load(BasicBaseVisitor* visitor)override{
                cout<<"loading bulitin"<<endl;
            }
            virtual Enum getKind()override{return Info::BuiltIn;}
        };

        class Scope:public Info{
        public:
            Scope* parent=nullptr;
            std::map<std::string,Scope*> childScope;
            std::map<std::string,Info*> memberInfoList;
            virtual void load(BasicBaseVisitor* visitor)override{}
            virtual Enum getKind()override{return Info::Scope;}
            //动作类似using namespace scope
            void extend(Scope* scope);
            Info* lookUp(vector<string>& path);
            Info* lookUp(string name);
            static Scope* global;
        };

        class ClassInfo: public Scope{
        public:
            ClassInfo(string name, Scope* parent_){
                this->parent=parent_;
                this->name=strToLower(name);
                parent_->memberInfoList.insert(make_pair(this->name,this));
            }
            virtual Enum getKind()override{return Info::Class;}
        };

        class ModuleInfo: public Scope{
        public:
            ModuleInfo(string name, Scope* parent){
                this->parent=parent;
                parent->memberInfoList.insert(make_pair(strToLower(name),this));
            }
            virtual Enum getKind()override{return Info::Module;}
        };
    }
}

#endif //CLASSICBASIC_GENUTILITY_H

#include "structureGen.h"
#include "codeGen.h"
