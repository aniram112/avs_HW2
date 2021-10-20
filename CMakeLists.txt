# set minimum cmake version
cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

# project name and language
project(task LANGUAGES CXX)

set(BUILD_DIR "${CMAKE_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BUILD_DIR}/../bin")

set(BINARY_DIR "${CMAKE_BINARY_DIR}")

# Source files list
set(SOURCE_FILES
        # Headers
        rnd.h
        container.h
        cypher.h
        symbols.h
        numbers.h
        cyclic.h

        # Sources
        container.cpp
        main.cpp
        cypher.cpp
        symbols.cpp
        cyclic.cpp
        numbers.cpp)

add_executable(task ${SOURCE_FILES})
