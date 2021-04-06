cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)

#生成antlr cpp代码
execute_process(COMMAND antlr4 Basic.g4 -o antlr -Dlanguage=Cpp -listener)

file(COPY test.txt DESTINATION ${PROJECT_BINARY_DIR})

include(CTest)
enable_testing()

include_directories("/usr/include/antlr4-runtime")

file(GLOB antlrGrammar "./antlr/*.cpp")
add_executable(classicBasic main.cpp ${antlrGrammar})
target_link_libraries(classicBasic antlr4-runtime)
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
