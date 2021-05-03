//
// Created by yorkin on 4/19/21.
//
#include<iostream>
#include<cassert>
#include<sstream>
#include"src/codeGen.h"
#include"src/JIT.h"
#include"testHelper.h"
using namespace classicBasic;
using namespace std;

TestCase(getReturn100){
    string code;
    code = code+"function add()as integer\r\n"+
            "return 100\r\n"+
            "end function\r\n";
    ConfigureModule("getReturn100",code);
    auto func = jit.getFunctionAddress<int(void)>("add");
    return func()==100;
}

TestCase(passInteger){
    string code;
    code = code+"function pass(a as integer)as integer\n"+
            "return a\n end function\n";
    ConfigureModule("passInteger",code);
    auto func =jit.getFunctionAddress<int(int)>("pass");
    return func(200)==200 && func(1+20)==21;
}

TestCase(passBool){
    string code;
    code = code+"function passBool(a as Boolean)as Boolean\n"+
           "return a\n end function\n";
    ConfigureModule("passBool",code);
    auto func =jit.getFunctionAddress<bool(bool)>("passBool");
    return func(true)==true && func(false)==false;
}

TestCase(plus10){
    string code;
    code=code+"function plus10(a as Integer)as Integer\n"+
            "return a+10\n"+
            "end function\n";
    ConfigureModule("plus10",code);
    auto add=jit.getFunctionAddress<int(int)>("plus10");
    return add(-20)==-10 && add(99)==109;
}

TestCase(variableAssignReturn){
    string code=R"code(
        function assignReturn(a as integer)as integer
            dim b as long=a
            return b
        end function
    )code";
    ConfigureModule("variableAssignReturn",code);
    auto func=jit.getFunctionAddress<int(int)>("assignReturn");
    return func(100)==100 && func(-100)==-100;
}

TestCase(forLoop){
    string code=R"code(
    function forLoop(i as integer)as integer
        dim a as integer
        for a=0 to 9 step 2
            i=i+1
        next
        return i
    end function

    )code";
    ConfigureModule("forLoop",code);
    auto func=jit.getFunctionAddress<int(int)>("forLoop");
    return func(5)==10;
}

TestCase(returnBigger) {
    string code=R"code(
    function returnBigger(a as integer,b as integer)as integer
        dim c as integer
        if a>b then
            return a
        else
            return b
        end if
        return c
    end function
    )code";
    ConfigureModule("returnBigger", code);
    auto func = jit.getFunctionAddress<int(int, int)>("returnbigger");
    return func(10, 0) == 10 && func(100, 99999) == 99999;
}

TestCase(functionCall){
    string code = R"code(
    function add()as integer
        return 10
    end function

    function functionCall(x as integer)as integer
        dim a as integer
        return x+add
    end function
    )code";
    ConfigureModule("functionCall",code);
    auto f=jit.getFunctionAddress<int(int)>("functionCall");
    return f(20)==30;
}

TestCase(subCall){
    string code = R"code(
    sub subCall()

    end sub
    )code";
    ConfigureModule("subCall",code);
    auto f=jit.getFunctionAddress<void()>("subCall");
    f();
    return true;
}

TestCase(singleIF){
    string code = R"code(
    function isNeg(x as integer)as Boolean
        If x<0 then
            return true
        End If
        return false
    end function
    )code";
    ConfigureModule("isNeg",code);
    auto f=jit.getFunctionAddress<bool(int)>("isNeg");
    return f(0)==false && f(-10)==true && f(4)==false;
}

TestCase(mutiIF){
    string code = R"code(
    function mutiIF(x as integer)as integer
        If x=0 then
            return 1
        elseIf x=1 then
            return 2
            return 114514
        else
            return 0
        End If
    end function
    )code";
    ConfigureModule("mutiIF",code);
    auto f=jit.getFunctionAddress<int(int)>("mutiIF");
    return f(0)==1 && f(1)==2 && f(4)==0;
}

