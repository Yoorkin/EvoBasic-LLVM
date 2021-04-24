#将Basic.g4生成antlrcpp code.
#依赖于antlr4
execute_process(
        COMMAND antlr4 Basic.g4 -o ../antlr -Dlanguage=Cpp -visitor -no-listener
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/compiler/grammar
        OUTPUT_VARIABLE OUTPUT
)

message(STATUS "Basic*.cpp/Basic*.h has been generated to compiler/antlr")