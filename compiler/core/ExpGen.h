//
// Created by yorkin on 5/16/21.
//

#ifndef CLASSICBASIC_EXPGEN_H
#define CLASSICBASIC_EXPGEN_H

#include<antlr4-runtime/antlr4-runtime.h>
#include"../antlr/BasicLexer.h"
#include"../antlr/BasicParser.h"
#include"../antlr/BasicBaseVisitor.h"

class ConstExpVisitor:public BasicBaseVisitor {
    bool inConstExp=false;
public:
    virtual antlrcpp::Any visitConstExp(BasicParser::ConstExpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitBucketExp(BasicParser::BucketExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitMulExp(BasicParser::MulExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitNegExp(BasicParser::NegExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitRefExp(BasicParser::RefExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitPowModExp(BasicParser::PowModExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitLogicExp(BasicParser::LogicExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitBitExp(BasicParser::BitExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitLogicNotExp(BasicParser::LogicNotExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitPluExp(BasicParser::PluExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitCmpExp(BasicParser::CmpExpContext *ctx) override {
        return visitChildren(ctx);
    }


    virtual antlrcpp::Any visitTerminateNodeExp(BasicParser::TerminateNodeExpContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitFunctionCall(BasicParser::FunctionCallContext *ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTargetExp(BasicParser::TargetExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitMapExp(BasicParser::MapExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitArrayExp(BasicParser::ArrayExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitTupleExp(BasicParser::TupleExpContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitArrayOffset(BasicParser::ArrayOffsetContext *ctx) override {
        return visitChildren(ctx);
    }
    virtual antlrcpp::Any visitLambda(BasicParser::LambdaContext *ctx) override {
        return visitChildren(ctx);
    }
};


#endif //CLASSICBASIC_EXPGEN_H
