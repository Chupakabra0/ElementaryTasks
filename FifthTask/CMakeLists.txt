cmake_minimum_required(VERSION 3.0)
project(FifthTask)

set(CMAKE_CXX_STANDARD 20)

add_executable(FifthTask Main.cpp
        Models/Prescription/English/EnglishPrescription.cpp
        Models/Prescription/Base/Prescription.cpp
        Application/Application.cpp)