#include<iostream>
#include"core/codeGen.h"
#include"JIT/JIT.h"
using namespace std;
using namespace classicBasic;

int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    CodeGenerator generator(cout,"JIT");
    auto mainUnit = generator.createUnitFromFile("./test.txt");
    mainUnit->generate();
    generator.printLLVMIR();
}