cmake_minimum_required(VERSION 3.0)

set(This SectionChallenge13)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

set(Headers
    asd.h
)

set(Sources
    asd.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})

add_subdirectory(test)