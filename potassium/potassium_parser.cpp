
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_parser.g4 by ANTLR 4.9.1


#include "potassium_parserVisitor.h"

#include "potassium_parser.h"


using namespace antlrcpp;
using namespace potassium;
using namespace antlr4;

potassium_parser::potassium_parser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

potassium_parser::~potassium_parser() {
  delete _interpreter;
}

std::string potassium_parser::getGrammarFileName() const {
  return "potassium_parser.g4";
}

const std::vector<std::string>& potassium_parser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& potassium_parser::getVocabulary() const {
  return _vocabulary;
}


//----------------- LineContext ------------------------------------------------------------------

potassium_parser::LineContext::LineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

potassium_parser::StatementContext* potassium_parser::LineContext::statement() {
  return getRuleContext<potassium_parser::StatementContext>(0);
}

tree::TerminalNode* potassium_parser::LineContext::NEWLINE() {
  return getToken(potassium_parser::NEWLINE, 0);
}


size_t potassium_parser::LineContext::getRuleIndex() const {
  return potassium_parser::RuleLine;
}


antlrcpp::Any potassium_parser::LineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitLine(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::LineContext* potassium_parser::line() {
  LineContext *_localctx = _tracker.createInstance<LineContext>(_ctx, getState());
  enterRule(_localctx, 0, potassium_parser::RuleLine);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(18);
    statement();

    setState(19);
    match(potassium_parser::NEWLINE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

potassium_parser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* potassium_parser::TypeContext::INT() {
  return getToken(potassium_parser::INT, 0);
}

tree::TerminalNode* potassium_parser::TypeContext::FLOAT() {
  return getToken(potassium_parser::FLOAT, 0);
}

tree::TerminalNode* potassium_parser::TypeContext::BYTE() {
  return getToken(potassium_parser::BYTE, 0);
}


size_t potassium_parser::TypeContext::getRuleIndex() const {
  return potassium_parser::RuleType;
}


antlrcpp::Any potassium_parser::TypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitType(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::TypeContext* potassium_parser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 2, potassium_parser::RuleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(21);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << potassium_parser::INT)
      | (1ULL << potassium_parser::FLOAT)
      | (1ULL << potassium_parser::BYTE))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

potassium_parser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t potassium_parser::StatementContext::getRuleIndex() const {
  return potassium_parser::RuleStatement;
}

void potassium_parser::StatementContext::copyFrom(StatementContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- PrintStatmentContext ------------------------------------------------------------------

potassium_parser::PrintContext* potassium_parser::PrintStatmentContext::print() {
  return getRuleContext<potassium_parser::PrintContext>(0);
}

potassium_parser::PrintStatmentContext::PrintStatmentContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::PrintStatmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitPrintStatment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- AssigmentStantmentContext ------------------------------------------------------------------

potassium_parser::AssignmentContext* potassium_parser::AssigmentStantmentContext::assignment() {
  return getRuleContext<potassium_parser::AssignmentContext>(0);
}

potassium_parser::AssigmentStantmentContext::AssigmentStantmentContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::AssigmentStantmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitAssigmentStantment(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionAssigmentStantmentContext ------------------------------------------------------------------

potassium_parser::Function_assignmentContext* potassium_parser::FunctionAssigmentStantmentContext::function_assignment() {
  return getRuleContext<potassium_parser::Function_assignmentContext>(0);
}

potassium_parser::FunctionAssigmentStantmentContext::FunctionAssigmentStantmentContext(StatementContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::FunctionAssigmentStantmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitFunctionAssigmentStantment(this);
  else
    return visitor->visitChildren(this);
}
potassium_parser::StatementContext* potassium_parser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 4, potassium_parser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(26);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<potassium_parser::AssigmentStantmentContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(23);
      assignment();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<potassium_parser::FunctionAssigmentStantmentContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(24);
      function_assignment();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<StatementContext *>(_tracker.createInstance<potassium_parser::PrintStatmentContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(25);
      print();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentContext ------------------------------------------------------------------

potassium_parser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* potassium_parser::AssignmentContext::LET() {
  return getToken(potassium_parser::LET, 0);
}

tree::TerminalNode* potassium_parser::AssignmentContext::ID() {
  return getToken(potassium_parser::ID, 0);
}

tree::TerminalNode* potassium_parser::AssignmentContext::TYPE_DEF() {
  return getToken(potassium_parser::TYPE_DEF, 0);
}

potassium_parser::TypeContext* potassium_parser::AssignmentContext::type() {
  return getRuleContext<potassium_parser::TypeContext>(0);
}

tree::TerminalNode* potassium_parser::AssignmentContext::ASSIGN() {
  return getToken(potassium_parser::ASSIGN, 0);
}

potassium_parser::ExpressionContext* potassium_parser::AssignmentContext::expression() {
  return getRuleContext<potassium_parser::ExpressionContext>(0);
}


size_t potassium_parser::AssignmentContext::getRuleIndex() const {
  return potassium_parser::RuleAssignment;
}


antlrcpp::Any potassium_parser::AssignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitAssignment(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::AssignmentContext* potassium_parser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 6, potassium_parser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(28);
    match(potassium_parser::LET);
    setState(29);
    match(potassium_parser::ID);
    setState(30);
    match(potassium_parser::TYPE_DEF);
    setState(31);
    type();
    setState(32);
    match(potassium_parser::ASSIGN);
    setState(33);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_assignmentContext ------------------------------------------------------------------

potassium_parser::Function_assignmentContext::Function_assignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* potassium_parser::Function_assignmentContext::LET() {
  return getToken(potassium_parser::LET, 0);
}

std::vector<tree::TerminalNode *> potassium_parser::Function_assignmentContext::ID() {
  return getTokens(potassium_parser::ID);
}

tree::TerminalNode* potassium_parser::Function_assignmentContext::ID(size_t i) {
  return getToken(potassium_parser::ID, i);
}

tree::TerminalNode* potassium_parser::Function_assignmentContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

tree::TerminalNode* potassium_parser::Function_assignmentContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}

tree::TerminalNode* potassium_parser::Function_assignmentContext::ASSIGN() {
  return getToken(potassium_parser::ASSIGN, 0);
}

potassium_parser::ExpressionContext* potassium_parser::Function_assignmentContext::expression() {
  return getRuleContext<potassium_parser::ExpressionContext>(0);
}


size_t potassium_parser::Function_assignmentContext::getRuleIndex() const {
  return potassium_parser::RuleFunction_assignment;
}


antlrcpp::Any potassium_parser::Function_assignmentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_assignment(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::Function_assignmentContext* potassium_parser::function_assignment() {
  Function_assignmentContext *_localctx = _tracker.createInstance<Function_assignmentContext>(_ctx, getState());
  enterRule(_localctx, 8, potassium_parser::RuleFunction_assignment);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    match(potassium_parser::LET);
    setState(36);
    match(potassium_parser::ID);
    setState(37);
    match(potassium_parser::LPAREN);
    setState(41);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == potassium_parser::ID) {
      setState(38);
      match(potassium_parser::ID);
      setState(43);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(44);
    match(potassium_parser::RPAREN);
    setState(45);
    match(potassium_parser::ASSIGN);
    setState(46);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PrintContext ------------------------------------------------------------------

potassium_parser::PrintContext::PrintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* potassium_parser::PrintContext::PRINT() {
  return getToken(potassium_parser::PRINT, 0);
}

tree::TerminalNode* potassium_parser::PrintContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

potassium_parser::ExpressionContext* potassium_parser::PrintContext::expression() {
  return getRuleContext<potassium_parser::ExpressionContext>(0);
}

tree::TerminalNode* potassium_parser::PrintContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}


size_t potassium_parser::PrintContext::getRuleIndex() const {
  return potassium_parser::RulePrint;
}


antlrcpp::Any potassium_parser::PrintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitPrint(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::PrintContext* potassium_parser::print() {
  PrintContext *_localctx = _tracker.createInstance<PrintContext>(_ctx, getState());
  enterRule(_localctx, 10, potassium_parser::RulePrint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(48);
    match(potassium_parser::PRINT);
    setState(49);
    match(potassium_parser::LPAREN);
    setState(50);
    expression(0);
    setState(51);
    match(potassium_parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

potassium_parser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t potassium_parser::ExpressionContext::getRuleIndex() const {
  return potassium_parser::RuleExpression;
}

void potassium_parser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicalBinaryOperationContext ------------------------------------------------------------------

std::vector<potassium_parser::ExpressionContext *> potassium_parser::LogicalBinaryOperationContext::expression() {
  return getRuleContexts<potassium_parser::ExpressionContext>();
}

potassium_parser::ExpressionContext* potassium_parser::LogicalBinaryOperationContext::expression(size_t i) {
  return getRuleContext<potassium_parser::ExpressionContext>(i);
}

tree::TerminalNode* potassium_parser::LogicalBinaryOperationContext::AND() {
  return getToken(potassium_parser::AND, 0);
}

tree::TerminalNode* potassium_parser::LogicalBinaryOperationContext::OR() {
  return getToken(potassium_parser::OR, 0);
}

tree::TerminalNode* potassium_parser::LogicalBinaryOperationContext::EQ() {
  return getToken(potassium_parser::EQ, 0);
}

tree::TerminalNode* potassium_parser::LogicalBinaryOperationContext::LT() {
  return getToken(potassium_parser::LT, 0);
}

tree::TerminalNode* potassium_parser::LogicalBinaryOperationContext::GT() {
  return getToken(potassium_parser::GT, 0);
}

potassium_parser::LogicalBinaryOperationContext::LogicalBinaryOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::LogicalBinaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitLogicalBinaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CondExpressionContext ------------------------------------------------------------------

potassium_parser::Cond_expresionContext* potassium_parser::CondExpressionContext::cond_expresion() {
  return getRuleContext<potassium_parser::Cond_expresionContext>(0);
}

potassium_parser::CondExpressionContext::CondExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::CondExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitCondExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IntLiteralContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::IntLiteralContext::INTLIT() {
  return getToken(potassium_parser::INTLIT, 0);
}

potassium_parser::IntLiteralContext::IntLiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::IntLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitIntLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- LogicalUnaryOperationContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::LogicalUnaryOperationContext::NOT() {
  return getToken(potassium_parser::NOT, 0);
}

potassium_parser::ExpressionContext* potassium_parser::LogicalUnaryOperationContext::expression() {
  return getRuleContext<potassium_parser::ExpressionContext>(0);
}

potassium_parser::LogicalUnaryOperationContext::LogicalUnaryOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::LogicalUnaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitLogicalUnaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FloatLiteralContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::FloatLiteralContext::FLOATLIT() {
  return getToken(potassium_parser::FLOATLIT, 0);
}

potassium_parser::FloatLiteralContext::FloatLiteralContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::FloatLiteralContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitFloatLiteral(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenExpressionContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::ParenExpressionContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

potassium_parser::ExpressionContext* potassium_parser::ParenExpressionContext::expression() {
  return getRuleContext<potassium_parser::ExpressionContext>(0);
}

tree::TerminalNode* potassium_parser::ParenExpressionContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}

potassium_parser::ParenExpressionContext::ParenExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::ParenExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitParenExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryOperationContext ------------------------------------------------------------------

std::vector<potassium_parser::ExpressionContext *> potassium_parser::BinaryOperationContext::expression() {
  return getRuleContexts<potassium_parser::ExpressionContext>();
}

potassium_parser::ExpressionContext* potassium_parser::BinaryOperationContext::expression(size_t i) {
  return getRuleContext<potassium_parser::ExpressionContext>(i);
}

tree::TerminalNode* potassium_parser::BinaryOperationContext::MULT() {
  return getToken(potassium_parser::MULT, 0);
}

tree::TerminalNode* potassium_parser::BinaryOperationContext::DIV() {
  return getToken(potassium_parser::DIV, 0);
}

tree::TerminalNode* potassium_parser::BinaryOperationContext::MOD() {
  return getToken(potassium_parser::MOD, 0);
}

tree::TerminalNode* potassium_parser::BinaryOperationContext::PLUS() {
  return getToken(potassium_parser::PLUS, 0);
}

tree::TerminalNode* potassium_parser::BinaryOperationContext::MINUS() {
  return getToken(potassium_parser::MINUS, 0);
}

potassium_parser::BinaryOperationContext::BinaryOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::BinaryOperationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitBinaryOperation(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FuncCallExpressionContext ------------------------------------------------------------------

potassium_parser::Function_callContext* potassium_parser::FuncCallExpressionContext::function_call() {
  return getRuleContext<potassium_parser::Function_callContext>(0);
}

potassium_parser::FuncCallExpressionContext::FuncCallExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::FuncCallExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitFuncCallExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VarReferenceContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::VarReferenceContext::ID() {
  return getToken(potassium_parser::ID, 0);
}

potassium_parser::VarReferenceContext::VarReferenceContext(ExpressionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::VarReferenceContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitVarReference(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::ExpressionContext* potassium_parser::expression() {
   return expression(0);
}

potassium_parser::ExpressionContext* potassium_parser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  potassium_parser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  potassium_parser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 12;
  enterRecursionRule(_localctx, 12, potassium_parser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(65);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ParenExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(54);
      match(potassium_parser::LPAREN);
      setState(55);
      expression(0);
      setState(56);
      match(potassium_parser::RPAREN);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<LogicalUnaryOperationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(58);
      match(potassium_parser::NOT);
      setState(59);
      expression(7);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<CondExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(60);
      cond_expresion();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<FuncCallExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(61);
      function_call();
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<VarReferenceContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(62);
      match(potassium_parser::ID);
      break;
    }

    case 6: {
      _localctx = _tracker.createInstance<IntLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(63);
      match(potassium_parser::INTLIT);
      break;
    }

    case 7: {
      _localctx = _tracker.createInstance<FloatLiteralContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(64);
      match(potassium_parser::FLOATLIT);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(78);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(76);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(67);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(68);
          dynamic_cast<BinaryOperationContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << potassium_parser::MULT)
            | (1ULL << potassium_parser::DIV)
            | (1ULL << potassium_parser::MOD))) != 0))) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(69);
          dynamic_cast<BinaryOperationContext *>(_localctx)->right = expression(10);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(70);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(71);
          dynamic_cast<BinaryOperationContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == potassium_parser::PLUS

          || _la == potassium_parser::MINUS)) {
            dynamic_cast<BinaryOperationContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(72);
          dynamic_cast<BinaryOperationContext *>(_localctx)->right = expression(9);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<LogicalBinaryOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(73);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(74);
          dynamic_cast<LogicalBinaryOperationContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << potassium_parser::AND)
            | (1ULL << potassium_parser::OR)
            | (1ULL << potassium_parser::EQ)
            | (1ULL << potassium_parser::LT)
            | (1ULL << potassium_parser::GT))) != 0))) {
            dynamic_cast<LogicalBinaryOperationContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(75);
          dynamic_cast<LogicalBinaryOperationContext *>(_localctx)->right = expression(7);
          break;
        }

        default:
          break;
        } 
      }
      setState(80);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Cond_expresionContext ------------------------------------------------------------------

