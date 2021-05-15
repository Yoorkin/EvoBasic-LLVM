#compiler test

enable_testing()

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
add_executable(INBasicTest basicStmtTest.cpp basicStructureTest.cpp basicDeclareTest.cpp)
add_dependencies(INBasicTest INBasicCore)


target_include_directories(INBasicTest PRIVATE ${gtest_SOURCE_DIR}/include ${CORE_INCLUDE} ${ANTLR_INCLUDE_DIRS})
target_link_libraries(INBasicTest gtest_main INBasicCore)

add_test(NAME test COMMAND INBasicTest WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
gtest_discover_tests(INBasicTest)

get_property(CBTEST_INCLUDE_CHECK TARGET INBasicTest PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "INBasicTest include: ${CBTEST_INCLUDE_CHECK}")