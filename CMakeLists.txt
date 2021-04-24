cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(ANTLR_INCLUDE_DIRS "/usr/include/antlr4-runtime")

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using LLVM Include from: ${LLVM_INCLUDE_DIRS}")
message(STATUS "${CMAKE_CXX_FLAGS}")

include_directories(${ANTLR_INCLUDE_DIRS} compiler)

add_subdirectory(runtime ${CMAKE_BINARY_DIR}/runtime)
add_subdirectory(compiler ${CMAKE_BINARY_DIR}/compiler)
add_subdirectory(test ${CMAKE_BINARY_DIR}/test)

enable_testing()
set(UNITTEST_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test)
add_test(NAME test COMMAND cbTest WORKING_DIRECTORY ${UNITTEST_OUTPUT_DIR})