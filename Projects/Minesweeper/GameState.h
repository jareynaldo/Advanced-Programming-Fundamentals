
#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Tile.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <random>
#include <fstream>

class GameState {
public:
    // Enum to track the play status
    enum class PlayStatus { WIN, LOSS, PLAYING };

    GameState(sf::Vector2i dimensions, int numberOfMines);
    GameState(const char* filepath);
    void draw(sf::RenderWindow& window);
    int countAdjacentMines(int x, int y);


//    // Get the current count of flags placed on the board
//    int getFlagCount() const;
//
//    // Get the current count of mines on the board
//    int getMineCount() const;
//
//    // Get a pointer to the Tile at specified coordinates
//    Tile* getTile(int x, int y);
//
//    // Get the current play status
//    PlayStatus getPlayStatus() const;
//
//    // Set the play status
//    void setPlayStatus(PlayStatus status);
//
//    void handleClick(const sf::Vector2f& position, bool isLeftClick);

private:
    std::vector<std::vector<Tile>> board;
    sf::Texture tileTexture;


//    // Number of mines on the board
//    int mineCount;
//
//    // Number of flags placed by the player
//    int flagCount;
//
//    // Current play status
//    PlayStatus playStatus;
};

#endif // GAMESTATE_H
