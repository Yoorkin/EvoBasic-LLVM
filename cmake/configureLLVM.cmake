include(${CMAKE_SOURCE_DIR}/cmake/loadDependencies.cmake)
include(${CMAKE_SOURCE_DIR}/cmake/env.cmake)

Load_Dependencies(llvm-11.1.0.src.tar.xz
        https://github.com/llvm/llvm-project/releases/download/llvmorg-11.1.0/llvm-11.1.0.src.tar.xz
        89c1aabaca65f00fd03db1b69d65fa64fcb2b812)

execute_process(
        COMMAND cmake -S${DEPENDENCIES_DIR}/llvm-11.1.0.src -DCMAKE_BUILD_TYPE=Release
        WORKING_DIRECTORY ${DEPENDENCIES_DIR}/llvm-11.1.0.src/build
)

execute_process(
        COMMAND cmake --build . --parallel 8
        WORKING_DIRECTORY ${DEPENDENCIES_DIR}/llvm-11.1.0.src/build
)

execute_process(
        COMMAND cmake -DCMAKE_INSTALL_PREFIX=${LLVM_INSTALL_PATH} -P cmake_install.cmake
        WORKING_DIRECTORY ${DEPENDENCIES_DIR}/llvm-11.1.0.src/build
)



