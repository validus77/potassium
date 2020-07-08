#include "potassium_ast.h"
namespace potassium { namespace ast {

double ASTBinaryOperation::eval() {
	switch (op_) {
		case '*':
			return lhs_->eval() * rhs_->eval();
		case '/':
			return lhs_->eval() / rhs_->eval();
		case '+':
			return lhs_->eval() + rhs_->eval();
		case '-':
			return lhs_->eval() - rhs_->eval();
		default:
			return 0.0;
	}
}

}}