cmake_minimum_required(VERSION 3.27)
project(07_The_Cow_Strikes_Back)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(07_The_Cow_Strikes_Back
        Cow.cpp
        Cow.h
        cowsay.cpp
        Dragon.cpp
        Dragon.h
        HeiferGenerator.cpp
        HeiferGenerator.h
        IceDragon.cpp
        IceDragon.h)
