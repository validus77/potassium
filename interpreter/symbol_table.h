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

class SymbolTable {
public:
	SymbolTable() = default;
	SymbolTable(SymbolTable* parent) : parent_table_(parent) {}
	double get(std::string);
	llvm::Value* getVar(std::string);

	void set(std::string, double);
	void set(std::string, llvm::Value*);

	ASTFunction* getFun(std::string);
	void setFun(std::string, std::unique_ptr<ASTFunction>);

	std::vector<std::string> getFuns();
private:
	std::map<std::string, std::pair<double, llvm::Value*>> table_;
	std::map<std::string, std::unique_ptr<ASTFunction>> func_table_;
	SymbolTable* parent_table_;
};

}}