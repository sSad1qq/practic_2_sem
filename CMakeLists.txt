cmake_minimum_required(VERSION 4.2)
project(repos)

set(CMAKE_CXX_STANDARD 14)

include_directories(task1)
include_directories(task2)
include_directories(task3)

add_executable(repos
        task1/main.cpp
        task1/mod.cpp
        task1/mod.h
        task2/main.cpp
        task2/mod.cpp
        task2/mod.h
        task3/main.cpp
        task3/mod.cpp
        task3/mod.h)
