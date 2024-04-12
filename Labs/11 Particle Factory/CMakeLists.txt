cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)
project(ParticleSim)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

add_definitions(-DDEFAULT_INVENTORY_SIZE=150)
add_executable(kaboom kaboom.cpp)
target_link_libraries(kaboom sfml-graphics sfml-audio)
