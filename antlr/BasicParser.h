
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, Number = 23, String = 24, Boolean = 25, Comment = 26, 
    BlockComment = 27, WS = 28, ElseIf = 29, Wend = 30, From = 31, Import = 32, 
    Namespace = 33, Implement = 34, Type = 35, Alias = 36, Self = 37, Static = 38, 
    Module = 39, Public = 40, Private = 41, Protected = 42, Get = 43, Set = 44, 
    Property = 45, Var = 46, Dim = 47, Let = 48, Return = 49, Function = 50, 
    Difference = 51, Union = 52, Case = 53, Select = 54, End = 55, Until = 56, 
    Loop = 57, Exit = 58, While = 59, Do = 60, Each = 61, To = 62, Step = 63, 
    Next = 64, In = 65, For = 66, Optional = 67, Byval = 68, Byref = 69, 
    If = 70, Then = 71, Else = 72, Call = 73, Sub = 74, As = 75, ID = 76
  };

  enum {
    RuleStatements = 0, RuleStatement = 1, RuleExp = 2, RuleForStmt = 3, 
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
  class StatementContext;
  class ExpContext;
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementsContext* statements();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForStmtContext *forStmt();
    LoopStmtContext *loopStmt();
    IfStmtContext *ifStmt();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  ExpContext : public antlr4::ParserRuleContext {
  public:
    ExpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpContext() = default;
    void copyFrom(ExpContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PluOpContext : public ExpContext {
  public:
    PluOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberContext : public ExpContext {
  public:
    NumberContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *Number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CmpOpContext : public ExpContext {
  public:
    CmpOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BucketContext : public ExpContext {
  public:
    BucketContext(ExpContext *ctx);

    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  MulOpContext : public ExpContext {
  public:
    MulOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  PowModOpContext : public ExpContext {
  public:
    PowModOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegOpContext : public ExpContext {
  public:
    NegOpContext(ExpContext *ctx);

    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpContext {
  public:
    StringContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *String();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IDContext : public ExpContext {
  public:
    IDContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BooleanContext : public ExpContext {
  public:
    BooleanContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *Boolean();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BitOpContext : public ExpContext {
  public:
    BitOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicOpContext : public ExpContext {
  public:
    LogicOpContext(ExpContext *ctx);

    BasicParser::ExpContext *left = nullptr;
    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpContext* exp();
  ExpContext* exp(int precedence);
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
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


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LoopBodyContext* loopBody();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expSempred(ExpContext *_localctx, size_t predicateIndex);

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

