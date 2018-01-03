cmake_minimum_required(VERSION 3.0)
project(opencv_test_cpp)

# A list of useful CMake variables:
# see: https://cmake.org/Wiki/CMake_Useful_Variables

# Give this project a version number
set(APP_VERSION_MAJOR 1)
set(APP_VERSION_MINOR 0)
set(APP_VERSION_PATCH 0)
set(CMAKE_CXX_STANDARD 11)

# Find packages we want to include in our project
find_package(OpenCV REQUIRED)

# Configure header files to pass some cmake settings to src
configure_file(
    ${PROJECT_SOURCE_DIR}/config.hpp.in
    ${PROJECT_BINARY_DIR}/config.hpp
)

# Add the binary tree to the search path for include files (so we can find config.h)
include_directories(
    ${PROJECT_BINARY_DIR}
    ${OpenCV_INCLUDE_DIRS}
)

# Nice little way to display all variables present in CMake
#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

add_executable(app main.cpp)

# https://cmake.org/cmake/help/v3.0/command/target_link_libraries.html
target_link_libraries(app ${OpenCV_LIBS})
