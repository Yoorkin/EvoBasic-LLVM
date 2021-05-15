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
add_executable(cbTest basicStmtTest.cpp)

target_include_directories(cbTest PRIVATE ${gtest_SOURCE_DIR}/include)
target_link_libraries(cbTest gtest_main)

add_test(NAME test COMMAND cbTest WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
gtest_discover_tests(cbTest)

get_property(CBTEST_INCLUDE_CHECK TARGET cbTest PROPERTY INCLUDE_DIRECTORIES)
message(STATUS "cbTest include: ${CBTEST_INCLUDE_CHECK}")