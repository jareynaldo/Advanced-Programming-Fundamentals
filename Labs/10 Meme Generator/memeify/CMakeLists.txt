cmake_minimum_required(VERSION 3.27)
project(memeify)
set(CMAKE_CXX_STANDARD 14)



set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_library(memer memer.cpp
        memeify.h)

target_link_libraries(memer sfml-graphics sfml-audio)

add_executable (memeify memeify.cpp
        memeify.h)
target_link_libraries(memeify memer sfml-graphics sfml-audio)




