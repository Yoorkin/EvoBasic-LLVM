#include<gtest/gtest.h>
#include<core/genUtility.h>
#include<core/ExpGen.h>
#include<iostream>
#include "ExpGen.h"

using namespace std;
using namespace classicBasic;
using namespace classicBasic::constExpCompute;

#define loadUnit(name) stringstream stream(code);\
                        ANTLRInputStream input(stream);\
                        BasicLexer lexer(&input);\
                        CommonTokenStream tokens(&lexer);\
                        BasicParser parser(&tokens);\
                        BasicParser::ConstExpContext* tree = parser.constExp();\
                        CodeGenerator gen;\
                        auto unit=gen.CreateUnit(#name ,stream,cout);

TEST(constExp,AddSubMulDiv){
    string code=R"code(
        2*(7-4)/2
    )code";
    loadUnit(AddSubMulDiv)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::f32Ty);
    ASSERT_EQ(exp.data.f32val,3);
}

TEST(constExp,Add){
    string code=R"code(
        5+32
    )code";
    loadUnit(Add)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.data.i32val,37);
}

TEST(constExp,Sub){
    string code=R"code(
        5-27
    )code";
    loadUnit(Sub);
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.data.i32val,-22);
}

TEST(constExp,Mul){
    string code=R"code(
        11*8
    )code";
    loadUnit(Mul)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,88);
}

TEST(constExp,fpDiv){
    string code=R"code(
        20/3
    )code";
    loadUnit(fpDiv)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::f32Ty);
    ASSERT_TRUE(exp.data.f32val-6.66666 < 0.001f);
}

TEST(constExp,ZDiv){
    string code=R"code(
        20\3
    )code";
    loadUnit(ZDiv)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,6);
}

TEST(constExp,BucketExp){
    string code=R"code(
        9-(1+1*(5-1))
    )code";
    loadUnit(BucketExp)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,4);
}

TEST(constExp,TrueLiteral){
    string code=R"code(
        true
    )code";
    loadUnit(TrueLiteral)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::bTy);
    ASSERT_EQ(exp.data.bval,true);
}

TEST(constExp,FalseLiteral){
    string code=R"code(
        false
    )code";
    loadUnit(FalseLiteral)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::bTy);
    ASSERT_EQ(exp.data.bval,false);
}

TEST(constExp,IntegerLiteral){
    string code=R"code(
        114514
    )code";
    loadUnit(IntegerLiteral)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,114514);
}

TEST(constExp,FloatingPointLiteral){
    string code=R"code(
        3.1415926
    )code";
    loadUnit(FloatingPointLiteral)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::f64Ty);
    ASSERT_EQ(exp.data.f64val,3.1415926);
}

TEST(constExp,IntegralPromotion){
    string code=R"code(
        1+9876543210
    )code";
    loadUnit(IntegralPromotion)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i64Ty);
    ASSERT_EQ(exp.data.i64val,9876543211);
}

TEST(constExp,trueToi32Promotion){
    string code=R"code(
        true+1
    )code";
    loadUnit(IntegralPromotion)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,2);
}

TEST(constExp,falseToi32Promotion){
    string code=R"code(
        false-1
    )code";
    loadUnit(IntegralPromotion)
    ConstExpVisitor visitor(*unit);
    auto exp = visitor.visitConstExp(tree).as<ExpRetValue>();
    ASSERT_EQ(exp.kind, BuiltInKind::i32Ty);
    ASSERT_EQ(exp.data.i32val,-1);
}


#undef loadUnit