potassium_parser::Cond_expresionContext::Cond_expresionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t potassium_parser::Cond_expresionContext::getRuleIndex() const {
  return potassium_parser::RuleCond_expresion;
}

void potassium_parser::Cond_expresionContext::copyFrom(Cond_expresionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- IfCondContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::IfCondContext::IF() {
  return getToken(potassium_parser::IF, 0);
}

tree::TerminalNode* potassium_parser::IfCondContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

tree::TerminalNode* potassium_parser::IfCondContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}

std::vector<potassium_parser::ExpressionContext *> potassium_parser::IfCondContext::expression() {
  return getRuleContexts<potassium_parser::ExpressionContext>();
}

potassium_parser::ExpressionContext* potassium_parser::IfCondContext::expression(size_t i) {
  return getRuleContext<potassium_parser::ExpressionContext>(i);
}

potassium_parser::IfCondContext::IfCondContext(Cond_expresionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::IfCondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitIfCond(this);
  else
    return visitor->visitChildren(this);
}
//----------------- IfElseCondContext ------------------------------------------------------------------

tree::TerminalNode* potassium_parser::IfElseCondContext::IF() {
  return getToken(potassium_parser::IF, 0);
}

tree::TerminalNode* potassium_parser::IfElseCondContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

tree::TerminalNode* potassium_parser::IfElseCondContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}

