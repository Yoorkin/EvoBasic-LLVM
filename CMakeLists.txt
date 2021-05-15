cmake_minimum_required(VERSION 3.0.0)
project(classicBasic VERSION 0.1.0)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -v")

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

#add_subdirectory(runtime ${CMAKE_BINARY_DIR}/runtime)
add_subdirectory(compiler ${CMAKE_BINARY_DIR}/compiler)
add_subdirectory(test ${CMAKE_BINARY_DIR}/test)


