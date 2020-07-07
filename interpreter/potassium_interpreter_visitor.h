#pragma once

#include "antlr4-runtime.h"
#include "../potassium/potassium_parserVisitor.h"

#include "potassium_ast.h"

namespace potassium {
    class  potassium_interpreter_visitor : public potassium_parserVisitor {
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
	        auto var = std::make_unique<ast::ASTVariable>(ctx->ID()->getText());
            auto value = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTValue*>());
	        return new ast::ASTAssigment(std::move(var), std::move(value));
        }

        virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *ctx) override {
            //std::cout << "Print: " << std::endl;
	        auto value = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTValue*>());
            return new ast::ASTPrint(std::unique_ptr<ast::ASTNode>(std::move(value)));
        }

        virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *ctx) override {
             //std::cout << "IntLit: " << ctx->getText() << std::endl;
	        return new ast::ASTValue(std::stof(ctx->getText()));
        }

        virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *ctx) override {
              //std::cout << "FloatLit: " << ctx->getText() << std::endl;
			return new ast::ASTValue(std::stof(ctx->getText()));
        }

        virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *ctx) override {
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *ctx) override {
            //std::cout << "bin exprection: " << ctx->getText() << std::endl;

	        auto left = std::unique_ptr<ast::ASTNode>(this->visit(ctx->left).as<ast::ASTNode*>());
	        auto right = std::unique_ptr<ast::ASTNode>(this->visit(ctx->right).as<ast::ASTNode*>());
            char op = ctx->op->getText()[0];

            return new ast::ASTBinaryOperation(op, std::move(left), std::move(right));
        }

        virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *ctx) override {
            return new ast::ASTVariable(ctx->getText());
        }

    private:

    };
}

