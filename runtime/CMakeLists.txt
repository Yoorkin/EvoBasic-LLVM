cmake_minimum_required(VERSION 3.0.0)
project(cbRuntime VERSION 1.0.1)
file(GLOB runtime_source "./*.c")
add_library(cbRuntime SHARED ${runtime_source} ../test/basicStmtTest.cpp)
