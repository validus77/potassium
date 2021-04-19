
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_lexer.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace potassium {


class  potassium_lexer : public antlr4::Lexer {
public:
  enum {
    NEWLINE = 1, WS = 2, INTLIT = 3, FLOATLIT = 4, LET = 5, PRINT = 6, IF = 7, 
    ELSE = 8, WHILE = 9, INT = 10, FLOAT = 11, BYTE = 12, STRING = 13, PLUS = 14, 
    MINUS = 15, MULT = 16, DIV = 17, MOD = 18, ASSIGN = 19, TYPE_DEF = 20, 
    LPAREN = 21, RPAREN = 22, AND = 23, OR = 24, EQ = 25, XOR = 26, NOT = 27, 
    LT = 28, GT = 29, ID = 30
  };

  explicit potassium_lexer(antlr4::CharStream *input);
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
