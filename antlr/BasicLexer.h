
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
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

