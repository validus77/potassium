#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>
#include "symbol_table.h"
namespace potassium { namespace ast {

class ASTNode {
public:
	virtual ~ASTNode() {}
	virtual double eval(SymbolTable& symbols) {return 0.0;}
protected:
	bool eq(double lhs, double rhs);
};

class ASTValue : public ASTNode {
public:
	ASTValue(double value) : value_(value) {}
	virtual double eval(SymbolTable& symbols) { return value_;}
private:
	double value_;
};

class ASTVariable : public ASTNode {
public:
	ASTVariable(const std::string name) : name_(name) {}
	const std::string& name() { return name_; }
	virtual double eval(SymbolTable& symbols) {return symbols.get(name_);}
private:
	std::string name_;
};

class ASTBinaryOperation : public ASTNode {
public:
	ASTBinaryOperation(char op, std::unique_ptr<ASTNode> lhs, std::unique_ptr<ASTNode> rhs) :
		op_(op), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}

	virtual double eval(SymbolTable& symbols);

private:
	char op_;
	std::unique_ptr<ASTNode> lhs_;
	std::unique_ptr<ASTNode> rhs_;
};

class ASTUnaryOperation : public ASTNode {
public:
	ASTUnaryOperation(char op, std::unique_ptr<ASTNode> rhs) :
		op_(op), rhs_(std::move(rhs)) {}

	virtual double eval(SymbolTable& symbols);
private:
	char op_;
	std::unique_ptr<ASTNode> rhs_;
};


class ASTAssigment : public ASTNode {
public:
	ASTAssigment(std::unique_ptr<ASTVariable> variable, std::unique_ptr<ASTNode> value) :
		variable_(std::move(variable)), value_(std::move(value)) {}

	virtual double eval(SymbolTable& symbols);
private:
	std::unique_ptr<ASTVariable> variable_;
	std::unique_ptr<ASTNode> value_;

};

class ASTPrint : public ASTNode {
public:
	ASTPrint(std::unique_ptr<ASTNode> value) : value_(std::move(value)) {
	}
	virtual double eval(SymbolTable& symbols) {
		std::cout << value_->eval(symbols) << std::endl;
		return 0.0;
	}
private:
	std::unique_ptr<ASTNode> value_;
};

class ASTCond : public ASTNode {
public:
	ASTCond(std::unique_ptr<ASTNode> test_exp, std::unique_ptr<ASTNode> then_exp, std::unique_ptr<ASTNode> else_exp) :
		test_exp_(move(test_exp)), then_exp_(std::move(then_exp)), else_exp_(std::move(else_exp)) {}

	ASTCond(std::unique_ptr<ASTNode> test_exp, std::unique_ptr<ASTNode> then_exp) :
		test_exp_(move(test_exp)), then_exp_(std::move(then_exp)) {}

	virtual double eval(SymbolTable& symbols);
private:
	std::unique_ptr<ASTNode> test_exp_;
	std::unique_ptr<ASTNode> then_exp_;
	std::unique_ptr<ASTNode> else_exp_;
};

class ASTFunction : public ASTNode {
public:
	ASTFunction(std::string name, std::unique_ptr<ASTNode> body, std::vector<std::unique_ptr<ASTVariable>> params) :
	name_(name), body_(std::move(body)), params_(std::move(params)) {}

	virtual double eval(SymbolTable& symbols);
	std::vector<std::unique_ptr<ASTVariable>>& params() {return params_;}
	std::unique_ptr<ASTNode>& body() {return body_;}
private:
	std::string name_;
	std::unique_ptr<ASTNode> body_;
	std::vector<std::unique_ptr<ASTVariable>> params_;
};

class ASTFunctionCall : public ASTNode {
public:
	ASTFunctionCall(std::string name, std::vector<std::unique_ptr<ASTNode>> params) :
	name_(name), params_(std::move(params)) {}

	virtual double eval(SymbolTable& symbols);
private:
	std::string name_;
	std::vector<std::unique_ptr<ASTNode>> params_;
};

}}