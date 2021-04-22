#include<iostream>
#include"codeGen.h"
using namespace std;


int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    CodeGenerator generator;
    auto mainUnit = generator.CreateUnit("main",stream,cout);
    mainUnit->generate();
    mainUnit->printIR();
}