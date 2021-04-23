#compiler test


set(INCLUDE ${ANTLR_INCLUDE_DIRS} ${CMAKE_SOURCE_DIR}/compiler)

message("-- Test include ${INCLUDE}")

file(GLOB COMPILER_SOURCE "${CMAKE_SOURCE_DIR}/compiler/antlr/*.cpp" "${CMAKE_SOURCE_DIR}/compiler/src/codeGen.cpp")

add_executable(cbTest basicStmtTest.cpp ${COMPILER_SOURCE} testHelper.h)

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC MCJIT Support mcdisassembler nativecodegen IRReader)
target_link_libraries(cbTest antlr4-runtime ${llvm_libs})
target_include_directories(cbTest PUBLIC ${INCLUDE})
get_target_property(debug cbTest INTERFACE_INCLUDE_DIRECTORIES)
message("${debug}")
