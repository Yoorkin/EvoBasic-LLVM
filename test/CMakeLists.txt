#compiler test
#message(STATUS "Test include ${INCLUDE_DIRS}")

file(GLOB COMPILER_SOURCE "${CMAKE_SOURCE_DIR}/compiler/antlr/*.cpp" "${CMAKE_SOURCE_DIR}/compiler/src/codeGen.cpp")

add_executable(cbTest basicStmtTest.cpp ${COMPILER_SOURCE} testHelper.h)

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC MCJIT Support mcdisassembler nativecodegen IRReader)
target_link_libraries(cbTest antlr4-runtime ${llvm_libs})