tree::TerminalNode* potassium_parser::IfElseCondContext::ELSE() {
  return getToken(potassium_parser::ELSE, 0);
}

std::vector<potassium_parser::ExpressionContext *> potassium_parser::IfElseCondContext::expression() {
  return getRuleContexts<potassium_parser::ExpressionContext>();
}

potassium_parser::ExpressionContext* potassium_parser::IfElseCondContext::expression(size_t i) {
  return getRuleContext<potassium_parser::ExpressionContext>(i);
}

potassium_parser::IfElseCondContext::IfElseCondContext(Cond_expresionContext *ctx) { copyFrom(ctx); }


antlrcpp::Any potassium_parser::IfElseCondContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitIfElseCond(this);
  else
    return visitor->visitChildren(this);
}
potassium_parser::Cond_expresionContext* potassium_parser::cond_expresion() {
  Cond_expresionContext *_localctx = _tracker.createInstance<Cond_expresionContext>(_ctx, getState());
  enterRule(_localctx, 14, potassium_parser::RuleCond_expresion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(95);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<Cond_expresionContext *>(_tracker.createInstance<potassium_parser::IfCondContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(81);
      match(potassium_parser::IF);
      setState(82);
      match(potassium_parser::LPAREN);
      setState(83);
      dynamic_cast<IfCondContext *>(_localctx)->test_exp = expression(0);
      setState(84);
      match(potassium_parser::RPAREN);
      setState(85);
      dynamic_cast<IfCondContext *>(_localctx)->then_exp = expression(0);
      break;
    }

    case 2: {
      _localctx = dynamic_cast<Cond_expresionContext *>(_tracker.createInstance<potassium_parser::IfElseCondContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(87);
      match(potassium_parser::IF);
      setState(88);
      match(potassium_parser::LPAREN);
      setState(89);
      dynamic_cast<IfElseCondContext *>(_localctx)->test_exp = expression(0);
      setState(90);
      match(potassium_parser::RPAREN);
      setState(91);
      dynamic_cast<IfElseCondContext *>(_localctx)->then_exp = expression(0);
      setState(92);
      match(potassium_parser::ELSE);
      setState(93);
      dynamic_cast<IfElseCondContext *>(_localctx)->else_exp = expression(0);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

potassium_parser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* potassium_parser::Function_callContext::ID() {
  return getToken(potassium_parser::ID, 0);
}

tree::TerminalNode* potassium_parser::Function_callContext::LPAREN() {
  return getToken(potassium_parser::LPAREN, 0);
}

tree::TerminalNode* potassium_parser::Function_callContext::RPAREN() {
  return getToken(potassium_parser::RPAREN, 0);
}

std::vector<potassium_parser::ExpressionContext *> potassium_parser::Function_callContext::expression() {
  return getRuleContexts<potassium_parser::ExpressionContext>();
}

potassium_parser::ExpressionContext* potassium_parser::Function_callContext::expression(size_t i) {
  return getRuleContext<potassium_parser::ExpressionContext>(i);
}


size_t potassium_parser::Function_callContext::getRuleIndex() const {
  return potassium_parser::RuleFunction_call;
}


antlrcpp::Any potassium_parser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<potassium_parserVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

potassium_parser::Function_callContext* potassium_parser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 16, potassium_parser::RuleFunction_call);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(97);
    match(potassium_parser::ID);
    setState(98);
    match(potassium_parser::LPAREN);
    setState(102);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << potassium_parser::INTLIT)
      | (1ULL << potassium_parser::FLOATLIT)
      | (1ULL << potassium_parser::IF)
      | (1ULL << potassium_parser::LPAREN)
      | (1ULL << potassium_parser::NOT)
      | (1ULL << potassium_parser::ID))) != 0)) {
      setState(99);
      expression(0);
      setState(104);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(105);
    match(potassium_parser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool potassium_parser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 6: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool potassium_parser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 9);
    case 1: return precpred(_ctx, 8);
    case 2: return precpred(_ctx, 6);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> potassium_parser::_decisionToDFA;
atn::PredictionContextCache potassium_parser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN potassium_parser::_atn;
std::vector<uint16_t> potassium_parser::_serializedATN;

std::vector<std::string> potassium_parser::_ruleNames = {
  "line", "type", "statement", "assignment", "function_assignment", "print", 
  "expression", "cond_expresion", "function_call"
};

std::vector<std::string> potassium_parser::_literalNames = {
  "", "", "", "", "", "'let'", "'print'", "'if'", "'else'", "'while'", "'int'", 
  "'float'", "'byte'", "'string'", "'+'", "'-'", "'*'", "'/'", "'%'", "'<-'", 
  "':'", "'('", "')'", "'&'", "'|'", "'='", "'^'", "'!'", "'<'", "'>'"
};

std::vector<std::string> potassium_parser::_symbolicNames = {
  "", "NEWLINE", "WS", "INTLIT", "FLOATLIT", "LET", "PRINT", "IF", "ELSE", 
  "WHILE", "INT", "FLOAT", "BYTE", "STRING", "PLUS", "MINUS", "MULT", "DIV", 
  "MOD", "ASSIGN", "TYPE_DEF", "LPAREN", "RPAREN", "AND", "OR", "EQ", "XOR", 
  "NOT", "LT", "GT", "ID"
};

dfa::Vocabulary potassium_parser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> potassium_parser::_tokenNames;

potassium_parser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x20, 0x6e, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 0x9, 
    0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 0x4, 
    0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 
    0x4, 0x1d, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 
    0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 
    0x2a, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x2d, 0xb, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x44, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x7, 0x8, 0x4f, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 
    0x52, 0xb, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x5, 0x9, 0x62, 0xa, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 
    0x7, 0xa, 0x67, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x6a, 0xb, 0xa, 0x3, 0xa, 
    0x3, 0xa, 0x3, 0xa, 0x2, 0x3, 0xe, 0xb, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
    0xe, 0x10, 0x12, 0x2, 0x6, 0x3, 0x2, 0xc, 0xe, 0x3, 0x2, 0x12, 0x14, 
    0x3, 0x2, 0x10, 0x11, 0x4, 0x2, 0x19, 0x1b, 0x1e, 0x1f, 0x2, 0x72, 0x2, 
    0x14, 0x3, 0x2, 0x2, 0x2, 0x4, 0x17, 0x3, 0x2, 0x2, 0x2, 0x6, 0x1c, 
    0x3, 0x2, 0x2, 0x2, 0x8, 0x1e, 0x3, 0x2, 0x2, 0x2, 0xa, 0x25, 0x3, 0x2, 
    0x2, 0x2, 0xc, 0x32, 0x3, 0x2, 0x2, 0x2, 0xe, 0x43, 0x3, 0x2, 0x2, 0x2, 
    0x10, 0x61, 0x3, 0x2, 0x2, 0x2, 0x12, 0x63, 0x3, 0x2, 0x2, 0x2, 0x14, 
    0x15, 0x5, 0x6, 0x4, 0x2, 0x15, 0x16, 0x7, 0x3, 0x2, 0x2, 0x16, 0x3, 
    0x3, 0x2, 0x2, 0x2, 0x17, 0x18, 0x9, 0x2, 0x2, 0x2, 0x18, 0x5, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x1d, 0x5, 0x8, 0x5, 0x2, 0x1a, 0x1d, 0x5, 0xa, 
    0x6, 0x2, 0x1b, 0x1d, 0x5, 0xc, 0x7, 0x2, 0x1c, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x1c, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x1d, 0x7, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x1f, 0x7, 0x7, 0x2, 0x2, 0x1f, 
    0x20, 0x7, 0x20, 0x2, 0x2, 0x20, 0x21, 0x7, 0x16, 0x2, 0x2, 0x21, 0x22, 
    0x5, 0x4, 0x3, 0x2, 0x22, 0x23, 0x7, 0x15, 0x2, 0x2, 0x23, 0x24, 0x5, 
    0xe, 0x8, 0x2, 0x24, 0x9, 0x3, 0x2, 0x2, 0x2, 0x25, 0x26, 0x7, 0x7, 
    0x2, 0x2, 0x26, 0x27, 0x7, 0x20, 0x2, 0x2, 0x27, 0x2b, 0x7, 0x17, 0x2, 
    0x2, 0x28, 0x2a, 0x7, 0x20, 0x2, 0x2, 0x29, 0x28, 0x3, 0x2, 0x2, 0x2, 
    0x2a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x2b, 0x29, 0x3, 0x2, 0x2, 0x2, 0x2b, 
    0x2c, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x2e, 0x3, 0x2, 0x2, 0x2, 0x2d, 0x2b, 
    0x3, 0x2, 0x2, 0x2, 0x2e, 0x2f, 0x7, 0x18, 0x2, 0x2, 0x2f, 0x30, 0x7, 
    0x15, 0x2, 0x2, 0x30, 0x31, 0x5, 0xe, 0x8, 0x2, 0x31, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x32, 0x33, 0x7, 0x8, 0x2, 0x2, 0x33, 0x34, 0x7, 0x17, 0x2, 
    0x2, 0x34, 0x35, 0x5, 0xe, 0x8, 0x2, 0x35, 0x36, 0x7, 0x18, 0x2, 0x2, 
    0x36, 0xd, 0x3, 0x2, 0x2, 0x2, 0x37, 0x38, 0x8, 0x8, 0x1, 0x2, 0x38, 
    0x39, 0x7, 0x17, 0x2, 0x2, 0x39, 0x3a, 0x5, 0xe, 0x8, 0x2, 0x3a, 0x3b, 
    0x7, 0x18, 0x2, 0x2, 0x3b, 0x44, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x3d, 0x7, 
    0x1d, 0x2, 0x2, 0x3d, 0x44, 0x5, 0xe, 0x8, 0x9, 0x3e, 0x44, 0x5, 0x10, 
    0x9, 0x2, 0x3f, 0x44, 0x5, 0x12, 0xa, 0x2, 0x40, 0x44, 0x7, 0x20, 0x2, 
    0x2, 0x41, 0x44, 0x7, 0x5, 0x2, 0x2, 0x42, 0x44, 0x7, 0x6, 0x2, 0x2, 
    0x43, 0x37, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3c, 0x3, 0x2, 0x2, 0x2, 0x43, 
    0x3e, 0x3, 0x2, 0x2, 0x2, 0x43, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x43, 0x40, 
    0x3, 0x2, 0x2, 0x2, 0x43, 0x41, 0x3, 0x2, 0x2, 0x2, 0x43, 0x42, 0x3, 
    0x2, 0x2, 0x2, 0x44, 0x50, 0x3, 0x2, 0x2, 0x2, 0x45, 0x46, 0xc, 0xb, 
    0x2, 0x2, 0x46, 0x47, 0x9, 0x3, 0x2, 0x2, 0x47, 0x4f, 0x5, 0xe, 0x8, 
    0xc, 0x48, 0x49, 0xc, 0xa, 0x2, 0x2, 0x49, 0x4a, 0x9, 0x4, 0x2, 0x2, 
    0x4a, 0x4f, 0x5, 0xe, 0x8, 0xb, 0x4b, 0x4c, 0xc, 0x8, 0x2, 0x2, 0x4c, 
    0x4d, 0x9, 0x5, 0x2, 0x2, 0x4d, 0x4f, 0x5, 0xe, 0x8, 0x9, 0x4e, 0x45, 
    0x3, 0x2, 0x2, 0x2, 0x4e, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4f, 0x52, 0x3, 0x2, 0x2, 0x2, 0x50, 0x4e, 0x3, 0x2, 
    0x2, 0x2, 0x50, 0x51, 0x3, 0x2, 0x2, 0x2, 0x51, 0xf, 0x3, 0x2, 0x2, 
    0x2, 0x52, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 0x7, 0x9, 0x2, 0x2, 
    0x54, 0x55, 0x7, 0x17, 0x2, 0x2, 0x55, 0x56, 0x5, 0xe, 0x8, 0x2, 0x56, 
    0x57, 0x7, 0x18, 0x2, 0x2, 0x57, 0x58, 0x5, 0xe, 0x8, 0x2, 0x58, 0x62, 
    0x3, 0x2, 0x2, 0x2, 0x59, 0x5a, 0x7, 0x9, 0x2, 0x2, 0x5a, 0x5b, 0x7, 
    0x17, 0x2, 0x2, 0x5b, 0x5c, 0x5, 0xe, 0x8, 0x2, 0x5c, 0x5d, 0x7, 0x18, 
    0x2, 0x2, 0x5d, 0x5e, 0x5, 0xe, 0x8, 0x2, 0x5e, 0x5f, 0x7, 0xa, 0x2, 
    0x2, 0x5f, 0x60, 0x5, 0xe, 0x8, 0x2, 0x60, 0x62, 0x3, 0x2, 0x2, 0x2, 
    0x61, 0x53, 0x3, 0x2, 0x2, 0x2, 0x61, 0x59, 0x3, 0x2, 0x2, 0x2, 0x62, 
    0x11, 0x3, 0x2, 0x2, 0x2, 0x63, 0x64, 0x7, 0x20, 0x2, 0x2, 0x64, 0x68, 
    0x7, 0x17, 0x2, 0x2, 0x65, 0x67, 0x5, 0xe, 0x8, 0x2, 0x66, 0x65, 0x3, 
    0x2, 0x2, 0x2, 0x67, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x68, 0x66, 0x3, 0x2, 
    0x2, 0x2, 0x68, 0x69, 0x3, 0x2, 0x2, 0x2, 0x69, 0x6b, 0x3, 0x2, 0x2, 
    0x2, 0x6a, 0x68, 0x3, 0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x18, 0x2, 0x2, 
    0x6c, 0x13, 0x3, 0x2, 0x2, 0x2, 0x9, 0x1c, 0x2b, 0x43, 0x4e, 0x50, 0x61, 
    0x68, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

potassium_parser::Initializer potassium_parser::_init;
