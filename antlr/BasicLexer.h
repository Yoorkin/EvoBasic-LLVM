
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, T__24 = 25, Number = 26, 
    String = 27, Boolean = 28, Comment = 29, BlockComment = 30, LineEnd = 31, 
    WS = 32, If = 33, ElseIf = 34, Wend = 35, From = 36, Import = 37, Namespace = 38, 
    Implement = 39, Type = 40, Alias = 41, Self = 42, Static = 43, Module = 44, 
    Public = 45, Private = 46, Protected = 47, Get = 48, Set = 49, Property = 50, 
    Var = 51, Dim = 52, Let = 53, Return = 54, Function = 55, Difference = 56, 
    Union = 57, Case = 58, Select = 59, End = 60, Until = 61, Loop = 62, 
    Exit = 63, While = 64, Do = 65, Each = 66, To = 67, Step = 68, Next = 69, 
    In = 70, For = 71, Optional = 72, Byval = 73, Byref = 74, Then = 75, 
    Else = 76, Call = 77, Sub = 78, As = 79, ID = 80
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

