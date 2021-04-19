
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_parser.g4 by ANTLR 4.9.1

#pragma once


#include "antlr4-runtime.h"


namespace potassium {


class  potassium_parser : public antlr4::Parser {
public:
  enum {
    NEWLINE = 1, WS = 2, INTLIT = 3, FLOATLIT = 4, LET = 5, PRINT = 6, IF = 7, 
    ELSE = 8, WHILE = 9, INT = 10, FLOAT = 11, BYTE = 12, STRING = 13, PLUS = 14, 
    MINUS = 15, MULT = 16, DIV = 17, MOD = 18, ASSIGN = 19, TYPE_DEF = 20, 
    LPAREN = 21, RPAREN = 22, AND = 23, OR = 24, EQ = 25, XOR = 26, NOT = 27, 
    LT = 28, GT = 29, ID = 30
  };

  enum {
    RuleLine = 0, RuleType = 1, RuleStatement = 2, RuleAssignment = 3, RuleFunction_assignment = 4, 
    RulePrint = 5, RuleExpression = 6, RuleCond_expresion = 7, RuleFunction_call = 8
  };

  explicit potassium_parser(antlr4::TokenStream *input);
  ~potassium_parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class LineContext;
  class TypeContext;
  class StatementContext;
  class AssignmentContext;
  class Function_assignmentContext;
  class PrintContext;
  class ExpressionContext;
  class Cond_expresionContext;
  class Function_callContext; 

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

  class  TypeContext : public antlr4::ParserRuleContext {
  public:
    TypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INT();
    antlr4::tree::TerminalNode *FLOAT();
    antlr4::tree::TerminalNode *BYTE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypeContext* type();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    StatementContext() = default;
    void copyFrom(StatementContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  PrintStatmentContext : public StatementContext {
  public:
    PrintStatmentContext(StatementContext *ctx);

    PrintContext *print();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  AssigmentStantmentContext : public StatementContext {
  public:
    AssigmentStantmentContext(StatementContext *ctx);

    AssignmentContext *assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionAssigmentStantmentContext : public StatementContext {
  public:
    FunctionAssigmentStantmentContext(StatementContext *ctx);

    Function_assignmentContext *function_assignment();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  StatementContext* statement();

  class  AssignmentContext : public antlr4::ParserRuleContext {
  public:
    AssignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *TYPE_DEF();
    TypeContext *type();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentContext* assignment();

  class  Function_assignmentContext : public antlr4::ParserRuleContext {
  public:
    Function_assignmentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LET();
    std::vector<antlr4::tree::TerminalNode *> ID();
    antlr4::tree::TerminalNode* ID(size_t i);
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_assignmentContext* function_assignment();

  class  PrintContext : public antlr4::ParserRuleContext {
  public:
    PrintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PRINT();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PrintContext* print();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  LogicalBinaryOperationContext : public ExpressionContext {
  public:
    LogicalBinaryOperationContext(ExpressionContext *ctx);

    potassium_parser::ExpressionContext *left = nullptr;
    antlr4::Token *op = nullptr;
    potassium_parser::ExpressionContext *right = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *AND();
    antlr4::tree::TerminalNode *OR();
    antlr4::tree::TerminalNode *EQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CondExpressionContext : public ExpressionContext {
  public:
    CondExpressionContext(ExpressionContext *ctx);

    Cond_expresionContext *cond_expresion();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IntLiteralContext : public ExpressionContext {
  public:
    IntLiteralContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *INTLIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  LogicalUnaryOperationContext : public ExpressionContext {
  public:
    LogicalUnaryOperationContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *NOT();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FloatLiteralContext : public ExpressionContext {
  public:
    FloatLiteralContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *FLOATLIT();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenExpressionContext : public ExpressionContext {
  public:
    ParenExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryOperationContext : public ExpressionContext {
  public:
    BinaryOperationContext(ExpressionContext *ctx);

    potassium_parser::ExpressionContext *left = nullptr;
    antlr4::Token *op = nullptr;
    potassium_parser::ExpressionContext *right = nullptr;
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *MOD();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FuncCallExpressionContext : public ExpressionContext {
  public:
    FuncCallExpressionContext(ExpressionContext *ctx);

    Function_callContext *function_call();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VarReferenceContext : public ExpressionContext {
  public:
    VarReferenceContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *ID();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);
  class  Cond_expresionContext : public antlr4::ParserRuleContext {
  public:
    Cond_expresionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    Cond_expresionContext() = default;
    void copyFrom(Cond_expresionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  IfCondContext : public Cond_expresionContext {
  public:
    IfCondContext(Cond_expresionContext *ctx);

    potassium_parser::ExpressionContext *test_exp = nullptr;
    potassium_parser::ExpressionContext *then_exp = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  IfElseCondContext : public Cond_expresionContext {
  public:
    IfElseCondContext(Cond_expresionContext *ctx);

    potassium_parser::ExpressionContext *test_exp = nullptr;
    potassium_parser::ExpressionContext *then_exp = nullptr;
    potassium_parser::ExpressionContext *else_exp = nullptr;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *ELSE();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  Cond_expresionContext* cond_expresion();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

}  // namespace potassium
