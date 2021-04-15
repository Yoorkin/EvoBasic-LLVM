#include<iostream>
#include"visitor.h"
#include"errorListener.h"
using namespace std;

int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    Reporter reporter(cout,stream,"./test.txt");
    BasicErrorListener errorListener(reporter);

    ANTLRInputStream input(stream);
    BasicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    BasicParser parser(&tokens);
    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);
    tree::ParseTree *tree = parser.moduleBody();
    LLVMInitializeNativeTarget();
    LLVMInitializeNativeAsmPrinter();
    LLVMContext context;
    IRBuilder<> builder(context);
    Module mod("test",context);
    Visitor visitor(mod,context);
    visitor.visit(tree);
    mod.print(llvm::outs(),nullptr,false);
}