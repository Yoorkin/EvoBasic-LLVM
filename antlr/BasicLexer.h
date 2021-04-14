
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
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

