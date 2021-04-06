
// Generated from Basic.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"




class  BasicLexer : public antlr4::Lexer {
public:
  enum {
    Number = 1, Comment = 2, BlockComment = 3, WS = 4, ElseIf = 5, Wend = 6, 
    From = 7, Import = 8, Namespace = 9, Implement = 10, Type = 11, Alias = 12, 
    Self = 13, Static = 14, Module = 15, Public = 16, Private = 17, Protected = 18, 
    Get = 19, Set = 20, Property = 21, Var = 22, Dim = 23, Let = 24, Return = 25, 
    Function = 26, Difference = 27, Union = 28, Case = 29, Select = 30, 
    End = 31, Until = 32, Loop = 33, Exit = 34, While = 35, Do = 36, Each = 37, 
    To = 38, Step = 39, Next = 40, In = 41, For = 42, Optional = 43, Byval = 44, 
    Byref = 45, If = 46, Then = 47, Else = 48, Call = 49, Sub = 50, As = 51
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

