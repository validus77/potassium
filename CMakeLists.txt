cmake_minimum_required(VERSION 3.16)
project(potassium)

set(CMAKE_CXX_STANDARD 14)

link_directories("../antlr4-cpp-runtime-4/lib")

file(GLOB Parser_Sources SRC_FILES "./potassium/*.cpp")
file(GLOB Interpreter_Sources "./interpreter/*.cpp")
add_executable(potassium ${Parser_Sources} ${Interpreter_Sources} main.cpp)

target_include_directories(potassium PRIVATE "../antlr4-cpp-runtime-4/antlr4-runtime")
TARGET_LINK_LIBRARIES(potassium antlr4-runtime.a)