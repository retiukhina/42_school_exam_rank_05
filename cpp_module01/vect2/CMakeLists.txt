cmake_minimum_required(VERSION 3.28)

project(vect2 VERSION 0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
file(GLOB _SOURCES "*.cpp" )

add_executable(vect2 ${_SOURCES})

target_compile_options(vect2 PRIVATE -Wall -Wextra -Wpedantic -Wconversion -g)