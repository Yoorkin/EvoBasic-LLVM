
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"
#include "BasicParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by BasicParser.
 */
class  BasicVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by BasicParser.
   */
    virtual antlrcpp::Any visitStatements(BasicParser::StatementsContext *context) = 0;

    virtual antlrcpp::Any visitStatement(BasicParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitPluOp(BasicParser::PluOpContext *context) = 0;

    virtual antlrcpp::Any visitNumber(BasicParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitCmpOp(BasicParser::CmpOpContext *context) = 0;

    virtual antlrcpp::Any visitBucket(BasicParser::BucketContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(BasicParser::MulOpContext *context) = 0;

    virtual antlrcpp::Any visitPowModOp(BasicParser::PowModOpContext *context) = 0;

    virtual antlrcpp::Any visitNegOp(BasicParser::NegOpContext *context) = 0;

    virtual antlrcpp::Any visitString(BasicParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitID(BasicParser::IDContext *context) = 0;

    virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitBitOp(BasicParser::BitOpContext *context) = 0;

    virtual antlrcpp::Any visitLogicOp(BasicParser::LogicOpContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(BasicParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForeachStmt(BasicParser::ForeachStmtContext *context) = 0;

    virtual antlrcpp::Any visitIfStmt(BasicParser::IfStmtContext *context) = 0;

    virtual antlrcpp::Any visitLoopStmt(BasicParser::LoopStmtContext *context) = 0;

    virtual antlrcpp::Any visitLoopBody(BasicParser::LoopBodyContext *context) = 0;


};

