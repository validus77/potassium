#include <iostream>
#include "antlr4-runtime.h"
#include "./potassium/potassium_parser.h"
#include "./potassium/potassium_lexer.h"
#include "./interpreter/potassium_interpreter_visitor.h"
#include "./interpreter/potassium_ast.h"
#include "./interpreter/symbol_table.h"

using namespace std;
using namespace antlr4;

int main()
{

    string str_input;
    std::stringstream stream;
    potassium::potassium_interpreter_visitor visitor;
    potassium::ast::SymbolTable global_symbols;

    while(str_input != "quit()")
    {
        getline(cin, str_input);
        stream << str_input << std::endl;

        ANTLRInputStream input(stream);
        potassium::potassium_lexer lexer(&input);
        CommonTokenStream tokens(&lexer);
        potassium::potassium_parser parser(&tokens);
        potassium::potassium_parser::LineContext* tree = parser.line();
        auto* program = visitor.visitLine(tree).as<potassium::ast::ASTNode*>();
	    program->eval(global_symbols);



    }

    return 0;
}

