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

enum class KType {
    INT,
    FLOAT,
    BYTE,
    STRING,
    NULL_TYPE
};

struct VarRecord {
    VarRecord() = default;

    VarRecord(const std::string& _name, double _float_val, llvm::Value* _value, const KType& _type) :
    name(_name), type(_type), float_val(_float_val), llvm_value(_value)
    {}

    std::string name;
    double float_val;
    llvm::Value* llvm_value;
    KType type;
};

class SymbolTable {
public:
	SymbolTable() = default;
	SymbolTable(SymbolTable* parent) : parent_table_(parent) {}
	double getVar(std::string);
	llvm::Value* getVar(std::string, LLVMContext*);
	KType getVarType(std::string, LLVMContext*);

	void setVar(std::string, double, const KType& type);
	void setVar(std::string, llvm::Value*, const KType& type);

	ASTFunction* getFun(std::string);
    llvm::Function* getFun(std::string, LLVMContext* context);

	void setFun(std::string, std::unique_ptr<ASTFunction>);


    std::vector<std::string> getFuns();
private:
	std::map<std::string, VarRecord> table_;
	std::map<std::string, std::unique_ptr<ASTFunction>> func_table_;
	SymbolTable* parent_table_;
};

}}