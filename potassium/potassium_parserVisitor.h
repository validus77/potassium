
// Generated from /Users/jritteman/Code/potassium/grammar/potassium_parser.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "potassium_parser.h"


namespace potassium {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by potassium_parser.
 */
class  potassium_parserVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by potassium_parser.
   */
    virtual antlrcpp::Any visitLine(potassium_parser::LineContext *context) = 0;

    virtual antlrcpp::Any visitAssigmentStantment(potassium_parser::AssigmentStantmentContext *context) = 0;

    virtual antlrcpp::Any visitFunctionAssigmentStantment(potassium_parser::FunctionAssigmentStantmentContext *context) = 0;

    virtual antlrcpp::Any visitPrintStatment(potassium_parser::PrintStatmentContext *context) = 0;

    virtual antlrcpp::Any visitInitialAssigment(potassium_parser::InitialAssigmentContext *context) = 0;

    virtual antlrcpp::Any visitUpdateAssignment(potassium_parser::UpdateAssignmentContext *context) = 0;

    virtual antlrcpp::Any visitFunction_assignment(potassium_parser::Function_assignmentContext *context) = 0;

    virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *context) = 0;

    virtual antlrcpp::Any visitBlockExpression(potassium_parser::BlockExpressionContext *context) = 0;

    virtual antlrcpp::Any visitLogicalBinaryOperation(potassium_parser::LogicalBinaryOperationContext *context) = 0;

    virtual antlrcpp::Any visitCondExpression(potassium_parser::CondExpressionContext *context) = 0;

    virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *context) = 0;

    virtual antlrcpp::Any visitLogicalUnaryOperation(potassium_parser::LogicalUnaryOperationContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *context) = 0;

    virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *context) = 0;

    virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *context) = 0;

    virtual antlrcpp::Any visitFuncCallExpression(potassium_parser::FuncCallExpressionContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatment(potassium_parser::WhileStatmentContext *context) = 0;

    virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *context) = 0;

    virtual antlrcpp::Any visitIfCond(potassium_parser::IfCondContext *context) = 0;

    virtual antlrcpp::Any visitIfElseCond(potassium_parser::IfElseCondContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(potassium_parser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitWhile_loop(potassium_parser::While_loopContext *context) = 0;

    virtual antlrcpp::Any visitBlock(potassium_parser::BlockContext *context) = 0;


};

}  // namespace potassium
