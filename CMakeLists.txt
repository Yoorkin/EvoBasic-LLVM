cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
#生成antlr cpp代码
execute_process(COMMAND antlr4 Basic.g4 -o antlr -Dlanguage=Cpp -visitor -no-listener)

find_package(LLVM REQUIRED CONFIG)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O3")
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "sdfsadf ${CMAKE_CXX_FLAGS}")

file(COPY test.txt DESTINATION ${PROJECT_BINARY_DIR})

include(CTest)
enable_testing()

include_directories("/usr/include/antlr4-runtime" ${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})
add_compile_definitions(LLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1)

file(GLOB antlrGrammar "./antlr/*.cpp")

add_executable(classicBasic main.cpp ${antlrGrammar})

llvm_map_components_to_libnames(llvm_libs Core ExecutionEngine Interpreter MC MCJIT Support nativecodegen)
target_link_libraries(classicBasic antlr4-runtime ${llvm_libs} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
