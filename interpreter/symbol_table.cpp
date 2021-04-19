#include "symbol_table.h"
#include "potassium_ast.h"

namespace potassium { namespace  ast {
	double SymbolTable::getVar(std::string name) {
		auto it = table_.find(name);
		if(it != table_.end())
			return it->second.float_val;
		else if(parent_table_) {
			return parent_table_->getVar(name);
		}
		return 0.0; // this shoud be an error
	}

	llvm::Value* SymbolTable::getVar(std::string name, LLVMContext* context) {
		auto it = table_.find(name);
		if(it != table_.end())
			return it->second.llvm_value;
		else if(parent_table_) {
			return parent_table_->getVar(name, context);
		}
		return nullptr; // this shoud be an error
	}

	KType SymbolTable::getVarType(std::string name, LLVMContext* context) {
        auto it = table_.find(name);
        if(it != table_.end())
            return it->second.type;
        else if(parent_table_) {
            return parent_table_->getVarType(name, context);
        }
        return KType::NULL_TYPE; // this should be an error
	}

        void SymbolTable::setVar(std::string name, double value, const KType& type) {
		auto it = table_.find(name);
		if(it != table_.end())
		{
			it->second.float_val = value;
		} else {
			table_[name] = VarRecord(name, value, nullptr, type);
		}
	}

	void SymbolTable::setVar(std::string name, llvm::Value* value, const KType& type) {
		auto it = table_.find(name);
		if(it != table_.end())
		{
			it->second.llvm_value = value;
		} else {
			table_[name] = VarRecord(name, 0.0, value, type);
		}
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

	llvm::Function* SymbolTable::getFun(std::string name, LLVMContext* context) {

        if(llvm::Function* fun = context->potassium_module->getFunction(name))
            return fun;

        if(ASTFunction* ast_function = getFun(name)) {
            size_t params_size = ast_function->params().size() == 0 ? 0 : ast_function->params().size() - 1;
            std::vector<llvm::Type *> proto_arg_vector(params_size,
                                                       llvm::Type::getDoubleTy(context->potassium_context));

            llvm::FunctionType *function_type =
                    llvm::FunctionType::get(llvm::Type::getDoubleTy(context->potassium_context), proto_arg_vector,
                                            false);

            llvm::Function *function =
                    llvm::Function::Create(function_type, llvm::Function::ExternalLinkage, name,
                                           context->potassium_module.get());

            return function;
        }
        return nullptr;
	}

	void SymbolTable::setFun(std::string name, std::unique_ptr<ASTFunction> fun) {
		    func_table_[name] = std::move(fun);
	}

    std::vector<std::string> SymbolTable::getFuns() {
		std::vector<std::string> out;
		for(auto& fun : func_table_) {
			out.emplace_back(fun.first);
		}
		return out;
	}
}}