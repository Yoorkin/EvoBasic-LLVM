
// Generated from Basic.g4 by ANTLR 4.9.1


#include "BasicListener.h"

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

void BasicParser::StatementsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatements(this);
}

void BasicParser::StatementsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatements(this);
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
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
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

//----------------- ExpContext ------------------------------------------------------------------

BasicParser::ExpContext::ExpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* BasicParser::ExpContext::Number() {
  return getToken(BasicParser::Number, 0);
}


size_t BasicParser::ExpContext::getRuleIndex() const {
  return BasicParser::RuleExp;
}

void BasicParser::ExpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExp(this);
}

void BasicParser::ExpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExp(this);
}

BasicParser::ExpContext* BasicParser::exp() {
  ExpContext *_localctx = _tracker.createInstance<ExpContext>(_ctx, getState());
  enterRule(_localctx, 2, BasicParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(22);
    match(BasicParser::Number);
   
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

void BasicParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void BasicParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

BasicParser::StatementContext* BasicParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, BasicParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(27);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::For: {
        enterOuterAlt(_localctx, 1);
        setState(24);
        forStmt();
        break;
      }

      case BasicParser::While:
      case BasicParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(25);
        loopStmt();
        break;
      }

      case BasicParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(26);
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

void BasicParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void BasicParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
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
    setState(29);
    match(BasicParser::For);
    setState(30);
    exp();
    setState(31);
    match(BasicParser::To);
    setState(32);
    exp();
    setState(33);
    match(BasicParser::Step);
    setState(34);
    exp();
    setState(38);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(35);
        statement(); 
      }
      setState(40);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
    setState(43);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(41);
      match(BasicParser::Exit);
      setState(42);
      match(BasicParser::For);
    }
    setState(48);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(45);
      statement();
      setState(50);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(51);
    match(BasicParser::Next);
    setState(52);
    exp();
   
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

void BasicParser::ForeachStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeachStmt(this);
}

void BasicParser::ForeachStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeachStmt(this);
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
    setState(54);
    match(BasicParser::For);
    setState(55);
    match(BasicParser::Each);
    setState(56);
    exp();
    setState(57);
    match(BasicParser::Step);
    setState(58);
    match(BasicParser::In);
    setState(59);
    exp();
    setState(63);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(60);
        statement(); 
      }
      setState(65);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
    setState(68);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(66);
      match(BasicParser::Exit);
      setState(67);
      match(BasicParser::For);
    }
    setState(73);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(70);
      statement();
      setState(75);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(76);
    match(BasicParser::Next);
    setState(77);
    exp();
   
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

void BasicParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void BasicParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
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
    setState(79);
    match(BasicParser::If);
    setState(80);
    exp();
    setState(81);
    match(BasicParser::Then);
    setState(85);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(82);
      statement();
      setState(87);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(99);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::ElseIf) {
      setState(88);
      match(BasicParser::ElseIf);
      setState(89);
      exp();
      setState(90);
      match(BasicParser::Then);
      setState(94);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(91);
        statement();
        setState(96);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(101);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(109);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Else) {
      setState(102);
      match(BasicParser::Else);
      setState(106);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(103);
        statement();
        setState(108);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(111);
    match(BasicParser::End);
    setState(112);
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

void BasicParser::LoopStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopStmt(this);
}

void BasicParser::LoopStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopStmt(this);
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
    setState(151);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(114);
      match(BasicParser::Do);
      setState(115);
      match(BasicParser::While);
      setState(116);
      exp();
      setState(118);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::Exit)
        | (1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(117);
        loopBody();
      }
      setState(120);
      match(BasicParser::Loop);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(122);
      match(BasicParser::Do);
      setState(123);
      match(BasicParser::Until);
      setState(124);
      exp();
      setState(126);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::Exit)
        | (1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(125);
        loopBody();
      }
      setState(128);
      match(BasicParser::Loop);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(130);
      match(BasicParser::Do);
      setState(132);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::Exit)
        | (1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(131);
        loopBody();
      }
      setState(134);
      match(BasicParser::Loop);
      setState(135);
      match(BasicParser::Until);
      setState(136);
      exp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(137);
      match(BasicParser::Do);
      setState(139);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::Exit)
        | (1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(138);
        loopBody();
      }
      setState(141);
      match(BasicParser::Loop);
      setState(142);
      match(BasicParser::While);
      setState(143);
      exp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(144);
      match(BasicParser::While);
      setState(145);
      exp();
      setState(147);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::Exit)
        | (1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(146);
        loopBody();
      }
      setState(149);
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

