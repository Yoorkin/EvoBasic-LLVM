#ifndef CB_VISITOR
#define CB_VISITOR

#include"errorListener.h"

#include<map>
#include<string>
#include<stack>
#include<list>
#include<iostream>

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

namespace classicBasic{
    using namespace llvm;
    using namespace std;
    using namespace antlr4;

    class CodeGenVisitor;
    class TypeTable;
    class CodeGenerator;
    class JIT;

    class CodeGenVisitor: public BasicBaseVisitor{
        SourceUnit& unit;
        CodeGenerator& gen;
    public:

        CodeGenVisitor(SourceUnit* unit);
        virtual antlrcpp::Any visitClassDecl(BasicParser::ClassDeclContext *ctx) override;
        virtual antlrcpp::Any visitModuleDecl(BasicParser::ModuleDeclContext *ctx) override;

        virtual antlrcpp::Any visitVarDecl(BasicParser::VarDeclContext *ctx) override;

        virtual antlrcpp::Any visitTypeLocation(BasicParser::TypeLocationContext *ctx) override;

        virtual antlrcpp::Any visitAssignStmt(BasicParser::AssignStmtContext *ctx) override;
        virtual antlrcpp::Any visitExitStmt(BasicParser::ExitStmtContext *ctx) override;
        virtual antlrcpp::Any visitReturnStmt(BasicParser::ReturnStmtContext *ctx) override;
        virtual antlrcpp::Any visitConstExp(BasicParser::ConstExpContext *ctx) override;
        virtual antlrcpp::Any visitForeachStmt(BasicParser::ForeachStmtContext *ctx) override;
        virtual antlrcpp::Any visitForStmt(BasicParser::ForStmtContext *ctx) override;
        virtual antlrcpp::Any visitSingleLineIf(BasicParser::SingleLineIfContext *ctx) override;
        virtual antlrcpp::Any visitMutiLineIf(BasicParser::MutiLineIfContext *ctx) override;
        virtual antlrcpp::Any visitIfBlock(BasicParser::IfBlockContext *ctx) override;
        virtual antlrcpp::Any visitDoWhile(BasicParser::DoWhileContext *ctx) override;
        virtual antlrcpp::Any visitDoUntil(BasicParser::DoUntilContext *ctx) override;
        virtual antlrcpp::Any visitLoopUntil(BasicParser::LoopUntilContext *ctx) override;
        virtual antlrcpp::Any visitLoopWhile(BasicParser::LoopWhileContext *ctx) override;
    };
}

#endif