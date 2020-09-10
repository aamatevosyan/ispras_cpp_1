cmake_minimum_required(VERSION 3.17)
project(ispras_cpp_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ispras_cpp_1 main.cpp qesolver.h qesolver.cpp mctester.h ansi.h)