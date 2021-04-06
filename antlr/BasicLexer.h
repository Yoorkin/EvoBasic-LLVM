
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
public:
  enum {
    Number = 1, WS = 2, ElseIf = 3, Wend = 4, From = 5, Import = 6, Namespace = 7, 
    Implement = 8, Type = 9, Alias = 10, Self = 11, Static = 12, Module = 13, 
    Public = 14, Private = 15, Protected = 16, Get = 17, Set = 18, Property = 19, 
    Var = 20, Dim = 21, Let = 22, Return = 23, Function = 24, Difference = 25, 
    Union = 26, Case = 27, Select = 28, End = 29, Until = 30, Loop = 31, 
    Exit = 32, While = 33, Do = 34, Each = 35, To = 36, Step = 37, Next = 38, 
    In = 39, For = 40, Optional = 41, Byval = 42, Byref = 43, If = 44, Then = 45, 
    Else = 46, Call = 47, Sub = 48, As = 49
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