TestCase(Fibonacci){
    string code = R"code(
    function Fibonacci(x as integer)as integer
        If x=0 then
            return 0
        elseIf x=1 then
            return 1
        else
            return Fibonacci(x-1)+Fibonacci(x-2)
        End If
        return -1
    end function
    )code";
    ConfigureModule("Fibonacci",code);
    auto f=jit.getFunctionAddress<int(int)>("Fibonacci");
    return f(0)==0 && f(1)==1 && f(4)==3;
}

TestCase(nonReturn){
    string code = R"code(
    function nonReturn(x as integer)as integer

    end function
    )code";
    ConfigureModule("Fibonacci",code);
    auto f=jit.getFunctionAddress<int(int)>("nonReturn");
    return f(10)==0;
}

TestCase(whileLoop){
    string code = R"code(
    function whileLoop(x as integer)as integer
        while x<100
            x=x+1
        loop
        return x
    end function
    )code";
    ConfigureModule("whileLoop",code);
    auto f=jit.getFunctionAddress<int(int)>("whileLoop");
    return f(10)==100 && f(-100)==100;
}

TestCase(doWhileLoop){
    string code = R"code(
    function doWhileLoop(x as integer)as integer
        do while x<100
            x=x+1
        loop
        return x
    end function
    )code";
    ConfigureModule("doWhileLoop",code);
    auto f=jit.getFunctionAddress<int(int)>("doWhileLoop");
    return f(10)==100 && f(-100)==100;
}

TestCase(doUntilLoop){
    string code = R"code(
    function doUntilLoop(x as integer)as integer
        do until x=100
            x=x+1
        loop
        return x
    end function
    )code";
    ConfigureModule("doUntilLoop",code);
    auto f=jit.getFunctionAddress<int(int)>("doUntilLoop");
    return f(10)==100 && f(-100)==100;
}

TestCase(doLoopUntil){
    string code = R"code(
    function doLoopUntil(x as integer)as integer
        do
            x=x+1
        loop until x=100
        return x
    end function
    )code";
    ConfigureModule("doLoopUntil",code);
    auto f=jit.getFunctionAddress<int(int)>("doLoopUntil");
    return f(10)==100 && f(-100)==100;
}

TestCase(doLoopWhile){
    string code = R"code(
    function doLoopWhile(x as integer)as integer
        do
            x=x+1
        loop while x<100
        return x
    end function
    )code";
    ConfigureModule("doLoopWhile",code);
    auto f=jit.getFunctionAddress<int(int)>("doLoopWhile");
    return f(10)==100 && f(-100)==100;
}


TestCase(doLoopUntilRunOnce){
    string code = R"code(
    function doLoopUntilRunOnce(x as integer)as integer
        do
            x=50
        loop until true
        return x
    end function
    )code";
    ConfigureModule("doLoopUntilRunOnce",code);
    auto f=jit.getFunctionAddress<int(int)>("doLoopUntilRunOnce");
    return f(10)==50 && f(-100)==50;
}

TestCase(doLoopWhileRunOnce){
    string code = R"code(
    function doLoopWhileRunOnce(x as integer)as integer
        do
            x=50
        loop while false
        return x
    end function
    )code";
    ConfigureModule("doLoopWhileRunOnce",code);
    auto f=jit.getFunctionAddress<int(int)>("doLoopWhileRunOnce");
    return f(10)==50 && f(-100)==50;
}



int main(){
    Begin;
    Test(getReturn100);
    Test(passInteger);
    Test(passBool);
    Test(plus10);
    Test(variableAssignReturn);
    Test(forLoop);
    Test(returnBigger);
    Test(functionCall);
    Test(subCall);
    Test(singleIF);
    Test(mutiIF);
    Test(nonReturn);
    Test(doWhileLoop);
    Test(doUntilLoop);
    Test(doLoopWhile);
    Test(doLoopUntil);
    Test(doLoopUntilRunOnce);
    Test(doLoopWhileRunOnce);
    Report("BasicStmtTest");
}