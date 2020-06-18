cmake_minimum_required(VERSION 3.15)
project(hw3PartA)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -pedantic-errors -DNDEBUG")

add_executable(hw3PartA main.cpp Auxiliaries.cpp Auxiliaries.h IntMatrix.h IntMatrix.cpp)