cmake_minimum_required(VERSION 3.15)


set(PROJECT_NAME example)
project("${PROJECT_NAME}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++20")



add_executable("${PROJECT_NAME}" main.cpp func.cpp)