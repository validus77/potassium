#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <vector>

// LLVM
#include "llvm/ADT/APFloat.h"
#include "llvm/ADT/STLExtras.h"
#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Transforms/InstCombine/InstCombine.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Scalar/GVN.h"
#include "llvm/Support/TargetSelect.h"

#include "potassium_git.h"
#include "symbol_table.h"

namespace potassium { namespace ast {

struct LLVMContext {
    LLVMContext(bool optimize = false, bool compile = false):
        builder(potassium_context),
        optimize_(optimize),
        compile_only(compile) {

        llvm::InitializeNativeTarget();
        llvm::InitializeNativeTargetAsmPrinter();
        llvm::InitializeNativeTargetAsmParser();

        jit = std::make_unique<llvm::orc::PotassiumJIT>();

        newModule();
    }

    void newModule() {
        potassium_module = std::unique_ptr<llvm::Module>(new llvm::Module("potassium jit",potassium_context));
        potassium_module->setDataLayout(jit->getTargetMachine().createDataLayout());
        if(optimize_) {
            fpm = std::make_unique<llvm::legacy::FunctionPassManager>(potassium_module.get());
            fpm->add(llvm::createInstructionCombiningPass());
            fpm->add(llvm::createReassociatePass());
            fpm->add(llvm::createGVNPass());
            fpm->add(llvm::createCFGSimplificationPass());
            fpm->doInitialization();
        }
    }

    llvm::LLVMContext potassium_context;
    llvm::IRBuilder<> builder;
    std::unique_ptr<llvm::Module> potassium_module;
    std::unique_ptr<llvm::legacy::FunctionPassManager> fpm;
    std::unique_ptr<llvm::orc::PotassiumJIT> jit;
    bool compile_only;

private:
    bool optimize_;
};

class ASTNode {
public:
    ASTNode() = default;

	virtual ~ASTNode() {}
	virtual double eval(SymbolTable& symbols, LLVMContext* context) {return 0.0;}
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context) {return nullptr;}

protected:
	bool eq(double lhs, double rhs);
};

class ASTValue : public ASTNode {
public:
	ASTValue(double value) : value_(value) {}
	virtual double eval(SymbolTable& symbols, LLVMContext* context) { return value_;}
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context) {
		return llvm::ConstantFP::get(context->potassium_context, llvm::APFloat(value_));}
private:
	double value_;
};

class ASTVariable : public ASTNode {
public:
	ASTVariable(const std::string name) : name_(name) {}
	const std::string& name() { return name_; }
	virtual double eval(SymbolTable& symbols, LLVMContext* context) {return symbols.getVar(name_);}
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context) {return symbols.getVar(name_, context);}
private:
	std::string name_;
};

class ASTBinaryOperation : public ASTNode {
public:
	ASTBinaryOperation(char op, std::unique_ptr<ASTNode> lhs, std::unique_ptr<ASTNode> rhs) :
		op_(op), lhs_(std::move(lhs)), rhs_(std::move(rhs)) {}

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);

private:
	char op_;
	std::unique_ptr<ASTNode> lhs_;
	std::unique_ptr<ASTNode> rhs_;
};

class ASTUnaryOperation : public ASTNode {
public:
	ASTUnaryOperation(char op, std::unique_ptr<ASTNode> rhs) :
		op_(op), rhs_(std::move(rhs)) {}

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
    virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);

private:
	char op_;
	std::unique_ptr<ASTNode> rhs_;
};


class ASTAssigment : public ASTNode {
public:
	ASTAssigment(std::unique_ptr<ASTVariable> variable, std::unique_ptr<ASTNode> value) :
		variable_(std::move(variable)), value_(std::move(value)) {}

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);
private:
	std::unique_ptr<ASTVariable> variable_;
	std::unique_ptr<ASTNode> value_;

};

class ASTPrint : public ASTNode {
public:
	ASTPrint(std::unique_ptr<ASTNode> value) : value_(std::move(value)) {}
	virtual double eval(SymbolTable& symbols, LLVMContext* context);
private:
	std::unique_ptr<ASTNode> value_;
};

class ASTCond : public ASTNode {
public:
	ASTCond(std::unique_ptr<ASTNode> test_exp, std::unique_ptr<ASTNode> then_exp, std::unique_ptr<ASTNode> else_exp) :
		test_exp_(move(test_exp)), then_exp_(std::move(then_exp)), else_exp_(std::move(else_exp)) {}

	ASTCond(std::unique_ptr<ASTNode> test_exp, std::unique_ptr<ASTNode> then_exp) :
		test_exp_(move(test_exp)), then_exp_(std::move(then_exp)) {}

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);
private:
	std::unique_ptr<ASTNode> test_exp_;
	std::unique_ptr<ASTNode> then_exp_;
	std::unique_ptr<ASTNode> else_exp_;
};

class ASTFunction : public ASTNode {
public:
	ASTFunction(std::string name, std::unique_ptr<ASTNode> body, std::vector<std::unique_ptr<ASTVariable>> params) :
	name_(name), body_(std::move(body)), params_(std::move(params)) {}

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
	virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);

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

	virtual double eval(SymbolTable& symbols, LLVMContext* context);
    virtual llvm::Value* codegen(SymbolTable& symbols, LLVMContext* context);

private:
	std::string name_;
	std::vector<std::unique_ptr<ASTNode>> params_;
};

}}