#include <iostream>
#include <cstdlib>

#include "./thrid-party/cxxopts.h"

#include "llvm/Support/FileSystem.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/TargetRegistry.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Target/TargetMachine.h"
#include "llvm/Target/TargetOptions.h"
#include "llvm/Support/raw_ostream.h"


#include "version.h"
#include "./potassium/potassium_parser.h"
#include "./potassium/potassium_lexer.h"
#include "./interpreter/potassium_interpreter_visitor.h"

using namespace std;
using namespace antlr4;


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

int buildObjFile(potassium::ast::LLVMContext* context, const string& outfile, cxxopts::ParseResult& results) {
    std::error_code error_code;
    llvm::raw_fd_ostream obj_stream(outfile, error_code, llvm::sys::fs::OF_None);

    if (error_code) {
        llvm::errs() << "Could not open file: " << error_code.message();
        return -2;
    }

    auto target_triple = llvm::sys::getDefaultTargetTriple();

    llvm::InitializeNativeTarget();
    llvm::InitializeNativeTargetAsmPrinter();

    std::string error;
    auto* target = llvm::TargetRegistry::lookupTarget(target_triple, error);

    string CPU = "generic";
    string Features = "";

    llvm::TargetOptions opt;
    auto realoc_modle = llvm::Optional<llvm::Reloc::Model>();
    auto target_machine = target->createTargetMachine(target_triple, CPU, Features, opt, realoc_modle);
    context->potassium_module->setDataLayout(target_machine->createDataLayout());
    context->potassium_module->setTargetTriple(target_triple);

    llvm::legacy::PassManager pass;
    auto file_type = results.count("S")? llvm::CGFT_AssemblyFile : llvm::CGFT_ObjectFile;


    if (target_machine->addPassesToEmitFile(pass, obj_stream, nullptr, file_type)) {
        llvm::errs() << "TargetMachine can't emit a file of this type";
        return -3;
    }

    pass.run(*context->potassium_module);
    obj_stream.flush();
    return 0;
}

int main(int argc, char** argv) {
    cxxopts::Options options("Potassium", "Minimal functional programming language");

    options.add_options()
            ("i,file", "Source file(s) to compile", cxxopts::value<vector<string>>())
            ("o,output", "Object file to output", cxxopts::value<string>())
            ("S", "Only generate asm file")
            ("O,optimization", "Optimization level 0,1", cxxopts::value<int>()->default_value("1"))
            ("v, version", "Print version number")
            ("h,help", "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    if (result.count(("version"))) {
        auto TargetTriple = llvm::sys::getDefaultTargetTriple();
        cout << VER_STR << " (" << TargetTriple.c_str() << ")" << endl;
        exit(0);
    }

    bool optimize = result["O"].as<int>() == 1;
    auto llvmContext = std::make_unique<potassium::ast::LLVMContext>(optimize, true);

    potassium::potassium_interpreter_visitor visitor;
    potassium::ast::SymbolTable global_symbols;

    if(result.count("file")) {
        for (auto &file_name : result["file"].as <vector<string>>()) {
            ifstream file;
            file.open(file_name);
            if (!file) {
                cout << "Can not open file: " << file_name << endl;
            } else {
	            bool in_block = false;
	            stringstream  multi_line_input;
                std::string line;
                while (std::getline(file, line)) {
	                multi_line_input << line << endl;
	                if (line.find('{') != std::string::npos) {
		                in_block = true;
	                }
	                if(in_block && (line.find('}') != std::string::npos)) {
		                in_block = false;
	                }
	                if(!in_block) {
		                runPotassiumLine(multi_line_input.str(), global_symbols, visitor, llvmContext.get());
		                multi_line_input.str(string());
	                }
                }
            }
        }
    }

    if(result["output"].count())
        return buildObjFile(llvmContext.get(), result["output"].as<string>(), result);
    return -1;

}
