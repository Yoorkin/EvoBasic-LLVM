cmake_minimum_required(VERSION 3.0.0)
project(cbCompiler VERSION 1.0.1)

message(STATUS "Compiler include ${INCLUDE_DIRS}")

add_definitions(${LLVM_DEFINITIONS})
add_definitions(-DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1)

file(GLOB COMPILER_SOURCE "src/*.cpp" "src/*.h" "antlr/*.cpp")
add_executable(cbCompiler ${COMPILER_SOURCE} src/errorListener.cpp)

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC mcdisassembler MCJIT Support nativecodegen IRReader)
target_link_libraries(cbCompiler antlr4-runtime ${llvm_libs})