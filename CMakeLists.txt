cmake_minimum_required(VERSION 3.3)
project(scales_cot4400_assign)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Random2DMatrix.cpp Random2DMatrix.h)
add_executable(scales_cot4400_assign ${SOURCE_FILES})