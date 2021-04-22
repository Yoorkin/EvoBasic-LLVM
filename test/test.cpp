//
// Created by yorkin on 4/19/21.
//
#include<iostream>
#include<cassert>
#include<sstream>
#include"src/codeGen.h"
#include"src/JIT.h"
using namespace std;
//
//void confgure(){
//    std::ifstream stream;
//    stream.open("./test.txt");
//    CodeGenerator generator;
//    auto mainUnit = generator.CreateUnit("main",stream,cout);
//    mainUnit->generate();
//    JIT jit;
//    jit.addUnit(mainUnit);
//    int(*ptr)(void) = jit.getFunctionAddress<int()>("add");
//}


bool test(){
    string code;
    code = code+"function add()as integer\r\n"+
            "return 100\r\n"+
            "end function\r\n";
    stringstream stream(code);
    CodeGenerator generator;
    auto mainUnit = generator.CreateUnit("main",stream,cout);
    auto unit=generator.CreateUnit("test",stream,cout);
    unit->generate();
    unit->printIR();
    JIT jit;
    jit.addUnit(unit);
    auto func = jit.getFunctionAddress<int(void)>("add");
    assert(func()==100);
}

int main(){

    test();
}