
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
    void placeFlag(int x, int y);
    void removeFlag(int x, int y);
    int getMineCount() const { return mineCount; }
    int getFlagCount() const { return flagCount; }
    void updateMineCounterDisplay();
    sf::Vector2i getDimensions();
    Tile& getTile(int x, int y);
    void updateFlagCount();
    int countFlags() const;


    PlayStatus currentFaceState = PlayStatus::WIN;
    sf::Texture faceTexture;
    sf::Sprite faceSprite;

    bool checkVictory();

private:
    std::vector<std::vector<Tile>> board;
    sf::Texture tileTexture;
    sf::Texture digitsTexture;
    std::array<sf::Sprite, 3> digitSprites;
    int mineCount;
    int flagCount;


    sf::Vector2i getDimensions() const;

};

#endif
