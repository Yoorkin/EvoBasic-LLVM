#include<iostream>
#include"codeGen.h"
#include"JIT.h"
using namespace std;
using namespace classicBasic;

int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    CodeGenerator generator;
    auto mainUnit = generator.CreateUnit("main",stream,cout);
    mainUnit->generate();
    mainUnit->printIR();
}