cmake_minimum_required(VERSION 3.30)
project(semafori)

set(CMAKE_CXX_STANDARD 20)

add_executable(semafori main.cpp
        grader.cpp)
