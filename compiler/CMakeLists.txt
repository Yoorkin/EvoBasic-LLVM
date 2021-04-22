cmake_minimum_required(VERSION 3.0.0)
project(cbCompiler VERSION 1.0.1)

#生成antlrcpp-parser代码
execute_process(
    COMMAND
    cd compiler/grammar &&
    antlr4 Basic.g4 -o ../antlr -Dlanguage=Cpp -visitor -no-listener &&
    cd ../../
)

include_directories(${ANTLR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
add_compile_definitions(LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1)

file(GLOB COMPILER_SOURCE "src/*.cpp" "antlr/*.cpp")

add_executable(cbCompiler ${COMPILER_SOURCE})

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC mcdisassembler MCJIT Support nativecodegen IRReader)
target_link_libraries(cbCompiler antlr4-runtime ${llvm_libs})