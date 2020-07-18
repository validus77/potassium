
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_parser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"


namespace potassium {


class  potassium_parser : public antlr4::Parser {
public:
  enum {
    NEWLINE = 1, WS = 2, INTLIT = 3, FLOATLIT = 4, LET = 5, PRINT = 6, IF = 7, 
    ELSE = 8, WHILE = 9, MUT = 10, PLUS = 11, MINUS = 12, MULT = 13, DIV = 14, 
    MOD = 15, ASSIGN = 16, LPAREN = 17, RPAREN = 18, LBRACKET = 19, RBRACKET = 20, 
    AND = 21, OR = 22, EQ = 23, XOR = 24, NOT = 25, LT = 26, GT = 27, ID = 28
  };

  enum {
    RuleLine = 0, RuleStatement = 1, RuleAssignment = 2, RuleFunction_assignment = 3, 
    RulePrint = 4, RuleExpression = 5, RuleCond_expresion = 6, RuleFunction_call = 7, 
    RuleWhile_loop = 8, RuleBlock = 9
  };

  potassium_parser(antlr4::TokenStream *input);
  ~potassium_parser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class LineContext;
  class StatementContext;
  class AssignmentContext;
  class Function_assignmentContext;
  class PrintContext;
  class ExpressionContext;
  class Cond_expresionContext;
  class Function_callContext;
  class While_loopContext;
  class BlockContext; 

  class  LineContext : public antlr4::ParserRuleContext {
  public:
    LineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementContext *statement();
    antlr4::tree::TerminalNode *NEWLINE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LineContext* line();

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
   
    AssignmentContext() = default;
    void copyFrom(AssignmentContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  UpdateAssignmentContext : public AssignmentContext {
  public:
    UpdateAssignmentContext(AssignmentContext *ctx);

    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  InitialAssigmentContext : public AssignmentContext {
  public:
    InitialAssigmentContext(AssignmentContext *ctx);

    antlr4::tree::TerminalNode *LET();
    antlr4::tree::TerminalNode *ID();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *MUT();

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

  class  BlockExpressionContext : public ExpressionContext {
  public:
    BlockExpressionContext(ExpressionContext *ctx);

    BlockContext *block();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
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

  class  WhileStatmentContext : public ExpressionContext {
  public:
    WhileStatmentContext(ExpressionContext *ctx);

    While_loopContext *while_loop();

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

  class  While_loopContext : public antlr4::ParserRuleContext {
  public:
    potassium_parser::ExpressionContext *test = nullptr;;
    potassium_parser::ExpressionContext *body = nullptr;;
    While_loopContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_loopContext* while_loop();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    std::vector<antlr4::tree::TerminalNode *> NEWLINE();
    antlr4::tree::TerminalNode* NEWLINE(size_t i);
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    std::vector<AssignmentContext *> assignment();
    AssignmentContext* assignment(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();


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
