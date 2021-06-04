//
// Created by yorkin on 5/16/21.
//

#ifndef CLASSICBASIC_EXPGEN_H
#define CLASSICBASIC_EXPGEN_H

#include<antlr4-runtime/antlr4-runtime.h>
#include"../antlr/BasicLexer.h"
#include"../antlr/BasicParser.h"
#include"../antlr/BasicBaseVisitor.h"

#include"genUtility.h"
#include"basicTypeDef.h"
#include<cmath>
#include<functional>

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

namespace classicBasic{
    //TODO: 考虑添加INF和NaH https://zh.wikipedia.org/wiki/NaN
    enum BuiltInKind{bTy,i8Ty,i16Ty,i32Ty,i64Ty,f32Ty,f64Ty};

    namespace constExpCompute{
        class ExpRetValue{
        public:
            ExpRetValue()=default;
            ExpRetValue(f64 x);
            ExpRetValue(i64 x);
            ExpRetValue(i32 x);
            ExpRetValue(bool x);
            /* 值越大的提升优先级更高 bool,character,i8,i16 -> i32 -> i64 -> f64
             * integer: i32
             * demical: f64
             * character: 根据UTF8编码大小为1字节到6字节
             * string:  utf8编码
             */
            BuiltInKind kind;
            union Data{
                i64 i64val;
                i32 i32val;
                i16 i16val;
                i8 i8val;

                f64 f64val;
                f32 f32val;

                bool bval;
            }data;
        };

        namespace builtInCast{
            void b_(ExpRetValue& e);
            void i8_(ExpRetValue& e);
            void i16_(ExpRetValue& e);
            void i32_(ExpRetValue& e);
            void i64_(ExpRetValue& e);
            void f32_(ExpRetValue& e);
            void f64_(ExpRetValue& e);
        }
        void doNothing(ExpRetValue& e);
        BuiltInKind promotion(ExpRetValue& a, ExpRetValue& b);

        namespace Compute{
            void neg(ExpRetValue& a);
            void add(ExpRetValue& a, ExpRetValue& b);
            void sub(ExpRetValue& a, ExpRetValue& b);
            void mul(ExpRetValue& a, ExpRetValue& b);
            void fpDiv(ExpRetValue& a, ExpRetValue& b);
            void ZDiv(ExpRetValue& a, ExpRetValue& b);
            void pow(ExpRetValue& a, ExpRetValue& b);
            void mod(ExpRetValue& a, ExpRetValue& b);
            void LE(ExpRetValue& a, ExpRetValue& b);
            void LeftShift(ExpRetValue& a, ExpRetValue& b);
            void RightShift(ExpRetValue& a, ExpRetValue& b);
            void BitAnd(ExpRetValue& a, ExpRetValue& b);
            void BitOr(ExpRetValue& a, ExpRetValue& b);
            void BitXor(ExpRetValue& a, ExpRetValue& b);
            void BitNot(ExpRetValue& a);
            void GE(ExpRetValue& a, ExpRetValue& b);
            void EQ(ExpRetValue& a, ExpRetValue& b);
            void LT(ExpRetValue& a, ExpRetValue& b);
            void GT(ExpRetValue& a, ExpRetValue& b);
            void NE(ExpRetValue& a, ExpRetValue& b);
            void And(ExpRetValue& a, ExpRetValue& b);
            void Or(ExpRetValue& a, ExpRetValue& b);
            void Xor(ExpRetValue& a, ExpRetValue& b);
            void Not(ExpRetValue& a);
        }

        using namespace std;
        class ConstExpVisitor:public BasicBaseVisitor {
            CodeGenerator& gen;
            Unit& unit;
        public:
            ConstExpVisitor(Unit& unit): unit(unit), gen(*(unit.gen)){}
            virtual antlrcpp::Any visitConstExp(BasicParser::ConstExpContext *ctx)override;
            virtual antlrcpp::Any visitMulExp(BasicParser::MulExpContext *ctx) override;
            virtual antlrcpp::Any visitNegExp(BasicParser::NegExpContext *ctx) override;
            virtual antlrcpp::Any visitRefExp(BasicParser::RefExpContext *ctx) override;
            virtual antlrcpp::Any visitPowModExp(BasicParser::PowModExpContext *ctx) override;
            virtual antlrcpp::Any visitLogicExp(BasicParser::LogicExpContext *ctx) override;
            virtual antlrcpp::Any visitBitExp(BasicParser::BitExpContext *ctx) override;
            virtual antlrcpp::Any visitLogicNotExp(BasicParser::LogicNotExpContext *ctx) override;
            virtual antlrcpp::Any visitPluExp(BasicParser::PluExpContext *ctx) override;
            virtual antlrcpp::Any visitCmpExp(BasicParser::CmpExpContext *ctx) override;

