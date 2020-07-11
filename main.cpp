#include <iostream>
#include <cstdlib>

#include "./thrid-party/cxxopts.h"
#include "llvm/Support/raw_ostream.h"

#include "./potassium/potassium_parser.h"
#include "./potassium/potassium_lexer.h"
#include "./interpreter/potassium_interpreter_visitor.h"
#include "./interpreter/potassium_ast.h"


using namespace std;
using namespace antlr4;


void printBanner(bool jit = false) {
	cout << "| ___ \\   | |                    (_)                \n"
	        "| |_/ /__ | |_ __ _ ___ ___  __ _ _ _   _ _ __ ___  \n"
	        "|  __/ _ \\| __/ _` / __/ __|/ _` | | | | | '_ ` _ \\ \n"
	        "| | | (_) | || (_| \\__ \\__ \\ (_| | | |_| | | | | | |\n"
	        "\\_|  \\___/ \\__\\__,_|___/___/\\__,_|_|\\__,_|_| |_| |_|\n"
		 "                                                    " << endl;
	cout << "Version: 0.0.1" << endl;
	if(jit) {
		auto TargetTriple = llvm::sys::getDefaultTargetTriple();
		cout << "JIT compiler enabled, Arch: "<< TargetTriple.c_str() << endl;
	} else {
		cout << "JIT compiler disabled" << endl;
	}
}

std::string env(const char *name)
{
    const char *ret = getenv(name);
    if (!ret) return std::string();
    return std::string(ret);
}

void runPotassiumLine(std::string line, potassium::ast::SymbolTable& globals,
	potassium::potassium_interpreter_visitor& visitor, potassium::ast::LLVMContext* llvmContext) {
	std::stringstream stream;
	stream << line << std::endl;
	ANTLRInputStream input(stream);
	potassium::potassium_lexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	potassium::potassium_parser parser(&tokens);
	potassium::potassium_parser::LineContext* tree = parser.line();
    try {
        auto* program = visitor.visitLine(tree).as<potassium::ast::ASTNode*>();
        program->eval(globals, llvmContext);
    }
    catch(...)
    {
        cout << "parse error, ignoring line: " << line << endl;
        return;
    }
}

int main(int argc, char** argv)
{
    cxxopts::Options options("Potassium", "Minimal functional programming language");

    options.add_options()
            ("n,no-jit", "Disable jit compiler", cxxopts::value<bool>()->default_value("false"))
            ("O, O0", "Optimization disabled (applies only to jit)")
            ("f,file", "Source file to run, if in interactive mode will run first", cxxopts::value<std::string>())
            ("c,cmd-line", "Do not run in interactive mode", cxxopts::value<bool>()->default_value("false"))
            ("d, debug", "Will print llvm IR in interactive mode (if jit not disabled)")
            ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    bool enableJIT = !result.count("no-jit");

	std::unique_ptr<potassium::ast::LLVMContext> llvmContext;

	if(enableJIT) {
        llvmContext = std::make_unique<potassium::ast::LLVMContext>(!result.count("O0"));
	}

	potassium::potassium_interpreter_visitor visitor;
	potassium::ast::SymbolTable global_symbols;

	// check if we are loading a file or interactive

	bool interactive_mode = !result.count("cmd-line");

	if(interactive_mode)
		printBanner(enableJIT);

	//Read the prelude file
    string prelude_path = env("POTASSIUM_PATH");
	ifstream preludeFile;
	preludeFile.open(std::string(prelude_path) + "prelude.k");
	if (!preludeFile) {
		if(interactive_mode)
			cout << "Unable to open prelude file, no prelude functions loaded. Try setting POTASSIUM_PATH" << endl;
	} else {
		if(interactive_mode)
			cout << "Loading prelude functions" << endl;
		std::string line;
		while (std::getline(preludeFile, line))
		{
			runPotassiumLine(line, global_symbols, visitor, llvmContext.get());
		}
		if(interactive_mode)
			cout << "Done" << endl;
	}

    if(result.count("file")) {
        ifstream file;
        file.open(result["file"].as<std::string>());
        if (!file) {
            cout << "Can not open file: " << result["file"].as<std::string>() << endl;
        } else {
            std::string line;
            while (std::getline(file, line)) {
                runPotassiumLine(line, global_symbols, visitor, llvmContext.get());
            }
        }
    }

	if(interactive_mode)
	{
		string str_input;
		cout << "type quit() to exit" << endl;
		if(enableJIT && result.count("O0"))
		    cout << "Optimization disabled" << endl;
        if(enableJIT && result.count("debug"))
            cout << "Debug mode enabled" << endl;
		while (str_input != "quit()")
		{
			cout << "> ";
			getline(cin, str_input);
			if (str_input == "quit()")
			{
				cout << "Bye" << endl;
				break;
			} else if( str_input == "list_fun()") {
			    cout << "Functions: " << endl;
				for(auto& fun : global_symbols.getFuns()) {
					cout << "\t" << fun << endl;
				}
			} else
			{
				runPotassiumLine(str_input, global_symbols, visitor, llvmContext.get());

				if(enableJIT && result.count("debug")) {
                    llvmContext->potassium_module->print(llvm::outs(), nullptr);
                    cout << endl;
                }
			}
		}
	}

    return 0;
}