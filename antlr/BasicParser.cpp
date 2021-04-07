
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


//----------------- StatementsContext ------------------------------------------------------------------

BasicParser::StatementsContext::StatementsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<BasicParser::StatementContext *> BasicParser::StatementsContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::StatementsContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::StatementsContext::getRuleIndex() const {
  return BasicParser::RuleStatements;
}


antlrcpp::Any BasicParser::StatementsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitStatements(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::StatementsContext* BasicParser::statements() {
  StatementsContext *_localctx = _tracker.createInstance<StatementsContext>(_ctx, getState());
  enterRule(_localctx, 0, BasicParser::RuleStatements);
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
    setState(19);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(16);
      statement();
      setState(21);
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
  enterRule(_localctx, 2, BasicParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(25);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::For: {
        enterOuterAlt(_localctx, 1);
        setState(22);
        forStmt();
        break;
      }

      case BasicParser::While:
      case BasicParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        loopStmt();
        break;
      }

      case BasicParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(24);
        ifStmt();
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
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, BasicParser::RuleExp, precedence);

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
    setState(38);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::T__0: {
        _localctx = _tracker.createInstance<NegOpContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(28);
        match(BasicParser::T__0);
        setState(29);
        exp(12);
        break;
      }

      case BasicParser::T__20: {
        _localctx = _tracker.createInstance<BucketContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(30);
        match(BasicParser::T__20);
        setState(31);
        exp(0);
        setState(32);
        match(BasicParser::T__21);
        break;
      }

      case BasicParser::Number: {
        _localctx = _tracker.createInstance<NumberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(34);
        match(BasicParser::Number);
        break;
      }

      case BasicParser::String: {
        _localctx = _tracker.createInstance<StringContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(35);
        match(BasicParser::String);
        break;
      }

      case BasicParser::ID: {
        _localctx = _tracker.createInstance<IDContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(36);
        match(BasicParser::ID);
        break;
      }

      case BasicParser::Boolean: {
        _localctx = _tracker.createInstance<BooleanContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(37);
        match(BasicParser::Boolean);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(60);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(58);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BitOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(40);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(41);
          dynamic_cast<BitOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__1)
            | (1ULL << BasicParser::T__2)
            | (1ULL << BasicParser::T__3))) != 0))) {
            dynamic_cast<BitOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(42);
          dynamic_cast<BitOpContext *>(_localctx)->right = exp(12);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PowModOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(43);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(44);
          dynamic_cast<PowModOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BasicParser::T__4

          || _la == BasicParser::T__5)) {
            dynamic_cast<PowModOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(45);
          dynamic_cast<PowModOpContext *>(_localctx)->right = exp(11);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<MulOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(46);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(47);
          dynamic_cast<MulOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__6)
            | (1ULL << BasicParser::T__7)
            | (1ULL << BasicParser::T__8))) != 0))) {
            dynamic_cast<MulOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(48);
          dynamic_cast<MulOpContext *>(_localctx)->right = exp(10);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<PluOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(49);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(50);
          dynamic_cast<PluOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == BasicParser::T__0

          || _la == BasicParser::T__9)) {
            dynamic_cast<PluOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(51);
          dynamic_cast<PluOpContext *>(_localctx)->right = exp(9);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<CmpOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(52);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(53);
          dynamic_cast<CmpOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__10)
            | (1ULL << BasicParser::T__11)
            | (1ULL << BasicParser::T__12)
            | (1ULL << BasicParser::T__13)
            | (1ULL << BasicParser::T__14)
            | (1ULL << BasicParser::T__15))) != 0))) {
            dynamic_cast<CmpOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(54);
          dynamic_cast<CmpOpContext *>(_localctx)->right = exp(8);
          break;
        }

        case 6: {
          auto newContext = _tracker.createInstance<LogicOpContext>(_tracker.createInstance<ExpContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExp);
          setState(55);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(56);
          dynamic_cast<LogicOpContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << BasicParser::T__16)
            | (1ULL << BasicParser::T__17)
            | (1ULL << BasicParser::T__18)
            | (1ULL << BasicParser::T__19))) != 0))) {
            dynamic_cast<LogicOpContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(57);
          dynamic_cast<LogicOpContext *>(_localctx)->right = exp(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(62);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
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

std::vector<tree::TerminalNode *> BasicParser::ForStmtContext::For() {
  return getTokens(BasicParser::For);
}

tree::TerminalNode* BasicParser::ForStmtContext::For(size_t i) {
  return getToken(BasicParser::For, i);
}

std::vector<BasicParser::ExpContext *> BasicParser::ForStmtContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::ForStmtContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
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

std::vector<BasicParser::StatementContext *> BasicParser::ForStmtContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::ForStmtContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

tree::TerminalNode* BasicParser::ForStmtContext::Exit() {
  return getToken(BasicParser::Exit, 0);
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
  enterRule(_localctx, 6, BasicParser::RuleForStmt);
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
    enterOuterAlt(_localctx, 1);
    setState(63);
    match(BasicParser::For);
    setState(64);
    exp(0);
    setState(65);
    match(BasicParser::To);
    setState(66);
    exp(0);
    setState(67);
    match(BasicParser::Step);
    setState(68);
    exp(0);
    setState(72);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(69);
        statement(); 
      }
      setState(74);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(77);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(75);
      match(BasicParser::Exit);
      setState(76);
      match(BasicParser::For);
    }
    setState(82);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(79);
      statement();
      setState(84);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(85);
    match(BasicParser::Next);
    setState(86);
    exp(0);
   
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

std::vector<tree::TerminalNode *> BasicParser::ForeachStmtContext::For() {
  return getTokens(BasicParser::For);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::For(size_t i) {
  return getToken(BasicParser::For, i);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Each() {
  return getToken(BasicParser::Each, 0);
}

std::vector<BasicParser::ExpContext *> BasicParser::ForeachStmtContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::ForeachStmtContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Step() {
  return getToken(BasicParser::Step, 0);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::In() {
  return getToken(BasicParser::In, 0);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Next() {
  return getToken(BasicParser::Next, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::ForeachStmtContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::ForeachStmtContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

tree::TerminalNode* BasicParser::ForeachStmtContext::Exit() {
  return getToken(BasicParser::Exit, 0);
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
  enterRule(_localctx, 8, BasicParser::RuleForeachStmt);
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
    enterOuterAlt(_localctx, 1);
    setState(88);
    match(BasicParser::For);
    setState(89);
    match(BasicParser::Each);
    setState(90);
    exp(0);
    setState(91);
    match(BasicParser::Step);
    setState(92);
    match(BasicParser::In);
    setState(93);
    exp(0);
    setState(97);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(94);
        statement(); 
      }
      setState(99);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
    setState(102);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(100);
      match(BasicParser::Exit);
      setState(101);
      match(BasicParser::For);
    }
    setState(107);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(104);
      statement();
      setState(109);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(110);
    match(BasicParser::Next);
    setState(111);
    exp(0);
   
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

std::vector<tree::TerminalNode *> BasicParser::IfStmtContext::If() {
  return getTokens(BasicParser::If);
}

tree::TerminalNode* BasicParser::IfStmtContext::If(size_t i) {
  return getToken(BasicParser::If, i);
}

std::vector<BasicParser::ExpContext *> BasicParser::IfStmtContext::exp() {
  return getRuleContexts<BasicParser::ExpContext>();
}

BasicParser::ExpContext* BasicParser::IfStmtContext::exp(size_t i) {
  return getRuleContext<BasicParser::ExpContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::IfStmtContext::Then() {
  return getTokens(BasicParser::Then);
}

tree::TerminalNode* BasicParser::IfStmtContext::Then(size_t i) {
  return getToken(BasicParser::Then, i);
}

tree::TerminalNode* BasicParser::IfStmtContext::End() {
  return getToken(BasicParser::End, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::IfStmtContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::IfStmtContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> BasicParser::IfStmtContext::ElseIf() {
  return getTokens(BasicParser::ElseIf);
}

tree::TerminalNode* BasicParser::IfStmtContext::ElseIf(size_t i) {
  return getToken(BasicParser::ElseIf, i);
}

tree::TerminalNode* BasicParser::IfStmtContext::Else() {
  return getToken(BasicParser::Else, 0);
}


size_t BasicParser::IfStmtContext::getRuleIndex() const {
  return BasicParser::RuleIfStmt;
}


antlrcpp::Any BasicParser::IfStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitIfStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::IfStmtContext* BasicParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, BasicParser::RuleIfStmt);
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
    setState(113);
    match(BasicParser::If);
    setState(114);
    exp(0);
    setState(115);
    match(BasicParser::Then);
    setState(119);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(116);
      statement();
      setState(121);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(133);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::ElseIf) {
      setState(122);
      match(BasicParser::ElseIf);
      setState(123);
      exp(0);
      setState(124);
      match(BasicParser::Then);
      setState(128);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 59) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
        | (1ULL << (BasicParser::Do - 59))
        | (1ULL << (BasicParser::For - 59))
        | (1ULL << (BasicParser::If - 59)))) != 0)) {
        setState(125);
        statement();
        setState(130);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(135);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Else) {
      setState(136);
      match(BasicParser::Else);
      setState(140);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (((((_la - 59) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
        | (1ULL << (BasicParser::Do - 59))
        | (1ULL << (BasicParser::For - 59))
        | (1ULL << (BasicParser::If - 59)))) != 0)) {
        setState(137);
        statement();
        setState(142);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(145);
    match(BasicParser::End);
    setState(146);
    match(BasicParser::If);
   
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

tree::TerminalNode* BasicParser::LoopStmtContext::Do() {
  return getToken(BasicParser::Do, 0);
}

tree::TerminalNode* BasicParser::LoopStmtContext::While() {
  return getToken(BasicParser::While, 0);
}

BasicParser::ExpContext* BasicParser::LoopStmtContext::exp() {
  return getRuleContext<BasicParser::ExpContext>(0);
}

tree::TerminalNode* BasicParser::LoopStmtContext::Loop() {
  return getToken(BasicParser::Loop, 0);
}

BasicParser::LoopBodyContext* BasicParser::LoopStmtContext::loopBody() {
  return getRuleContext<BasicParser::LoopBodyContext>(0);
}

tree::TerminalNode* BasicParser::LoopStmtContext::Until() {
  return getToken(BasicParser::Until, 0);
}

tree::TerminalNode* BasicParser::LoopStmtContext::Wend() {
  return getToken(BasicParser::Wend, 0);
}


size_t BasicParser::LoopStmtContext::getRuleIndex() const {
  return BasicParser::RuleLoopStmt;
}


antlrcpp::Any BasicParser::LoopStmtContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLoopStmt(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::LoopStmtContext* BasicParser::loopStmt() {
  LoopStmtContext *_localctx = _tracker.createInstance<LoopStmtContext>(_ctx, getState());
  enterRule(_localctx, 12, BasicParser::RuleLoopStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(185);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(148);
      match(BasicParser::Do);
      setState(149);
      match(BasicParser::While);
      setState(150);
      exp(0);
      setState(152);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (BasicParser::Exit - 58))
        | (1ULL << (BasicParser::While - 58))
        | (1ULL << (BasicParser::Do - 58))
        | (1ULL << (BasicParser::For - 58))
        | (1ULL << (BasicParser::If - 58)))) != 0)) {
        setState(151);
        loopBody();
      }
      setState(154);
      match(BasicParser::Loop);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(156);
      match(BasicParser::Do);
      setState(157);
      match(BasicParser::Until);
      setState(158);
      exp(0);
      setState(160);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (BasicParser::Exit - 58))
        | (1ULL << (BasicParser::While - 58))
        | (1ULL << (BasicParser::Do - 58))
        | (1ULL << (BasicParser::For - 58))
        | (1ULL << (BasicParser::If - 58)))) != 0)) {
        setState(159);
        loopBody();
      }
      setState(162);
      match(BasicParser::Loop);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(164);
      match(BasicParser::Do);
      setState(166);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (BasicParser::Exit - 58))
        | (1ULL << (BasicParser::While - 58))
        | (1ULL << (BasicParser::Do - 58))
        | (1ULL << (BasicParser::For - 58))
        | (1ULL << (BasicParser::If - 58)))) != 0)) {
        setState(165);
        loopBody();
      }
      setState(168);
      match(BasicParser::Loop);
      setState(169);
      match(BasicParser::Until);
      setState(170);
      exp(0);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(171);
      match(BasicParser::Do);
      setState(173);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (BasicParser::Exit - 58))
        | (1ULL << (BasicParser::While - 58))
        | (1ULL << (BasicParser::Do - 58))
        | (1ULL << (BasicParser::For - 58))
        | (1ULL << (BasicParser::If - 58)))) != 0)) {
        setState(172);
        loopBody();
      }
      setState(175);
      match(BasicParser::Loop);
      setState(176);
      match(BasicParser::While);
      setState(177);
      exp(0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(178);
      match(BasicParser::While);
      setState(179);
      exp(0);
      setState(181);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 58) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 58)) & ((1ULL << (BasicParser::Exit - 58))
        | (1ULL << (BasicParser::While - 58))
        | (1ULL << (BasicParser::Do - 58))
        | (1ULL << (BasicParser::For - 58))
        | (1ULL << (BasicParser::If - 58)))) != 0)) {
        setState(180);
        loopBody();
      }
      setState(183);
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

