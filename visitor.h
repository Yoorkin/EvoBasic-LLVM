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

class Visitor:public BasicBaseVisitor{
  map<string,llvm::Type*> buildInTypes;
  llvm::Module* mod;
  LLVMContext* context;
  BasicBlock* block;
  Function *function;
  public:
  Visitor(llvm::Module* m,LLVMContext* ctx){
    mod=m;
    context=ctx;
    buildInTypes.operator=({
      {"integer",Type::getInt32Ty(*context)},
      {"single",Type::getFloatTy(*context)},
      {"double",Type::getDoubleTy(*context)},
      {"boolean",Type::getInt1Ty(*context)},
      {"long",Type::getInt64Ty(*context)},
      {"byte",Type::getInt8Ty(*context)}
    });
  }

  virtual antlrcpp::Any visitDeclare(BasicParser::DeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override {
    vector<Type*> argsType;
    for(auto arg:ctx->variable()){
      argsType.push_back(buildInTypes.find(arg->type->getText())->second);
    }
    cout<<ctx->returnType->getText()<<endl;
    Type* retType = buildInTypes.find(ctx->returnType->getText())->second;
    FunctionType *type = FunctionType::get(retType,argsType,false);
    function = Function::Create(type,Function::ExternalLinkage,ctx->name->getText(),mod);
    block = BasicBlock::Create(*context, "EntryBlock", function);
    auto argsName = ctx->variable();
    auto arg = function->arg_begin();
    for(auto param:ctx->variable()){
      arg->setName(param->name->getText());
      arg++;
    }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override {
    vector<Type*> argsType;
    for(auto arg:ctx->variable()){
      argsType.push_back(buildInTypes.find(arg->type->getText())->second);
    }
    FunctionType *type = FunctionType::get(Type::getVoidTy(*context),argsType,false);
    function = Function::Create(type,Function::ExternalLinkage,ctx->name->getText(),mod);
    block = BasicBlock::Create(*context, "EntryBlock", function);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BasicParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPluOp(BasicParser::PluOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmpOp(BasicParser::CmpOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicNotOp(BasicParser::LogicNotOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNegOp(BasicParser::NegOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(BasicParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBucket(BasicParser::BucketContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulOp(BasicParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPowModOp(BasicParser::PowModOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitID(BasicParser::IDContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBitOp(BasicParser::BitOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogicOp(BasicParser::LogicOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(BasicParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeachStmt(BasicParser::ForeachStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSingleLineIf(BasicParser::SingleLineIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMutiLineIf(BasicParser::MutiLineIfContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfBlock(BasicParser::IfBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoWhile(BasicParser::DoWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDoUntil(BasicParser::DoUntilContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopUntil(BasicParser::LoopUntilContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopWhile(BasicParser::LoopWhileContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileWend(BasicParser::WhileWendContext *ctx) override {
    return visitChildren(ctx);
  }

};

#endif