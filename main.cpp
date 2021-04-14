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
    IRBuilder<> builder(context);
    Module mod("test",context);
//    auto s = StructType::create({Type::getInt32Ty(context),Type::getFloatTy(context)},"my_struct");
//    auto s2 = StructType::create({Type::getInt32Ty(context),Type::getFloatTy(context)},"my_struct2");
//    auto ft = FunctionType::get(Type::getVoidTy(context),false);
//    auto f = Function::Create(ft,GlobalValue::LinkageTypes::ExternalLinkage,"main",mod);
//    BasicBlock* b = BasicBlock::Create(context,"enasdfdftry",f);
//    builder.SetInsertPoint(b);
    //builders.CreateAlloca(s,ConstantInt::get(Type::getInt32Ty(context),4),"myInst");
//    builder.CreateAlloca(s2,ConstantInt::get(Type::getInt32Ty(context),4),"myInst2");
    Visitor visitor(mod,context);
    visitor.visit(tree);
    mod.print(llvm::outs(),nullptr,false);
}