            virtual antlrcpp::Any visitTerminateNodeExp(BasicParser::TerminateNodeExpContext *ctx) override;
            virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override;
            virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override;
            virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override;
            virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override;
            virtual antlrcpp::Any visitFunctionCall(BasicParser::FunctionCallContext *ctx) override;
            virtual antlrcpp::Any visitBucketExp(BasicParser::BucketExpContext *ctx) override;
            virtual antlrcpp::Any visitTargetExp(BasicParser::TargetExpContext *ctx) override;
            virtual antlrcpp::Any visitMapExp(BasicParser::MapExpContext *ctx) override;
            virtual antlrcpp::Any visitArrayExp(BasicParser::ArrayExpContext *ctx) override;
            virtual antlrcpp::Any visitTupleExp(BasicParser::TupleExpContext *ctx) override;
            virtual antlrcpp::Any visitArrayOffset(BasicParser::ArrayOffsetContext *ctx) override;
            virtual antlrcpp::Any visitLambda(BasicParser::LambdaContext *ctx) override;
        };

    }

    namespace ExpLLVMValueCast{
        enum LLVMValueKind{
            bTy,i8Ty,i16Ty,i32Ty,i64Ty,f32Ty,f64Ty
        };

        class ExpRetInfo{
        public:
            llvm::Value* value;
            LLVMValueKind kind;
            ExpRetInfo(Value* v,LLVMValueKind k):value(v),kind(k){}
            ExpRetInfo cast(LLVMValueKind dst,Unit* unit);
        };

        void promotionLLVMValue(ExpRetInfo* a,ExpRetInfo* b){
#define i8_ Type::getInt8Ty(gen.getContext())
#define i16_ Type::getInt16Ty(gen.getContext())
#define i32_ Type::getInt32Ty(gen.getContext())
#define i64_ Type::getInt64Ty(gen.getContext())
#define f32_ Type::getFloatTy(gen.getContext())
#define f64_ Type::getDoubleTy(gen.getContext())
#define N nullptr
            llvm::Type* promotion_table[7][7]={
                    /* b    i8   i16  i32  i64  f32  f64 */
                    /*b*/  {N,   i8_, i16_,i32_,i64_,f32_,f64_},
                    /*i8*/ {i8_, N,   i16_,i32_,i64_,f32_,f64_},
                    /*i16*/{i16_,i16_,N,   i32_,i64_,f32_,f64_},
                    /*i32*/{i32_,i32_,i32_,N   ,i64_,f32_,f64_},
                    /*i64*/{i64_,i64_,i64_,i64_,N   ,f32_,f64_},
                    /*f32*/{f32_,f32_,f32_,f32_,f32_,N   ,f64_},
                    /*f64*/{f64_,f64_,f64_,f64_,f64_,f64_,N   }
            };
#undef N
#undef i8_
#undef i16_
#undef i32_
#undef i64_
#undef f32_
#undef f64_
            auto cvt = promotion_table[a->kind][b->kind];
            // return a->kind;
        }
    }


    class ExpVisitor:public BasicBaseVisitor {
        CodeGenerator& gen;
        Unit& unit;
    public:

        ExpVisitor(Unit& unit): unit(unit), gen(*(unit.gen)){}
        virtual antlrcpp::Any visitMulExp(BasicParser::MulExpContext *ctx) override;
        virtual antlrcpp::Any visitNegExp(BasicParser::NegExpContext *ctx) override;
        virtual antlrcpp::Any visitRefExp(BasicParser::RefExpContext *ctx) override;
        virtual antlrcpp::Any visitPowModExp(BasicParser::PowModExpContext *ctx) override;
        virtual antlrcpp::Any visitLogicExp(BasicParser::LogicExpContext *ctx) override;
        virtual antlrcpp::Any visitBitExp(BasicParser::BitExpContext *ctx) override;
        virtual antlrcpp::Any visitLogicNotExp(BasicParser::LogicNotExpContext *ctx) override;
        virtual antlrcpp::Any visitPluExp(BasicParser::PluExpContext *ctx) override;
        virtual antlrcpp::Any visitCmpExp(BasicParser::CmpExpContext *ctx) override;

        virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override;
        virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override;
        virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override;
        virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override;
        virtual antlrcpp::Any visitFunctionCall(BasicParser::FunctionCallContext *ctx) override;
        virtual antlrcpp::Any visitBucketExp(BasicParser::BucketExpContext *ctx) override;
        virtual antlrcpp::Any visitTargetExp(BasicParser::TargetExpContext *ctx) override;
        virtual antlrcpp::Any visitMapExp(BasicParser::MapExpContext *ctx) override;
        virtual antlrcpp::Any visitArrayExp(BasicParser::ArrayExpContext *ctx) override;
        virtual antlrcpp::Any visitTupleExp(BasicParser::TupleExpContext *ctx) override;
        virtual antlrcpp::Any visitArrayOffset(BasicParser::ArrayOffsetContext *ctx) override;
        virtual antlrcpp::Any visitLambda(BasicParser::LambdaContext *ctx) override;
    };
}



#endif //CLASSICBASIC_EXPGEN_H
