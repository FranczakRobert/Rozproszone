cmake_minimum_required(VERSION 3.22)
project(zadanie)

set(CMAKE_CXX_STANDARD 14)

add_executable(zadanie main.cpp File/FileController.cpp File/FileController.h Matrix/Matrix.cpp Matrix/Matrix.h Matrix/MatrixController.cpp Matrix/MatrixController.h)
