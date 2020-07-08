#pragma once
#include <map>
#include <string>
#include <memory>
#include <iostream>

namespace potassium { namespace ast {
class SymbolTable {
public:
	double get(std::string);
	void   set(std::string, double);
private:
	std::map<std::string, double> table_;
};

}}