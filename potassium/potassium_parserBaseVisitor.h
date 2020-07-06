
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_parser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "potassium_parserVisitor.h"


namespace potassium {

/**
 * This class provides an empty implementation of potassium_parserVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  potassium_parserBaseVisitor : public potassium_parserVisitor {
public:

  virtual antlrcpp::Any visitLine(potassium_parser::LineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssigmentStantment(potassium_parser::AssigmentStantmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrintStatment(potassium_parser::PrintStatmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignment(potassium_parser::AssignmentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace potassium
