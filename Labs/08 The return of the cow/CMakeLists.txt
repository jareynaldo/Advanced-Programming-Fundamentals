cmake_minimum_required(VERSION 3.27)
project(08_The_return_of_the_cow)

set(CMAKE_CXX_STANDARD 17)

include_directories(cows)

add_executable(08_The_return_of_the_cow
        cowsay.cpp
        Cow.cpp
        Cow.h
        Dragon.cpp
        Dragon.h
        FileCow.cpp
        FileCow.h
        HeiferGenerator.cpp
        HeiferGenerator.h
        IceDragon.cpp
        IceDragon.h



)
