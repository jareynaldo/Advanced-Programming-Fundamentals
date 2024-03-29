cmake_minimum_required(VERSION 3.27)
project(08_Return_of_the_Cow_2)

set(CMAKE_CXX_STANDARD 17)

include_directories(.)

add_executable(08_Return_of_the_Cow_2
        Cow.cpp
        Cow.h
        FileCow.cpp
        FileCow.h
        cowsay.cpp
        Dragon.cpp
        Dragon.h
        HeiferGenerator.cpp
        HeiferGenerator.h
        IceDragon.cpp
        IceDragon.h
        )
