
// Generated from Basic.g4 by ANTLR 4.9.1


#include "BasicVisitor.h"

#include "BasicParser.h"


using namespace antlrcpp;
using namespace antlr4;

BasicParser::BasicParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

BasicParser::~BasicParser() {
  delete _interpreter;
}

std::string BasicParser::getGrammarFileName() const {
  return "Basic.g4";
}

const std::vector<std::string>& BasicParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& BasicParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ModuleBodyContext ------------------------------------------------------------------

BasicParser::ModuleBodyContext::ModuleBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BasicParser::DeclareContext *> BasicParser::ModuleBodyContext::declare() {
  return getRuleContexts<BasicParser::DeclareContext>();
}

BasicParser::DeclareContext* BasicParser::ModuleBodyContext::declare(size_t i) {
  return getRuleContext<BasicParser::DeclareContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::ModuleBodyContext::LineEnd() {
  return getTokens(BasicParser::LineEnd);
}

tree::TerminalNode* BasicParser::ModuleBodyContext::LineEnd(size_t i) {
  return getToken(BasicParser::LineEnd, i);
}


size_t BasicParser::ModuleBodyContext::getRuleIndex() const {
  return BasicParser::RuleModuleBody;
}


antlrcpp::Any BasicParser::ModuleBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitModuleBody(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ModuleBodyContext* BasicParser::moduleBody() {
  ModuleBodyContext *_localctx = _tracker.createInstance<ModuleBodyContext>(_ctx, getState());
  enterRule(_localctx, 0, BasicParser::RuleModuleBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(30);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::Dim - 29))
      | (1ULL << (BasicParser::Function - 29))
      | (1ULL << (BasicParser::Sub - 29)))) != 0)) {
      setState(28);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case BasicParser::Dim:
        case BasicParser::Function:
        case BasicParser::Sub: {
          setState(26);
          declare();
          break;
        }

        case BasicParser::LineEnd: {
          setState(27);
          match(BasicParser::LineEnd);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(32);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclareContext ------------------------------------------------------------------

BasicParser::DeclareContext::DeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BasicParser::FunctionDeclContext* BasicParser::DeclareContext::functionDecl() {
  return getRuleContext<BasicParser::FunctionDeclContext>(0);
}

BasicParser::SubDeclContext* BasicParser::DeclareContext::subDecl() {
  return getRuleContext<BasicParser::SubDeclContext>(0);
}

BasicParser::VarDeclContext* BasicParser::DeclareContext::varDecl() {
  return getRuleContext<BasicParser::VarDeclContext>(0);
}


size_t BasicParser::DeclareContext::getRuleIndex() const {
  return BasicParser::RuleDeclare;
}


antlrcpp::Any BasicParser::DeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitDeclare(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::DeclareContext* BasicParser::declare() {
  DeclareContext *_localctx = _tracker.createInstance<DeclareContext>(_ctx, getState());
  enterRule(_localctx, 2, BasicParser::RuleDeclare);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(36);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::Function: {
        enterOuterAlt(_localctx, 1);
        setState(33);
        functionDecl();
        break;
      }

      case BasicParser::Sub: {
        enterOuterAlt(_localctx, 2);
        setState(34);
        subDecl();
        break;
      }

      case BasicParser::Dim: {
        enterOuterAlt(_localctx, 3);
        setState(35);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

BasicParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::VarDeclContext::Dim() {
  return getToken(BasicParser::Dim, 0);
}

std::vector<BasicParser::VariableContext *> BasicParser::VarDeclContext::variable() {
  return getRuleContexts<BasicParser::VariableContext>();
}

BasicParser::VariableContext* BasicParser::VarDeclContext::variable(size_t i) {
  return getRuleContext<BasicParser::VariableContext>(i);
}


size_t BasicParser::VarDeclContext::getRuleIndex() const {
  return BasicParser::RuleVarDecl;
}


antlrcpp::Any BasicParser::VarDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitVarDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VarDeclContext* BasicParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, BasicParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(38);
    match(BasicParser::Dim);
    setState(39);
    variable();
    setState(44);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::T__0) {
      setState(40);
      match(BasicParser::T__0);
      setState(41);
      variable();
      setState(46);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

BasicParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::VariableContext::As() {
  return getToken(BasicParser::As, 0);
}

std::vector<tree::TerminalNode *> BasicParser::VariableContext::ID() {
  return getTokens(BasicParser::ID);
}

tree::TerminalNode* BasicParser::VariableContext::ID(size_t i) {
  return getToken(BasicParser::ID, i);
}

BasicParser::ExpContext* BasicParser::VariableContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}


size_t BasicParser::VariableContext::getRuleIndex() const {
  return BasicParser::RuleVariable;
}


antlrcpp::Any BasicParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::VariableContext* BasicParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 6, BasicParser::RuleVariable);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(47);
    dynamic_cast<VariableContext *>(_localctx)->name = match(BasicParser::ID);
    setState(48);
    match(BasicParser::As);
    setState(49);
    dynamic_cast<VariableContext *>(_localctx)->type = match(BasicParser::ID);
    setState(52);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::T__1) {
      setState(50);
      match(BasicParser::T__1);
      setState(51);
      dynamic_cast<VariableContext *>(_localctx)->initial = exp(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

BasicParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BasicParser::FunctionDeclContext::Function() {
  return getTokens(BasicParser::Function);
}

tree::TerminalNode* BasicParser::FunctionDeclContext::Function(size_t i) {
  return getToken(BasicParser::Function, i);
}

tree::TerminalNode* BasicParser::FunctionDeclContext::As() {
  return getToken(BasicParser::As, 0);
}

tree::TerminalNode* BasicParser::FunctionDeclContext::End() {
  return getToken(BasicParser::End, 0);
}

std::vector<tree::TerminalNode *> BasicParser::FunctionDeclContext::ID() {
  return getTokens(BasicParser::ID);
}

tree::TerminalNode* BasicParser::FunctionDeclContext::ID(size_t i) {
  return getToken(BasicParser::ID, i);
}

std::vector<BasicParser::StatementContext *> BasicParser::FunctionDeclContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::FunctionDeclContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::FunctionDeclContext::getRuleIndex() const {
  return BasicParser::RuleFunctionDecl;
}


antlrcpp::Any BasicParser::FunctionDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitFunctionDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::FunctionDeclContext* BasicParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, BasicParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(54);
    match(BasicParser::Function);
    setState(55);
    dynamic_cast<FunctionDeclContext *>(_localctx)->name = match(BasicParser::ID);
    setState(56);
    match(BasicParser::T__2);
    setState(57);
    match(BasicParser::T__3);
    setState(58);
    match(BasicParser::As);
    setState(59);
    dynamic_cast<FunctionDeclContext *>(_localctx)->returnType = match(BasicParser::ID);
    setState(63);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::If - 29))
      | (1ULL << (BasicParser::Exit - 29))
      | (1ULL << (BasicParser::While - 29))
      | (1ULL << (BasicParser::Do - 29))
      | (1ULL << (BasicParser::For - 29)))) != 0)) {
      setState(60);
      statement();
      setState(65);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(66);
    match(BasicParser::End);
    setState(67);
    match(BasicParser::Function);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SubDeclContext ------------------------------------------------------------------

BasicParser::SubDeclContext::SubDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> BasicParser::SubDeclContext::Sub() {
  return getTokens(BasicParser::Sub);
}

tree::TerminalNode* BasicParser::SubDeclContext::Sub(size_t i) {
  return getToken(BasicParser::Sub, i);
}

tree::TerminalNode* BasicParser::SubDeclContext::End() {
  return getToken(BasicParser::End, 0);
}

tree::TerminalNode* BasicParser::SubDeclContext::ID() {
  return getToken(BasicParser::ID, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::SubDeclContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::SubDeclContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::SubDeclContext::getRuleIndex() const {
  return BasicParser::RuleSubDecl;
}


antlrcpp::Any BasicParser::SubDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitSubDecl(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::SubDeclContext* BasicParser::subDecl() {
  SubDeclContext *_localctx = _tracker.createInstance<SubDeclContext>(_ctx, getState());
  enterRule(_localctx, 10, BasicParser::RuleSubDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(69);
    match(BasicParser::Sub);
    setState(70);
    dynamic_cast<SubDeclContext *>(_localctx)->name = match(BasicParser::ID);
    setState(73);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::T__2) {
      setState(71);
      match(BasicParser::T__2);
      setState(72);
      match(BasicParser::T__3);
    }
    setState(78);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::If - 29))
      | (1ULL << (BasicParser::Exit - 29))
      | (1ULL << (BasicParser::While - 29))
      | (1ULL << (BasicParser::Do - 29))
      | (1ULL << (BasicParser::For - 29)))) != 0)) {
      setState(75);
      statement();
      setState(80);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(81);
    match(BasicParser::End);
    setState(82);
    match(BasicParser::Sub);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

BasicParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

BasicParser::ForStmtContext* BasicParser::StatementContext::forStmt() {
  return getRuleContext<BasicParser::ForStmtContext>(0);
}

BasicParser::LoopStmtContext* BasicParser::StatementContext::loopStmt() {
  return getRuleContext<BasicParser::LoopStmtContext>(0);
}

BasicParser::IfStmtContext* BasicParser::StatementContext::ifStmt() {
  return getRuleContext<BasicParser::IfStmtContext>(0);
}

tree::TerminalNode* BasicParser::StatementContext::LineEnd() {
  return getToken(BasicParser::LineEnd, 0);
}

tree::TerminalNode* BasicParser::StatementContext::Exit() {
  return getToken(BasicParser::Exit, 0);
}

tree::TerminalNode* BasicParser::StatementContext::For() {
  return getToken(BasicParser::For, 0);
}

tree::TerminalNode* BasicParser::StatementContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::StatementContext::Sub() {
  return getToken(BasicParser::Sub, 0);
}

tree::TerminalNode* BasicParser::StatementContext::Function() {
  return getToken(BasicParser::Function, 0);
}


size_t BasicParser::StatementContext::getRuleIndex() const {
  return BasicParser::RuleStatement;
}


antlrcpp::Any BasicParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::StatementContext* BasicParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 12, BasicParser::RuleStatement);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(90);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::For: {
        enterOuterAlt(_localctx, 1);
        setState(84);
        forStmt();
        break;
      }

      case BasicParser::While:
      case BasicParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(85);
        loopStmt();
        break;
      }

      case BasicParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(86);
        ifStmt();
        break;
      }

      case BasicParser::LineEnd: {
        enterOuterAlt(_localctx, 4);
        setState(87);
        match(BasicParser::LineEnd);
        break;
      }

      case BasicParser::Exit: {
        enterOuterAlt(_localctx, 5);
        setState(88);
        match(BasicParser::Exit);
        setState(89);
        dynamic_cast<StatementContext *>(_localctx)->exitFlag = _input->LT(1);
        _la = _input->LA(1);
        if (!(((((_la - 53) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 53)) & ((1ULL << (BasicParser::Function - 53))
          | (1ULL << (BasicParser::Do - 53))
          | (1ULL << (BasicParser::For - 53))
          | (1ULL << (BasicParser::Sub - 53)))) != 0))) {
          dynamic_cast<StatementContext *>(_localctx)->exitFlag = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpContext ------------------------------------------------------------------

BasicParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BasicParser::ExpContext::getRuleIndex() const {
  return BasicParser::RuleExp;
}

void BasicParser::ExpContext::copyFrom(ExpContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PluOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::PluOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::PluOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::PluOpContext::PluOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::PluOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitPluOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CmpOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::CmpOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::CmpOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::CmpOpContext::CmpOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::CmpOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitCmpOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicNotOpContext ------------------------------------------------------------------

BasicParser::ExpContext* BasicParser::LogicNotOpContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

BasicParser::LogicNotOpContext::LogicNotOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::LogicNotOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLogicNotOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NegOpContext ------------------------------------------------------------------

BasicParser::ExpContext* BasicParser::NegOpContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

BasicParser::NegOpContext::NegOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::NegOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitNegOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::StringContext::String() {
  return getToken(BasicParser::String, 0);
}

BasicParser::StringContext::StringContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::StringContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitString(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::NumberContext::Number() {
  return getToken(BasicParser::Number, 0);
}

BasicParser::NumberContext::NumberContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BucketContext ------------------------------------------------------------------

BasicParser::ExpContext* BasicParser::BucketContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

BasicParser::BucketContext::BucketContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::BucketContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitBucket(this);
  else
    return visitor->visitChildren(this);
}
//----------------- MulOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::MulOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::MulOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::MulOpContext::MulOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- PowModOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::PowModOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::PowModOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::PowModOpContext::PowModOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::PowModOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitPowModOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IDContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::IDContext::ID() {
  return getToken(BasicParser::ID, 0);
}

BasicParser::IDContext::IDContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::IDContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitID(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BooleanContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::BooleanContext::Boolean() {
  return getToken(BasicParser::Boolean, 0);
}

BasicParser::BooleanContext::BooleanContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::BooleanContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitBoolean(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BitOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::BitOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::BitOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::BitOpContext::BitOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::BitOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitBitOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicOpContext ------------------------------------------------------------------

std::vector<BasicParser::ExpContext *> BasicParser::LogicOpContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::LogicOpContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

BasicParser::LogicOpContext::LogicOpContext(ExpContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::LogicOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLogicOp(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ExpContext* BasicParser::exp() {
   return exp(0);
}

BasicParser::ExpContext* BasicParser::exp(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  BasicParser::ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, parentState);
  BasicParser::ExpContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 14;
  enterRecursionRule(_localctx, 14, BasicParser::RuleExp, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(105);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::T__4:
      case BasicParser::T__5: {
        _localctx = _tracker.createInstance<NegOpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(93);
        dynamic_cast<NegOpContext *>(_localctx)->op = _input->LT(1);
        _la = _input->LA(1);
        if (!(_la == BasicParser::T__4

        || _la == BasicParser::T__5)) {
          dynamic_cast<NegOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(94);
        exp(13);
        break;
      }

      case BasicParser::T__19: {
        _localctx = _tracker.createInstance<LogicNotOpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(95);
        match(BasicParser::T__19);
        setState(96);
        dynamic_cast<LogicNotOpContext *>(_localctx)->right = exp(7);
        break;
      }

      case BasicParser::T__2: {
        _localctx = _tracker.createInstance<BucketContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(97);
        match(BasicParser::T__2);
        setState(98);
        exp(0);
        setState(99);
        match(BasicParser::T__3);
        break;
      }

      case BasicParser::Number: {
        _localctx = _tracker.createInstance<NumberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(101);
        match(BasicParser::Number);
        break;
      }

      case BasicParser::String: {
        _localctx = _tracker.createInstance<StringContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(102);
        match(BasicParser::String);
        break;
      }

      case BasicParser::ID: {
        _localctx = _tracker.createInstance<IDContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(103);
        match(BasicParser::ID);
        break;
      }

      case BasicParser::Boolean: {
        _localctx = _tracker.createInstance<BooleanContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(104);
        match(BasicParser::Boolean);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(127);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(125);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BitOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(107);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(108);
          dynamic_cast<BitOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BasicParser::T__6

          || _la == BasicParser::T__7)) {
            dynamic_cast<BitOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(109);
          dynamic_cast<BitOpContext *>(_localctx)->right = exp(13);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PowModOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(110);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(111);
          dynamic_cast<PowModOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BasicParser::T__8

          || _la == BasicParser::T__9)) {
            dynamic_cast<PowModOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(112);
          dynamic_cast<PowModOpContext *>(_localctx)->right = exp(12);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MulOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(113);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(114);
          dynamic_cast<MulOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__10)
            | (1ULL << BasicParser::T__11)
            | (1ULL << BasicParser::T__12))) != 0))) {
            dynamic_cast<MulOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(115);
          dynamic_cast<MulOpContext *>(_localctx)->right = exp(11);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<PluOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(116);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(117);
          dynamic_cast<PluOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BasicParser::T__4

          || _la == BasicParser::T__13)) {
            dynamic_cast<PluOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(118);
          dynamic_cast<PluOpContext *>(_localctx)->right = exp(10);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CmpOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(119);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(120);
          dynamic_cast<CmpOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__1)
            | (1ULL << BasicParser::T__14)
            | (1ULL << BasicParser::T__15)
            | (1ULL << BasicParser::T__16)
            | (1ULL << BasicParser::T__17)
            | (1ULL << BasicParser::T__18))) != 0))) {
            dynamic_cast<CmpOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(121);
          dynamic_cast<CmpOpContext *>(_localctx)->right = exp(9);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LogicOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(122);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(123);
          dynamic_cast<LogicOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__20)
            | (1ULL << BasicParser::T__21)
            | (1ULL << BasicParser::T__22))) != 0))) {
            dynamic_cast<LogicOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(124);
          dynamic_cast<LogicOpContext *>(_localctx)->right = exp(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(129);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

BasicParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::ForStmtContext::For() {
  return getToken(BasicParser::For, 0);
}

tree::TerminalNode* BasicParser::ForStmtContext::To() {
  return getToken(BasicParser::To, 0);
}

tree::TerminalNode* BasicParser::ForStmtContext::Step() {
  return getToken(BasicParser::Step, 0);
}

tree::TerminalNode* BasicParser::ForStmtContext::Next() {
  return getToken(BasicParser::Next, 0);
}

std::vector<BasicParser::ExpContext *> BasicParser::ForStmtContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::ForStmtContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

std::vector<BasicParser::StatementContext *> BasicParser::ForStmtContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::ForStmtContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::ForStmtContext::getRuleIndex() const {
  return BasicParser::RuleForStmt;
}


antlrcpp::Any BasicParser::ForStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitForStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ForStmtContext* BasicParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 16, BasicParser::RuleForStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(130);
    match(BasicParser::For);
    setState(131);
    dynamic_cast<ForStmtContext *>(_localctx)->iterator = exp(0);
    setState(132);
    match(BasicParser::T__1);
    setState(133);
    dynamic_cast<ForStmtContext *>(_localctx)->begin = exp(0);
    setState(134);
    match(BasicParser::To);
    setState(135);
    dynamic_cast<ForStmtContext *>(_localctx)->end = exp(0);
    setState(136);
    match(BasicParser::Step);
    setState(137);
    dynamic_cast<ForStmtContext *>(_localctx)->step = exp(0);
    setState(141);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::If - 29))
      | (1ULL << (BasicParser::Exit - 29))
      | (1ULL << (BasicParser::While - 29))
      | (1ULL << (BasicParser::Do - 29))
      | (1ULL << (BasicParser::For - 29)))) != 0)) {
      setState(138);
      statement();
      setState(143);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(144);
    match(BasicParser::Next);
    setState(146);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::T__2)
      | (1ULL << BasicParser::T__4)
      | (1ULL << BasicParser::T__5)
      | (1ULL << BasicParser::T__19)
      | (1ULL << BasicParser::Number)
      | (1ULL << BasicParser::String)
      | (1ULL << BasicParser::Boolean))) != 0) || _la == BasicParser::ID) {
      setState(145);
      dynamic_cast<ForStmtContext *>(_localctx)->nextFlag = exp(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForeachStmtContext ------------------------------------------------------------------

BasicParser::ForeachStmtContext::ForeachStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::ForeachStmtContext::For() {
  return getToken(BasicParser::For, 0);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Each() {
  return getToken(BasicParser::Each, 0);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::In() {
  return getToken(BasicParser::In, 0);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Next() {
  return getToken(BasicParser::Next, 0);
}

std::vector<BasicParser::ExpContext *> BasicParser::ForeachStmtContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::ForeachStmtContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

std::vector<BasicParser::StatementContext *> BasicParser::ForeachStmtContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::ForeachStmtContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::ForeachStmtContext::getRuleIndex() const {
  return BasicParser::RuleForeachStmt;
}


antlrcpp::Any BasicParser::ForeachStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitForeachStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::ForeachStmtContext* BasicParser::foreachStmt() {
  ForeachStmtContext *_localctx = _tracker.createInstance<ForeachStmtContext>(_ctx, getState());
  enterRule(_localctx, 18, BasicParser::RuleForeachStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(BasicParser::For);
    setState(149);
    match(BasicParser::Each);
    setState(150);
    dynamic_cast<ForeachStmtContext *>(_localctx)->iterator = exp(0);
    setState(151);
    match(BasicParser::In);
    setState(152);
    dynamic_cast<ForeachStmtContext *>(_localctx)->group = exp(0);
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::If - 29))
      | (1ULL << (BasicParser::Exit - 29))
      | (1ULL << (BasicParser::While - 29))
      | (1ULL << (BasicParser::Do - 29))
      | (1ULL << (BasicParser::For - 29)))) != 0)) {
      setState(153);
      statement();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(159);
    match(BasicParser::Next);
    setState(161);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::T__2)
      | (1ULL << BasicParser::T__4)
      | (1ULL << BasicParser::T__5)
      | (1ULL << BasicParser::T__19)
      | (1ULL << BasicParser::Number)
      | (1ULL << BasicParser::String)
      | (1ULL << BasicParser::Boolean))) != 0) || _la == BasicParser::ID) {
      setState(160);
      dynamic_cast<ForeachStmtContext *>(_localctx)->nextFlag = exp(0);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

BasicParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BasicParser::IfStmtContext::getRuleIndex() const {
  return BasicParser::RuleIfStmt;
}

void BasicParser::IfStmtContext::copyFrom(IfStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- MutiLineIfContext ------------------------------------------------------------------

std::vector<tree::TerminalNode *> BasicParser::MutiLineIfContext::If() {
  return getTokens(BasicParser::If);
}

tree::TerminalNode* BasicParser::MutiLineIfContext::If(size_t i) {
  return getToken(BasicParser::If, i);
}

tree::TerminalNode* BasicParser::MutiLineIfContext::End() {
  return getToken(BasicParser::End, 0);
}

std::vector<BasicParser::IfBlockContext *> BasicParser::MutiLineIfContext::ifBlock() {
  return getRuleContexts<BasicParser::IfBlockContext>();
}

BasicParser::IfBlockContext* BasicParser::MutiLineIfContext::ifBlock(size_t i) {
  return getRuleContext<BasicParser::IfBlockContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::MutiLineIfContext::ElseIf() {
  return getTokens(BasicParser::ElseIf);
}

tree::TerminalNode* BasicParser::MutiLineIfContext::ElseIf(size_t i) {
  return getToken(BasicParser::ElseIf, i);
}

tree::TerminalNode* BasicParser::MutiLineIfContext::Else() {
  return getToken(BasicParser::Else, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::MutiLineIfContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::MutiLineIfContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::MutiLineIfContext::MutiLineIfContext(IfStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::MutiLineIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitMutiLineIf(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SingleLineIfContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::SingleLineIfContext::If() {
  return getToken(BasicParser::If, 0);
}

tree::TerminalNode* BasicParser::SingleLineIfContext::Then() {
  return getToken(BasicParser::Then, 0);
}

tree::TerminalNode* BasicParser::SingleLineIfContext::LineEnd() {
  return getToken(BasicParser::LineEnd, 0);
}

BasicParser::ExpContext* BasicParser::SingleLineIfContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

std::vector<BasicParser::StatementContext *> BasicParser::SingleLineIfContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::SingleLineIfContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

tree::TerminalNode* BasicParser::SingleLineIfContext::Else() {
  return getToken(BasicParser::Else, 0);
}

BasicParser::SingleLineIfContext::SingleLineIfContext(IfStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::SingleLineIfContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitSingleLineIf(this);
  else
    return visitor->visitChildren(this);
}
BasicParser::IfStmtContext* BasicParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 20, BasicParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(204);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<IfStmtContext *>(_tracker.createInstance<BasicParser::SingleLineIfContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(163);
      match(BasicParser::If);
      setState(164);
      dynamic_cast<SingleLineIfContext *>(_localctx)->condition = exp(0);
      setState(165);
      match(BasicParser::Then);
      setState(169);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(166);
          statement(); 
        }
        setState(171);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
      }
      setState(179);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BasicParser::Else) {
        setState(172);
        match(BasicParser::Else);
        setState(176);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
        while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
          if (alt == 1) {
            setState(173);
            dynamic_cast<SingleLineIfContext *>(_localctx)->elsestatement = statement(); 
          }
          setState(178);
          _errHandler->sync(this);
          alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx);
        }
      }
      setState(181);
      match(BasicParser::LineEnd);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<IfStmtContext *>(_tracker.createInstance<BasicParser::MutiLineIfContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(183);
      match(BasicParser::If);
      setState(184);
      dynamic_cast<MutiLineIfContext *>(_localctx)->firstBlock = ifBlock();
      setState(189);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == BasicParser::ElseIf) {
        setState(185);
        match(BasicParser::ElseIf);
        setState(186);
        dynamic_cast<MutiLineIfContext *>(_localctx)->elseifBlock = ifBlock();
        setState(191);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(199);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == BasicParser::Else) {
        setState(192);
        match(BasicParser::Else);
        setState(196);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 29) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
          | (1ULL << (BasicParser::If - 29))
          | (1ULL << (BasicParser::Exit - 29))
          | (1ULL << (BasicParser::While - 29))
          | (1ULL << (BasicParser::Do - 29))
          | (1ULL << (BasicParser::For - 29)))) != 0)) {
          setState(193);
          dynamic_cast<MutiLineIfContext *>(_localctx)->elseBlock = statement();
          setState(198);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(201);
      match(BasicParser::End);
      setState(202);
      match(BasicParser::If);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfBlockContext ------------------------------------------------------------------

BasicParser::IfBlockContext::IfBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::IfBlockContext::Then() {
  return getToken(BasicParser::Then, 0);
}

BasicParser::ExpContext* BasicParser::IfBlockContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

std::vector<BasicParser::StatementContext *> BasicParser::IfBlockContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::IfBlockContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::IfBlockContext::getRuleIndex() const {
  return BasicParser::RuleIfBlock;
}


antlrcpp::Any BasicParser::IfBlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitIfBlock(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::IfBlockContext* BasicParser::ifBlock() {
  IfBlockContext *_localctx = _tracker.createInstance<IfBlockContext>(_ctx, getState());
  enterRule(_localctx, 22, BasicParser::RuleIfBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(206);
    dynamic_cast<IfBlockContext *>(_localctx)->condition = exp(0);
    setState(207);
    match(BasicParser::Then);
    setState(211);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
      | (1ULL << (BasicParser::If - 29))
      | (1ULL << (BasicParser::Exit - 29))
      | (1ULL << (BasicParser::While - 29))
      | (1ULL << (BasicParser::Do - 29))
      | (1ULL << (BasicParser::For - 29)))) != 0)) {
      setState(208);
      statement();
      setState(213);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LoopStmtContext ------------------------------------------------------------------

BasicParser::LoopStmtContext::LoopStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t BasicParser::LoopStmtContext::getRuleIndex() const {
  return BasicParser::RuleLoopStmt;
}

void BasicParser::LoopStmtContext::copyFrom(LoopStmtContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DoUntilContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::DoUntilContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::DoUntilContext::Until() {
  return getToken(BasicParser::Until, 0);
}

BasicParser::ExpContext* BasicParser::DoUntilContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

tree::TerminalNode* BasicParser::DoUntilContext::Loop() {
  return getToken(BasicParser::Loop, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::DoUntilContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::DoUntilContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::DoUntilContext::DoUntilContext(LoopStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::DoUntilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitDoUntil(this);
  else
    return visitor->visitChildren(this);
}
//----------------- WhileWendContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::WhileWendContext::While() {
  return getToken(BasicParser::While, 0);
}

BasicParser::ExpContext* BasicParser::WhileWendContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

tree::TerminalNode* BasicParser::WhileWendContext::Wend() {
  return getToken(BasicParser::Wend, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::WhileWendContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::WhileWendContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::WhileWendContext::WhileWendContext(LoopStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::WhileWendContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitWhileWend(this);
  else
    return visitor->visitChildren(this);
}
//----------------- DoWhileContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::DoWhileContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::DoWhileContext::While() {
  return getToken(BasicParser::While, 0);
}

BasicParser::ExpContext* BasicParser::DoWhileContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

tree::TerminalNode* BasicParser::DoWhileContext::Loop() {
  return getToken(BasicParser::Loop, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::DoWhileContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::DoWhileContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::DoWhileContext::DoWhileContext(LoopStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::DoWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitDoWhile(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LoopUntilContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::LoopUntilContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::LoopUntilContext::Loop() {
  return getToken(BasicParser::Loop, 0);
}

tree::TerminalNode* BasicParser::LoopUntilContext::Until() {
  return getToken(BasicParser::Until, 0);
}

BasicParser::ExpContext* BasicParser::LoopUntilContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

std::vector<BasicParser::StatementContext *> BasicParser::LoopUntilContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::LoopUntilContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::LoopUntilContext::LoopUntilContext(LoopStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::LoopUntilContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLoopUntil(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LoopWhileContext ------------------------------------------------------------------

tree::TerminalNode* BasicParser::LoopWhileContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::LoopWhileContext::Loop() {
  return getToken(BasicParser::Loop, 0);
}

tree::TerminalNode* BasicParser::LoopWhileContext::While() {
  return getToken(BasicParser::While, 0);
}

BasicParser::ExpContext* BasicParser::LoopWhileContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

std::vector<BasicParser::StatementContext *> BasicParser::LoopWhileContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::LoopWhileContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

BasicParser::LoopWhileContext::LoopWhileContext(LoopStmtContext *ctx) { copyFrom(ctx); }


antlrcpp::Any BasicParser::LoopWhileContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLoopWhile(this);
  else
    return visitor->visitChildren(this);
}
BasicParser::LoopStmtContext* BasicParser::loopStmt() {
  LoopStmtContext *_localctx = _tracker.createInstance<LoopStmtContext>(_ctx, getState());
  enterRule(_localctx, 24, BasicParser::RuleLoopStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(266);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<LoopStmtContext *>(_tracker.createInstance<BasicParser::DoWhileContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(214);
      match(BasicParser::Do);
      setState(215);
      match(BasicParser::While);
      setState(216);
      exp(0);
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
        | (1ULL << (BasicParser::If - 29))
        | (1ULL << (BasicParser::Exit - 29))
        | (1ULL << (BasicParser::While - 29))
        | (1ULL << (BasicParser::Do - 29))
        | (1ULL << (BasicParser::For - 29)))) != 0)) {
        setState(217);
        statement();
        setState(222);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(223);
      match(BasicParser::Loop);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<LoopStmtContext *>(_tracker.createInstance<BasicParser::DoUntilContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(225);
      match(BasicParser::Do);
      setState(226);
      match(BasicParser::Until);
      setState(227);
      exp(0);
      setState(231);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
        | (1ULL << (BasicParser::If - 29))
        | (1ULL << (BasicParser::Exit - 29))
        | (1ULL << (BasicParser::While - 29))
        | (1ULL << (BasicParser::Do - 29))
        | (1ULL << (BasicParser::For - 29)))) != 0)) {
        setState(228);
        statement();
        setState(233);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(234);
      match(BasicParser::Loop);
      break;
    }

    case 3: {
      _localctx = dynamic_cast<LoopStmtContext *>(_tracker.createInstance<BasicParser::LoopUntilContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(236);
      match(BasicParser::Do);
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
        | (1ULL << (BasicParser::If - 29))
        | (1ULL << (BasicParser::Exit - 29))
        | (1ULL << (BasicParser::While - 29))
        | (1ULL << (BasicParser::Do - 29))
        | (1ULL << (BasicParser::For - 29)))) != 0)) {
        setState(237);
        statement();
        setState(242);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(243);
      match(BasicParser::Loop);
      setState(244);
      match(BasicParser::Until);
      setState(245);
      exp(0);
      break;
    }

    case 4: {
      _localctx = dynamic_cast<LoopStmtContext *>(_tracker.createInstance<BasicParser::LoopWhileContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(246);
      match(BasicParser::Do);
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
        | (1ULL << (BasicParser::If - 29))
        | (1ULL << (BasicParser::Exit - 29))
        | (1ULL << (BasicParser::While - 29))
        | (1ULL << (BasicParser::Do - 29))
        | (1ULL << (BasicParser::For - 29)))) != 0)) {
        setState(247);
        statement();
        setState(252);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(253);
      match(BasicParser::Loop);
      setState(254);
      match(BasicParser::While);
      setState(255);
      exp(0);
      break;
    }

    case 5: {
      _localctx = dynamic_cast<LoopStmtContext *>(_tracker.createInstance<BasicParser::WhileWendContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(256);
      match(BasicParser::While);
      setState(257);
      exp(0);
      setState(261);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 29) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 29)) & ((1ULL << (BasicParser::LineEnd - 29))
        | (1ULL << (BasicParser::If - 29))
        | (1ULL << (BasicParser::Exit - 29))
        | (1ULL << (BasicParser::While - 29))
        | (1ULL << (BasicParser::Do - 29))
        | (1ULL << (BasicParser::For - 29)))) != 0)) {
        setState(258);
        statement();
        setState(263);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(264);
      match(BasicParser::Wend);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool BasicParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 7: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BasicParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 12);
    case 1: return precpred(_ctx, 11);
    case 2: return precpred(_ctx, 10);
    case 3: return precpred(_ctx, 9);
    case 4: return precpred(_ctx, 8);
    case 5: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> BasicParser::_decisionToDFA;
