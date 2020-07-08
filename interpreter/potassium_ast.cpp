#include "potassium_ast.h"
namespace potassium { namespace ast {

bool ASTNode::eq(double lhs, double rhs) {
	constexpr double EPSILON = 0.0001;
	double diff = lhs - rhs;
	return (diff < EPSILON) && (-diff < EPSILON);
}

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
		case '&':
			return (!eq(lhs_->eval(symbols), 0.0) && !eq(rhs_->eval(symbols), 0.0))? 1.0 : 0.0;
		case '|':
			return (!eq(lhs_->eval(symbols), 0.0) || !eq(rhs_->eval(symbols), 0.0))? 1.0 : 0.0;
		case '^':
			return (!eq(lhs_->eval(symbols), 0.0) != !eq(rhs_->eval(symbols), 0.0))? 1.0 : 0.0;
		case '=':
			return (lhs_->eval(symbols) == rhs_->eval(symbols))? 1.0 : 0.0;
		case '>':
			return (lhs_->eval(symbols) > rhs_->eval(symbols))? 1.0 : 0.0;
		case '<':
			return (lhs_->eval(symbols) < rhs_->eval(symbols))? 1.0 : 0.0;
		default:
			return 0.0;
	}
}

double ASTUnaryOperation::eval(SymbolTable& symbols) {
	switch (op_) {
		case '!':
			return eq(rhs_->eval(symbols), 0.0);
		default:
			return 0.0;
	}
}

double ASTAssigment::eval(SymbolTable &symbols) {
	double val = value_->eval(symbols);
	symbols.set(variable_->name(), val);
	return val;
}

double ASTCond::eval(SymbolTable &symbols) {
	if(!eq(test_exp_->eval(symbols), 0.0))
		return then_exp_->eval(symbols);
	else if(else_exp_)
		return else_exp_->eval(symbols);
	else
		return 0.0;
}

}}