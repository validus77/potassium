cmake_minimum_required(VERSION 3.16)
project(potassium)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_RELEASE_INIT "-O3")
set(CMAKE_CXX_FLAGS_DEBUG_INIT "-O0")

if (APPLE)
    set(ANTLR4_PATH "../antlr4-cpp-runtime-4")
    link_directories(${ANTLR4_PATH}/lib)
    set(ENV{LLVM_DIR} /usr/local/opt/llvm/lib/cmake)
    find_package(LLVM REQUIRED CONFIG)
elseif(UNIX)
    set(ANTLR4_PATH "/usr/local/include/")
    set(LLVM_PATH "/usr/include/llvm")
    find_package(LLVM 10.0.0 REQUIRED CONFIG)
endif()

message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "LLVM_INCLUDE_DIRS: ${LLVM_INCLUDE_DIRS}")
message(STATUS "LLVM_DEFINITIONS: ${LLVM_DEFINITIONS}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")


file(GLOB Parser_Sources SRC_FILES "./potassium/*.cpp")
file(GLOB Interpreter_Sources "./interpreter/*.cpp")
add_definitions(${LLVM_DEFINITIONS})

add_executable(potassium-s ${Parser_Sources} ${Interpreter_Sources} shell.cpp)
add_executable(potassium-c ${Parser_Sources} ${Interpreter_Sources} compiler.cpp)


# Find the libraries that correspond to the LLVM components
# that we wish to use
llvm_map_components_to_libnames(
        llvm_libs
        Analysis
        Core
        ExecutionEngine
        InstCombine
        Object
        OrcJIT
        RuntimeDyld
        ScalarOpts
        Support
        TransformUtils
        native
        irreader
)

target_include_directories(potassium-s PRIVATE ${ANTLR4_PATH}/antlr4-runtime ${LLVM_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(potassium-s antlr4-runtime.a  ${llvm_libs})

target_include_directories(potassium-c PRIVATE ${ANTLR4_PATH}/antlr4-runtime ${LLVM_INCLUDE_DIRS})
TARGET_LINK_LIBRARIES(potassium-c antlr4-runtime.a  ${llvm_libs})