atn::PredictionContextCache BasicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BasicParser::_atn;
std::vector<uint16_t> BasicParser::_serializedATN;

std::vector<std::string> BasicParser::_ruleNames = {
  "moduleBody", "declare", "varDecl", "variable", "functionDecl", "subDecl", 
  "statement", "exp", "forStmt", "foreachStmt", "ifStmt", "ifBlock", "loopStmt"
};

std::vector<std::string> BasicParser::_literalNames = {
  "", "','", "'='", "'('", "')'", "'-'", "'~'", "'&'", "'|'", "'^'", "'mod'", 
  "'*'", "'/'", "'\\'", "'+'", "'>'", "'<'", "'<='", "'<>'", "'>='", "'not'", 
  "'and'", "'or'", "'xor'"
};

std::vector<std::string> BasicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "Number", "String", "Boolean", "Comment", "BlockComment", 
  "LineEnd", "WS", "If", "ElseIf", "Wend", "From", "Import", "Namespace", 
  "Implement", "Type", "Alias", "Self", "Static", "Module", "Public", "Private", 
  "Protected", "Get", "Set", "Property", "Var", "Dim", "Let", "Return", 
  "Function", "Difference", "Union", "Case", "Select", "End", "Until", "Loop", 
  "Exit", "While", "Do", "Each", "To", "Step", "Next", "In", "For", "Optional", 
  "Byval", "Byref", "Then", "Else", "Call", "Sub", "As", "ID"
};

