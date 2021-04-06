
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
  enterRule(_localctx, 0, BasicParser::RuleExp);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
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
  enterRule(_localctx, 2, BasicParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(19);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case BasicParser::For: {
        enterOuterAlt(_localctx, 1);
        setState(16);
        forStmt();
        break;
      }

      case BasicParser::While:
      case BasicParser::Do: {
        enterOuterAlt(_localctx, 2);
        setState(17);
        loopStmt();
        break;
      }

      case BasicParser::If: {
        enterOuterAlt(_localctx, 3);
        setState(18);
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
  enterRule(_localctx, 4, BasicParser::RuleForStmt);
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
    setState(21);
    match(BasicParser::For);
    setState(22);
    exp();
    setState(23);
    match(BasicParser::To);
    setState(24);
    exp();
    setState(25);
    match(BasicParser::Step);
    setState(26);
    exp();
    setState(30);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(27);
        statement(); 
      }
      setState(32);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx);
    }
    setState(35);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(33);
      match(BasicParser::Exit);
      setState(34);
      match(BasicParser::For);
    }
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(37);
      statement();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(43);
    match(BasicParser::Next);
    setState(44);
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
  enterRule(_localctx, 6, BasicParser::RuleForeachStmt);
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
    setState(46);
    match(BasicParser::For);
    setState(47);
    match(BasicParser::Each);
    setState(48);
    exp();
    setState(49);
    match(BasicParser::Step);
    setState(50);
    match(BasicParser::In);
    setState(51);
    exp();
    setState(55);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(52);
        statement(); 
      }
      setState(57);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
    setState(60);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Exit) {
      setState(58);
      match(BasicParser::Exit);
      setState(59);
      match(BasicParser::For);
    }
    setState(65);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(62);
      statement();
      setState(67);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(68);
    match(BasicParser::Next);
    setState(69);
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
  enterRule(_localctx, 8, BasicParser::RuleIfStmt);
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
    setState(71);
    match(BasicParser::If);
    setState(72);
    exp();
    setState(73);
    match(BasicParser::Then);
    setState(77);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(74);
      statement();
      setState(79);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(91);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == BasicParser::ElseIf) {
      setState(80);
      match(BasicParser::ElseIf);
      setState(81);
      exp();
      setState(82);
      match(BasicParser::Then);
      setState(86);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(83);
        statement();
        setState(88);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(93);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(101);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == BasicParser::Else) {
      setState(94);
      match(BasicParser::Else);
      setState(98);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << BasicParser::While)
        | (1ULL << BasicParser::Do)
        | (1ULL << BasicParser::For)
        | (1ULL << BasicParser::If))) != 0)) {
        setState(95);
        statement();
        setState(100);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
    }
    setState(103);
    match(BasicParser::End);
    setState(104);
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

BasicParser::LoopBodyContext* BasicParser::LoopStmtContext::loopBody() {
  return getRuleContext<BasicParser::LoopBodyContext>(0);
}

tree::TerminalNode* BasicParser::LoopStmtContext::Loop() {
  return getToken(BasicParser::Loop, 0);
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
  enterRule(_localctx, 10, BasicParser::RuleLoopStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(135);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(106);
      match(BasicParser::Do);
      setState(107);
      match(BasicParser::While);
      setState(108);
      exp();
      setState(109);
      loopBody();
      setState(110);
      match(BasicParser::Loop);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(112);
      match(BasicParser::Do);
      setState(113);
      match(BasicParser::Until);
      setState(114);
      exp();
      setState(115);
      loopBody();
      setState(116);
      match(BasicParser::Loop);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(118);
      match(BasicParser::Do);
      setState(119);
      loopBody();
      setState(120);
      match(BasicParser::Loop);
      setState(121);
      match(BasicParser::Until);
      setState(122);
      exp();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(124);
      match(BasicParser::Do);
      setState(125);
      loopBody();
      setState(126);
      match(BasicParser::Loop);
      setState(127);
      match(BasicParser::While);
      setState(128);
      exp();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(130);
      match(BasicParser::While);
      setState(131);
      exp();
      setState(132);
      loopBody();
      setState(133);
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
  enterRule(_localctx, 12, BasicParser::RuleLoopBody);
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
    setState(140);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(137);
      statement();
      setState(142);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(143);
    match(BasicParser::Exit);
    setState(144);
    match(BasicParser::Do);
    setState(148);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << BasicParser::While)
      | (1ULL << BasicParser::Do)
      | (1ULL << BasicParser::For)
      | (1ULL << BasicParser::If))) != 0)) {
      setState(145);
      statement();
      setState(150);
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
  "exp", "statement", "forStmt", "foreachStmt", "ifStmt", "loopStmt", "loopBody"
};

