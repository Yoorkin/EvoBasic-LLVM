
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "BasicListener.h"


/**
 * This class provides an empty implementation of BasicListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  BasicBaseListener : public BasicListener {
public:

  virtual void enterExp(BasicParser::ExpContext * /*ctx*/) override { }
  virtual void exitExp(BasicParser::ExpContext * /*ctx*/) override { }

  virtual void enterStatement(BasicParser::StatementContext * /*ctx*/) override { }
  virtual void exitStatement(BasicParser::StatementContext * /*ctx*/) override { }

  virtual void enterForStmt(BasicParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(BasicParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterForeachStmt(BasicParser::ForeachStmtContext * /*ctx*/) override { }
  virtual void exitForeachStmt(BasicParser::ForeachStmtContext * /*ctx*/) override { }

  virtual void enterIfStmt(BasicParser::IfStmtContext * /*ctx*/) override { }
  virtual void exitIfStmt(BasicParser::IfStmtContext * /*ctx*/) override { }

  virtual void enterLoopStmt(BasicParser::LoopStmtContext * /*ctx*/) override { }
  virtual void exitLoopStmt(BasicParser::LoopStmtContext * /*ctx*/) override { }

  virtual void enterLoopBody(BasicParser::LoopBodyContext * /*ctx*/) override { }
  virtual void exitLoopBody(BasicParser::LoopBodyContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

