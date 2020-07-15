#include "llvm/Support/raw_ostream.h"
#include "llvm/ADT/APFloat.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"

#include <cctype>
#include <cstdint>
#include <memory>
#include <vector>
#include "potassium_ast.h"

namespace potassium { namespace ast {

bool ASTNode::eq(double lhs, double rhs) {
	constexpr double EPSILON = 0.0001;
	double diff = lhs - rhs;
	return (diff < EPSILON) && (-diff < EPSILON);
}

double ASTBinaryOperation::eval(SymbolTable& symbols, LLVMContext* context) {
	switch (op_) {
		case '*':
			return lhs_->eval(symbols, context) * rhs_->eval(symbols, context);
		case '/':
			return lhs_->eval(symbols, context) / rhs_->eval(symbols, context);
        case '%':
            return std::fmod(lhs_->eval(symbols, context), rhs_->eval(symbols, context));
		case '+':
			return lhs_->eval(symbols, context) + rhs_->eval(symbols, context);
		case '-':
			return lhs_->eval(symbols, context) - rhs_->eval(symbols, context);
		case '&':
			return (!eq(lhs_->eval(symbols, context), 0.0) && !eq(rhs_->eval(symbols, context), 0.0))? 1.0 : 0.0;
		case '|':
			return (!eq(lhs_->eval(symbols, context), 0.0) || !eq(rhs_->eval(symbols, context), 0.0))? 1.0 : 0.0;
		case '^':
			return (!eq(lhs_->eval(symbols, context), 0.0) != !eq(rhs_->eval(symbols, context), 0.0))? 1.0 : 0.0;
		case '=':
			return (lhs_->eval(symbols, context) == rhs_->eval(symbols, context))? 1.0 : 0.0;
		case '>':
			return (lhs_->eval(symbols, context) > rhs_->eval(symbols, context))? 1.0 : 0.0;
		case '<':
			return (lhs_->eval(symbols, context) < rhs_->eval(symbols, context))? 1.0 : 0.0;
		default:
			return 0.0;
	}
}

llvm::Value* ASTBinaryOperation::codegen(SymbolTable& symbols, LLVMContext* context) {

	llvm::Value *L = lhs_->codegen(symbols, context);
	llvm::Value *R = rhs_->codegen(symbols, context);
	if (!L || !R)
		return nullptr;

	switch (op_) {
		case '*':
			return context->builder.CreateFMul(L,R, "multtmp");
		case '/':
			return context->builder.CreateFDiv(L,R, "multdiv");
        case '%':
            return context->builder.CreateFRem(L,R,"modtmp");
		case '+':
			return context->builder.CreateFAdd(L, R, "addtmp");
		case '-':
			return context->builder.CreateFSub(L, R, "subtmp");
		case '&':
		    L = context->builder.CreateFPToUI(L,llvm::Type::getInt1Ty(context->potassium_context),"lhsi");
            R = context->builder.CreateFPToUI(R,llvm::Type::getInt1Ty(context->potassium_context),"rhsi");
            L = context->builder.CreateAnd(L,R,"andtmp");
            return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
		case '|':
            L = context->builder.CreateFPToUI(L,llvm::Type::getInt1Ty(context->potassium_context),"lhsi");
            R = context->builder.CreateFPToUI(R,llvm::Type::getInt1Ty(context->potassium_context),"rhsi");
            L = context->builder.CreateOr(L,R,"ortmp");
            return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
		case '^':
            L = context->builder.CreateFPToUI(L,llvm::Type::getInt1Ty(context->potassium_context),"lhsi");
            R = context->builder.CreateFPToUI(R,llvm::Type::getInt1Ty(context->potassium_context),"rhsi");
            L = context->builder.CreateXor(L,R,"andtmp");
            return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
		case '=':
			L = context->builder.CreateFCmpUEQ(L,R,"eqtmp");
            return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
		case '>':
			L =  context->builder.CreateFCmpUGT(L,R,"gttmp");
			return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                                                                 "booltmp");
		case '<':
            L = context->builder.CreateFCmpULT(L, R, "cmptmp");
            // Convert bool 0/1 to double 0.0 or 1.0
            return context->builder.CreateUIToFP(L, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
		default:
			return nullptr;
	}
}

double ASTUnaryOperation::eval(SymbolTable& symbols, LLVMContext* context) {
	switch (op_) {
		case '!':
			return eq(rhs_->eval(symbols, context), 0.0);
		default:
			return 0.0;
	}
}

llvm::Value* ASTUnaryOperation::codegen(SymbolTable& symbols, LLVMContext* context){
    llvm::Value *R = rhs_->codegen(symbols, context);

    switch (op_) {
        case '!':
            R = context->builder.CreateFPToUI(R,llvm::Type::getInt1Ty(context->potassium_context),"rhsi");
            R =  context->builder.CreateNot(R, "nottmp");
            return context->builder.CreateUIToFP(R, llvm::Type::getDoubleTy(context->potassium_context),
                                        "booltmp");
        default:
            return nullptr;
    }
}

double ASTAssigment::eval(SymbolTable &symbols, LLVMContext* context) {
	double val = value_->eval(symbols, context);
	symbols.setVar(variable_->name(), val);
	if(context)
	    codegen(symbols, context);
	return val;
}

llvm::Value* ASTAssigment::codegen(SymbolTable& symbols, LLVMContext* context) {
	llvm::Value* val = value_->codegen(symbols, context);
	symbols.setVar(variable_->name(), val);
	return val;
}

double ASTCond::eval(SymbolTable &symbols, LLVMContext* context) {
	if(!eq(test_exp_->eval(symbols, context), 0.0))
		return then_exp_->eval(symbols, context);
	else if(else_exp_)
		return else_exp_->eval(symbols, context);
	else
		return 0.0;
}

llvm::Value* ASTCond::codegen(SymbolTable& symbols, LLVMContext* context) {
	llvm::Value* test_value = test_exp_->codegen(symbols, context);
	if (!test_value)
		return nullptr;
	test_value = context->builder.CreateFCmpONE(
		test_value, llvm::ConstantFP::get(context->potassium_context, llvm::APFloat(0.0)), "ifcond");
	llvm::Function *function = context->builder.GetInsertBlock()->getParent();

	llvm::BasicBlock *then_block =
		llvm::BasicBlock::Create(context->potassium_context, "then", function);
	llvm::BasicBlock *else_block = llvm::BasicBlock::Create(context->potassium_context, "else");
	llvm::BasicBlock *merge_block = llvm::BasicBlock::Create(context->potassium_context, "ifcont");

    context->builder.CreateCondBr(test_value, then_block, else_block);
// Then block
    context->builder.SetInsertPoint(then_block);
	llvm::Value* then_value = then_exp_->codegen(symbols, context);
	if (!then_value)
		return nullptr;

    context->builder.CreateBr(merge_block);
	then_block = context->builder.GetInsertBlock();
// Else block
	function->getBasicBlockList().push_back(else_block);
    context->builder.SetInsertPoint(else_block);

	llvm::Value* else_value = else_exp_->codegen(symbols, context);
	if (!else_value)
		return nullptr;

	context->builder.CreateBr(merge_block);
	else_block = context->builder.GetInsertBlock();

    // Merged IF Then Else
    function->getBasicBlockList().push_back(merge_block);
    context->builder.SetInsertPoint(merge_block);
	llvm::PHINode* phi =
            context->builder.CreatePHI(llvm::Type::getDoubleTy(context->potassium_context), 2, "iftmp");

	phi->addIncoming(then_value, then_block);
	phi->addIncoming(else_value, else_block);
	return phi;
}


double ASTFunction::eval(SymbolTable &symbols, LLVMContext* context) {
	symbols.setFun(name_, std::unique_ptr<ASTFunction>(this));
    if(context)
        codegen(symbols, context);
	return 0.0;
}

llvm::Value* ASTFunction::codegen(SymbolTable& symbols, LLVMContext* context) {
	// build the function type

	size_t params_size = params_.size() == 0? 0 : params_.size() -1;
	std::vector<llvm::Type*> proto_arg_vector(params_size,
	                           llvm::Type::getDoubleTy(context->potassium_context));

	llvm::FunctionType* function_type =
		llvm::FunctionType::get(llvm::Type::getDoubleTy(context->potassium_context), proto_arg_vector, false);

	llvm::Function* function =
		llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, name_, context->potassium_module.get());
	uint32_t idx = 0;
	for (auto &Arg : function->args())
	{
		Arg.setName(params_[idx + 1]->name());
		idx++;
	}

