
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "BasicParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by BasicParser.
 */
class  BasicListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterExp(BasicParser::ExpContext *ctx) = 0;
  virtual void exitExp(BasicParser::ExpContext *ctx) = 0;

  virtual void enterStatement(BasicParser::StatementContext *ctx) = 0;
  virtual void exitStatement(BasicParser::StatementContext *ctx) = 0;

  virtual void enterForStmt(BasicParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(BasicParser::ForStmtContext *ctx) = 0;

  virtual void enterForeachStmt(BasicParser::ForeachStmtContext *ctx) = 0;
  virtual void exitForeachStmt(BasicParser::ForeachStmtContext *ctx) = 0;

  virtual void enterIfStmt(BasicParser::IfStmtContext *ctx) = 0;
  virtual void exitIfStmt(BasicParser::IfStmtContext *ctx) = 0;

  virtual void enterLoopStmt(BasicParser::LoopStmtContext *ctx) = 0;
  virtual void exitLoopStmt(BasicParser::LoopStmtContext *ctx) = 0;

  virtual void enterLoopBody(BasicParser::LoopBodyContext *ctx) = 0;
  virtual void exitLoopBody(BasicParser::LoopBodyContext *ctx) = 0;


};

