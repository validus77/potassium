#pragma once
#include <map>
#include <string>
#include <memory>
#include <iostream>

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


namespace potassium { namespace ast {
class ASTFunction;
class LLVMContext;

struct Var {
    double value = 0.0;
    llvm::AllocaInst* llvm_value = nullptr;
    bool is_mutable = false;
};
class SymbolTable {
public:
	SymbolTable() = default;
	SymbolTable(SymbolTable* parent) : parent_table_(parent) {}
	double getVar(std::string);
    llvm::AllocaInst* getVar(std::string, LLVMContext*);

	void setVar(std::string, double, bool);
	void setVar(std::string, llvm::AllocaInst*, bool);
	bool varIsMut(std::string);

	ASTFunction* getFun(std::string);
    llvm::Function* getFun(std::string, LLVMContext* context);

	void setFun(std::string, std::unique_ptr<ASTFunction>);


    std::vector<std::string> getFuns();
private:
	std::map<std::string, Var> table_;
	std::map<std::string, std::unique_ptr<ASTFunction>> func_table_;
	SymbolTable* parent_table_;
};

}}