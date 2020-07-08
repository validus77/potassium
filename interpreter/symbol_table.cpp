#include "symbol_table.h"
#include "potassium_ast.h"

namespace potassium { namespace  ast {
	double SymbolTable::get(std::string name) {
		auto it = table_.find(name);
		if(it != table_.end())
			return it->second;
		else if(parent_table_) {
			return parent_table_->get(name);
		}
		return 0.0; // this shoud be an error
	}

	void SymbolTable::set(std::string name, double value) {
		table_[name] = value;
	}

	ASTFunction* SymbolTable::getFun(std::string name) {
		auto it = func_table_.find(name);
		if(it != func_table_.end())
			return it->second.get();

		else if(parent_table_) {
			return parent_table_->getFun(name);
		}
		return nullptr; // this shoud be an error
	}

	void SymbolTable::setFun(std::string name, std::unique_ptr<ASTFunction> fun) {
		func_table_[name] = std::move(fun);
	}
}}