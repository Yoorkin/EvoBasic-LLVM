//
// Created by yorkin on 4/27/21.
//

#ifndef CLASSICBASIC_STRUCTUREGEN_H
#define CLASSICBASIC_STRUCTUREGEN_H

#include"errorListener.h"

#include<map>
#include<string>
#include<stack>
#include<list>
#include<iostream>
#include<set>
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

#include"genUtility.h"

using namespace llvm;
using namespace std;
using namespace antlr4;
namespace classicBasic {

    class StructureVisitor : public BasicBaseVisitor {
    public:
        LLVMContext& context;
        llvm::Module* mod;
        Reporter reporter;
        virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            auto retT = TypeTable::find(ctx->returnType);
            FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            info->retInfo=new structure::ParameterInfo();
            info->retInfo->type=retT;
            //info->retInfo->array=ctx->returnType TODO:支持返回数组
            return info;
        }
        virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            return info;
        }

        virtual antlrcpp::Any visitExternalFunction(BasicParser::ExternalFunctionContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            auto retT = TypeTable::find(ctx->returnType);
            FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            info->retInfo=new structure::ParameterInfo();
            info->retInfo->type=retT;
            //info->retInfo->array=ctx->returnType TODO:支持返回数组
            return info;
        }
        virtual antlrcpp::Any visitExternalSub(BasicParser::ExternalSubContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            return info;
        }

        virtual antlrcpp::Any visitPropertyGet(BasicParser::PropertyGetContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            auto retT = TypeTable::find(ctx->returnType);
            FunctionType* fT = FunctionType::get(retT,typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            info->retInfo=new structure::ParameterInfo();
            info->retInfo->type=retT;
            //info->retInfo->array=ctx->returnType TODO:支持返回数组
            return info;
        }
        virtual antlrcpp::Any visitPropertySet(BasicParser::PropertySetContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            return info;
        }
        virtual antlrcpp::Any visitPropertyLet(BasicParser::PropertyLetContext *ctx) override {
            auto info = new structure::FunctionInfo();
            info->parameterInfoList = std::move(visit(ctx->parameterList()).as<list<structure::ParameterInfo*>>());
            vector<Type*> typelist;
            bool hasParamArray=false;
            for(auto p:info->parameterInfoList){
                if(p->paramArray) hasParamArray=true;
                else typelist.push_back(p->type);
            }
            FunctionType* fT = FunctionType::get(Type::getVoidTy(context),typelist,hasParamArray);
            info->name=strToLower(ctx->name->getText());
            info->function=Function::Create(fT,GlobalValue::LinkageTypes::ExternalLinkage,info->name,mod);
            return info;
        }

        virtual antlrcpp::Any visitEnumDecl(BasicParser::EnumDeclContext *ctx) override {
            auto info = new structure::EnumInfo();
            info->name=strToLower(ctx->name->getText());
            int index=0;
            for(auto pctx:ctx->enumPair()){
                string name = strToLower(pctx->name->getText());
                if(pctx->value!=nullptr)index=std::stoi(pctx->value->getText());
                info->memberList.insert(make_pair(name,ConstantInt::get(Type::getInt32Ty(context),index)));
                index++;
            }
            return info;
        }

        virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *ctx) override {
            auto info = new structure::TypeInfo();
            vector<Type*> members;
            info->name=strToLower(ctx->name->getText());
            for(auto pctx:ctx->nameTypePair()){
                NameTypePairTmp p = visit(pctx).as<NameTypePairTmp>();
                info->memberInfoList.insert(make_pair(p.name,p.type));
            }
            info->structure=llvm::StructType::create(members,info->name);
            return info;
        }

        virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override {
            return visitChildren(ctx);
            //TODO
        }
        virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override {
            return visitChildren(ctx);
            //TODO
        }

        struct NameTypePairTmp{
            bool isArray;
            int lbound,ubound;
            string name;
            Type* type;
        };
        virtual antlrcpp::Any visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx) override {
            NameTypePairTmp tmp;
            tmp.isArray=false;
            tmp.name=strToLower(ctx->name->getText());
            tmp.type=TypeTable::find(ctx->typeLocation());
            return tmp;
        }
        virtual antlrcpp::Any visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx) override {
            NameTypePairTmp tmp;
            tmp.isArray=true;
            tmp.type=TypeTable::find(ctx->typeLocation(),true);
            return tmp;
        }

        virtual antlrcpp::Any visitParameterList(BasicParser::ParameterListContext *ctx) override {
            list<structure::ParameterInfo*> args;
            for(auto child:ctx->necessaryParameter()){
                auto arg=visit(child).as<structure::ParameterInfo*>();
                args.push_back(arg);
            }
            for(auto child:ctx->optionalParameter()){
                auto arg=visit(child).as<structure::ParameterInfo*>();
                args.push_back(arg);
            }
            auto arg=visit(ctx->paramArrayParameter()).as<structure::ParameterInfo*>();
            args.push_back(arg);
            return args;
        }
        virtual antlrcpp::Any visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx) override {
            auto info = new structure::ParameterInfo();
            auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
            info->type=p.type;
            info->name=p.name;
            info->byval = !(ctx->passFlag==nullptr||strToLower(ctx->passFlag->getText())=="byref");
            return info;
        }
        virtual antlrcpp::Any visitOptionalParameter(BasicParser::OptionalParameterContext *ctx) override {
            auto info = new structure::ParameterInfo();
            auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
            info->type=p.type;
            info->name=p.name;
            info->initial=ctx->initial;
            return info;
        }
        virtual antlrcpp::Any visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx) override {
            auto info = new structure::ParameterInfo();
            auto p = visit(ctx->nameTypePair()).as<NameTypePairTmp>();
            info->type=p.type;
            info->name=p.name;
            info->paramArray=true;
            return info;
        }


    };
}
#endif //CLASSICBASIC_STRUCTUREGEN_H
