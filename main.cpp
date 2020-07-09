#include <iostream>
#include <fstream>
#include "./potassium/potassium_parser.h"
#include "./potassium/potassium_lexer.h"
#include "./interpreter/potassium_interpreter_visitor.h"
#include "./interpreter/potassium_ast.h"
#include "./interpreter/symbol_table.h"

using namespace std;
using namespace antlr4;


void printBanner() {
	cout << "| ___ \\   | |                    (_)                \n"
	        "| |_/ /__ | |_ __ _ ___ ___  __ _ _ _   _ _ __ ___  \n"
	        "|  __/ _ \\| __/ _` / __/ __|/ _` | | | | | '_ ` _ \\ \n"
	        "| | | (_) | || (_| \\__ \\__ \\ (_| | | |_| | | | | | |\n"
	        "\\_|  \\___/ \\__\\__,_|___/___/\\__,_|_|\\__,_|_| |_| |_|\n"
		 "                                                    " << endl;
	cout << "Version: 0.0.1" << endl;
}
void runPotassiumLine(std::string line, potassium::ast::SymbolTable& globals,
	potassium::potassium_interpreter_visitor& visitor) {
	std::stringstream stream;
	stream << line << std::endl;
	ANTLRInputStream input(stream);
	potassium::potassium_lexer lexer(&input);
	CommonTokenStream tokens(&lexer);
	potassium::potassium_parser parser(&tokens);
	potassium::potassium_parser::LineContext* tree = parser.line();
	auto* program = visitor.visitLine(tree).as<potassium::ast::ASTNode*>();
	program->eval(globals);
}

int main(int argc, char** argv)
{
	potassium::potassium_interpreter_visitor visitor;
	potassium::ast::SymbolTable global_symbols;

	// check if we are loading a file or interactive

	bool interactive_mode = (argc <  2);

	if(interactive_mode)
		printBanner();

	//Read the prelude file
	ifstream preludeFile;
	preludeFile.open("../resources/prelude.pt");
	if (!preludeFile) {
		if(interactive_mode)
			cout << "Unable to open prelude file, no prelude functions loaded" << endl;
	} else {
		if(interactive_mode)
			cout << "Loading prelude functions" << endl;
		std::string line;
		while (std::getline(preludeFile, line))
		{
			runPotassiumLine(line, global_symbols, visitor);
		}
		if(interactive_mode)
			cout << "Done" << endl;
	}

	if(interactive_mode)
	{
		string str_input;
		cout << "type quit() to exit" << endl;
		while (str_input != "quit()")
		{
			cout << "> ";
			getline(cin, str_input);
			if (str_input != "quit()")
				runPotassiumLine(str_input, global_symbols, visitor);
			else
				cout << "Bye" << endl;
		}
	} else {
		for(int i = 1; i < argc; i++) {
			ifstream file;
			file.open(argv[i]);
			if (!file) {
				cout << "Can not open file: " << argv[i] << endl;
			} else {
				std::string line;
				while (std::getline(file, line))
				{
					runPotassiumLine(line, global_symbols, visitor);
				}
			}
		}
	}


    return 0;
}

