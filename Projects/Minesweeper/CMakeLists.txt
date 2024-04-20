cmake_minimum_required(VERSION 3.1)
project(Minesweeper)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR "C:/Libraries/SFML-2.5.1/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(.)


add_executable(Minesweeper
        minesweeper.cpp
        Button.h
        GameState.h
        minesweeper.h
        Tile.h
        Toolbox.h
        GameState.cpp
        Tile.cpp
        Button.cpp)

target_link_libraries(Minesweeper sfml-graphics sfml-window sfml-system)
