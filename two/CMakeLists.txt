cmake_minimum_required(VERSION 2.8.4)
project(two)

include(cmake/FindWiringPi.cmake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -lwiringPi")

set(SOURCE_FILES lab1.cpp main.cpp)
add_executable(two ${SOURCE_FILES})