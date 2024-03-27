cmake_minimum_required(VERSION 3.21)
project(Project10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -pedantic -pedantic-errors")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-limit-debug-info")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
        RepairDriver.cpp
        Trie.h
        Trie.cpp
        TrieNode.h
        TrieNode.cpp Repair.h Repair.cpp)

add_executable(Project10 ${SOURCE_FILES})
