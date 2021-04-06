#include<iostream>
#include<antlr4-runtime/antlr4-runtime.h>
#include"antlr/BasicLexer.h"
#include"antlr/BasicParser.h"
#include"antlr/BasicBaseListener.h"
#include"antlr/BasicListener.h"
using namespace std;
using namespace antlr4;
class Listener:public BasicListener{
    virtual void enterExp(BasicParser::ExpContext *ctx)override{
        
    }
    virtual void exitExp(BasicParser::ExpContext *ctx)override{
        
    }

    virtual void enterStatement(BasicParser::StatementContext *ctx)override{
        
    }
    virtual void exitStatement(BasicParser::StatementContext *ctx)override{
        
    }

    virtual void enterForStmt(BasicParser::ForStmtContext *ctx)override{
        
    }
    virtual void exitForStmt(BasicParser::ForStmtContext *ctx)override{
        cout<<ctx->exp(0)->getText()<<endl;
    }

    virtual void enterForeachStmt(BasicParser::ForeachStmtContext *ctx)override{
        
    }
    virtual void exitForeachStmt(BasicParser::ForeachStmtContext *ctx)override{
        
    }

    virtual void enterIfStmt(BasicParser::IfStmtContext *ctx)override{
        
    }
    virtual void exitIfStmt(BasicParser::IfStmtContext *ctx)override{
        
    }

    virtual void enterLoopStmt(BasicParser::LoopStmtContext *ctx)override{
        
    }
    virtual void exitLoopStmt(BasicParser::LoopStmtContext *ctx)override{
        
    }

    virtual void enterLoopBody(BasicParser::LoopBodyContext *ctx)override{
        
    }
    virtual void exitLoopBody(BasicParser::LoopBodyContext *ctx)override{
        
    }
    
    virtual void visitTerminal(antlr4::tree::TerminalNode *node)override{}
    virtual void visitErrorNode(antlr4::tree::ErrorNode *node)override{}
    virtual void enterEveryRule(ParserRuleContext *ctx)override{}
    virtual void exitEveryRule(ParserRuleContext *ctx)override{}
    virtual void enterStatements(BasicParser::StatementsContext *ctx)override{}
    virtual void exitStatements(BasicParser::StatementsContext *ctx)override{}
};

int main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open("./test.txt");
    ANTLRInputStream input(stream);
    BasicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    BasicParser parser(&tokens);

    tree::ParseTree *tree = parser.statement();
    Listener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
}