//----------------- LoopBodyContext ------------------------------------------------------------------

BasicParser::LoopBodyContext::LoopBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::LoopBodyContext::Exit() {
  return getToken(BasicParser::Exit, 0);
}

tree::TerminalNode* BasicParser::LoopBodyContext::Do() {
  return getToken(BasicParser::Do, 0);
}

std::vector<BasicParser::StatementContext *> BasicParser::LoopBodyContext::statement() {
  return getRuleContexts<BasicParser::StatementContext>();
}

BasicParser::StatementContext* BasicParser::LoopBodyContext::statement(size_t i) {
  return getRuleContext<BasicParser::StatementContext>(i);
}


size_t BasicParser::LoopBodyContext::getRuleIndex() const {
  return BasicParser::RuleLoopBody;
}


antlrcpp::Any BasicParser::LoopBodyContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<BasicVisitor*>(visitor))
    return parserVisitor->visitLoopBody(this);
  else
    return visitor->visitChildren(this);
}

BasicParser::LoopBodyContext* BasicParser::loopBody() {
  LoopBodyContext *_localctx = _tracker.createInstance<LoopBodyContext>(_ctx, getState());
  enterRule(_localctx, 14, BasicParser::RuleLoopBody);
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
    setState(190);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(187);
      statement();
      setState(192);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(193);
    match(BasicParser::Exit);
    setState(194);
    match(BasicParser::Do);
    setState(198);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (((((_la - 59) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 59)) & ((1ULL << (BasicParser::While - 59))
      | (1ULL << (BasicParser::Do - 59))
      | (1ULL << (BasicParser::For - 59))
      | (1ULL << (BasicParser::If - 59)))) != 0)) {
      setState(195);
      statement();
      setState(200);
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

bool BasicParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 2: return expSempred(dynamic_cast<ExpContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool BasicParser::expSempred(ExpContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 11);
    case 1: return precpred(_ctx, 10);
    case 2: return precpred(_ctx, 9);
    case 3: return precpred(_ctx, 8);
    case 4: return precpred(_ctx, 7);
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
  "statements", "statement", "exp", "forStmt", "foreachStmt", "ifStmt", 
  "loopStmt", "loopBody"
};

std::vector<std::string> BasicParser::_literalNames = {
  "", "'-'", "'~'", "'&'", "'|'", "'^'", "'mod'", "'*'", "'/'", "'\\'", 
  "'+'", "'='", "'>'", "'<'", "'<='", "'<>'", "'>='", "'and'", "'or'", "'not'", 
  "'xor'", "'('", "')'"
};

std::vector<std::string> BasicParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "Number", "String", "Boolean", "Comment", "BlockComment", 
  "WS", "ElseIf", "Wend", "From", "Import", "Namespace", "Implement", "Type", 
  "Alias", "Self", "Static", "Module", "Public", "Private", "Protected", 
  "Get", "Set", "Property", "Var", "Dim", "Let", "Return", "Function", "Difference", 
  "Union", "Case", "Select", "End", "Until", "Loop", "Exit", "While", "Do", 
  "Each", "To", "Step", "Next", "In", "For", "Optional", "Byval", "Byref", 
  "If", "Then", "Else", "Call", "Sub", "As", "ID"
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
    0x3, 0x4e, 0xcc, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x7, 0x2, 0x14, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x17, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x1c, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 
    0x29, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x3d, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x40, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x49, 0xa, 0x5, 
    0xc, 0x5, 0xe, 0x5, 0x4c, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x50, 
    0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 0x53, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x56, 
    0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x62, 0xa, 0x6, 0xc, 
    0x6, 0xe, 0x6, 0x65, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x69, 0xa, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x6c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x6f, 0xb, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x7, 0x7, 0x78, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x7b, 0xb, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x81, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0x84, 0xb, 0x7, 0x7, 0x7, 0x86, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0x89, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x8d, 0xa, 0x7, 0xc, 0x7, 
    0xe, 0x7, 0x90, 0xb, 0x7, 0x5, 0x7, 0x92, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9b, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0xa3, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0xa9, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 
    0x8, 0xb0, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x5, 0x8, 0xb8, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0xbc, 
    0xa, 0x8, 0x3, 0x9, 0x7, 0x9, 0xbf, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xc2, 
    0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xc7, 0xa, 0x9, 0xc, 
    0x9, 0xe, 0x9, 0xca, 0xb, 0x9, 0x3, 0x9, 0x2, 0x3, 0x6, 0xa, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x2, 0x8, 0x3, 0x2, 0x4, 0x6, 0x3, 0x2, 
    0x7, 0x8, 0x3, 0x2, 0x9, 0xb, 0x4, 0x2, 0x3, 0x3, 0xc, 0xc, 0x3, 0x2, 
    0xd, 0x12, 0x3, 0x2, 0x13, 0x16, 0x2, 0xe7, 0x2, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x6, 0x28, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x41, 0x3, 0x2, 0x2, 0x2, 0xa, 0x5a, 0x3, 0x2, 0x2, 0x2, 0xc, 0x73, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x10, 0xc0, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x14, 0x5, 0x4, 0x3, 0x2, 0x13, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x18, 0x1c, 0x5, 0x8, 0x5, 0x2, 0x19, 
    0x1c, 0x5, 0xe, 0x8, 0x2, 0x1a, 0x1c, 0x5, 0xc, 0x7, 0x2, 0x1b, 0x18, 
    0x3, 0x2, 0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x1b, 0x1a, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0x5, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1e, 0x8, 0x4, 
    0x1, 0x2, 0x1e, 0x1f, 0x7, 0x3, 0x2, 0x2, 0x1f, 0x29, 0x5, 0x6, 0x4, 
    0xe, 0x20, 0x21, 0x7, 0x17, 0x2, 0x2, 0x21, 0x22, 0x5, 0x6, 0x4, 0x2, 
    0x22, 0x23, 0x7, 0x18, 0x2, 0x2, 0x23, 0x29, 0x3, 0x2, 0x2, 0x2, 0x24, 
    0x29, 0x7, 0x19, 0x2, 0x2, 0x25, 0x29, 0x7, 0x1a, 0x2, 0x2, 0x26, 0x29, 
    0x7, 0x4e, 0x2, 0x2, 0x27, 0x29, 0x7, 0x1b, 0x2, 0x2, 0x28, 0x1d, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x20, 0x3, 0x2, 0x2, 0x2, 0x28, 0x24, 0x3, 0x2, 
    0x2, 0x2, 0x28, 0x25, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 0x2, 0x2, 
    0x2, 0x28, 0x27, 0x3, 0x2, 0x2, 0x2, 0x29, 0x3e, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2b, 0xc, 0xd, 0x2, 0x2, 0x2b, 0x2c, 0x9, 0x2, 0x2, 0x2, 0x2c, 
    0x3d, 0x5, 0x6, 0x4, 0xe, 0x2d, 0x2e, 0xc, 0xc, 0x2, 0x2, 0x2e, 0x2f, 
    0x9, 0x3, 0x2, 0x2, 0x2f, 0x3d, 0x5, 0x6, 0x4, 0xd, 0x30, 0x31, 0xc, 
    0xb, 0x2, 0x2, 0x31, 0x32, 0x9, 0x4, 0x2, 0x2, 0x32, 0x3d, 0x5, 0x6, 
    0x4, 0xc, 0x33, 0x34, 0xc, 0xa, 0x2, 0x2, 0x34, 0x35, 0x9, 0x5, 0x2, 
    0x2, 0x35, 0x3d, 0x5, 0x6, 0x4, 0xb, 0x36, 0x37, 0xc, 0x9, 0x2, 0x2, 
    0x37, 0x38, 0x9, 0x6, 0x2, 0x2, 0x38, 0x3d, 0x5, 0x6, 0x4, 0xa, 0x39, 
    0x3a, 0xc, 0x8, 0x2, 0x2, 0x3a, 0x3b, 0x9, 0x7, 0x2, 0x2, 0x3b, 0x3d, 
    0x5, 0x6, 0x4, 0x9, 0x3c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x2d, 0x3, 
    0x2, 0x2, 0x2, 0x3c, 0x30, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x33, 0x3, 0x2, 
    0x2, 0x2, 0x3c, 0x36, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x39, 0x3, 0x2, 0x2, 
    0x2, 0x3d, 0x40, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x3c, 0x3, 0x2, 0x2, 0x2, 
    0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x40, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x41, 0x42, 0x7, 0x44, 0x2, 0x2, 0x42, 0x43, 
    0x5, 0x6, 0x4, 0x2, 0x43, 0x44, 0x7, 0x40, 0x2, 0x2, 0x44, 0x45, 0x5, 
    0x6, 0x4, 0x2, 0x45, 0x46, 0x7, 0x41, 0x2, 0x2, 0x46, 0x4a, 0x5, 0x6, 
    0x4, 0x2, 0x47, 0x49, 0x5, 0x4, 0x3, 0x2, 0x48, 0x47, 0x3, 0x2, 0x2, 
    0x2, 0x49, 0x4c, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x48, 0x3, 0x2, 0x2, 0x2, 
    0x4a, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x4c, 
    0x4a, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x7, 0x3c, 0x2, 0x2, 0x4e, 0x50, 
    0x7, 0x44, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x50, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x54, 0x3, 0x2, 0x2, 0x2, 0x51, 0x53, 0x5, 0x4, 
    0x3, 0x2, 0x52, 0x51, 0x3, 0x2, 0x2, 0x2, 0x53, 0x56, 0x3, 0x2, 0x2, 
    0x2, 0x54, 0x52, 0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 
    0x55, 0x57, 0x3, 0x2, 0x2, 0x2, 0x56, 0x54, 0x3, 0x2, 0x2, 0x2, 0x57, 
    0x58, 0x7, 0x42, 0x2, 0x2, 0x58, 0x59, 0x5, 0x6, 0x4, 0x2, 0x59, 0x9, 
    0x3, 0x2, 0x2, 0x2, 0x5a, 0x5b, 0x7, 0x44, 0x2, 0x2, 0x5b, 0x5c, 0x7, 
    0x3f, 0x2, 0x2, 0x5c, 0x5d, 0x5, 0x6, 0x4, 0x2, 0x5d, 0x5e, 0x7, 0x41, 
    0x2, 0x2, 0x5e, 0x5f, 0x7, 0x43, 0x2, 0x2, 0x5f, 0x63, 0x5, 0x6, 0x4, 
    0x2, 0x60, 0x62, 0x5, 0x4, 0x3, 0x2, 0x61, 0x60, 0x3, 0x2, 0x2, 0x2, 
    0x62, 0x65, 0x3, 0x2, 0x2, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x63, 
    0x64, 0x3, 0x2, 0x2, 0x2, 0x64, 0x68, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x67, 0x7, 0x3c, 0x2, 0x2, 0x67, 0x69, 0x7, 
    0x44, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 
    0x2, 0x2, 0x69, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6c, 0x5, 0x4, 0x3, 
    0x2, 0x6b, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x6d, 0x6b, 0x3, 0x2, 0x2, 0x2, 0x6d, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x6e, 
    0x70, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x6d, 0x3, 0x2, 0x2, 0x2, 0x70, 0x71, 
    0x7, 0x42, 0x2, 0x2, 0x71, 0x72, 0x5, 0x6, 0x4, 0x2, 0x72, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x73, 0x74, 0x7, 0x48, 0x2, 0x2, 0x74, 0x75, 0x5, 0x6, 
    0x4, 0x2, 0x75, 0x79, 0x7, 0x49, 0x2, 0x2, 0x76, 0x78, 0x5, 0x4, 0x3, 
    0x2, 0x77, 0x76, 0x3, 0x2, 0x2, 0x2, 0x78, 0x7b, 0x3, 0x2, 0x2, 0x2, 
    0x79, 0x77, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 0x2, 0x2, 0x7a, 
    0x87, 0x3, 0x2, 0x2, 0x2, 0x7b, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x7d, 
    0x7, 0x1f, 0x2, 0x2, 0x7d, 0x7e, 0x5, 0x6, 0x4, 0x2, 0x7e, 0x82, 0x7, 
    0x49, 0x2, 0x2, 0x7f, 0x81, 0x5, 0x4, 0x3, 0x2, 0x80, 0x7f, 0x3, 0x2, 
    0x2, 0x2, 0x81, 0x84, 0x3, 0x2, 0x2, 0x2, 0x82, 0x80, 0x3, 0x2, 0x2, 
    0x2, 0x82, 0x83, 0x3, 0x2, 0x2, 0x2, 0x83, 0x86, 0x3, 0x2, 0x2, 0x2, 
    0x84, 0x82, 0x3, 0x2, 0x2, 0x2, 0x85, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x86, 
    0x89, 0x3, 0x2, 0x2, 0x2, 0x87, 0x85, 0x3, 0x2, 0x2, 0x2, 0x87, 0x88, 
    0x3, 0x2, 0x2, 0x2, 0x88, 0x91, 0x3, 0x2, 0x2, 0x2, 0x89, 0x87, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x8e, 0x7, 0x4a, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x4, 
    0x3, 0x2, 0x8c, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 
    0x2, 0x8e, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x92, 0x3, 0x2, 0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 
    0x8a, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x93, 0x94, 0x7, 0x39, 0x2, 0x2, 0x94, 0x95, 0x7, 
    0x48, 0x2, 0x2, 0x95, 0xd, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x7, 0x3e, 
    0x2, 0x2, 0x97, 0x98, 0x7, 0x3d, 0x2, 0x2, 0x98, 0x9a, 0x5, 0x6, 0x4, 
    0x2, 0x99, 0x9b, 0x5, 0x10, 0x9, 0x2, 0x9a, 0x99, 0x3, 0x2, 0x2, 0x2, 
    0x9a, 0x9b, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9d, 0x7, 0x3b, 0x2, 0x2, 0x9d, 0xbc, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 
    0x7, 0x3e, 0x2, 0x2, 0x9f, 0xa0, 0x7, 0x3a, 0x2, 0x2, 0xa0, 0xa2, 0x5, 
    0x6, 0x4, 0x2, 0xa1, 0xa3, 0x5, 0x10, 0x9, 0x2, 0xa2, 0xa1, 0x3, 0x2, 
    0x2, 0x2, 0xa2, 0xa3, 0x3, 0x2, 0x2, 0x2, 0xa3, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa4, 0xa5, 0x7, 0x3b, 0x2, 0x2, 0xa5, 0xbc, 0x3, 0x2, 0x2, 0x2, 
    0xa6, 0xa8, 0x7, 0x3e, 0x2, 0x2, 0xa7, 0xa9, 0x5, 0x10, 0x9, 0x2, 0xa8, 
    0xa7, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa9, 0xaa, 
    0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0x7, 0x3b, 0x2, 0x2, 0xab, 0xac, 0x7, 
    0x3a, 0x2, 0x2, 0xac, 0xbc, 0x5, 0x6, 0x4, 0x2, 0xad, 0xaf, 0x7, 0x3e, 
    0x2, 0x2, 0xae, 0xb0, 0x5, 0x10, 0x9, 0x2, 0xaf, 0xae, 0x3, 0x2, 0x2, 
    0x2, 0xaf, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 0x3, 0x2, 0x2, 0x2, 
    0xb1, 0xb2, 0x7, 0x3b, 0x2, 0x2, 0xb2, 0xb3, 0x7, 0x3d, 0x2, 0x2, 0xb3, 
    0xbc, 0x5, 0x6, 0x4, 0x2, 0xb4, 0xb5, 0x7, 0x3d, 0x2, 0x2, 0xb5, 0xb7, 
    0x5, 0x6, 0x4, 0x2, 0xb6, 0xb8, 0x5, 0x10, 0x9, 0x2, 0xb7, 0xb6, 0x3, 
    0x2, 0x2, 0x2, 0xb7, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb9, 0x3, 0x2, 
    0x2, 0x2, 0xb9, 0xba, 0x7, 0x20, 0x2, 0x2, 0xba, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbb, 0x96, 0x3, 0x2, 0x2, 0x2, 0xbb, 0x9e, 0x3, 0x2, 0x2, 0x2, 
    0xbb, 0xa6, 0x3, 0x2, 0x2, 0x2, 0xbb, 0xad, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xb4, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xf, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbf, 
    0x5, 0x4, 0x3, 0x2, 0xbe, 0xbd, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc2, 0x3, 
    0x2, 0x2, 0x2, 0xc0, 0xbe, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc1, 0x3, 0x2, 
    0x2, 0x2, 0xc1, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc2, 0xc0, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x7, 0x3c, 0x2, 0x2, 0xc4, 0xc8, 0x7, 0x3e, 0x2, 0x2, 
    0xc5, 0xc7, 0x5, 0x4, 0x3, 0x2, 0xc6, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc7, 
    0xca, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc6, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 
    0x3, 0x2, 0x2, 0x2, 0xc9, 0x11, 0x3, 0x2, 0x2, 0x2, 0xca, 0xc8, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x15, 0x1b, 0x28, 0x3c, 0x3e, 0x4a, 0x4f, 0x54, 
    0x63, 0x68, 0x6d, 0x79, 0x82, 0x87, 0x8e, 0x91, 0x9a, 0xa2, 0xa8, 0xaf, 
    0xb7, 0xbb, 0xc0, 0xc8, 
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
