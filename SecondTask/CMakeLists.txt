cmake_minimum_required(VERSION 3.0)
project(SecondTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(SecondTask main.cpp Envelope.hpp EnvelopeFunctions.cpp View.hpp Helpers.hpp)