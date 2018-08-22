cmake_minimum_required(VERSION 3.10)
project(MatrixLab)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h MatrixFactory.h MatrixType.h )
add_executable(MatrixLab main.cpp)


add_library(core ${SOURCE_FILES})
target_link_libraries(MatrixLab core)
