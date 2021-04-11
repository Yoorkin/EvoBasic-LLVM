#ifndef CB_VISITOR
#define CB_VISITOR

#include<map>
#include<string>

#include<antlr4-runtime/antlr4-runtime.h>
#include"antlr/BasicLexer.h"
#include"antlr/BasicParser.h"
#include"antlr/BasicBaseVisitor.h"

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

string strToLower(string str){
    transform(str.begin(),str.end(),str.begin(),[](unsigned char c){ return std::tolower(c); });
    return str;
}

class TypeTable{
    LLVMContext& context;
    llvm::Module& mod;
    map<string,llvm::Type*> builtInTypes;
public:
    TypeTable(llvm::Module& mod,LLVMContext& context):mod(mod),context(context){
        builtInTypes.operator=({
               {"integer",Type::getInt32Ty(context)},
               {"single",Type::getFloatTy(context)},
               {"double",Type::getDoubleTy(context)},
               {"boolean",Type::getInt1Ty(context)},
               {"long",Type::getInt64Ty(context)},
               {"byte",Type::getInt8Ty(context)}
       });
    }

    Type* find(Token* type){
        string name = strToLower(type->getText());
        auto builtIn = builtInTypes.find(name);
        if(builtIn!=builtInTypes.end())return builtIn->second;
        auto structure = mod.getTypeByName(name.c_str());
        if(structure!=nullptr)return structure;
        //TODO: 报告找不到类型
        return nullptr;
    }

};

class ArgumentInfo{
public:
    string name;
    Type* type;
    antlr4::tree::ParseTree* initial;
    ArgumentInfo(BasicParser::VariableContext *ctx,TypeTable& typeTable){
        name=strToLower(ctx->name->getText());
        type=typeTable.find(ctx->type->ID()->getSymbol());
    }
};

class Visitor:public BasicBaseVisitor{
    llvm::Module& mod;
    LLVMContext& context;
    TypeTable typeTable;
public:

    Visitor(llvm::Module& m,LLVMContext& ctx):context(ctx),mod(m),typeTable(m,ctx){}

    virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *ctx) override {
        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto arg:ctx->variable()){
            arguments.push_back(visitVariable(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        return StructType::create(paramList,strToLower(ctx->name->getText()));
    }

    virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override {
        ArgumentInfo info(ctx,typeTable);
        return info;
    }

    virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override {
        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto arg:ctx->variable()){
            arguments.push_back(visitVariable(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        Type* retType = typeTable.find(ctx->returnType);
        FunctionType *type = FunctionType::get(retType,paramList,false);
        auto function = Function::Create(type,Function::ExternalLinkage,strToLower(ctx->name->getText()),mod);
        auto block = BasicBlock::Create(context, "EntryBlock", function);
        auto param = function->arg_begin();
        for(auto& arg:arguments){
            param->setName(arg.name);
            param++;
        }
        return function;
    }

    virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override {
        vector<Type*> paramList;
        vector<ArgumentInfo> arguments;
        for(auto& arg:ctx->variable()){
            arguments.push_back(visitVariable(arg).as<ArgumentInfo>());
            paramList.push_back(arguments.back().type);
        }
        FunctionType *type = FunctionType::get(Type::getVoidTy(context),paramList,false);
        string funcionName = ctx->name->getText();
        auto function = Function::Create(type,Function::ExternalLinkage,strToLower(ctx->name->getText()),mod);
        auto block = BasicBlock::Create(context, "EntryBlock", function);
        auto param = function->arg_begin();
        for(auto& arg:arguments){
            param->setName(arg.name);
            param++;
        }
        return function;
    }
};

#endif