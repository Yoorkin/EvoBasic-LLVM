cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -v -lstdc++")

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
message(
        WARNING "Vcpkg toolchain file undefined. "
        "please add argument like:\n"
        "   -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake\n"
        "For more information in https://github.com/Yoorkin/classicBasic/wiki/HowToBuild"
)
else()
    message(STATUS "Using toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
    include(${CMAKE_TOOLCHAIN_FILE})
endif()

find_library(ANTLR_LIB NAMES libantlr4-runtime.so libantlr4-runtime.a PATH_SUFFIXES vcpkg)
find_path(ANTLR_INCLUDE NAMES antlr4-runtime/antlr4-runtime.h)
message(STATUS "Using Antlr4 library: ${ANTLR_LIB}")
message(STATUS "Using Antlr4 include from: ${ANTLR_INCLUDE}")

execute_process(COMMAND cmake -P ${CMAKE_SOURCE_DIR}/cmake/antlrCppGen.cmake)

find_package(LLVM REQUIRED CONFIG)
message(STATUS "Found LLVM ${LLVM_PACKAGE_VERSION}")
if(NOT ${LLVM_PACKAGE_VERSION} EQUAL "11.1.0")
    message(WARNING "The recommended LLVM version is 11.1.0 . This version of LLVM may have different interfaces and cause unexpected behavior."
            "If you want to download and built LLVM 11.1.0 automatically,try:"
            "cmake -P <path to this project>/cmake/configureLLVM.cmake"
            )
endif()
message(STATUS "Using LLVMConfig.cmake in: ${LLVM_DIR}")
message(STATUS "Using LLVM Library from: ${LLVM_LIBRARY_DIRS}")
message(STATUS "Using LLVM Include from: ${LLVM_INCLUDE_DIRS}")

set(ANTLR_INCLUDE_DIRS
        ${ANTLR_INCLUDE}
        ${ANTLR_INCLUDE}/antlr4-runtime
        ${ANTLR_INCLUDE}/antlr4-runtime/atn
        ${ANTLR_INCLUDE}/antlr4-runtime/dfa
        ${ANTLR_INCLUDE}/antlr4-runtime/misc
        ${ANTLR_INCLUDE}/antlr4-runtime/support
        ${ANTLR_INCLUDE}/antlr4-runtime/tree
        ${ANTLR_INCLUDE}/antlr4-runtime/utf8
)
set(INCLUDE_DIRS ${ANTLR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS} compiler)
include_directories(${INCLUDE_DIRS})
add_subdirectory(runtime ${CMAKE_BINARY_DIR}/runtime)
add_subdirectory(compiler ${CMAKE_BINARY_DIR}/compiler)
add_subdirectory(test ${CMAKE_BINARY_DIR}/test)

enable_testing()
set(UNITTEST_OUTPUT_DIR ${CMAKE_BINARY_DIR}/test)
add_test(NAME test COMMAND cbTest WORKING_DIRECTORY ${UNITTEST_OUTPUT_DIR})
