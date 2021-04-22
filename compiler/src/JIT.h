//
// Created by yorkin on 4/20/21.
//

#ifndef CLASSICBASIC_JIT_H
#define CLASSICBASIC_JIT_H
#include"codeGen.h"

#include<llvm/IR/DerivedTypes.h>
#include<llvm/IR/IRBuilder.h>
#include<llvm/IR/Function.h>
#include<llvm/IR/InstrTypes.h>
#include<llvm/IR/Instruction.h>
#include<llvm/IR/LLVMContext.h>
#include<llvm/IR/Module.h>
#include<llvm/IR/Verifier.h>
#include<llvm/Support/raw_ostream.h>
#include<llvm/Target/TargetMachine.h>

#include<llvm/ExecutionEngine/JITSymbol.h>
#include<llvm/ExecutionEngine/Orc/LLJIT.h>
#include<llvm/ExecutionEngine/Orc/CompileUtils.h>
#include<llvm/ExecutionEngine/Orc/Core.h>
#include<llvm/ExecutionEngine/Orc/JITTargetMachineBuilder.h>
#include<llvm/ExecutionEngine/Orc/ExecutionUtils.h>
#include<llvm/ExecutionEngine/Orc/IRCompileLayer.h>
#include<llvm/ExecutionEngine/Orc/RTDyldObjectLinkingLayer.h>
#include<llvm/ExecutionEngine/SectionMemoryManager.h>
#include<llvm/IR/DataLayout.h>
#include<llvm/ExecutionEngine/ExecutionEngine.h>
#include<llvm/IR/ValueSymbolTable.h>
#include<llvm/Support/DynamicLibrary.h>
#include <llvm/ExecutionEngine/GenericValue.h>
#include<llvm/ExecutionEngine/MCJIT.h>
#include <llvm/ExecutionEngine/Interpreter.h>
#include"codeGen.h"
using namespace std;
class JIT{
    ExecutionEngine* engine=nullptr;
public:
    JIT(){}
    void addUnit(GenerateUnit* unit){
        unique_ptr<llvm::Module> ptr(&unit->mod);
        if(engine==nullptr)
            engine=EngineBuilder(std::move(ptr)).create();
        else
            engine->addModule(std::move(ptr));
    }
    template<typename FunctionT>
    FunctionT* getFunctionAddress(string name){
        return (FunctionT*)engine->getFunctionAddress(strToLower(name));
    }
};
#endif //CLASSICBASIC_JIT_H
