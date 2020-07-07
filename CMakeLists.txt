cmake_minimum_required(VERSION 3.16)
project(potassium)

set(CMAKE_CXX_STANDARD 14)

if (APPLE)
    set(ANTLR4_PATH "../antlr4-cpp-runtime-4")
    link_directories(${ANTLR4_PATH}/lib)
elseif(UNIX)
    set(ANTLR4_PATH "/usr/local/include/")
endif()

file(GLOB Parser_Sources SRC_FILES "./potassium/*.cpp")
file(GLOB Interpreter_Sources "./interpreter/*.cpp")
add_executable(potassium ${Parser_Sources} ${Interpreter_Sources} main.cpp)

target_include_directories(potassium PRIVATE ${ANTLR4_PATH}/antlr4-runtime)
TARGET_LINK_LIBRARIES(potassium antlr4-runtime.a)