#compiler test
message(STATUS "Test include ${INCLUDE_DIRS}")

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()

file(GLOB COMPILER_SOURCE "${CMAKE_SOURCE_DIR}/compiler/antlr/*.cpp" "${CMAKE_SOURCE_DIR}/compiler/src/codeGen.cpp")

add_executable(cbTest basicStmtTest.cpp ${COMPILER_SOURCE} testHelper.h)

llvm_map_components_to_libnames(llvm_libs Core Interpreter MC MCJIT Support mcdisassembler nativecodegen IRReader)
target_link_libraries(cbTest gtest_main antlr4-runtime ${llvm_libs})

include(GoogleTest)
gtest_discover_tests(cbTest)