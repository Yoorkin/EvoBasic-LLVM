//
// Created by yorkin on 4/27/21.
//

#ifndef CLASSICBASIC_STRUCTUREGEN_H
#define CLASSICBASIC_STRUCTUREGEN_H

#include"errorListener.h"

#include<map>
#include<string>
#include<stack>
#include<list>
#include<iostream>
#include<set>
#include<antlr4-runtime/antlr4-runtime.h>
#include"../antlr/BasicLexer.h"
#include"../antlr/BasicParser.h"
#include"../antlr/BasicBaseVisitor.h"

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

#include"genUtility.h"

namespace classicBasic {
    using namespace llvm;
    using namespace std;
    using namespace antlr4;

    namespace structure{
        class Scope;
    }

    class StructureVisitor : public BasicBaseVisitor {
        LLVMContext& context;
        llvm::Module& mod;
        Reporter& reporter;
        structure::Scope* scope;
        CodeGenerator& gen;
    public:
        StructureVisitor(GenerateUnit& unit,structure::Scope* scope);

        virtual antlrcpp::Any visitFunctionDecl(BasicParser::FunctionDeclContext *ctx) override;
        virtual antlrcpp::Any visitSubDecl(BasicParser::SubDeclContext *ctx) override;

        virtual antlrcpp::Any visitExternalFunction(BasicParser::ExternalFunctionContext *ctx) override;
        virtual antlrcpp::Any visitExternalSub(BasicParser::ExternalSubContext *ctx) override;

        virtual antlrcpp::Any visitPropertyGet(BasicParser::PropertyGetContext *ctx) override;
        virtual antlrcpp::Any visitPropertySet(BasicParser::PropertySetContext *ctx) override;
        virtual antlrcpp::Any visitPropertyLet(BasicParser::PropertyLetContext *ctx) override;

        virtual antlrcpp::Any visitEnumDecl(BasicParser::EnumDeclContext *ctx) override;

        struct NameTypePairTmp{
            bool isArray;
            int lbound,ubound;
            string name;
            Type* type;
        };

        virtual antlrcpp::Any visitTypeDecl(BasicParser::TypeDeclContext *ctx) override;

        virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override;
        virtual antlrcpp::Any visitVariable(BasicParser::VariableContext *ctx) override;

        virtual antlrcpp::Any visitNormalNameTypePair(BasicParser::NormalNameTypePairContext *ctx) override;
        virtual antlrcpp::Any visitArrayNameTypePair(BasicParser::ArrayNameTypePairContext *ctx) override;

        virtual antlrcpp::Any visitParameterList(BasicParser::ParameterListContext *ctx) override;
        virtual antlrcpp::Any visitNecessaryParameter(BasicParser::NecessaryParameterContext *ctx) override;
        virtual antlrcpp::Any visitOptionalParameter(BasicParser::OptionalParameterContext *ctx) override;
        virtual antlrcpp::Any visitParamArrayParameter(BasicParser::ParamArrayParameterContext *ctx) override;

    };
}
#endif //CLASSICBASIC_STRUCTUREGEN_H
