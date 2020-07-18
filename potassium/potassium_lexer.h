
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_lexer.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace potassium {


class  potassium_lexer : public antlr4::Lexer {
public:
  enum {
    NEWLINE = 1, WS = 2, INTLIT = 3, FLOATLIT = 4, LET = 5, PRINT = 6, IF = 7, 
    ELSE = 8, WHILE = 9, MUT = 10, PLUS = 11, MINUS = 12, MULT = 13, DIV = 14, 
    MOD = 15, ASSIGN = 16, LPAREN = 17, RPAREN = 18, LBRACKET = 19, RBRACKET = 20, 
    AND = 21, OR = 22, EQ = 23, XOR = 24, NOT = 25, LT = 26, GT = 27, ID = 28
  };

  potassium_lexer(antlr4::CharStream *input);
  ~potassium_lexer();

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

}  // namespace potassium
