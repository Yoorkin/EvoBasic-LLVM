cmake_minimum_required(VERSION 3.0.0)
include(${CMAKE_SOURCE_DIR}/cmake/env.cmake)
project(classicBasic VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(ANTLR_INCLUDE_DIRS "/usr/include/antlr4-runtime")
set(LLVM_DIR ${LLVM_INSTALL_PATH}/lib/cmake/llvm)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using LLVM Include from: ${LLVM_INCLUDE_DIRS}")

set(INCLUDE_DIRS ${ANTLR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS} compiler)
include_directories(${INCLUDE_DIRS})

add_subdirectory(runtime ${CMAKE_BINARY_DIR}/runtime)
add_subdirectory(compiler ${CMAKE_BINARY_DIR}/compiler)
add_subdirectory(test ${CMAKE_BINARY_DIR}/test)

enable_testing()
set(UNITTEST_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test)
add_test(NAME test COMMAND cbTest WORKING_DIRECTORY ${UNITTEST_OUTPUT_DIR})