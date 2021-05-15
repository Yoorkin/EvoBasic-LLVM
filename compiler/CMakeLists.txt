cmake_minimum_required(VERSION 3.0.0)
project(cbCompiler VERSION 1.0.1)

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

find_library(ANTLR_LIB NAMES libantlr4-runtime.so libantlr4-runtime.a PATH_SUFFIXES vcpkg)
find_path(ANTLR_INCLUDE NAMES antlr4-runtime/antlr4-runtime.h)
message(STATUS "Using Antlr4 library: ${ANTLR_LIB}")
message(STATUS "Using Antlr4 include from: ${ANTLR_INCLUDE}")

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

add_definitions(${LLVM_DEFINITIONS})
add_definitions(-DLLVM_DISABLE_ABI_BREAKING_CHECKS_ENFORCING=1)

file(GLOB COMPILER_SOURCE "src/*.cpp" "src/*.h" "antlr/*.cpp")
add_executable(cbCompiler ${COMPILER_SOURCE} src/errorListener.cpp)

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC mcdisassembler MCJIT Support nativecodegen IRReader)
target_link_libraries(cbCompiler antlr4-runtime ${llvm_libs})
target_include_directories(cbCompiler PRIVATE ${ANTLR_INCLUDE_DIRS} ${LLVM_INCLUDE_DIRS})

get_property(CBCOMPILER_INCLUDE_CHECK TARGET cbCompiler PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "cbCompiler include ${CBCOMPILER_INCLUDE_CHECK}")