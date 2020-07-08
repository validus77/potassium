#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "symbol_table.h"
namespace potassium { namespace ast {

class ASTNode {
public:
	virtual ~ASTNode() {}
	virtual double eval(SymbolTable& symbols) {return 0.0;}
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

}}