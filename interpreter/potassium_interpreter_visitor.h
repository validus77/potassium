#pragma once

#include "antlr4-runtime.h"
#include "../potassium/potassium_parserVisitor.h"

#include "potassium_ast.h"

namespace potassium {
    class  potassium_interpreter_visitor : public potassium_parserVisitor {
    public:

        virtual antlrcpp::Any visitLine(potassium_parser::LineContext *ctx) override {
            return std::move(visitChildren(ctx));
        }

        virtual antlrcpp::Any visitAssigmentStantment(potassium_parser::AssigmentStantmentContext *ctx) override {
            return std::move(visitChildren(ctx));
        }

        virtual antlrcpp::Any visitPrintStatment(potassium_parser::PrintStatmentContext *ctx) override {
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitAssignment(potassium_parser::AssignmentContext *ctx) override {
	        auto var = std::make_unique<ast::ASTVariable>(ctx->ID()->getText());
        	auto value = std::move(this->visit(ctx->expression()).as<std::unique_ptr<ast::ASTNode>>());
	        auto asg = std::make_unique<ast::ASTAssigment>(std::move(var), std::move(value));
	        return std::move(asg);
        }

        virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *ctx) override {
            // std::cout << "Print: " << std::endl;
	        auto value = std::make_unique<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTNode>());
            auto print = std::make_unique<ast::ASTPrint>(std::unique_ptr<ast::ASTNode>(std::move(value)));
            return std::move(print);
        }

        virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *ctx) override {
            // std::cout << "IntLit: " << ctx->getText() << std::endl;
	        auto lit_node = ast::ASTValue(std::stof(ctx->getText()));
	        return ast::ASTValue(std::stof(ctx->getText()));
        }

        virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *ctx) override {
            //  std::cout << "FloatLit: " << ctx->getText() << std::endl;
            //auto lit_node = ast::ASTValue(std::stof(ctx->getText()));
			return ast::ASTValue(std::stof(ctx->getText()));
        }

        virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *ctx) override {
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *ctx) override {
            //std::cout << "bin exprection: " << ctx->getText() << std::endl;

	        auto left = std::move(this->visit(ctx->left).as<std::unique_ptr<ast::ASTNode>>());
	        auto right = std::move(this->visit(ctx->right).as<std::unique_ptr<ast::ASTNode>>());
            char op = ctx->op->getText()[0];

            auto ret = std::make_unique<ast::ASTBinaryOperation>(op, std::move(left), std::move(right));
            return std::move(ret);
        }

        virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *ctx) override {
            auto var = std::make_unique<ast::ASTVariable>(ctx->getText());
            return var;
        }

    private:

    };
}

