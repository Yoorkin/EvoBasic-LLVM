//
// Created by yorkin on 5/16/21.
//

#ifndef CLASSICBASIC_EXPGEN_H
#define CLASSICBASIC_EXPGEN_H

#include<antlr4-runtime/antlr4-runtime.h>
#include"../antlr/BasicLexer.h"
#include"../antlr/BasicParser.h"
#include"../antlr/BasicBaseVisitor.h"

class ConstExpGen:public BasicBaseVisitor {
public:

    virtual antlrcpp::Any visitBody(BasicParser::BodyContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitClassDecl(BasicParser::ClassDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitClassMember(BasicParser::ClassMemberContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitModuleDecl(BasicParser::ModuleDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitModuleMember(BasicParser::ModuleMemberContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEnumDecl(BasicParser::EnumDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPropertyGet(BasicParser::PropertyGetContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPropertySet(BasicParser::PropertySetContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitPropertyLet(BasicParser::PropertyLetContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOperatorOverride(BasicParser::OperatorOverrideContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitImportDecl(BasicParser::ImportDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitEnumPair(BasicParser::EnumPairContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExternalSub(BasicParser::ExternalSubContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExternalFunction(BasicParser::ExternalFunctionContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFactoryDecl(BasicParser::FactoryDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParameterList(BasicParser::ParameterListContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitOptionalParameter(BasicParser::OptionalParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTypeLocation(BasicParser::TypeLocationContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLine(BasicParser::LineContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStatement(BasicParser::StatementContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCallStmt(BasicParser::CallStmtContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInnerCall(BasicParser::InnerCallContext *ctx) override {
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

    virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override {
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

    virtual antlrcpp::Any visitInnerCallOp(BasicParser::InnerCallOpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBitOp(BasicParser::BitOpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitLogicOp(BasicParser::LogicOpContext *ctx) override {
        return visitChildren(ctx);
    }



};


#endif //CLASSICBASIC_EXPGEN_H
