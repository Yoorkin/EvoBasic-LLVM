//
// Created by yorkin on 4/20/21.
//

#ifndef CLASSICBASIC_JIT_H
#define CLASSICBASIC_JIT_H

#include "llvm/ExecutionEngine/ExecutionEngine.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/MCJIT.h"

#include"genUtility.h"
namespace classicBasic{
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
}

#endif //CLASSICBASIC_JIT_H
