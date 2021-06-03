cmake_minimum_required(VERSION 3.0.0)
project(INBasicRT VERSION 1.0.1)
file(GLOB runtime_source INBasicRT.cpp)
add_library(INBasicRT STATIC ${runtime_source})
