cmake_minimum_required(VERSION 3.0)
project(ThirdTask)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/googletest-download"
        )

# Prevent GoogleTest from overriding our compiler/linker options
# when building with Visual Studio
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This adds the following targets:
# gtest, gtest_main, gmock and gmock_main
add_subdirectory("${CMAKE_BINARY_DIR}/googletest-src"
        "${CMAKE_BINARY_DIR}/googletest-build"
        )

# Now simply link your own targets against gtest, gmock,
# etc. as appropriate

#------------------------ INCLUDES -------------------------------------------
include_directories(${CMAKE_SOURCE_DIR}/Models)
include_directories(${CMAKE_SOURCE_DIR}/Services)
include_directories(${CMAKE_SOURCE_DIR}/View)
#-----------------------------------------------------------------------------

#-------------------------- TESTS --------------------------------------------
include_directories("${CMAKE_BINARY_DIR}/googletest-src/googlemock/include")
include_directories("${CMAKE_BINARY_DIR}/googletest-src/googletest/include")
#-----------------------------------------------------------------------------

#-------------------------- PROGRAM ------------------------------------------
add_executable(ThirdTask Main.cpp Models/Base/Shape.cpp Models/Triangle/Triangle.cpp
		Application/Application.cpp)
#-----------------------------------------------------------------------------

#---------------------------- TESTS ------------------------------------------
add_executable(Tests Tests/TestsMain.cpp Tests/ServicesTests/ConverterTests.cpp
Tests/ServicesTests/ConsoleInputValidatorTests.cpp Tests/ServicesTests/ErrorTests.cpp
Tests/ServicesTests/StringCleanerTests.cpp Tests/ServicesTests/StringSplitterTests.cpp
Tests/ModelsTests/TriangleTests.cpp Models/Base/Shape.cpp Models/Triangle/Triangle.cpp)
#-----------------------------------------------------------------------------

#----------------------------- LIBS ------------------------------------------
target_link_libraries(Tests gtest gtest_main)
#-----------------------------------------------------------------------------