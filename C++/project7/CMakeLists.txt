cmake_minimum_required(VERSION 3.15)
project(project7)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-limit-debug-info")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
    FifoPointAgenda.h
    LifoPointAgenda.h
    Main.cpp
    Maze.cpp
    Maze.h
    MazeSolver.cpp
    MazeSolver.h
    Point.cpp
    Point.h
    PointAgenda.h
    Queue_t.h
    Stack_t.h)

add_executable(project7 ${SOURCE_FILES})