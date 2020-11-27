cmake_minimum_required(VERSION 3.0)
project(FirstTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(FirstTask main.cpp Models/Board/Board.hpp ViewModels/View.hpp Services/Converter/Converter.hpp Services/Errors/ErrorHandler.hpp Models/Board/BoardFactory.hpp Services/Errors/ErrorCode.hpp Services/ConsoleValidator/ConsoleValidator.hpp)