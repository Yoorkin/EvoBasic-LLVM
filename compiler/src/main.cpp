#include<iostream>
#include"codeGen.h"
#include"JIT.h"
using namespace std;


int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    CodeGenerator generator;
    auto mainUnit = generator.CreateUnit("main",stream,cout);
    mainUnit->generate();
    mainUnit->printIR();
    JIT jit;
    jit.addUnit(mainUnit);
    auto f = jit.getFunctionAddress<int(int)>("functionCall");
    cout<<f(20)<<endl;
}