dfa::Vocabulary BasicParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> BasicParser::_tokenNames;

BasicParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x50, 0x10f, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0x1f, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0x22, 
    0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x27, 0xa, 0x3, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x2d, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x30, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x5, 0x5, 0x37, 0xa, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x40, 0xa, 0x6, 0xc, 0x6, 0xe, 
    0x6, 0x43, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 0x4c, 0xa, 0x7, 0x3, 0x7, 0x7, 0x7, 0x4f, 
    0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x52, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0x5d, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 
    0x3, 0x9, 0x5, 0x9, 0x6c, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x7, 0x9, 0x80, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x83, 0xb, 0x9, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x7, 0xa, 0x8e, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x91, 0xb, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 0x95, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 
    0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 0x9d, 0xa, 0xb, 0xc, 
    0xb, 0xe, 0xb, 0xa0, 0xb, 0xb, 0x3, 0xb, 0x3, 0xb, 0x5, 0xb, 0xa4, 0xa, 
    0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xaa, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0xad, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xb1, 
    0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xb4, 0xb, 0xc, 0x5, 0xc, 0xb6, 0xa, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 
    0xbe, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc1, 0xb, 0xc, 0x3, 0xc, 0x3, 0xc, 
    0x7, 0xc, 0xc5, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xc8, 0xb, 0xc, 0x5, 0xc, 
    0xca, 0xa, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x5, 0xc, 0xcf, 0xa, 0xc, 
    0x3, 0xd, 0x3, 0xd, 0x3, 0xd, 0x7, 0xd, 0xd4, 0xa, 0xd, 0xc, 0xd, 0xe, 
    0xd, 0xd7, 0xb, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 
    0xdd, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xe0, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xe8, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0xeb, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x7, 0xe, 0xf1, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0xf4, 0xb, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0xfb, 0xa, 0xe, 0xc, 
    0xe, 0xe, 0xe, 0xfe, 0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 
    0x3, 0xe, 0x3, 0xe, 0x7, 0xe, 0x106, 0xa, 0xe, 0xc, 0xe, 0xe, 0xe, 0x109, 
    0xb, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x10d, 0xa, 0xe, 0x3, 0xe, 0x2, 
    0x3, 0x10, 0xf, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 
    0x16, 0x18, 0x1a, 0x2, 0xa, 0x6, 0x2, 0x37, 0x37, 0x41, 0x41, 0x47, 
    0x47, 0x4e, 0x4e, 0x3, 0x2, 0x7, 0x8, 0x3, 0x2, 0x9, 0xa, 0x3, 0x2, 
    0xb, 0xc, 0x3, 0x2, 0xd, 0xf, 0x4, 0x2, 0x7, 0x7, 0x10, 0x10, 0x4, 0x2, 
    0x4, 0x4, 0x11, 0x15, 0x3, 0x2, 0x17, 0x19, 0x2, 0x12f, 0x2, 0x20, 0x3, 
    0x2, 0x2, 0x2, 0x4, 0x26, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x8, 0x31, 0x3, 0x2, 0x2, 0x2, 0xa, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0xe, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x12, 0x84, 0x3, 0x2, 0x2, 0x2, 0x14, 0x96, 0x3, 
    0x2, 0x2, 0x2, 0x16, 0xce, 0x3, 0x2, 0x2, 0x2, 0x18, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0x1a, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1f, 0x5, 0x4, 0x3, 
    0x2, 0x1d, 0x1f, 0x7, 0x1f, 0x2, 0x2, 0x1e, 0x1c, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x2, 0x2, 0x20, 
    0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 0x21, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x23, 0x27, 0x5, 
    0xa, 0x6, 0x2, 0x24, 0x27, 0x5, 0xc, 0x7, 0x2, 0x25, 0x27, 0x5, 0x6, 
    0x4, 0x2, 0x26, 0x23, 0x3, 0x2, 0x2, 0x2, 0x26, 0x24, 0x3, 0x2, 0x2, 
    0x2, 0x26, 0x25, 0x3, 0x2, 0x2, 0x2, 0x27, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0x29, 0x7, 0x34, 0x2, 0x2, 0x29, 0x2e, 0x5, 0x8, 0x5, 0x2, 0x2a, 
    0x2b, 0x7, 0x3, 0x2, 0x2, 0x2b, 0x2d, 0x5, 0x8, 0x5, 0x2, 0x2c, 0x2a, 
    0x3, 0x2, 0x2, 0x2, 0x2d, 0x30, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x2c, 0x3, 
    0x2, 0x2, 0x2, 0x2e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x2f, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x31, 0x32, 0x7, 0x50, 0x2, 
    0x2, 0x32, 0x33, 0x7, 0x4f, 0x2, 0x2, 0x33, 0x36, 0x7, 0x50, 0x2, 0x2, 
    0x34, 0x35, 0x7, 0x4, 0x2, 0x2, 0x35, 0x37, 0x5, 0x10, 0x9, 0x2, 0x36, 
    0x34, 0x3, 0x2, 0x2, 0x2, 0x36, 0x37, 0x3, 0x2, 0x2, 0x2, 0x37, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x37, 0x2, 0x2, 0x39, 0x3a, 0x7, 
    0x50, 0x2, 0x2, 0x3a, 0x3b, 0x7, 0x5, 0x2, 0x2, 0x3b, 0x3c, 0x7, 0x6, 
    0x2, 0x2, 0x3c, 0x3d, 0x7, 0x4f, 0x2, 0x2, 0x3d, 0x41, 0x7, 0x50, 0x2, 
    0x2, 0x3e, 0x40, 0x5, 0xe, 0x8, 0x2, 0x3f, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x41, 
    0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x44, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 
    0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x3c, 0x2, 0x2, 0x45, 0x46, 0x7, 
    0x37, 0x2, 0x2, 0x46, 0xb, 0x3, 0x2, 0x2, 0x2, 0x47, 0x48, 0x7, 0x4e, 
    0x2, 0x2, 0x48, 0x4b, 0x7, 0x50, 0x2, 0x2, 0x49, 0x4a, 0x7, 0x5, 0x2, 
    0x2, 0x4a, 0x4c, 0x7, 0x6, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x4b, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x50, 0x3, 0x2, 0x2, 0x2, 0x4d, 
    0x4f, 0x5, 0xe, 0x8, 0x2, 0x4e, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x52, 
    0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x50, 0x51, 0x3, 
    0x2, 0x2, 0x2, 0x51, 0x53, 0x3, 0x2, 0x2, 0x2, 0x52, 0x50, 0x3, 0x2, 
    0x2, 0x2, 0x53, 0x54, 0x7, 0x3c, 0x2, 0x2, 0x54, 0x55, 0x7, 0x4e, 0x2, 
    0x2, 0x55, 0xd, 0x3, 0x2, 0x2, 0x2, 0x56, 0x5d, 0x5, 0x12, 0xa, 0x2, 
    0x57, 0x5d, 0x5, 0x1a, 0xe, 0x2, 0x58, 0x5d, 0x5, 0x16, 0xc, 0x2, 0x59, 
    0x5d, 0x7, 0x1f, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x3f, 0x2, 0x2, 0x5b, 0x5d, 
    0x9, 0x2, 0x2, 0x2, 0x5c, 0x56, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x5c, 0x58, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x5c, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5d, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x5e, 0x5f, 0x8, 0x9, 0x1, 0x2, 0x5f, 0x60, 0x9, 0x3, 0x2, 0x2, 
    0x60, 0x6c, 0x5, 0x10, 0x9, 0xf, 0x61, 0x62, 0x7, 0x16, 0x2, 0x2, 0x62, 
    0x6c, 0x5, 0x10, 0x9, 0x9, 0x63, 0x64, 0x7, 0x5, 0x2, 0x2, 0x64, 0x65, 
    0x5, 0x10, 0x9, 0x2, 0x65, 0x66, 0x7, 0x6, 0x2, 0x2, 0x66, 0x6c, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x6c, 0x7, 0x1a, 0x2, 0x2, 0x68, 0x6c, 0x7, 0x1b, 
    0x2, 0x2, 0x69, 0x6c, 0x7, 0x50, 0x2, 0x2, 0x6a, 0x6c, 0x7, 0x1c, 0x2, 
    0x2, 0x6b, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x61, 0x3, 0x2, 0x2, 0x2, 
    0x6b, 0x63, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x67, 0x3, 0x2, 0x2, 0x2, 0x6b, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6a, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x81, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0xc, 
    0xe, 0x2, 0x2, 0x6e, 0x6f, 0x9, 0x4, 0x2, 0x2, 0x6f, 0x80, 0x5, 0x10, 
    0x9, 0xf, 0x70, 0x71, 0xc, 0xd, 0x2, 0x2, 0x71, 0x72, 0x9, 0x5, 0x2, 
    0x2, 0x72, 0x80, 0x5, 0x10, 0x9, 0xe, 0x73, 0x74, 0xc, 0xc, 0x2, 0x2, 
    0x74, 0x75, 0x9, 0x6, 0x2, 0x2, 0x75, 0x80, 0x5, 0x10, 0x9, 0xd, 0x76, 
    0x77, 0xc, 0xb, 0x2, 0x2, 0x77, 0x78, 0x9, 0x7, 0x2, 0x2, 0x78, 0x80, 
    0x5, 0x10, 0x9, 0xc, 0x79, 0x7a, 0xc, 0xa, 0x2, 0x2, 0x7a, 0x7b, 0x9, 
    0x8, 0x2, 0x2, 0x7b, 0x80, 0x5, 0x10, 0x9, 0xb, 0x7c, 0x7d, 0xc, 0x8, 
    0x2, 0x2, 0x7d, 0x7e, 0x9, 0x9, 0x2, 0x2, 0x7e, 0x80, 0x5, 0x10, 0x9, 
    0x9, 0x7f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x70, 0x3, 0x2, 0x2, 0x2, 
    0x7f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x76, 0x3, 0x2, 0x2, 0x2, 0x7f, 
    0x79, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x80, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x82, 0x11, 0x3, 0x2, 0x2, 0x2, 0x83, 0x81, 0x3, 0x2, 
    0x2, 0x2, 0x84, 0x85, 0x7, 0x47, 0x2, 0x2, 0x85, 0x86, 0x5, 0x10, 0x9, 
    0x2, 0x86, 0x87, 0x7, 0x4, 0x2, 0x2, 0x87, 0x88, 0x5, 0x10, 0x9, 0x2, 
    0x88, 0x89, 0x7, 0x43, 0x2, 0x2, 0x89, 0x8a, 0x5, 0x10, 0x9, 0x2, 0x8a, 
    0x8b, 0x7, 0x44, 0x2, 0x2, 0x8b, 0x8f, 0x5, 0x10, 0x9, 0x2, 0x8c, 0x8e, 
    0x5, 0xe, 0x8, 0x2, 0x8d, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x91, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x92, 0x3, 0x2, 0x2, 0x2, 0x91, 0x8f, 0x3, 0x2, 0x2, 
    0x2, 0x92, 0x94, 0x7, 0x45, 0x2, 0x2, 0x93, 0x95, 0x5, 0x10, 0x9, 0x2, 
    0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x94, 0x95, 0x3, 0x2, 0x2, 0x2, 0x95, 
    0x13, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x47, 0x2, 0x2, 0x97, 0x98, 
    0x7, 0x42, 0x2, 0x2, 0x98, 0x99, 0x5, 0x10, 0x9, 0x2, 0x99, 0x9a, 0x7, 
    0x46, 0x2, 0x2, 0x9a, 0x9e, 0x5, 0x10, 0x9, 0x2, 0x9b, 0x9d, 0x5, 0xe, 
    0x8, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa0, 0x3, 0x2, 0x2, 
    0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x3, 0x2, 0x2, 0x2, 
    0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 0x3, 0x2, 0x2, 0x2, 0xa1, 
    0xa3, 0x7, 0x45, 0x2, 0x2, 0xa2, 0xa4, 0x5, 0x10, 0x9, 0x2, 0xa3, 0xa2, 
    0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa4, 0x15, 0x3, 
    0x2, 0x2, 0x2, 0xa5, 0xa6, 0x7, 0x21, 0x2, 0x2, 0xa6, 0xa7, 0x5, 0x10, 
    0x9, 0x2, 0xa7, 0xab, 0x7, 0x4b, 0x2, 0x2, 0xa8, 0xaa, 0x5, 0xe, 0x8, 
    0x2, 0xa9, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xad, 0x3, 0x2, 0x2, 0x2, 
    0xab, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xab, 0xac, 0x3, 0x2, 0x2, 0x2, 0xac, 
    0xb5, 0x3, 0x2, 0x2, 0x2, 0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xae, 0xb2, 
    0x7, 0x4c, 0x2, 0x2, 0xaf, 0xb1, 0x5, 0xe, 0x8, 0x2, 0xb0, 0xaf, 0x3, 
    0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 0x2, 0xb3, 0xb6, 0x3, 0x2, 0x2, 
    0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xae, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb7, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xb8, 0x7, 0x1f, 0x2, 0x2, 0xb8, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xb9, 0xba, 
    0x7, 0x21, 0x2, 0x2, 0xba, 0xbf, 0x5, 0x18, 0xd, 0x2, 0xbb, 0xbc, 0x7, 
    0x22, 0x2, 0x2, 0xbc, 0xbe, 0x5, 0x18, 0xd, 0x2, 0xbd, 0xbb, 0x3, 0x2, 
    0x2, 0x2, 0xbe, 0xc1, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xbd, 0x3, 0x2, 0x2, 
    0x2, 0xbf, 0xc0, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc9, 0x3, 0x2, 0x2, 0x2, 
    0xc1, 0xbf, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc6, 0x7, 0x4c, 0x2, 0x2, 0xc3, 
    0xc5, 0x5, 0xe, 0x8, 0x2, 0xc4, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc8, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0xc9, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x3, 0x2, 0x2, 
    0x2, 0xca, 0xcb, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xcc, 0x7, 0x3c, 0x2, 0x2, 
    0xcc, 0xcd, 0x7, 0x21, 0x2, 0x2, 0xcd, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xce, 
    0xa5, 0x3, 0x2, 0x2, 0x2, 0xce, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xcf, 0x17, 
    0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x5, 0x10, 0x9, 0x2, 0xd1, 0xd5, 0x7, 
    0x4b, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0xe, 0x8, 0x2, 0xd3, 0xd2, 0x3, 0x2, 
    0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd3, 0x3, 0x2, 0x2, 
    0x2, 0xd5, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd6, 0x19, 0x3, 0x2, 0x2, 0x2, 
    0xd7, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 0x7, 0x41, 0x2, 0x2, 0xd9, 
    0xda, 0x7, 0x40, 0x2, 0x2, 0xda, 0xde, 0x5, 0x10, 0x9, 0x2, 0xdb, 0xdd, 
    0x5, 0xe, 0x8, 0x2, 0xdc, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdf, 0x3, 0x2, 
    0x2, 0x2, 0xdf, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 
    0x2, 0xe1, 0xe2, 0x7, 0x3e, 0x2, 0x2, 0xe2, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0xe3, 0xe4, 0x7, 0x41, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x3d, 0x2, 0x2, 0xe5, 
    0xe9, 0x5, 0x10, 0x9, 0x2, 0xe6, 0xe8, 0x5, 0xe, 0x8, 0x2, 0xe7, 0xe6, 
    0x3, 0x2, 0x2, 0x2, 0xe8, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xe7, 0x3, 
    0x2, 0x2, 0x2, 0xe9, 0xea, 0x3, 0x2, 0x2, 0x2, 0xea, 0xec, 0x3, 0x2, 
    0x2, 0x2, 0xeb, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x7, 0x3e, 0x2, 
    0x2, 0xed, 0x10d, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf2, 0x7, 0x41, 0x2, 0x2, 
    0xef, 0xf1, 0x5, 0xe, 0x8, 0x2, 0xf0, 0xef, 0x3, 0x2, 0x2, 0x2, 0xf1, 
    0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0xf3, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf5, 0xf6, 0x7, 0x3e, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x3d, 
    0x2, 0x2, 0xf7, 0x10d, 0x5, 0x10, 0x9, 0x2, 0xf8, 0xfc, 0x7, 0x41, 0x2, 
    0x2, 0xf9, 0xfb, 0x5, 0xe, 0x8, 0x2, 0xfa, 0xf9, 0x3, 0x2, 0x2, 0x2, 
    0xfb, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 0x2, 0x2, 0xfc, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0xfd, 0xff, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x7, 0x3e, 0x2, 0x2, 0x100, 0x101, 
    0x7, 0x40, 0x2, 0x2, 0x101, 0x10d, 0x5, 0x10, 0x9, 0x2, 0x102, 0x103, 
    0x7, 0x40, 0x2, 0x2, 0x103, 0x107, 0x5, 0x10, 0x9, 0x2, 0x104, 0x106, 
    0x5, 0xe, 0x8, 0x2, 0x105, 0x104, 0x3, 0x2, 0x2, 0x2, 0x106, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x107, 0x105, 0x3, 0x2, 0x2, 0x2, 0x107, 0x108, 
    0x3, 0x2, 0x2, 0x2, 0x108, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x109, 0x107, 
    0x3, 0x2, 0x2, 0x2, 0x10a, 0x10b, 0x7, 0x23, 0x2, 0x2, 0x10b, 0x10d, 
    0x3, 0x2, 0x2, 0x2, 0x10c, 0xd8, 0x3, 0x2, 0x2, 0x2, 0x10c, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0x10c, 0xee, 0x3, 0x2, 0x2, 0x2, 0x10c, 0xf8, 0x3, 0x2, 
    0x2, 0x2, 0x10c, 0x102, 0x3, 0x2, 0x2, 0x2, 0x10d, 0x1b, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x1e, 0x20, 0x26, 0x2e, 0x36, 0x41, 0x4b, 0x50, 0x5c, 0x6b, 
    0x7f, 0x81, 0x8f, 0x94, 0x9e, 0xa3, 0xab, 0xb2, 0xb5, 0xbf, 0xc6, 0xc9, 
    0xce, 0xd5, 0xde, 0xe9, 0xf2, 0xfc, 0x107, 0x10c, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

BasicParser::Initializer BasicParser::_init;
