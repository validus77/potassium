#pragma once

#include "antlr4-runtime.h"
#include "../potassium/potassium_parserVisitor.h"

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
            double* val = this->visit(ctx->expression()).as<double*>();
            sym_table_[ctx->ID()->getText()] = val;
            std::cout << "Insert: " << ctx->ID()->getText() << " = " << *val << std::endl;
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitPrint(potassium_parser::PrintContext *ctx) override {
            // std::cout << "Print: " << std::endl;
            std::cout << *(this->visit(ctx->expression()).as<double*>()) << std::endl;
            return antlrcpp::Any();
        }

        virtual antlrcpp::Any visitIntLiteral(potassium_parser::IntLiteralContext *ctx) override {
            // std::cout << "IntLit: " << ctx->getText() << std::endl;
            double* ret = new double();
            *ret = std::stof(ctx->getText());
            return ret;
        }

        virtual antlrcpp::Any visitFloatLiteral(potassium_parser::FloatLiteralContext *ctx) override {
            //  std::cout << "FloatLit: " << ctx->getText() << std::endl;
            double* ret = new double();
            *ret = std::stof(ctx->getText());
            return ret;
        }

        virtual antlrcpp::Any visitParenExpression(potassium_parser::ParenExpressionContext *ctx) override {
            return visitChildren(ctx);
        }

        virtual antlrcpp::Any visitBinaryOperation(potassium_parser::BinaryOperationContext *ctx) override {
            //std::cout << "bin exprection: " << ctx->getText() << std::endl;
            double* ret = new double();
            double* left = this->visit(ctx->left).as<double*>();
            double* right = this->visit(ctx->right).as<double*>();
            std::string op = ctx->op->getText();

            switch (op[0])
            {
                case '*':
                    *ret = *left * *right;
                    break;
                case '/':
                    *ret = *left / *right;
                    break;
                case '+':
                    //std::cout << "L: " << *left << " R: " << *right << std::endl;
                    *ret = *left + *right;
                    break;
                case '-':
                    *ret = *left - *right;
                    break;
            }
            return ret;
        }

        virtual antlrcpp::Any visitVarReference(potassium_parser::VarReferenceContext *ctx) override {
            return sym_table_[ctx->getText()];
        }

    private:
        std::map<std::string, double*> sym_table_;

    };
}

