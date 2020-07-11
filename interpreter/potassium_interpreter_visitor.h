#pragma once

#include "antlr4-runtime.h"
#include "../potassium/potassium_parserBaseVisitor.h"

#include "potassium_ast.h"

namespace potassium {
    class  potassium_interpreter_visitor : public potassium_parserBaseVisitor {
    public:

        virtual antlrcpp::Any visitLine(potassium_parser::LineContext *ctx) override {
            return static_cast<ast::ASTNode*>(visit(ctx->statement()));
        }

        virtual antlrcpp::Any visitAssigmentStantment(potassium_parser::AssigmentStantmentContext *ctx) override {
            return static_cast<ast::ASTNode*>(visit(ctx->assignment()));
        }

        virtual antlrcpp::Any visitPrintStatment(potassium_parser::PrintStatmentContext *ctx) override {
            return static_cast<ast::ASTNode*>(visit(ctx->print()));
        }

        virtual antlrcpp::Any visitAssignment(potassium_parser::AssignmentContext *ctx) override {
	        auto var = std::make_unique<ast::ASTVariable>(ctx->ID()->getText());
            auto value = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTNode*>());
	        return static_cast<ast::ASTNode*>(new ast::ASTAssigment(std::move(var), std::move(value)));
        }

        virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *ctx) override {
	        auto value = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTNode*>());
            return static_cast<ast::ASTNode*>(new ast::ASTPrint(std::move(value)));
        }

        virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *ctx) override {
	        return static_cast<ast::ASTNode*>(new ast::ASTValue(std::stof(ctx->getText())));
        }

        virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *ctx) override {
	        return static_cast<ast::ASTNode*>(new ast::ASTValue(std::stof(ctx->getText())));
        }

        virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *ctx) override {
            return static_cast<ast::ASTNode*>(visit(ctx->expression()));
        }

        virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *ctx) override {

	        auto left = std::unique_ptr<ast::ASTNode>(this->visit(ctx->left).as<ast::ASTNode*>());
	        auto right = std::unique_ptr<ast::ASTNode>(this->visit(ctx->right).as<ast::ASTNode*>());
            char op = ctx->op->getText()[0];

            return static_cast<ast::ASTNode*>(new ast::ASTBinaryOperation(op, std::move(left), std::move(right)));
        }

	    virtual antlrcpp::Any visitLogicalBinaryOperation(potassium_parser::LogicalBinaryOperationContext *ctx) override {
		    auto left = std::unique_ptr<ast::ASTNode>(this->visit(ctx->left).as<ast::ASTNode*>());
		    auto right = std::unique_ptr<ast::ASTNode>(this->visit(ctx->right).as<ast::ASTNode*>());
		    char op = ctx->op->getText()[0];

		    return static_cast<ast::ASTNode*>(new ast::ASTBinaryOperation(op, std::move(left), std::move(right)));
	    }

	    virtual antlrcpp::Any visitLogicalUnaryOperation(potassium_parser::LogicalUnaryOperationContext *ctx) override {
		    auto right = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTNode*>());
		    char op = ctx->NOT()->getText()[0]; // Note that NOT ius hardcoded as the only unary op right now.

		    return static_cast<ast::ASTNode*>(new ast::ASTUnaryOperation(op,std::move(right)));
	    }

        virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *ctx) override {
            return static_cast<ast::ASTNode*>(new ast::ASTVariable(ctx->getText()));
        }

	    virtual antlrcpp::Any visitIfCond(potassium_parser::IfCondContext *ctx) override {
		    auto test_exp = std::unique_ptr<ast::ASTNode>(this->visit(ctx->test_exp).as<ast::ASTNode*>());
		    auto then_exp = std::unique_ptr<ast::ASTNode>(this->visit(ctx->then_exp).as<ast::ASTNode*>());
        	return static_cast<ast::ASTNode*>(new ast::ASTCond(std::move(test_exp), std::move(then_exp)));
	    }

	    virtual antlrcpp::Any visitIfElseCond(potassium_parser::IfElseCondContext *ctx) override {
		    auto test_exp = std::unique_ptr<ast::ASTNode>(this->visit(ctx->test_exp).as<ast::ASTNode*>());
		    auto then_exp = std::unique_ptr<ast::ASTNode>(this->visit(ctx->then_exp).as<ast::ASTNode*>());
		    auto else_exp = std::unique_ptr<ast::ASTNode>(this->visit(ctx->else_exp).as<ast::ASTNode*>());

		    return static_cast<ast::ASTNode*>(
		    	new ast::ASTCond(std::move(test_exp), std::move(then_exp), std::move(else_exp)));
	    }

	    virtual antlrcpp::Any visitFunction_assignment(potassium_parser::Function_assignmentContext *ctx) override {
		    auto body = std::unique_ptr<ast::ASTNode>(this->visit(ctx->expression()).as<ast::ASTNode*>());
		    std::vector<std::unique_ptr<ast::ASTVariable>> params;


		    for(auto& id : ctx->ID()) {
			    params.emplace_back(std::make_unique<ast::ASTVariable>(id->getText()));
		    }
		    return static_cast<ast::ASTNode*>(new ast::ASTFunction(ctx->ID(0)->getText(), std::move(body), std::move
		    (params)));
	    }

	    virtual antlrcpp::Any visitFunction_call(potassium_parser::Function_callContext *ctx) override {
		    std::vector<std::unique_ptr<ast::ASTNode>> params;
		    for(auto& pram_exp : ctx->expression()){
			    params.emplace_back(std::unique_ptr<ast::ASTNode>(this->visit(pram_exp).as<ast::ASTNode*>()));
		    }
        	return static_cast<ast::ASTNode*>(new ast::ASTFunctionCall(ctx->ID()->getText(), std::move(params)));
	    }

    private:

    };
}

