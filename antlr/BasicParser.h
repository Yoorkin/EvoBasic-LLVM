
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicParser : public antlr4::Parser {
public:
  enum {
    Number = 1, Comment = 2, BlockComment = 3, WS = 4, ElseIf = 5, Wend = 6, 
    From = 7, Import = 8, Namespace = 9, Implement = 10, Type = 11, Alias = 12, 
    Self = 13, Static = 14, Module = 15, Public = 16, Private = 17, Protected = 18, 
    Get = 19, Set = 20, Property = 21, Var = 22, Dim = 23, Let = 24, Return = 25, 
    Function = 26, Difference = 27, Union = 28, Case = 29, Select = 30, 
    End = 31, Until = 32, Loop = 33, Exit = 34, While = 35, Do = 36, Each = 37, 
    To = 38, Step = 39, Next = 40, In = 41, For = 42, Optional = 43, Byval = 44, 
    Byref = 45, If = 46, Then = 47, Else = 48, Call = 49, Sub = 50, As = 51
  };

  enum {
    RuleStatements = 0, RuleExp = 1, RuleStatement = 2, RuleForStmt = 3, 
    RuleForeachStmt = 4, RuleIfStmt = 5, RuleLoopStmt = 6, RuleLoopBody = 7
  };

  explicit BasicParser(antlr4::TokenStream *input);
  ~BasicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class StatementsContext;
  class ExpContext;
  class StatementContext;
  class ForStmtContext;
  class ForeachStmtContext;
  class IfStmtContext;
  class LoopStmtContext;
  class LoopBodyContext; 

  class  StatementsContext : public antlr4::ParserRuleContext {
  public:
    StatementsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementsContext* statements();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Number();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ExpContext* exp();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForStmtContext *forStmt();
    LoopStmtContext *loopStmt();
    IfStmtContext *ifStmt();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  StatementContext* statement();

  class  ForStmtContext : public antlr4::ParserRuleContext {
  public:
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> For();
    antlr4::tree::TerminalNode* For(size_t i);
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *To();
    antlr4::tree::TerminalNode *Step();
    antlr4::tree::TerminalNode *Next();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Exit();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForStmtContext* forStmt();

  class  ForeachStmtContext : public antlr4::ParserRuleContext {
  public:
    ForeachStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> For();
    antlr4::tree::TerminalNode* For(size_t i);
    antlr4::tree::TerminalNode *Each();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    antlr4::tree::TerminalNode *Step();
    antlr4::tree::TerminalNode *In();
    antlr4::tree::TerminalNode *Next();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Exit();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  ForeachStmtContext* foreachStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<antlr4::tree::TerminalNode *> Then();
    antlr4::tree::TerminalNode* Then(size_t i);
    antlr4::tree::TerminalNode *End();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ElseIf();
    antlr4::tree::TerminalNode* ElseIf(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  IfStmtContext* ifStmt();

  class  LoopStmtContext : public antlr4::ParserRuleContext {
  public:
    LoopStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *While();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Loop();
    LoopBodyContext *loopBody();
    antlr4::tree::TerminalNode *Until();
    antlr4::tree::TerminalNode *Wend();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LoopStmtContext* loopStmt();

  class  LoopBodyContext : public antlr4::ParserRuleContext {
  public:
    LoopBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Exit();
    antlr4::tree::TerminalNode *Do();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;
   
  };

  LoopBodyContext* loopBody();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