	 // insert the args in to the function scope
	SymbolTable function_scope_symbols(&symbols);

	for (auto &Arg : function->args())
		function_scope_symbols.setVar(Arg.getName(), &Arg);
	// Build the function
	llvm::BasicBlock* body = llvm::BasicBlock::Create(context->potassium_context, "func_body", function);
    context->builder.SetInsertPoint(body);

	if (llvm::Value* ret_value = body_->codegen(function_scope_symbols, context)) {
		// Finish off the function.
        context->builder.CreateRet(ret_value);
        if(context->fpm)
            context->fpm->run(*function);
		//Validate the generated code, checking for consistency.
		llvm::verifyFunction(*function, &llvm::errs());
	}

	return nullptr;
}

double ASTFunctionCall::eval(SymbolTable &symbols, LLVMContext* context) {
	SymbolTable function_scope_symbols(&symbols);
	ASTFunction* funct = symbols.getFun(name_);
	if(funct == nullptr) {
		std::cout << "No function defined: " << name_ << std::endl;
		return 0.0;
	}
	auto& funct_prams = funct->params();
	for(int i = 0; i < params_.size(); i++) {
		function_scope_symbols.setVar(funct_prams[i+1]->name(), params_[i]->eval(symbols, context));
	}
	return funct->body()->eval(function_scope_symbols, context);
}

llvm::Value* ASTFunctionCall::codegen(SymbolTable& symbols, LLVMContext* context){
// Look up the name in the global module table.
    SymbolTable function_scope_symbols(&symbols);
	llvm::Function *function = function_scope_symbols.getFun(name_, context);
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
        paramsVal.push_back(params_[i]->codegen(function_scope_symbols, context));
    }

