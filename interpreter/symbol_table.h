#pragma once
#include <map>
#include <string>
#include <memory>
#include <iostream>

namespace potassium { namespace ast {
class ASTFunction;

class SymbolTable {
public:
	SymbolTable() = default;
	SymbolTable(SymbolTable* parent) : parent_table_(parent) {}
	double get(std::string);
	void   set(std::string, double);

	ASTFunction* getFun(std::string);
	void setFun(std::string, std::unique_ptr<ASTFunction>);
private:
	std::map<std::string, double> table_;
	std::map<std::string, std::unique_ptr<ASTFunction>> func_table_;
	SymbolTable* parent_table_;
};

}}