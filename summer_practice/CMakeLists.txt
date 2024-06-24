cmake_minimum_required(VERSION 3.27)

set(CMAKE_CXX_STANDARD 20)

project(practice)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

set(SOURCE_FILES
        source/main.cpp
        source/FibonacciHeap.cpp
        source/FibonacciTree.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
