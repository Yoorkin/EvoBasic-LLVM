
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, Number = 24, String = 25, Boolean = 26, 
    Comment = 27, BlockComment = 28, LineEnd = 29, WS = 30, If = 31, ElseIf = 32, 
    Wend = 33, From = 34, Import = 35, Namespace = 36, Implement = 37, Type = 38, 
    Alias = 39, Self = 40, Static = 41, Module = 42, Public = 43, Private = 44, 
    Protected = 45, Get = 46, Set = 47, Property = 48, Var = 49, Dim = 50, 
    Let = 51, Return = 52, Function = 53, Difference = 54, Union = 55, Case = 56, 
    Select = 57, End = 58, Until = 59, Loop = 60, Exit = 61, While = 62, 
    Do = 63, Each = 64, To = 65, Step = 66, Next = 67, In = 68, For = 69, 
    Optional = 70, Byval = 71, Byref = 72, Then = 73, Else = 74, Call = 75, 
    Sub = 76, As = 77, ID = 78
  };

  enum {
    RuleModuleBody = 0, RuleDeclare = 1, RuleVarDecl = 2, RuleVariable = 3, 
    RuleFunctionDecl = 4, RuleSubDecl = 5, RuleStatement = 6, RuleExp = 7, 
    RuleForStmt = 8, RuleForeachStmt = 9, RuleIfStmt = 10, RuleIfBlock = 11, 
    RuleLoopStmt = 12
  };

  explicit BasicParser(antlr4::TokenStream *input);
  ~BasicParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ModuleBodyContext;
  class DeclareContext;
  class VarDeclContext;
  class VariableContext;
  class FunctionDeclContext;
  class SubDeclContext;
  class StatementContext;
  class ExpContext;
  class ForStmtContext;
  class ForeachStmtContext;
  class IfStmtContext;
  class IfBlockContext;
  class LoopStmtContext; 

  class  ModuleBodyContext : public antlr4::ParserRuleContext {
  public:
    ModuleBodyContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<DeclareContext *> declare();
    DeclareContext* declare(size_t i);
    std::vector<antlr4::tree::TerminalNode *> LineEnd();
    antlr4::tree::TerminalNode* LineEnd(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModuleBodyContext* moduleBody();

  class  DeclareContext : public antlr4::ParserRuleContext {
  public:
    DeclareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionDeclContext *functionDecl();
    SubDeclContext *subDecl();
    VarDeclContext *varDecl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareContext* declare();

  class  VarDeclContext : public antlr4::ParserRuleContext {
  public:
    VarDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Dim();
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarDeclContext* varDecl();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *type = nullptr;
    BasicParser::ExpContext *initial = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *As();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *returnType = nullptr;
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Function();
    antlr4::tree::TerminalNode* Function(size_t i);
    antlr4::tree::TerminalNode *As();
    antlr4::tree::TerminalNode *End();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  SubDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    SubDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Sub();
    antlr4::tree::TerminalNode* Sub(size_t i);
    antlr4::tree::TerminalNode *End();
    antlr4::tree::TerminalNode *ID();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubDeclContext* subDecl();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *exitFlag = nullptr;
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForStmtContext *forStmt();
    LoopStmtContext *loopStmt();
    IfStmtContext *ifStmt();
    antlr4::tree::TerminalNode *LineEnd();
    antlr4::tree::TerminalNode *Exit();
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *Function();


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

  class  LogicNotOpContext : public ExpContext {
  public:
    LogicNotOpContext(ExpContext *ctx);

    BasicParser::ExpContext *right = nullptr;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegOpContext : public ExpContext {
  public:
    NegOpContext(ExpContext *ctx);

    antlr4::Token *op = nullptr;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpContext {
  public:
    StringContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *String();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NumberContext : public ExpContext {
  public:
    NumberContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *Number();

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
    BasicParser::ExpContext *iterator = nullptr;
    BasicParser::ExpContext *begin = nullptr;
    BasicParser::ExpContext *end = nullptr;
    BasicParser::ExpContext *step = nullptr;
    BasicParser::ExpContext *nextFlag = nullptr;
    ForStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *To();
    antlr4::tree::TerminalNode *Step();
    antlr4::tree::TerminalNode *Next();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStmtContext* forStmt();

  class  ForeachStmtContext : public antlr4::ParserRuleContext {
  public:
    BasicParser::ExpContext *iterator = nullptr;
    BasicParser::ExpContext *group = nullptr;
    BasicParser::ExpContext *nextFlag = nullptr;
    ForeachStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *Each();
    antlr4::tree::TerminalNode *In();
    antlr4::tree::TerminalNode *Next();
    std::vector<ExpContext *> exp();
    ExpContext* exp(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForeachStmtContext* foreachStmt();

  class  IfStmtContext : public antlr4::ParserRuleContext {
  public:
    IfStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    IfStmtContext() = default;
    void copyFrom(IfStmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  MutiLineIfContext : public IfStmtContext {
  public:
    MutiLineIfContext(IfStmtContext *ctx);

    BasicParser::IfBlockContext *firstBlock = nullptr;
    BasicParser::IfBlockContext *elseifBlock = nullptr;
    BasicParser::StatementContext *elseBlock = nullptr;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    antlr4::tree::TerminalNode *End();
    std::vector<IfBlockContext *> ifBlock();
    IfBlockContext* ifBlock(size_t i);
    std::vector<antlr4::tree::TerminalNode *> ElseIf();
    antlr4::tree::TerminalNode* ElseIf(size_t i);
    antlr4::tree::TerminalNode *Else();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SingleLineIfContext : public IfStmtContext {
  public:
    SingleLineIfContext(IfStmtContext *ctx);

    BasicParser::ExpContext *condition = nullptr;
    BasicParser::StatementContext *elsestatement = nullptr;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *Then();
    antlr4::tree::TerminalNode *LineEnd();
    ExpContext *exp();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *Else();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IfStmtContext* ifStmt();

  class  IfBlockContext : public antlr4::ParserRuleContext {
  public:
    BasicParser::ExpContext *condition = nullptr;
    IfBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Then();
    ExpContext *exp();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfBlockContext* ifBlock();

  class  LoopStmtContext : public antlr4::ParserRuleContext {
  public:
    LoopStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    LoopStmtContext() = default;
    void copyFrom(LoopStmtContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DoUntilContext : public LoopStmtContext {
  public:
    DoUntilContext(LoopStmtContext *ctx);

    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Until();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Loop();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  WhileWendContext : public LoopStmtContext {
  public:
    WhileWendContext(LoopStmtContext *ctx);

    antlr4::tree::TerminalNode *While();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Wend();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DoWhileContext : public LoopStmtContext {
  public:
    DoWhileContext(LoopStmtContext *ctx);

    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *While();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Loop();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LoopUntilContext : public LoopStmtContext {
  public:
    LoopUntilContext(LoopStmtContext *ctx);

    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Loop();
    antlr4::tree::TerminalNode *Until();
    ExpContext *exp();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LoopWhileContext : public LoopStmtContext {
  public:
    LoopWhileContext(LoopStmtContext *ctx);

    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Loop();
    antlr4::tree::TerminalNode *While();
    ExpContext *exp();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  LoopStmtContext* loopStmt();


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

