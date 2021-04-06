cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories("/usr/include/antlr4-runtime")
include_directories("./antlr")

add_executable(classicBasic main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
