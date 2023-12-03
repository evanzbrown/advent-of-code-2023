cmake_minimum_required(VERSION 3.9)

project(advent-of-code)

set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(CHAL_INPUTS_PATH="${CMAKE_SOURCE_DIR}\\\\inputs")

add_executable(aoc 
  src/main.cpp
  src/day1.cpp
  src/day2.cpp
)
