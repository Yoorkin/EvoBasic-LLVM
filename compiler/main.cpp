#include<iostream>
#include"core/codeGen.h"
#include"JIT/JIT.h"
using namespace std;
using namespace classicBasic;

int main(int argc, const char* argv[]){
    CodeGenerator generator(cout,"main");
    auto mainUnit = generator.createUnitFromFile("./test.txt");
    //generator.createUnitFromIBL("../runtime/libINBasicRT.a");
    mainUnit->generate();
    std::error_code ec;
    llvm::raw_fd_ostream out("output.txt",ec);
    generator.printLLVMIR(llvm::outs());
}