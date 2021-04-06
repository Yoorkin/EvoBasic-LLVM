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
        cout<<23333<<endl;
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
}
void main(int argc, const char* argv[]){
    std::ifstream stream;
    stream.open(argv[1]);
    ANTLRInputStream input(stream);
    BasicLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    BasicParser parser(&tokens);

    tree::ParseTree *tree = parser.key();
    TreeShapeListener listener;
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);
}