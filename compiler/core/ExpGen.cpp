//
// Created by yorkin on 5/16/21.
//

#include "ExpGen.h"


namespace classicBasic{
    //TODO: 考虑添加INF和NaH https://zh.wikipedia.org/wiki/NaN
    namespace constExpCompute {

        ExpRetValue::ExpRetValue(f64 x) {
            data.f64val = x;
            kind = f64Ty;
        }
        ExpRetValue::ExpRetValue(i64 x) {
            data.i64val = x;
            kind = f64Ty;
        }
        ExpRetValue::ExpRetValue(i32 x) {
            data.i32val = x;
            kind = i32Ty;
        }
        ExpRetValue::ExpRetValue(bool x) {
            data.bval = x;
            kind = bTy;
        }

        namespace builtInCast{
            void b_(ExpRetValue& e){
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
            void i8_(ExpRetValue& e){
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
            void i16_(ExpRetValue& e){
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
            void i32_(ExpRetValue& e){
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
            void i64_(ExpRetValue& e){
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
            void f32_(ExpRetValue& e){
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
            void f64_(ExpRetValue& e){
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
        void doNothing(ExpRetValue& e){}

        BuiltInKind promotion(ExpRetValue& a, ExpRetValue& b){
#define N doNothing
            using namespace builtInCast;
            function<void(ExpRetValue&)> promotion_table[7][7]={
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
            cvt(a);
            cvt(b);
            return a.kind;
        }

        namespace Compute{
            void neg(ExpRetValue& a){
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
            void add(ExpRetValue& a, ExpRetValue& b){
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
            void sub(ExpRetValue& a, ExpRetValue& b){
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
            void mul(ExpRetValue& a, ExpRetValue& b){
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
            void fpDiv(ExpRetValue& a, ExpRetValue& b){
                //num Kind{bTy,i8Ty,i16Ty,i32Ty,i64Ty,f32Ty,f64Ty};
                if(a.kind<=f32Ty && b.kind<=f32Ty){
                    builtInCast::f32_(a);
                    builtInCast::f32_(b);
                    a.data.f32val/=b.data.f32val;
                }
                else{
                    builtInCast::f64_(a);
                    builtInCast::f64_(b);
                    a.data.f64val/=b.data.f64val;
                }
            }
            void ZDiv(ExpRetValue& a, ExpRetValue& b){
                /* 舍弃小数部分，四舍六入五成双
                 * 见 https://www.cnblogs.com/freshman0216/archive/2008/08/27/1276991.html
                 *   https://en.cppreference.com/w/cpp/language/operator_arithmetic
                 */
                if(a.kind<=i32Ty && b.kind<=i32Ty){
                    builtInCast::i32_(a);
                    builtInCast::i32_(b);
                    a.data.i32val/=b.data.i32val;
                }
                else if(a.kind>i32Ty || b.kind>i32Ty){
                    builtInCast::i64_(a);
                    builtInCast::i64_(b);
                    a.data.i64val/=b.data.i64val;
                }
            }
            void pow(ExpRetValue& a, ExpRetValue& b){
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
            void mod(ExpRetValue& a, ExpRetValue& b){
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
            void LE(ExpRetValue& a, ExpRetValue& b){
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
            void LeftShift(ExpRetValue& a, ExpRetValue& b){
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
            void RightShift(ExpRetValue& a, ExpRetValue& b){
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
            void BitAnd(ExpRetValue& a, ExpRetValue& b){
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
            void BitOr(ExpRetValue& a, ExpRetValue& b){
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
            void BitXor(ExpRetValue& a, ExpRetValue& b){
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
            void BitNot(ExpRetValue& a){
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
            void GE(ExpRetValue& a, ExpRetValue& b){
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
            void EQ(ExpRetValue& a, ExpRetValue& b){
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
            void LT(ExpRetValue& a, ExpRetValue& b){
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
            void GT(ExpRetValue& a, ExpRetValue& b){
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
            void NE(ExpRetValue& a, ExpRetValue& b){
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
            void And(ExpRetValue& a, ExpRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval&&b.data.bval);
            }
            void Or(ExpRetValue& a, ExpRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval||b.data.bval);
            }
            void Xor(ExpRetValue& a, ExpRetValue& b){
                builtInCast::b_(a);
                builtInCast::b_(b);
                a.data.bval=(a.data.bval xor b.data.bval);
            }
            void Not(ExpRetValue& a){
                builtInCast::b_(a);
                a.data.bval=(!a.data.bval);
            }
        }

        using namespace std;

        antlrcpp::Any ConstExpVisitor::visitConstExp(BasicParser::ConstExpContext *ctx){
            ExpRetValue value = visit(ctx->exp()).as<ExpRetValue>();
            return value;
            //TODO
        }
        antlrcpp::Any ConstExpVisitor::visitMulExp(BasicParser::MulExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            auto op=ctx->op->getText();
            if(op=="*")
                Compute::mul(left,right);
            else if(op=="\\")//整除
                Compute::ZDiv(left,right);
            else if(op=="/")//普通除
                Compute::fpDiv(left,right);

            return left;
        }
        antlrcpp::Any ConstExpVisitor::visitNegExp(BasicParser::NegExpContext *ctx)  {
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            Compute::neg(right);
            return right;
        }
        antlrcpp::Any ConstExpVisitor::visitRefExp(BasicParser::RefExpContext *ctx)  {
//                std::vector<std::string> paths;
//                for(auto t:ctx->terminateNode()){
//                    paths.push_back(t)
//                }
//                unit.scope->lookUp(strToLower(ctx->))
            //TODO
        }
        antlrcpp::Any ConstExpVisitor::visitPowModExp(BasicParser::PowModExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            Compute::pow(left,right);
            return left;
        }
        antlrcpp::Any ConstExpVisitor::visitLogicExp(BasicParser::LogicExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            char op = strToLower(ctx->op->getText())[0];
            if(op=='a')Compute::And(left,right);
            else if(op=='o')Compute::Or(left,right);
            else if(op=='x')Compute::Xor(left,right);
            return left;
        }
        antlrcpp::Any ConstExpVisitor::visitBitExp(BasicParser::BitExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            if(ctx->leftShift()!=nullptr)Compute::LeftShift(left,right);
            else if(ctx->rightShift()!=nullptr)Compute::RightShift(left,right);
            else if(ctx->andBit()!=nullptr)Compute::BitAnd(left,right);
            else if(ctx->orBit()!=nullptr)Compute::BitOr(left,right);
            else if(ctx->xorBit()!=nullptr)Compute::BitXor(left,right);
            return left;
        }
        antlrcpp::Any ConstExpVisitor::visitLogicNotExp(BasicParser::LogicNotExpContext *ctx)  {
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            Compute::Not(right);
            return right;
        }
        antlrcpp::Any ConstExpVisitor::visitPluExp(BasicParser::PluExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            if(ctx->op->getText()=="+")
                Compute::add(left,right);
            else
                Compute::sub(left,right);
            return left;
        }
        antlrcpp::Any ConstExpVisitor::visitCmpExp(BasicParser::CmpExpContext *ctx)  {
            ExpRetValue left = visit(ctx->left).as<ExpRetValue>();
            ExpRetValue right = visit(ctx->right).as<ExpRetValue>();
            if(ctx->eqCmp()!=nullptr)Compute::EQ(left,right);
            else if(ctx->neCmp()!=nullptr)Compute::NE(left,right);
            else if(ctx->ltCmp()!=nullptr)Compute::LT(left,right);
            else if(ctx->gtCmp()!=nullptr)Compute::GT(left,right);
            else if(ctx->leCmp()!=nullptr)Compute::LE(left,right);
            else if(ctx->geCmp()!=nullptr)Compute::GE(left,right);
            return left;
        }


        antlrcpp::Any ConstExpVisitor::visitTerminateNodeExp(BasicParser::TerminateNodeExpContext *ctx)  {
            //TODO
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitInteger(BasicParser::IntegerContext *ctx)  {
            i32 value = std::stoi(ctx->getText());
            return ExpRetValue(value);
        }
        antlrcpp::Any ConstExpVisitor::visitDecimal(BasicParser::DecimalContext *ctx)  {
            f64 value = std::stod(ctx->getText());
            return ExpRetValue(value);
        }
        antlrcpp::Any ConstExpVisitor::visitString(BasicParser::StringContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitBoolean(BasicParser::BooleanContext *ctx)  {
            bool value = strToLower(ctx->getText())[0]=='t'?true:false;
            return ExpRetValue(value);
        }
        antlrcpp::Any ConstExpVisitor::visitFunctionCall(BasicParser::FunctionCallContext *ctx)  {
            return visitChildren(ctx);
        }

        antlrcpp::Any ConstExpVisitor::visitBucketExp(BasicParser::BucketExpContext *ctx)  {
            return visit(ctx->exp());
        }
        antlrcpp::Any ConstExpVisitor::visitTargetExp(BasicParser::TargetExpContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitMapExp(BasicParser::MapExpContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitArrayExp(BasicParser::ArrayExpContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitTupleExp(BasicParser::TupleExpContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitArrayOffset(BasicParser::ArrayOffsetContext *ctx)  {
            return visitChildren(ctx);
        }
        antlrcpp::Any ConstExpVisitor::visitLambda(BasicParser::LambdaContext *ctx) {
            return visitChildren(ctx);
        }
    }

    namespace ExpLLVMValueCast {
        ExpRetInfo ExpRetInfo::cast(LLVMValueKind dst,Unit* unit) {
            IRBuilder<>& builder=unit->builder;
            LLVMContext& context=unit->gen->getContext();
            switch (kind) {
                case bTy:
                    switch (dst) {
                        case i8Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i16Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt32Ty(context)),i32Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getFloatTy(context)),f32Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case i8Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt1Ty(context)),bTy);
                        case i16Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt32Ty(context)),i32Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateZExt(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getFloatTy(context)),f32Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case i16Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt1Ty(context)),bTy);
                        case i8Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateSExt(this->value,Type::getInt32Ty(context)),i32Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateSExt(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getFloatTy(context)),f32Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case i32Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt1Ty(context)),bTy);
                        case i8Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i16Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateSExt(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getFloatTy(context)),f32Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case i64Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt1Ty(context)),bTy);
                        case i8Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i16Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateTrunc(this->value,Type::getInt32Ty(context)),i32Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getFloatTy(context)),f32Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateCast(Instruction::UIToFP,this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case f32Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt1Ty(context)),bTy);
                        case i8Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i16Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt32Ty(context)),i32Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f64Ty: return ExpRetInfo(builder.CreateFPExt(this->value,Type::getDoubleTy(context)),f64Ty);
                    }
                case f64Ty:
                    switch (dst) {
                        case bTy: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt1Ty(context)),bTy);
                        case i8Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt8Ty(context)),i8Ty);
                        case i16Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt16Ty(context)),i16Ty);
                        case i32Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt32Ty(context)),i32Ty);
                        case i64Ty: return ExpRetInfo(builder.CreateFPToUI(this->value,Type::getInt64Ty(context)),i64Ty);
                        case f32Ty: return ExpRetInfo(builder.CreateFPTrunc(this->value,Type::getDoubleTy(context)),f32Ty);
                    }
            }
        }
    }
    antlrcpp::Any ExpVisitor::visitMulExp(BasicParser::MulExpContext *ctx){
        auto left = visit(ctx->left).as<Value*>();
        unit.builder.CreateCast(Instruction::CastOps::)
//        left->getType()->getTypeID()
//        auto right = visit(ctx->right).as<Value*>();
//        char op = ctx->op->getText()[0];
//        if(op=='*')builder.CreateMul(left,right);
//        else if(op=='/')
        unit.builder.
    }
    antlrcpp::Any ExpVisitor::visitNegExp(BasicParser::NegExpContext *ctx){

    }
    antlrcpp::Any ExpVisitor::visitRefExp(BasicParser::RefExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitPowModExp(BasicParser::PowModExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitLogicExp(BasicParser::LogicExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitBitExp(BasicParser::BitExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitLogicNotExp(BasicParser::LogicNotExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitPluExp(BasicParser::PluExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitCmpExp(BasicParser::CmpExpContext *ctx){}

    antlrcpp::Any ExpVisitor::visitInteger(BasicParser::IntegerContext *ctx){
//        i32 val = std::stoi(ctx->getText());
//        return ExpRetInfo(ConstantInt::get(Type::getInt32Ty(gen.getContext()),val,true),BuiltInKind::i32Ty);
    }
    antlrcpp::Any ExpVisitor::visitDecimal(BasicParser::DecimalContext *ctx){
//        f64 val = std::stod(ctx->getText());
//        return ExpRetInfo(ConstantFP::get(Type::getDoubleTy(gen.getContext()),val),BuiltInKind::f64Ty);
    }
    antlrcpp::Any ExpVisitor::visitString(BasicParser::StringContext *ctx){
        //TODO
    }
    antlrcpp::Any ExpVisitor::visitBoolean(BasicParser::BooleanContext *ctx){
//        bool val = strToLower(ctx->getText())[0]=='t'? 1 : 0;
//        return ExpRetInfo(ConstantInt::get(Type::getInt1Ty(gen.getContext()),val),BuiltInKind::bTy);
    }
    antlrcpp::Any ExpVisitor::visitFunctionCall(BasicParser::FunctionCallContext *ctx){}
    antlrcpp::Any ExpVisitor::visitBucketExp(BasicParser::BucketExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitTargetExp(BasicParser::TargetExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitMapExp(BasicParser::MapExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitArrayExp(BasicParser::ArrayExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitTupleExp(BasicParser::TupleExpContext *ctx){}
    antlrcpp::Any ExpVisitor::visitArrayOffset(BasicParser::ArrayOffsetContext *ctx){}
    antlrcpp::Any ExpVisitor::visitLambda(BasicParser::LambdaContext *ctx){}
}