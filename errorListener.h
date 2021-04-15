//
// Created by yorkin on 4/15/21.
//

#ifndef CLASSICBASIC_ERRORLISTENER_H
#define CLASSICBASIC_ERRORLISTENER_H
#include<antlr4-runtime.h>
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
public:

    Reporter(ostream& out,istream& in,string filePath):out(out),path(filePath){
        string line;
        while(getline(in,line)){
            code.push_back(line);
        }
        in.clear();
        in.seekg(ios::beg);
    }

    void report(int row,int column,string error){
        if(first){
            out<<endl;
            out<<YellowBegin<<"In file "<<path<<":"<<ColorEnd<<endl;
            first=false;
        }
        out<<YellowBegin<<"│"<<ColorEnd;
        out<<RedBegin<<" line "<<row<<','<<column<<":"<<error<<ColorEnd<<endl;
        out<<YellowBegin<<"│"<<ColorEnd;
        out<<"  "<<code[row-1]<<endl;
        out<<YellowBegin<<"│\t"<<ColorEnd;
        for(int i=0;i<column;i++)out<<' ';
        cout<<"  "<<RedBegin;
        for(int i=0;i<4;i++)out<<'^';
        out<<ColorEnd<<endl;
    }
    void report(int row,int column,Error error){
        report(row,column,errorTable[error]);
    }
};

class BasicErrorListener:public BaseErrorListener{
    Reporter reporter;
public:
    BasicErrorListener(Reporter reporter):reporter(reporter){}
    virtual void syntaxError(Recognizer *recognizer, Token * offendingSymbol, size_t line, size_t charPositionInLine,
                             const std::string &msg, std::exception_ptr e) override{
        reporter.report(line,charPositionInLine,msg);
    }
};


#endif //CLASSICBASIC_ERRORLISTENER_H
