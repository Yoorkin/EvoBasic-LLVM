
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, T__21 = 22, T__22 = 23, T__23 = 24, Number = 25, String = 26, 
    Boolean = 27, Comment = 28, BlockComment = 29, LineEnd = 30, WS = 31, 
    If = 32, ElseIf = 33, Wend = 34, From = 35, Import = 36, Namespace = 37, 
    Implement = 38, Type = 39, Alias = 40, Self = 41, Static = 42, Module = 43, 
    Public = 44, Private = 45, Protected = 46, Get = 47, Set = 48, Property = 49, 
    Var = 50, Dim = 51, Let = 52, Return = 53, Function = 54, Difference = 55, 
    Union = 56, Case = 57, Select = 58, End = 59, Until = 60, Loop = 61, 
    Exit = 62, While = 63, Do = 64, Each = 65, To = 66, Step = 67, Next = 68, 
    In = 69, For = 70, Optional = 71, Byval = 72, Byref = 73, Then = 74, 
    Else = 75, Call = 76, Sub = 77, As = 78, ID = 79
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

