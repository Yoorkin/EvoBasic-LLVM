//
// Created by yorkin on 4/19/21.
//
#include<iostream>
#include<cassert>
#include<sstream>
#include"src/codeGen.h"
#include"src/JIT.h"
#include"testHelper.h"
using namespace std;

TestCase(getReturn100){
    string code;
    code = code+"function add()as integer\r\n"+
            "return 100\r\n"+
            "end function\r\n";
    stringstream stream(code);
    CodeGenerator generator;
    auto unit=generator.CreateUnit("test",stream,cout);
    unit->generate();
    unit->printIR();
    JIT jit;
    jit.addUnit(unit);
    auto func = jit.getFunctionAddress<int(void)>("add");
    return func()==100;
}

TestCase(passInteger){
    string code;
    code = code+"function pass(a as integer)as integer\n"+
            "return a\n end function\n";
    stringstream stream(code);
    CodeGenerator generator;
    auto unit=generator.CreateUnit("test",stream,cout);
    unit->generate();
    unit->printIR();
    JIT jit;
    jit.addUnit(unit);
    auto func =jit.getFunctionAddress<int(int)>("pass");
    return func(200)==200;
}

int main(){
    Begin;
    Test(getReturn100);
    Test(passInteger);
    Report;
}