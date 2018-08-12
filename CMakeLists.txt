cmake_minimum_required(VERSION 3.10)
project(MatrixLab)

set(CMAKE_CXX_STANDARD 11)

add_executable(MatrixLab main.cpp Matrix.h ColMatrix.h RowMatrix.h SquareMatrix.h RectangleMatrix.h MatrixFactory.h MatrixType.h)