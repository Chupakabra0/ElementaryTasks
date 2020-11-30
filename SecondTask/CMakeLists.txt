cmake_minimum_required(VERSION 3.0)
project(SecondTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(SecondTask main.cpp
        Models/Envelope/Envelope.hpp
        ViewModels/ViewModel.hpp
        Services/ConsoleInput/ConsoleInput.hpp
        Services/Converter/Converter.hpp
        Services/Errors/ErrorHandler.hpp
        Services/Errors/ErrorCode.hpp View/View.hpp)