void BasicParser::LoopBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLoopBody(this);
}

void BasicParser::LoopBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<BasicListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLoopBody(this);
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
    setState(156);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(153);
      statement();
      setState(158);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(159);
    match(BasicParser::Exit);
    setState(160);
    match(BasicParser::Do);
    setState(164);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(161);
      statement();
      setState(166);
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

// Static vars and initialization.
std::vector<dfa::DFA> BasicParser::_decisionToDFA;
atn::PredictionContextCache BasicParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN BasicParser::_atn;
std::vector<uint16_t> BasicParser::_serializedATN;

std::vector<std::string> BasicParser::_ruleNames = {
  "statements", "exp", "statement", "forStmt", "foreachStmt", "ifStmt", 
  "loopStmt", "loopBody"
};

std::vector<std::string> BasicParser::_literalNames = {
};

std::vector<std::string> BasicParser::_symbolicNames = {
  "", "Number", "Comment", "BlockComment", "WS", "ElseIf", "Wend", "From", 
  "Import", "Namespace", "Implement", "Type", "Alias", "Self", "Static", 
  "Module", "Public", "Private", "Protected", "Get", "Set", "Property", 
  "Var", "Dim", "Let", "Return", "Function", "Difference", "Union", "Case", 
  "Select", "End", "Until", "Loop", "Exit", "While", "Do", "Each", "To", 
  "Step", "Next", "In", "For", "Optional", "Byval", "Byref", "If", "Then", 
  "Else", "Call", "Sub", "As"
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
    0x3, 0x35, 0xaa, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x3, 0x2, 0x7, 0x2, 0x14, 0xa, 0x2, 
    0xc, 0x2, 0xe, 0x2, 0x17, 0xb, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x1e, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x7, 0x5, 0x27, 0xa, 0x5, 0xc, 
    0x5, 0xe, 0x5, 0x2a, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x2e, 0xa, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x31, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x34, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x40, 0xa, 0x6, 0xc, 0x6, 
    0xe, 0x6, 0x43, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0x47, 0xa, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x4a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x4d, 0xb, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x7, 0x7, 0x56, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x59, 0xb, 0x7, 0x3, 0x7, 
    0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x5f, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x62, 0xb, 0x7, 0x7, 0x7, 0x64, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 0x67, 
    0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x6b, 0xa, 0x7, 0xc, 0x7, 0xe, 
    0x7, 0x6e, 0xb, 0x7, 0x5, 0x7, 0x70, 0xa, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x79, 0xa, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x81, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x87, 
    0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x8e, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x5, 0x8, 0x96, 0xa, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x9a, 0xa, 
    0x8, 0x3, 0x9, 0x7, 0x9, 0x9d, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0xa0, 0xb, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0xa5, 0xa, 0x9, 0xc, 0x9, 
    0xe, 0x9, 0xa8, 0xb, 0x9, 0x3, 0x9, 0x2, 0x2, 0xa, 0x2, 0x4, 0x6, 0x8, 
    0xa, 0xc, 0xe, 0x10, 0x2, 0x2, 0x2, 0xba, 0x2, 0x15, 0x3, 0x2, 0x2, 
    0x2, 0x4, 0x18, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x8, 
    0x1f, 0x3, 0x2, 0x2, 0x2, 0xa, 0x38, 0x3, 0x2, 0x2, 0x2, 0xc, 0x51, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x99, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0x14, 0x5, 0x6, 0x4, 0x2, 0x13, 0x12, 0x3, 0x2, 
    0x2, 0x2, 0x14, 0x17, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 
    0x2, 0x15, 0x16, 0x3, 0x2, 0x2, 0x2, 0x16, 0x3, 0x3, 0x2, 0x2, 0x2, 
    0x17, 0x15, 0x3, 0x2, 0x2, 0x2, 0x18, 0x19, 0x7, 0x3, 0x2, 0x2, 0x19, 
    0x5, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x1e, 0x5, 0x8, 0x5, 0x2, 0x1b, 0x1e, 
    0x5, 0xe, 0x8, 0x2, 0x1c, 0x1e, 0x5, 0xc, 0x7, 0x2, 0x1d, 0x1a, 0x3, 
    0x2, 0x2, 0x2, 0x1d, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x1d, 0x1c, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x20, 0x7, 0x2c, 0x2, 
    0x2, 0x20, 0x21, 0x5, 0x4, 0x3, 0x2, 0x21, 0x22, 0x7, 0x28, 0x2, 0x2, 
    0x22, 0x23, 0x5, 0x4, 0x3, 0x2, 0x23, 0x24, 0x7, 0x29, 0x2, 0x2, 0x24, 
    0x28, 0x5, 0x4, 0x3, 0x2, 0x25, 0x27, 0x5, 0x6, 0x4, 0x2, 0x26, 0x25, 
    0x3, 0x2, 0x2, 0x2, 0x27, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x28, 0x26, 0x3, 
    0x2, 0x2, 0x2, 0x28, 0x29, 0x3, 0x2, 0x2, 0x2, 0x29, 0x2d, 0x3, 0x2, 
    0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2c, 0x7, 0x24, 0x2, 
    0x2, 0x2c, 0x2e, 0x7, 0x2c, 0x2, 0x2, 0x2d, 0x2b, 0x3, 0x2, 0x2, 0x2, 
    0x2d, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x32, 0x3, 0x2, 0x2, 0x2, 0x2f, 
    0x31, 0x5, 0x6, 0x4, 0x2, 0x30, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x31, 0x34, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0x30, 0x3, 0x2, 0x2, 0x2, 0x32, 0x33, 0x3, 
    0x2, 0x2, 0x2, 0x33, 0x35, 0x3, 0x2, 0x2, 0x2, 0x34, 0x32, 0x3, 0x2, 
    0x2, 0x2, 0x35, 0x36, 0x7, 0x2a, 0x2, 0x2, 0x36, 0x37, 0x5, 0x4, 0x3, 
    0x2, 0x37, 0x9, 0x3, 0x2, 0x2, 0x2, 0x38, 0x39, 0x7, 0x2c, 0x2, 0x2, 
    0x39, 0x3a, 0x7, 0x27, 0x2, 0x2, 0x3a, 0x3b, 0x5, 0x4, 0x3, 0x2, 0x3b, 
    0x3c, 0x7, 0x29, 0x2, 0x2, 0x3c, 0x3d, 0x7, 0x2b, 0x2, 0x2, 0x3d, 0x41, 
    0x5, 0x4, 0x3, 0x2, 0x3e, 0x40, 0x5, 0x6, 0x4, 0x2, 0x3f, 0x3e, 0x3, 
    0x2, 0x2, 0x2, 0x40, 0x43, 0x3, 0x2, 0x2, 0x2, 0x41, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x41, 0x42, 0x3, 0x2, 0x2, 0x2, 0x42, 0x46, 0x3, 0x2, 0x2, 
    0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x44, 0x45, 0x7, 0x24, 0x2, 0x2, 
    0x45, 0x47, 0x7, 0x2c, 0x2, 0x2, 0x46, 0x44, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x47, 0x3, 0x2, 0x2, 0x2, 0x47, 0x4b, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 
    0x5, 0x6, 0x4, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4d, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x4e, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4b, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x4f, 0x7, 0x2a, 0x2, 0x2, 0x4f, 0x50, 0x5, 0x4, 0x3, 0x2, 
    0x50, 0xb, 0x3, 0x2, 0x2, 0x2, 0x51, 0x52, 0x7, 0x30, 0x2, 0x2, 0x52, 
    0x53, 0x5, 0x4, 0x3, 0x2, 0x53, 0x57, 0x7, 0x31, 0x2, 0x2, 0x54, 0x56, 
    0x5, 0x6, 0x4, 0x2, 0x55, 0x54, 0x3, 0x2, 0x2, 0x2, 0x56, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x57, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x58, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x65, 0x3, 0x2, 0x2, 0x2, 0x59, 0x57, 0x3, 0x2, 0x2, 
    0x2, 0x5a, 0x5b, 0x7, 0x7, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0x4, 0x3, 0x2, 
    0x5c, 0x60, 0x7, 0x31, 0x2, 0x2, 0x5d, 0x5f, 0x5, 0x6, 0x4, 0x2, 0x5e, 
    0x5d, 0x3, 0x2, 0x2, 0x2, 0x5f, 0x62, 0x3, 0x2, 0x2, 0x2, 0x60, 0x5e, 
    0x3, 0x2, 0x2, 0x2, 0x60, 0x61, 0x3, 0x2, 0x2, 0x2, 0x61, 0x64, 0x3, 
    0x2, 0x2, 0x2, 0x62, 0x60, 0x3, 0x2, 0x2, 0x2, 0x63, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 0x66, 0x6f, 0x3, 0x2, 0x2, 0x2, 
    0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 0x6c, 0x7, 0x32, 0x2, 0x2, 0x69, 
    0x6b, 0x5, 0x6, 0x4, 0x2, 0x6a, 0x69, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6e, 
    0x3, 0x2, 0x2, 0x2, 0x6c, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x6d, 0x70, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x6c, 0x3, 0x2, 
    0x2, 0x2, 0x6f, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x3, 0x2, 0x2, 
    0x2, 0x70, 0x71, 0x3, 0x2, 0x2, 0x2, 0x71, 0x72, 0x7, 0x21, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x30, 0x2, 0x2, 0x73, 0xd, 0x3, 0x2, 0x2, 0x2, 0x74, 
    0x75, 0x7, 0x26, 0x2, 0x2, 0x75, 0x76, 0x7, 0x25, 0x2, 0x2, 0x76, 0x78, 
    0x5, 0x4, 0x3, 0x2, 0x77, 0x79, 0x5, 0x10, 0x9, 0x2, 0x78, 0x77, 0x3, 
    0x2, 0x2, 0x2, 0x78, 0x79, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x3, 0x2, 
    0x2, 0x2, 0x7a, 0x7b, 0x7, 0x23, 0x2, 0x2, 0x7b, 0x9a, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x7, 0x26, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x22, 0x2, 0x2, 
    0x7e, 0x80, 0x5, 0x4, 0x3, 0x2, 0x7f, 0x81, 0x5, 0x10, 0x9, 0x2, 0x80, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x83, 0x7, 0x23, 0x2, 0x2, 0x83, 0x9a, 0x3, 
    0x2, 0x2, 0x2, 0x84, 0x86, 0x7, 0x26, 0x2, 0x2, 0x85, 0x87, 0x5, 0x10, 
    0x9, 0x2, 0x86, 0x85, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 
    0x2, 0x87, 0x88, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x7, 0x23, 0x2, 0x2, 
    0x89, 0x8a, 0x7, 0x22, 0x2, 0x2, 0x8a, 0x9a, 0x5, 0x4, 0x3, 0x2, 0x8b, 
    0x8d, 0x7, 0x26, 0x2, 0x2, 0x8c, 0x8e, 0x5, 0x10, 0x9, 0x2, 0x8d, 0x8c, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0x8f, 0x90, 0x7, 0x23, 0x2, 0x2, 0x90, 0x91, 0x7, 0x25, 
    0x2, 0x2, 0x91, 0x9a, 0x5, 0x4, 0x3, 0x2, 0x92, 0x93, 0x7, 0x25, 0x2, 
    0x2, 0x93, 0x95, 0x5, 0x4, 0x3, 0x2, 0x94, 0x96, 0x5, 0x10, 0x9, 0x2, 
    0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x98, 0x7, 0x8, 0x2, 0x2, 0x98, 0x9a, 
    0x3, 0x2, 0x2, 0x2, 0x99, 0x74, 0x3, 0x2, 0x2, 0x2, 0x99, 0x7c, 0x3, 
    0x2, 0x2, 0x2, 0x99, 0x84, 0x3, 0x2, 0x2, 0x2, 0x99, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x99, 0x92, 0x3, 0x2, 0x2, 0x2, 0x9a, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x9b, 0x9d, 0x5, 0x6, 0x4, 0x2, 0x9c, 0x9b, 0x3, 0x2, 0x2, 0x2, 
    0x9d, 0xa0, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9e, 
    0x9f, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9e, 
    0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x7, 0x24, 0x2, 0x2, 0xa2, 0xa6, 0x7, 
    0x26, 0x2, 0x2, 0xa3, 0xa5, 0x5, 0x6, 0x4, 0x2, 0xa4, 0xa3, 0x3, 0x2, 
    0x2, 0x2, 0xa5, 0xa8, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 
    0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 0x2, 0xa7, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x17, 0x15, 0x1d, 0x28, 0x2d, 0x32, 
    0x41, 0x46, 0x4b, 0x57, 0x60, 0x65, 0x6c, 0x6f, 0x78, 0x80, 0x86, 0x8d, 
    0x95, 0x99, 0x9e, 0xa6, 
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
