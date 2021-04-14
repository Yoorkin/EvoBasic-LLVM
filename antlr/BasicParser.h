
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, Integer = 26, 
    Decimal = 27, String = 28, Boolean = 29, Comment = 30, BlockComment = 31, 
    LineEnd = 32, WS = 33, If = 34, ElseIf = 35, Wend = 36, From = 37, Import = 38, 
    Namespace = 39, Implement = 40, Type = 41, Alias = 42, Self = 43, Static = 44, 
    Module = 45, Public = 46, Private = 47, Protected = 48, Get = 49, Set = 50, 
    Property = 51, Var = 52, Dim = 53, Let = 54, Return = 55, Function = 56, 
    Difference = 57, Union = 58, Case = 59, Select = 60, End = 61, Until = 62, 
    Loop = 63, Exit = 64, While = 65, Do = 66, Each = 67, To = 68, Step = 69, 
    Next = 70, In = 71, For = 72, Optional = 73, Byval = 74, Byref = 75, 
    Then = 76, Else = 77, Call = 78, Sub = 79, As = 80, ID = 81
  };

  enum {
    RuleModuleBody = 0, RuleDeclare = 1, RuleTypeDecl = 2, RuleVarDecl = 3, 
    RuleVariable = 4, RuleFunctionDecl = 5, RuleSubDecl = 6, RuleVarType = 7, 
    RuleLine = 8, RuleStatement = 9, RuleCallStmt = 10, RulePassArg = 11, 
    RuleAssignStmt = 12, RuleExitStmt = 13, RuleReturnStmt = 14, RuleExp = 15, 
    RuleForStmt = 16, RuleForeachStmt = 17, RuleIfStmt = 18, RuleIfBlock = 19, 
    RuleLoopStmt = 20
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
  class TypeDeclContext;
  class VarDeclContext;
  class VariableContext;
  class FunctionDeclContext;
  class SubDeclContext;
  class VarTypeContext;
  class LineContext;
  class StatementContext;
  class CallStmtContext;
  class PassArgContext;
  class AssignStmtContext;
  class ExitStmtContext;
  class ReturnStmtContext;
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
    TypeDeclContext *typeDecl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclareContext* declare();

  class  TypeDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    TypeDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Type();
    antlr4::tree::TerminalNode* Type(size_t i);
    antlr4::tree::TerminalNode *End();
    antlr4::tree::TerminalNode *ID();
    std::vector<antlr4::tree::TerminalNode *> LineEnd();
    antlr4::tree::TerminalNode* LineEnd(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeDeclContext* typeDecl();

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
    BasicParser::VarTypeContext *type = nullptr;
    BasicParser::ExpContext *initial = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *As();
    antlr4::tree::TerminalNode *ID();
    VarTypeContext *varType();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  FunctionDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    antlr4::Token *returnType = nullptr;
    BasicParser::LineContext *lineContext = nullptr;
    std::vector<LineContext *> block;
    FunctionDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Function();
    antlr4::tree::TerminalNode* Function(size_t i);
    antlr4::tree::TerminalNode *As();
    antlr4::tree::TerminalNode *End();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);
    std::vector<LineContext *> line();
    LineContext* line(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionDeclContext* functionDecl();

  class  SubDeclContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *name = nullptr;
    BasicParser::LineContext *lineContext = nullptr;
    std::vector<LineContext *> block;
    SubDeclContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> Sub();
    antlr4::tree::TerminalNode* Sub(size_t i);
    antlr4::tree::TerminalNode *End();
    antlr4::tree::TerminalNode *ID();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);
    std::vector<VariableContext *> variable();
    VariableContext* variable(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SubDeclContext* subDecl();

  class  VarTypeContext : public antlr4::ParserRuleContext {
  public:
    VarTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VarTypeContext* varType();

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *LineEnd();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ForStmtContext *forStmt();
    LoopStmtContext *loopStmt();
    IfStmtContext *ifStmt();
    ExitStmtContext *exitStmt();
    ReturnStmtContext *returnStmt();
    AssignStmtContext *assignStmt();
    CallStmtContext *callStmt();
    VarDeclContext *varDecl();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  CallStmtContext : public antlr4::ParserRuleContext {
  public:
    CallStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Call();
    antlr4::tree::TerminalNode *ID();
    std::vector<PassArgContext *> passArg();
    PassArgContext* passArg(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CallStmtContext* callStmt();

  class  PassArgContext : public antlr4::ParserRuleContext {
  public:
    PassArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PassArgContext() = default;
    void copyFrom(PassArgContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ArgIgnoreContext : public PassArgContext {
  public:
    ArgIgnoreContext(PassArgContext *ctx);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgOptionalContext : public PassArgContext {
  public:
    ArgOptionalContext(PassArgContext *ctx);

    antlr4::Token *option = nullptr;
    BasicParser::ExpContext *value = nullptr;
    antlr4::tree::TerminalNode *ID();
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ArgPassValueContext : public PassArgContext {
  public:
    ArgPassValueContext(PassArgContext *ctx);

    BasicParser::ExpContext *value = nullptr;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PassArgContext* passArg();

  class  AssignStmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *left = nullptr;
    BasicParser::ExpContext *right = nullptr;
    AssignStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignStmtContext* assignStmt();

  class  ExitStmtContext : public antlr4::ParserRuleContext {
  public:
    antlr4::Token *exitFlag = nullptr;
    ExitStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Exit();
    antlr4::tree::TerminalNode *For();
    antlr4::tree::TerminalNode *Do();
    antlr4::tree::TerminalNode *Sub();
    antlr4::tree::TerminalNode *Function();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExitStmtContext* exitStmt();

  class  ReturnStmtContext : public antlr4::ParserRuleContext {
  public:
    ReturnStmtContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Return();
    ExpContext *exp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnStmtContext* returnStmt();

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

    antlr4::Token *op = nullptr;
    BasicParser::ExpContext *right = nullptr;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InnerCallContext : public ExpContext {
  public:
    InnerCallContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *ID();
    std::vector<PassArgContext *> passArg();
    PassArgContext* passArg(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NegOpContext : public ExpContext {
  public:
    NegOpContext(ExpContext *ctx);

    BasicParser::ExpContext *right = nullptr;
    ExpContext *exp();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringContext : public ExpContext {
  public:
    StringContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *String();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntegerContext : public ExpContext {
  public:
    IntegerContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *Integer();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  DecimalContext : public ExpContext {
  public:
    DecimalContext(ExpContext *ctx);

    antlr4::tree::TerminalNode *Decimal();

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

    BasicParser::LineContext *lineContext = nullptr;
    std::vector<LineContext *> elseBlock;
    std::vector<antlr4::tree::TerminalNode *> If();
    antlr4::tree::TerminalNode* If(size_t i);
    std::vector<IfBlockContext *> ifBlock();
    IfBlockContext* ifBlock(size_t i);
    antlr4::tree::TerminalNode *End();
    std::vector<antlr4::tree::TerminalNode *> ElseIf();
    antlr4::tree::TerminalNode* ElseIf(size_t i);
    antlr4::tree::TerminalNode *Else();
    antlr4::tree::TerminalNode *LineEnd();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SingleLineIfContext : public IfStmtContext {
  public:
    SingleLineIfContext(IfStmtContext *ctx);

    BasicParser::ExpContext *condition = nullptr;
    BasicParser::StatementContext *elseStatement = nullptr;
    antlr4::tree::TerminalNode *If();
    antlr4::tree::TerminalNode *Then();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *LineEnd();
    ExpContext *exp();
    antlr4::tree::TerminalNode *Else();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  IfStmtContext* ifStmt();

  class  IfBlockContext : public antlr4::ParserRuleContext {
  public:
    BasicParser::ExpContext *condition = nullptr;
    BasicParser::LineContext *lineContext = nullptr;
    std::vector<LineContext *> block;
    IfBlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *Then();
    antlr4::tree::TerminalNode *LineEnd();
    ExpContext *exp();
    std::vector<LineContext *> line();
    LineContext* line(size_t i);


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

