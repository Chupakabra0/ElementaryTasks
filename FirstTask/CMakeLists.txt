cmake_minimum_required(VERSION 3.0)
project(FirstTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstTask main.cpp ChessBoard.hpp View.hpp Helpers.hpp)