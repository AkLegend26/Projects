cmake_minimum_required(VERSION 3.6)
project(project0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")

set(SOURCE_FILES
        Calendar.cpp.obj
        Calendar.h
        CalTest.cpp
        Date.cpp
        Date.h
        Reminder.cpp
        Reminder.h)

add_executable(project0 ${SOURCE_FILES})