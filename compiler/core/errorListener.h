//
// Created by yorkin on 4/15/21.
//

#ifndef CLASSICBASIC_ERRORLISTENER_H
#define CLASSICBASIC_ERRORLISTENER_H
#include<antlr4-runtime/antlr4-runtime.h>
#include<antlr4-runtime/BaseErrorListener.h>
#include<ostream>
#include<map>
#include<string>
using namespace antlr4;
using namespace std;
class Reporter{
public:
    enum Error{};
private:
    ostream& out;
    vector<string> code;
    map<Error,string> errorTable={};
    const string RedBegin = "\033[31m";
    const string YellowBegin = "\033[33m";
    const string ColorEnd = "\033[0m";
    string path;
    bool first=true;
    Token* handling=nullptr;
public:

    Reporter(ostream& out,istream& in,string filePath):out(out),path(filePath){
        string line;
        while(getline(in,line)){
            code.push_back(line);
        }
        in.clear();
        in.seekg(ios::beg);
    }

    void warning(int row,int column,int span,string msg){
        if(span==0)span=1;
        if(first){
            out<<endl;
            out<<YellowBegin<<"In file "<<path<<":"<<ColorEnd<<endl;
            first=false;
        }
        out<<"│";
        out<<"warning in line "<<row<<','<<column<<":"<<msg<<ColorEnd<<endl;
        out<<YellowBegin<<"│"<<ColorEnd;
        out<<"  "<<code[row-1]<<endl;
        out<<YellowBegin<<"│"<<ColorEnd;
        for(int i=0;i<column;i++)out<<' ';
        cout<<"  ^";
        for(int i=1;i<span;i++)out<<'~';
        out<<endl;
    }
    void report(int row,int column,int span,string error){
        if(span==0)span=1;
        if(first){
            out<<endl;
            out<<YellowBegin<<"In file "<<path<<":"<<ColorEnd<<endl;
            first=false;
        }
        out<<YellowBegin<<"│"<<ColorEnd;
        out<<RedBegin<<" line "<<row<<','<<column<<":"<<error<<ColorEnd<<endl;
        out<<YellowBegin<<"│"<<ColorEnd;
        out<<"  "<<code[row-1]<<endl;
        out<<YellowBegin<<"│"<<ColorEnd;
        for(int i=0;i<column;i++)out<<' ';
        cout<<RedBegin<<"  ^";
        for(int i=1;i<span;i++)out<<'~';
        out<<ColorEnd<<endl;
    }
    void report(int row,int column,int span,Error error){
        report(row,column,span,errorTable[error]);
    }
    void report(Token* token,string error){
        report(token->getLine(),token->getCharPositionInLine(),token->getText().length(),error);
    }
    void warning(Token* token,string msg){
        warning(token->getLine(),token->getCharPositionInLine(),token->getText().length(),msg);
    }
    void report(string error){
        if(handling==nullptr)throw "error";
        report(handling,error);
        handling=nullptr;
    }
    void warning(string msg){
        if(handling==nullptr)throw "error";
        warning(handling,msg);
        handling=nullptr;
    }
    static Reporter* singleton;
};



class BasicErrorListener:public BaseErrorListener{
public:
    virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
                             const std::string &msg, std::exception_ptr e) override{
        Reporter::singleton->report(offendingSymbol,msg);
    }
};


#endif //CLASSICBASIC_ERRORLISTENER_H
