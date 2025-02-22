cmake_minimum_required(VERSION 3.30)
project(problemset)

set(CMAKE_CXX_STANDARD 20)

add_executable(problemset main.cpp
        grader.cpp)
