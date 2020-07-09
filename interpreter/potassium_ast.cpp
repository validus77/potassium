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

llvm::Value* ASTBinaryOperation::codegen(SymbolTable& symbols) {

	llvm::Value *L = lhs_->codegen(symbols);
	llvm::Value *R = rhs_->codegen(symbols);
	if (!L || !R)
		return nullptr;

	switch (op_) {
		case '*':
			return Builder.CreateMul(L,R, "multtmp");
		case '/':
			return Builder.CreateFDiv(L,R, "multdiv");
		case '+':
			return Builder.CreateFAdd(L, R, "addtmp");
		case '-':
			return Builder.CreateSub(L, R, "subtmp");
		case '&':
			return nullptr;
		case '|':
			return nullptr;
		case '^':
			return nullptr;
		case '=':
			return Builder.CreateFCmpOEQ(L,R,"eqtmp");
		case '>':
			return Builder.CreateFCmpOGT(L,R,"gttmp");
		case '<':
			return Builder.CreateFCmpOLT(L,R,"gttmp");
		default:
			return nullptr;
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

double ASTFunction::eval(SymbolTable &symbols) {
	symbols.setFun(name_, std::unique_ptr<ASTFunction>(this));
}

double ASTFunctionCall::eval(SymbolTable &symbols) {
	SymbolTable function_scope_symbols(&symbols);
	ASTFunction* funct = symbols.getFun(name_);
	if(funct == nullptr) {
		std::cout << "No function defined: " << name_ << std::endl;
		return 0.0;
	}
	auto& funct_prams = funct->params();
	for(int i = 0; i < params_.size(); i++) {
		function_scope_symbols.set(funct_prams[i+1]->name(), params_[i]->eval(symbols));
	}
	return funct->body()->eval(function_scope_symbols);
}

}}