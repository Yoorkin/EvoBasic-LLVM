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
namespace classicBasic{

    namespace ConstExpCompute{
        enum Kind{bTy,i8Ty,i16Ty,i32Ty,i64Ty,f32Ty,f64Ty};
        class expRetValue{
        public:
            expRetValue()=default;
            expRetValue(f64 x){
                data.f64val=x;
                kind=f64Ty;
            }
            expRetValue(i64 x){
                data.i64val=x;
                kind=f64Ty;
            }
            expRetValue(i32 x){
                data.i32val=x;
                kind=i32Ty;
            }
            expRetValue(bool x){
                data.bval=x;
                kind=bTy;
            }
            /* 值越大的提升优先级更高 bool,character,i8,i16 -> i32 -> i64 -> f64
             * integer: i32
             * demical: f64
             * character: 根据UTF8编码大小为1字节到6字节
             * string:  utf8编码
             */
            Kind kind;
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
            void b_(expRetValue& e){
                switch(e.kind){
                    case i8Ty:
                        e.data.bval=e.data.i8val>0;
                        break;
                    case i16Ty:
                        e.data.bval=e.data.i16val>0;
                        break;
                    case i32Ty:
                        e.data.bval=e.data.i32val>0;
                        break;
                    case i64Ty:
                        e.data.bval=e.data.i64val>0;
                        break;
                    case f32Ty:
                        e.data.bval=e.data.f32val>0;
                        break;
                    case f64Ty:
                        e.data.bval=e.data.f64val>0;
                        break;
                }
                e.kind=i8Ty;
            };
            void i8_(expRetValue& e){
                switch(e.kind){
                    case bTy:
                        e.data.i8val=e.data.bval?1:0;
                        break;
                    case i16Ty:
                        e.data.i8val=e.data.i16val?1:0;
                        break;
                    case i32Ty:
                        e.data.i8val=e.data.i32val?1:0;
                        break;
                    case i64Ty:
                        e.data.i8val=e.data.i64val?1:0;
                        break;
                    case f32Ty:
                        e.data.i8val=e.data.f32val?1:0;
                        break;
                    case f64Ty:
                        e.data.i8val=e.data.f64val?1:0;
                        break;
                }
                e.kind=i8Ty;
            };
            void i16_(expRetValue& e){
                switch(e.kind){
                    case bTy:
                        e.data.i16val=e.data.bval?1:0;
                        break;
                    case i8Ty:
                        e.data.i16val=e.data.i8val;
                        break;
                    case i32Ty:
                        e.data.i16val=e.data.i32val;
                        Reporter::singleton->warning("Integer转换为Short将被截断");
                        break;
                    case i64Ty:
                        e.data.i16val=e.data.i64val;
                        Reporter::singleton->warning("Long转换为Short将被截断");
                        break;
                    case f32Ty:
                        e.data.i16val=e.data.f32val;
                        Reporter::singleton->warning("Single转换为Short将被截断");
                        break;
                    case f64Ty:
                        e.data.i16val=e.data.f64val;
                        Reporter::singleton->warning("Double转换为Short将被截断");
                        break;
                }
                e.kind=i16Ty;
            };
            void i32_(expRetValue& e){
                i32 val=e.data.i32val;
                switch(e.kind){
                    case bTy:
                        e.data.i32val=e.data.bval?1:0;
                        break;
                    case i8Ty:
                        e.data.i32val=e.data.i8val;
                        break;
                    case i16Ty:
                        e.data.i32val=e.data.i16val;
                        break;
                    case i64Ty:
                        e.data.i32val=e.data.i64val;
                        Reporter::singleton->warning("Long转换为Integer将被截断");
                        break;
                    case f32Ty:
                        e.data.i32val=e.data.f32val;
                        Reporter::singleton->warning("Single转换为Integer将损失精度");
                        break;
                    case f64Ty:
                        e.data.i32val=e.data.f64val;
                        Reporter::singleton->warning("Double转换为Integer将损失精度");
                        break;
                }
                e.kind=i32Ty;
            };
            void i64_(expRetValue& e){
                switch(e.kind){
                    case bTy:
                        e.data.i64val=e.data.bval?1:0;
                        break;
                    case i8Ty:
                        e.data.i64val=e.data.i8val;
                        break;
                    case i16Ty:
                        e.data.i64val=e.data.i16val;
                        break;
                    case i32Ty:
                        e.data.i64val=e.data.i32val;
                        break;
                    case f32Ty:
                        e.data.i64val=e.data.f32val;
                        Reporter::singleton->warning("Single转换为Long将损失精度");
                        break;
                    case f64Ty:
                        e.data.i64val=e.data.f64val;
                        Reporter::singleton->warning("Double转换为Long将损失精度");
                        break;
                }
                e.kind=i64Ty;
            };
            void f32_(expRetValue& e){
                switch(e.kind){
                    case bTy:
                        e.data.f32val=e.data.bval?1:0;
                        break;
                    case i8Ty:
                        e.data.f32val=e.data.i8val;
                        break;
                    case i16Ty:
                        e.data.f32val=e.data.i16val;
                        break;
                    case i32Ty:
                        e.data.f32val=e.data.i32val;
                        break;
                    case i64Ty:
                        e.data.f32val=e.data.i64val;
                        Reporter::singleton->warning("Long转换为Single将被截断");
                        break;
                    case f64Ty:
                        e.data.f32val=e.data.f64val;
                        Reporter::singleton->warning("Double转换为Single将损失精度");
                        break;
                }
                e.kind=f32Ty;
            };
            void f64_(expRetValue& e){
                switch(e.kind){
                    case bTy:
                        e.data.f64val=e.data.bval?1:0;
                        break;
                    case i8Ty:
                        e.data.f64val=e.data.i8val;
                        break;
                    case i16Ty:
                        e.data.f64val=e.data.i16val;
                        break;
                    case i32Ty:
                        e.data.f64val=e.data.i32val;
                        break;
                    case i64Ty:
                        e.data.f64val=e.data.i64val;
                        break;
                    case f32Ty:
                        e.data.f64val=e.data.i32val;
                        break;
                }
                e.kind=f64Ty;
            };
        }

