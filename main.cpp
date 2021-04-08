#include<iostream>
#include"visitor.h"
using namespace std;


int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    ANTLRInputStream input(stream);
    BasicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    BasicParser parser(&tokens);
    tree::ParseTree *tree = parser.moduleBody();

    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMContext context;
    Module mod("test",context);
    Visitor visitor(&mod,&context);
    visitor.visit(tree);
    mod.print(llvm::outs(),nullptr,false);
}