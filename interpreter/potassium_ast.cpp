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
        case '%':
            return std::fmod(lhs_->eval(symbols), rhs_->eval(symbols));
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
        case '%':
            return Builder.CreateFRem(L,R,"modtmp");
		case '+':
			return Builder.CreateFAdd(L, R, "addtmp");
		case '-':
			return Builder.CreateSub(L, R, "subtmp");
		case '&':
		    L = Builder.CreateAnd(L,R,"andtmp");
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
		case '|':
            L = Builder.CreateOr(L,R,"ortmp");
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
		case '^':
            L = Builder.CreateXor(L,R,"andtmp");
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
		case '=':
			L = Builder.CreateFCmpOEQ(L,R,"eqtmp");
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
		case '>':
			L =  Builder.CreateFCmpOGT(L,R,"gttmp");
			return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                                                                 "booltmp");
		case '<':
            L = Builder.CreateFCmpULT(L, R, "cmptmp");
            // Convert bool 0/1 to double 0.0 or 1.0
            return Builder.CreateUIToFP(L, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
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

llvm::Value* ASTUnaryOperation::codegen(SymbolTable& symbols){
    llvm::Value *R = rhs_->codegen(symbols);

    switch (op_) {
        case '!':
            R =  Builder.CreateNot(R, "nottmp");
            return Builder.CreateUIToFP(R, llvm::Type::getDoubleTy(PotassiumContext),
                                        "booltmp");
        default:
            return nullptr;
    }
}


double ASTAssigment::eval(SymbolTable &symbols) {
	double val = value_->eval(symbols);
	symbols.setVar(variable_->name(), val);
	return val;
}


llvm::Value* ASTAssigment::codegen(SymbolTable& symbols) {
	llvm::Value* val = value_->codegen(symbols);
	symbols.setVar(variable_->name(), val);
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

llvm::Value* ASTCond::codegen(SymbolTable& symbols) {
	llvm::Value* test_value = test_exp_->codegen(symbols);
	if (!test_value)
		return nullptr;
	test_value = Builder.CreateFCmpONE(
		test_value, llvm::ConstantFP::get(PotassiumContext, llvm::APFloat(0.0)), "ifcond");
	llvm::Function *function = Builder.GetInsertBlock()->getParent();

	llvm::BasicBlock *then_block =
		llvm::BasicBlock::Create(PotassiumContext, "then", function);
	llvm::BasicBlock *else_block = llvm::BasicBlock::Create(PotassiumContext, "else");
	llvm::BasicBlock *merge_block = llvm::BasicBlock::Create(PotassiumContext, "ifcont");

	Builder.CreateCondBr(test_value, then_block, else_block);
// Then block
	Builder.SetInsertPoint(then_block);
	llvm::Value* then_value = then_exp_->codegen(symbols);
	if (!then_value)
		return nullptr;

	Builder.CreateBr(merge_block);
	then_block = Builder.GetInsertBlock();
// Else block
	function->getBasicBlockList().push_back(else_block);
	Builder.SetInsertPoint(else_block);

	llvm::Value* else_value = else_exp_->codegen(symbols);
	if (!else_value)
		return nullptr;

// Merged IF Then Else
	Builder.CreateBr(merge_block);
	merge_block = Builder.GetInsertBlock();

	function->getBasicBlockList().push_back(merge_block);
	Builder.SetInsertPoint(merge_block);
	llvm::PHINode* phi =
		Builder.CreatePHI(llvm::Type::getDoubleTy(PotassiumContext), 2, "iftmp");

	phi->addIncoming(then_value, then_block);
	phi->addIncoming(else_value, else_block);
	return phi;
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
		function_scope_symbols.setVar(funct_prams[i+1]->name(), params_[i]->eval(symbols));
	}
	return funct->body()->eval(function_scope_symbols);
}

llvm::Value* ASTFunctionCall::codegen(SymbolTable& symbols){
// Look up the name in the global module table.
    SymbolTable function_scope_symbols(&symbols);
    llvm::Function *function =  PotassiumModule->getFunction(name_);
    if (!function) {
        std::cout << "No function defined: " << name_ << std::endl;
        return nullptr;
    }
    // If argument mismatch error.
    if (function->arg_size() != params_.size()) {
        std::cout << "Incorrect # arguments passed" << std::endl;
        return nullptr;
    }
    std::vector<llvm::Value *> paramsVal;
    for (unsigned i = 0, e = params_.size(); i != e; ++i) {
        //function_scope_symbols.setVar(funct_prams[i+1]->name(), params_[i]->eval(symbols));
        paramsVal.push_back(params_[i]->codegen(function_scope_symbols));
    }

    return Builder.CreateCall(function, paramsVal, "calltmp");
}


}}