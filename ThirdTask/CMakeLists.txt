cmake_minimum_required(VERSION 3.0)
project(ThirdTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(ThirdTask Main.cpp Models/Base/Shape.cpp Models/Triangle/Triangle.cpp Application/Application.cpp)