std::vector<std::string> BasicParser::_literalNames = {
};

std::vector<std::string> BasicParser::_symbolicNames = {
  "", "Number", "WS", "ElseIf", "Wend", "From", "Import", "Namespace", "Implement", 
  "Type", "Alias", "Self", "Static", "Module", "Public", "Private", "Protected", 
  "Get", "Set", "Property", "Var", "Dim", "Let", "Return", "Function", "Difference", 
  "Union", "Case", "Select", "End", "Until", "Loop", "Exit", "While", "Do", 
  "Each", "To", "Step", "Next", "In", "For", "Optional", "Byval", "Byref", 
  "If", "Then", "Else", "Call", "Sub", "As"
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
    0x3, 0x33, 0x9a, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 
    0x3, 0x16, 0xa, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x1f, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x22, 
    0xb, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x26, 0xa, 0x4, 0x3, 0x4, 0x7, 
    0x4, 0x29, 0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0x2c, 0xb, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x7, 0x5, 0x38, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x3b, 0xb, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x3f, 0xa, 0x5, 0x3, 0x5, 0x7, 0x5, 
    0x42, 0xa, 0x5, 0xc, 0x5, 0xe, 0x5, 0x45, 0xb, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0x4e, 0xa, 
    0x6, 0xc, 0x6, 0xe, 0x6, 0x51, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x57, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5a, 0xb, 0x6, 
    0x7, 0x6, 0x5c, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x5f, 0xb, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x7, 0x6, 0x63, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x66, 0xb, 0x6, 
    0x5, 0x6, 0x68, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 
    0x7, 0x8a, 0xa, 0x7, 0x3, 0x8, 0x7, 0x8, 0x8d, 0xa, 0x8, 0xc, 0x8, 0xe, 
    0x8, 0x90, 0xb, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x95, 0xa, 
    0x8, 0xc, 0x8, 0xe, 0x8, 0x98, 0xb, 0x8, 0x3, 0x8, 0x2, 0x2, 0x9, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x2, 0x2, 0x2, 0xa5, 0x2, 0x10, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x15, 0x3, 0x2, 0x2, 0x2, 0x6, 0x17, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x30, 0x3, 0x2, 0x2, 0x2, 0xa, 0x49, 0x3, 0x2, 0x2, 0x2, 0xc, 0x89, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x10, 0x11, 0x7, 
    0x3, 0x2, 0x2, 0x11, 0x3, 0x3, 0x2, 0x2, 0x2, 0x12, 0x16, 0x5, 0x6, 
    0x4, 0x2, 0x13, 0x16, 0x5, 0xc, 0x7, 0x2, 0x14, 0x16, 0x5, 0xa, 0x6, 
    0x2, 0x15, 0x12, 0x3, 0x2, 0x2, 0x2, 0x15, 0x13, 0x3, 0x2, 0x2, 0x2, 
    0x15, 0x14, 0x3, 0x2, 0x2, 0x2, 0x16, 0x5, 0x3, 0x2, 0x2, 0x2, 0x17, 
    0x18, 0x7, 0x2a, 0x2, 0x2, 0x18, 0x19, 0x5, 0x2, 0x2, 0x2, 0x19, 0x1a, 
    0x7, 0x26, 0x2, 0x2, 0x1a, 0x1b, 0x5, 0x2, 0x2, 0x2, 0x1b, 0x1c, 0x7, 
    0x27, 0x2, 0x2, 0x1c, 0x20, 0x5, 0x2, 0x2, 0x2, 0x1d, 0x1f, 0x5, 0x4, 
    0x3, 0x2, 0x1e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x1f, 0x22, 0x3, 0x2, 0x2, 
    0x2, 0x20, 0x1e, 0x3, 0x2, 0x2, 0x2, 0x20, 0x21, 0x3, 0x2, 0x2, 0x2, 
    0x21, 0x25, 0x3, 0x2, 0x2, 0x2, 0x22, 0x20, 0x3, 0x2, 0x2, 0x2, 0x23, 
    0x24, 0x7, 0x22, 0x2, 0x2, 0x24, 0x26, 0x7, 0x2a, 0x2, 0x2, 0x25, 0x23, 
    0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x3, 0x2, 0x2, 0x2, 0x26, 0x2a, 0x3, 
    0x2, 0x2, 0x2, 0x27, 0x29, 0x5, 0x4, 0x3, 0x2, 0x28, 0x27, 0x3, 0x2, 
    0x2, 0x2, 0x29, 0x2c, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x28, 0x3, 0x2, 0x2, 
    0x2, 0x2a, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x2d, 0x3, 0x2, 0x2, 0x2, 
    0x2c, 0x2a, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2e, 0x7, 0x28, 0x2, 0x2, 0x2e, 
    0x2f, 0x5, 0x2, 0x2, 0x2, 0x2f, 0x7, 0x3, 0x2, 0x2, 0x2, 0x30, 0x31, 
    0x7, 0x2a, 0x2, 0x2, 0x31, 0x32, 0x7, 0x25, 0x2, 0x2, 0x32, 0x33, 0x5, 
    0x2, 0x2, 0x2, 0x33, 0x34, 0x7, 0x27, 0x2, 0x2, 0x34, 0x35, 0x7, 0x29, 
    0x2, 0x2, 0x35, 0x39, 0x5, 0x2, 0x2, 0x2, 0x36, 0x38, 0x5, 0x4, 0x3, 
    0x2, 0x37, 0x36, 0x3, 0x2, 0x2, 0x2, 0x38, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x39, 0x37, 0x3, 0x2, 0x2, 0x2, 0x39, 0x3a, 0x3, 0x2, 0x2, 0x2, 0x3a, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x3b, 0x39, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 
    0x7, 0x22, 0x2, 0x2, 0x3d, 0x3f, 0x7, 0x2a, 0x2, 0x2, 0x3e, 0x3c, 0x3, 
    0x2, 0x2, 0x2, 0x3e, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x3f, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x40, 0x42, 0x5, 0x4, 0x3, 0x2, 0x41, 0x40, 0x3, 0x2, 0x2, 
    0x2, 0x42, 0x45, 0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 
    0x43, 0x44, 0x3, 0x2, 0x2, 0x2, 0x44, 0x46, 0x3, 0x2, 0x2, 0x2, 0x45, 
    0x43, 0x3, 0x2, 0x2, 0x2, 0x46, 0x47, 0x7, 0x28, 0x2, 0x2, 0x47, 0x48, 
    0x5, 0x2, 0x2, 0x2, 0x48, 0x9, 0x3, 0x2, 0x2, 0x2, 0x49, 0x4a, 0x7, 
    0x2e, 0x2, 0x2, 0x4a, 0x4b, 0x5, 0x2, 0x2, 0x2, 0x4b, 0x4f, 0x7, 0x2f, 
    0x2, 0x2, 0x4c, 0x4e, 0x5, 0x4, 0x3, 0x2, 0x4d, 0x4c, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x51, 0x3, 0x2, 0x2, 0x2, 0x4f, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x4f, 0x50, 0x3, 0x2, 0x2, 0x2, 0x50, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x51, 
    0x4f, 0x3, 0x2, 0x2, 0x2, 0x52, 0x53, 0x7, 0x5, 0x2, 0x2, 0x53, 0x54, 
    0x5, 0x2, 0x2, 0x2, 0x54, 0x58, 0x7, 0x2f, 0x2, 0x2, 0x55, 0x57, 0x5, 
    0x4, 0x3, 0x2, 0x56, 0x55, 0x3, 0x2, 0x2, 0x2, 0x57, 0x5a, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x56, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5c, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x58, 0x3, 0x2, 0x2, 0x2, 
    0x5b, 0x52, 0x3, 0x2, 0x2, 0x2, 0x5c, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x5d, 
    0x5b, 0x3, 0x2, 0x2, 0x2, 0x5d, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x67, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x60, 0x64, 0x7, 
    0x30, 0x2, 0x2, 0x61, 0x63, 0x5, 0x4, 0x3, 0x2, 0x62, 0x61, 0x3, 0x2, 
    0x2, 0x2, 0x63, 0x66, 0x3, 0x2, 0x2, 0x2, 0x64, 0x62, 0x3, 0x2, 0x2, 
    0x2, 0x64, 0x65, 0x3, 0x2, 0x2, 0x2, 0x65, 0x68, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x64, 0x3, 0x2, 0x2, 0x2, 0x67, 0x60, 0x3, 0x2, 0x2, 0x2, 0x67, 
    0x68, 0x3, 0x2, 0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 
    0x7, 0x1f, 0x2, 0x2, 0x6a, 0x6b, 0x7, 0x2e, 0x2, 0x2, 0x6b, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x6c, 0x6d, 0x7, 0x24, 0x2, 0x2, 0x6d, 0x6e, 0x7, 0x23, 
    0x2, 0x2, 0x6e, 0x6f, 0x5, 0x2, 0x2, 0x2, 0x6f, 0x70, 0x5, 0xe, 0x8, 
    0x2, 0x70, 0x71, 0x7, 0x21, 0x2, 0x2, 0x71, 0x8a, 0x3, 0x2, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x24, 0x2, 0x2, 0x73, 0x74, 0x7, 0x20, 0x2, 0x2, 0x74, 
    0x75, 0x5, 0x2, 0x2, 0x2, 0x75, 0x76, 0x5, 0xe, 0x8, 0x2, 0x76, 0x77, 
    0x7, 0x21, 0x2, 0x2, 0x77, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x78, 0x79, 0x7, 
    0x24, 0x2, 0x2, 0x79, 0x7a, 0x5, 0xe, 0x8, 0x2, 0x7a, 0x7b, 0x7, 0x21, 
    0x2, 0x2, 0x7b, 0x7c, 0x7, 0x20, 0x2, 0x2, 0x7c, 0x7d, 0x5, 0x2, 0x2, 
    0x2, 0x7d, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 0x7, 0x24, 0x2, 0x2, 
    0x7f, 0x80, 0x5, 0xe, 0x8, 0x2, 0x80, 0x81, 0x7, 0x21, 0x2, 0x2, 0x81, 
    0x82, 0x7, 0x23, 0x2, 0x2, 0x82, 0x83, 0x5, 0x2, 0x2, 0x2, 0x83, 0x8a, 
    0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x7, 0x23, 0x2, 0x2, 0x85, 0x86, 0x5, 
    0x2, 0x2, 0x2, 0x86, 0x87, 0x5, 0xe, 0x8, 0x2, 0x87, 0x88, 0x7, 0x6, 
    0x2, 0x2, 0x88, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x89, 0x6c, 0x3, 0x2, 0x2, 
    0x2, 0x89, 0x72, 0x3, 0x2, 0x2, 0x2, 0x89, 0x78, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x89, 0x84, 0x3, 0x2, 0x2, 0x2, 0x8a, 
    0xd, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x8d, 0x5, 0x4, 0x3, 0x2, 0x8c, 0x8b, 
    0x3, 0x2, 0x2, 0x2, 0x8d, 0x90, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x8c, 0x3, 
    0x2, 0x2, 0x2, 0x8e, 0x8f, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x91, 0x3, 0x2, 
    0x2, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x92, 0x7, 0x22, 0x2, 
    0x2, 0x92, 0x96, 0x7, 0x24, 0x2, 0x2, 0x93, 0x95, 0x5, 0x4, 0x3, 0x2, 
    0x94, 0x93, 0x3, 0x2, 0x2, 0x2, 0x95, 0x98, 0x3, 0x2, 0x2, 0x2, 0x96, 
    0x94, 0x3, 0x2, 0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x98, 0x96, 0x3, 0x2, 0x2, 0x2, 0x11, 0x15, 0x20, 
    0x25, 0x2a, 0x39, 0x3e, 0x43, 0x4f, 0x58, 0x5d, 0x64, 0x67, 0x89, 0x8e, 
    0x96, 
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
