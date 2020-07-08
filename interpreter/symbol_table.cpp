#include "symbol_table.h"

namespace potassium { namespace  ast {
	double SymbolTable::get(std::string name) {
		auto it = table_.find(name);
		if(it != table_.end())
			return it->second;
		return 0.0; // this shoud be an error
	}

	void SymbolTable::set(std::string name, double value) {
		table_[name] = value;
	}
}}