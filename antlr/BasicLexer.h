
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
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
    If = 70, Then = 71, Else = 72, Call = 73, Sub = 74, As = 75
  };

  explicit BasicLexer(antlr4::CharStream *input);
  ~BasicLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

