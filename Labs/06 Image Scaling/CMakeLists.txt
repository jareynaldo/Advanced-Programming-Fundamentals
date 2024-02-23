cmake_minimum_required(VERSION 3.27)
project(06_Image_Scaling)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(06_Image_Scaling
    ConsoleGfx.cpp
    ConsoleGfx.h
    Image.cpp
    Image.h
    scaler.cpp)

