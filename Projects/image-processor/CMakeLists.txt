cmake_minimum_required(VERSION 3.27)
project(image_processor)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(input)
include_directories(output)
include_directories(src)

add_executable(image_processor
        input/car.tga
        input/circles.tga
        input/layer1.tga
        input/layer2.tga
        input/layer_blue.tga
        input/layer_green.tga
        input/layer_red.tga
        input/pattern1.tga
        input/pattern2.tga
        input/text.tga
        input/text2.tga
        output/readme.txt
        src/source.cpp
        src/source.h
        src/Image.cpp)
