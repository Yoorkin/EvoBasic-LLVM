
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "BasicVisitor.h"


/**
 * This class provides an empty implementation of BasicVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  BasicBaseVisitor : public BasicVisitor {
public:

  virtual antlrcpp::Any visitStatements(BasicParser::StatementsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(BasicParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPluOp(BasicParser::PluOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(BasicParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCmpOp(BasicParser::CmpOpContext *ctx) override {
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

  virtual antlrcpp::Any visitNegOp(BasicParser::NegOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
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

  virtual antlrcpp::Any visitIfStmt(BasicParser::IfStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopStmt(BasicParser::LoopStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLoopBody(BasicParser::LoopBodyContext *ctx) override {
    return visitChildren(ctx);
  }


};

