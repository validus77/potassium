#include "potassium_ast.h"
namespace potassium { namespace ast {

double ASTBinaryOperation::eval(SymbolTable& symbols) {
	switch (op_) {
		case '*':
			return lhs_->eval(symbols) * rhs_->eval(symbols);
		case '/':
			return lhs_->eval(symbols) / rhs_->eval(symbols);
		case '+':
			return lhs_->eval(symbols) + rhs_->eval(symbols);
		case '-':
			return lhs_->eval(symbols) - rhs_->eval(symbols);
		default:
			return 0.0;
	}
}

double ASTAssigment::eval(SymbolTable &symbols) {
	double val = value_->eval(symbols);
	symbols.set(variable_->name(), val);
	return val;
}

}}