        Kind promotion(expRetValue& a,expRetValue& b){
#define N nullptr
            using namespace builtInCast;
            function<void(expRetValue&)> promotion_table[7][7]={
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
            auto cvt = promotion_table[a.kind][b.kind];
            if(!cvt){
                cvt(a);
                cvt(b);
            }
            return a.kind;
        }

        namespace Compute{
            void neg(expRetValue& a){
                switch(a.kind){
                    case bTy:
                        a.data.bval=-a.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val=-a.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val=-a.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val=-a.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val=-a.data.i64val;
                        break;
                    case f32Ty:
                        a.data.f32val=-a.data.f32val;
                        break;
                    case f64Ty:
                        a.data.f64val=-a.data.f64val;
                        break;
                }
            }
            void add(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval+=b.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val+=b.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val+=b.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val+=b.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val+=b.data.i64val;
                        break;
                    case f32Ty:
                        a.data.f32val+=b.data.f32val;
                        break;
                    case f64Ty:
                        a.data.f64val+=b.data.f64val;
                        break;
                }
            }
            void sub(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval-=b.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val-=b.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val-=b.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val-=b.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val-=b.data.i64val;
                        break;
                    case f32Ty:
                        a.data.f32val-=b.data.f32val;
                        break;
                    case f64Ty:
                        a.data.f64val-=b.data.f64val;
                        break;
                }
            }
            void mul(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval*=b.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val*=b.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val*=b.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val*=b.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val*=b.data.i64val;
                        break;
                    case f32Ty:
                        a.data.f32val*=b.data.f32val;
                        break;
                    case f64Ty:
                        a.data.f64val*=b.data.f64val;
                        break;
                }
            }
            void div(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval/=b.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val/=b.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val/=b.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val/=b.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val/=b.data.i64val;
                        break;
                    case f32Ty:
                        a.data.f32val/=b.data.f32val;
                        break;
                    case f64Ty:
                        a.data.f64val/=b.data.f64val;
                        break;
                }
            }
            void pow(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=std::pow(a.data.bval,b.data.bval);
                        break;
                    case i8Ty:
                        a.data.i8val=std::pow(a.data.i8val,b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.i16val=std::pow(a.data.i16val,b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.i32val=std::pow(a.data.i32val,b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.i64val=std::pow(a.data.i64val,b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.f32val=std::pow(a.data.f32val,b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.f64val=std::pow(a.data.f64val,b.data.f64val);
                        break;
                }
            }
            void mod(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval%=b.data.bval;
                        break;
                    case i8Ty:
                        a.data.i8val%=b.data.i8val;
                        break;
                    case i16Ty:
                        a.data.i16val%=b.data.i16val;
                        break;
                    case i32Ty:
                        a.data.i32val%=b.data.i32val;
                        break;
                    case i64Ty:
                        a.data.i64val%=b.data.i64val;
                        break;
                    case f32Ty:
                    case f64Ty:
                        Reporter::singleton->report("浮点类型无法参与模运算");
                        break;
                }
            }
            void LE(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval<=b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val<=b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val<=b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val<=b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val<=b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val<=b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val<=b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void LeftShift(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval<<b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val<<b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val<<b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val<<b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val<<b.data.i64val);
                        break;
                    case f32Ty:
                    case f64Ty:
                        Reporter::singleton->report("浮点类型无法参与位运算");
                }
            }
            void RightShift(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval>>b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val>>b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val>>b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val>>b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val>>b.data.i64val);
                        break;
                    case f32Ty:
                    case f64Ty:
                        Reporter::singleton->report("浮点类型无法参与位运算");
                }
            }
            void BitAnd(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval>=b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val>=b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val>=b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val>=b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val>=b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val>=b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val>=b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void BitOr(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval|b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val|b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val|b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val|b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val|b.data.i64val);
                        break;
                    case f32Ty:
                    case f64Ty:
                        Reporter::singleton->report("浮点类型无法参与位运算");
                }
            }
            void BitXor(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval^b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val^b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val^b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val^b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val^b.data.i64val);
                        break;
                    case f32Ty:
                    case f64Ty:
                        Reporter::singleton->report("浮点类型无法参与位运算");
                }
            }
            void BitNot(expRetValue& a){
                switch(a.kind){
                    case bTy:
                        a.data.bval=(!a.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(!a.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(!a.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(!a.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(!a.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(!a.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(!a.data.f64val);
                        break;
                }
            }
            void GE(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval>=b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val>=b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val>=b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val>=b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val>=b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val>=b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val>=b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void EQ(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval==b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val==b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val==b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val==b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val==b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val==b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val==b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void LT(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval<b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val<b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val<b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val<b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val<b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val<b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val<b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void GT(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval>b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val>b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val>b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val>b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val>b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val>b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val>b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void NE(expRetValue& a,expRetValue& b){
                switch(promotion(a,b)){
                    case bTy:
                        a.data.bval=(a.data.bval!=b.data.bval);
                        break;
                    case i8Ty:
                        a.data.bval=(a.data.i8val!=b.data.i8val);
                        break;
                    case i16Ty:
                        a.data.bval=(a.data.i16val!=b.data.i16val);
                        break;
                    case i32Ty:
                        a.data.bval=(a.data.i32val!=b.data.i32val);
                        break;
                    case i64Ty:
                        a.data.bval=(a.data.i64val!=b.data.i64val);
                        break;
                    case f32Ty:
                        a.data.bval=(a.data.f32val!=b.data.f32val);
                        break;
                    case f64Ty:
                        a.data.bval=(a.data.f64val!=b.data.f64val);
                        break;
                }
                a.kind=bTy;
            }
            void And(expRetValue& a,expRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval&&b.data.bval);
            }
            void Or(expRetValue& a,expRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval||b.data.bval);
            }
            void Xor(expRetValue& a,expRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval xor b.data.bval);
            }
            void Not(expRetValue& a){
                builtInCast::b_(a);
                a.data.bval=(!a.data.bval);
            }
        }

        using namespace std;
        class ConstExpVisitor:public BasicBaseVisitor {
            CodeGenerator& gen;
            GenerateUnit& unit;
        public:
            ConstExpVisitor(GenerateUnit& unit):unit(unit),gen(unit.gen){}
            virtual antlrcpp::Any visitConstExp(BasicParser::ConstExpContext *ctx)override{
                expRetValue value = visit(ctx->exp()).as<expRetValue>();
                return value;
                //TODO
            }
            virtual antlrcpp::Any visitMulExp(BasicParser::MulExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                Compute::mul(left,right);
                return left;
            }
            virtual antlrcpp::Any visitNegExp(BasicParser::NegExpContext *ctx) override {
                expRetValue right = visit(ctx->right).as<expRetValue>();
                Compute::neg(right);
                return right;
            }
            virtual antlrcpp::Any visitRefExp(BasicParser::RefExpContext *ctx) override {
//                std::vector<std::string> paths;
//                for(auto t:ctx->terminateNode()){
//                    paths.push_back(t)
//                }
//                unit.scope->lookUp(strToLower(ctx->))
                //TODO
            }
            virtual antlrcpp::Any visitPowModExp(BasicParser::PowModExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                Compute::pow(left,right);
                return left;
            }
            virtual antlrcpp::Any visitLogicExp(BasicParser::LogicExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                char op = strToLower(ctx->op->getText())[0];
                if(op=='a')Compute::And(left,right);
                else if(op=='o')Compute::Or(left,right);
                else if(op=='x')Compute::Xor(left,right);
                return left;
            }
            virtual antlrcpp::Any visitBitExp(BasicParser::BitExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                if(ctx->leftShift()!=nullptr)Compute::LeftShift(left,right);
                else if(ctx->rightShift()!=nullptr)Compute::RightShift(left,right);
                else if(ctx->andBit()!=nullptr)Compute::BitAnd(left,right);
                else if(ctx->orBit()!=nullptr)Compute::BitOr(left,right);
                else if(ctx->xorBit()!=nullptr)Compute::BitXor(left,right);
                return left;
            }
            virtual antlrcpp::Any visitLogicNotExp(BasicParser::LogicNotExpContext *ctx) override {
                expRetValue right = visit(ctx->right).as<expRetValue>();
                Compute::Not(right);
                return right;
            }
            virtual antlrcpp::Any visitPluExp(BasicParser::PluExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                Compute::add(left,right);
                return left;
            }
            virtual antlrcpp::Any visitCmpExp(BasicParser::CmpExpContext *ctx) override {
                expRetValue left = visit(ctx->left).as<expRetValue>();
                expRetValue right = visit(ctx->right).as<expRetValue>();
                if(ctx->eqCmp()!=nullptr)Compute::EQ(left,right);
                else if(ctx->neCmp()!=nullptr)Compute::NE(left,right);
                else if(ctx->ltCmp()!=nullptr)Compute::LT(left,right);
                else if(ctx->gtCmp()!=nullptr)Compute::GT(left,right);
                else if(ctx->leCmp()!=nullptr)Compute::LE(left,right);
                else if(ctx->geCmp()!=nullptr)Compute::GE(left,right);
                return left;
            }


            virtual antlrcpp::Any visitTerminateNodeExp(BasicParser::TerminateNodeExpContext *ctx) override {
                //TODO
                return visitChildren(ctx);
            }
            virtual antlrcpp::Any visitInteger(BasicParser::IntegerContext *ctx) override {
                i32 value = std::stoi(ctx->getText());
                return expRetValue(value);
            }
            virtual antlrcpp::Any visitDecimal(BasicParser::DecimalContext *ctx) override {
                f64 value = std::stod(ctx->getText());
                return expRetValue(value);
            }
            virtual antlrcpp::Any visitString(BasicParser::StringContext *ctx) override {
                return visitChildren(ctx);
            }
            virtual antlrcpp::Any visitBoolean(BasicParser::BooleanContext *ctx) override {
                bool value = strToLower(ctx->getText())[0]=='t'?true:false;
                return expRetValue(value);
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
    }

}



#endif //CLASSICBASIC_EXPGEN_H