    return context->builder.CreateCall(function, paramsVal, "calltmp");
}

double ASTPrint::eval(SymbolTable& symbols, LLVMContext* context) {
    double result = 0.0;
    if(context)
    {
        if(context->compile_only)
            return result;

        ASTFunction f("__print_expr",std::move(value_),std::vector<std::unique_ptr<ASTVariable>>());
        f.codegen(symbols, context);
        context->jit->addModule(std::move(context->potassium_module));
        auto jit_symbol = context->jit->findSymbol("__print_expr");
        double (*jitFunc)() = (double (*)())(intptr_t)cantFail(jit_symbol.getAddress());
        result = jitFunc();
        context->newModule();
    } else {
        result = value_->eval(symbols, context);
    }

    std::cout << result << std::endl;
    return result;
}

double ASTBlock::eval(SymbolTable &symbols, LLVMContext *context) {
    SymbolTable block_scope(&symbols);
    double return_val;
    for(auto& exp : expressions_) {
        return_val = exp->eval(block_scope, context);
    }

    return return_val;
}

llvm::Value* ASTBlock::codegen(SymbolTable &symbols, LLVMContext *context) {
    SymbolTable block_scope(&symbols);
    llvm::Value* return_val;
    for(auto& exp : expressions_) {
        return_val = exp->codegen(block_scope, context);
    }

    return return_val;
}

}}