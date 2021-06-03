//
// Created by yorkin on 4/16/21.
//

#include"codeGen.h"

namespace classicBasic{
    using namespace structure;
    CodeGenVisitor::CodeGenVisitor(SourceUnit *unit):unit(*unit),gen(*(unit->gen)){

    }

    antlrcpp::Any CodeGenVisitor::visitClassDecl(BasicParser::ClassDeclContext *ctx){
        auto classScope = (Scope*)unit.scope->lookUp(strToLower(ctx->name->getText()));
        unit.scope=classScope;
        visitChildren(ctx);
        unit.scope=unit.scope->getParent();
    }
    antlrcpp::Any CodeGenVisitor::visitModuleDecl(BasicParser::ModuleDeclContext *ctx){
        auto classScope = (Scope*)unit.scope->lookUp(strToLower(ctx->name->getText()));
        unit.scope=classScope;
        visitChildren(ctx);
        unit.scope=unit.scope->getParent();
    }
    
    antlrcpp::Any CodeGenVisitor::visitVarDecl(BasicParser::VarDeclContext *ctx){

        return visitChildren(ctx);
    }
    
    antlrcpp::Any CodeGenVisitor::visitTypeLocation(BasicParser::TypeLocationContext *ctx){
        vector<string> path;
        for(auto p:ctx->path){
            cout<<p->getText()<<endl;
            path.push_back(strToLower(p->getText()));
        }
        path.push_back(strToLower(ctx->target->getText()));
        cout<<ctx->target->getText()<<endl;
        structure::Info* info = unit.scope->lookUp(path);
        return info;
    }
    
    antlrcpp::Any CodeGenVisitor::visitAssignStmt(BasicParser::AssignStmtContext *ctx){
        return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitExitStmt(BasicParser::ExitStmtContext *ctx){
        return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitReturnStmt(BasicParser::ReturnStmtContext *ctx){

    }
    antlrcpp::Any CodeGenVisitor::visitConstExp(BasicParser::ConstExpContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitForeachStmt(BasicParser::ForeachStmtContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitForStmt(BasicParser::ForStmtContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitSingleLineIf(BasicParser::SingleLineIfContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitMutiLineIf(BasicParser::MutiLineIfContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitIfBlock(BasicParser::IfBlockContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitDoWhile(BasicParser::DoWhileContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitDoUntil(BasicParser::DoUntilContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitLoopUntil(BasicParser::LoopUntilContext *ctx){
    return visitChildren(ctx);
    }
    antlrcpp::Any CodeGenVisitor::visitLoopWhile(BasicParser::LoopWhileContext *ctx){
    return visitChildren(ctx);
    }

}
