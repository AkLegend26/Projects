cmake_minimum_required(VERSION 3.6)
project(project2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors -D_GLIBCXX_DEBUG")

set(SOURCE_FILES
        Calendar.cpp
        Calendar.h
        CalTest.cpp
        Date.cpp
        Date.h
        Reminder.cpp
        Reminder.h)

add_executable(project2 ${SOURCE_FILES})