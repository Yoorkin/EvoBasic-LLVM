
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
    virtual antlrcpp::Any visitModuleBody(BasicParser::ModuleBodyContext *context) = 0;

    virtual antlrcpp::Any visitDeclare(BasicParser::DeclareContext *context) = 0;

    virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *context) = 0;

    virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *context) = 0;

    virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *context) = 0;

    virtual antlrcpp::Any visitVarType(BasicParser::VarTypeContext *context) = 0;

    virtual antlrcpp::Any visitStatement(BasicParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitAssignStmt(BasicParser::AssignStmtContext *context) = 0;

    virtual antlrcpp::Any visitExitStmt(BasicParser::ExitStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(BasicParser::ReturnStmtContext *context) = 0;

    virtual antlrcpp::Any visitPluOp(BasicParser::PluOpContext *context) = 0;

    virtual antlrcpp::Any visitCmpOp(BasicParser::CmpOpContext *context) = 0;

    virtual antlrcpp::Any visitLogicNotOp(BasicParser::LogicNotOpContext *context) = 0;

    virtual antlrcpp::Any visitNegOp(BasicParser::NegOpContext *context) = 0;

    virtual antlrcpp::Any visitString(BasicParser::StringContext *context) = 0;

    virtual antlrcpp::Any visitNumber(BasicParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitBucket(BasicParser::BucketContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(BasicParser::MulOpContext *context) = 0;

    virtual antlrcpp::Any visitPowModOp(BasicParser::PowModOpContext *context) = 0;

    virtual antlrcpp::Any visitID(BasicParser::IDContext *context) = 0;

    virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *context) = 0;

    virtual antlrcpp::Any visitBitOp(BasicParser::BitOpContext *context) = 0;

    virtual antlrcpp::Any visitLogicOp(BasicParser::LogicOpContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(BasicParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitForeachStmt(BasicParser::ForeachStmtContext *context) = 0;

    virtual antlrcpp::Any visitSingleLineIf(BasicParser::SingleLineIfContext *context) = 0;

    virtual antlrcpp::Any visitMutiLineIf(BasicParser::MutiLineIfContext *context) = 0;

    virtual antlrcpp::Any visitIfBlock(BasicParser::IfBlockContext *context) = 0;

    virtual antlrcpp::Any visitDoWhile(BasicParser::DoWhileContext *context) = 0;

    virtual antlrcpp::Any visitDoUntil(BasicParser::DoUntilContext *context) = 0;

    virtual antlrcpp::Any visitLoopUntil(BasicParser::LoopUntilContext *context) = 0;

    virtual antlrcpp::Any visitLoopWhile(BasicParser::LoopWhileContext *context) = 0;

    virtual antlrcpp::Any visitWhileWend(BasicParser::WhileWendContext *context) = 0;


};

