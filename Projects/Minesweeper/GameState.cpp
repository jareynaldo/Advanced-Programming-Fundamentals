//
// Created by jreyn on 4/16/2024.
//
#include "GameState.h"
#include <fstream>
#include <string>
#include <sstream>
#include <iostream>



//GameState::GameState(sf::Vector2i dimensions, int numberOfMines)
//        : mineCount(numberOfMines), flagCount(0), playStatus(PlayStatus::PLAYING) {
//    // Initialize the tiles based on the dimensions provided
//    tiles.resize(dimensions.y, std::vector<Tile>(dimensions.x));
//    // Place mines and set up tiles here
//}
GameState::GameState(const char* filepath) {
    board[600][480];
    std::ifstream file(filepath);
    std::string line;
    int y = 0;

    while (std::getline(file, line)) {
        std::istringstream lineStream(line);
        int x = 0;
        char ch;

        std::vector<Tile> tileRow;
        while (lineStream >> ch) {
            sf::Vector2f position(x * 32, y * 32);
            tileRow.emplace_back(position);

            if(ch == 1){
                tileRow[x].setMine(ch);
            };
            x++;
        }
        board.push_back(tileRow);
        y++;
    }
}

void GameState::draw(sf::RenderWindow& window) {
    for (auto& row : board) {
        for (auto& tile : row) {
            tile.draw(window);
        }
    }
}
//
//int GameState::getFlagCount() const {
//    return flagCount;
//}
//
//int GameState::getMineCount() const {
//    return mineCount;
//}
//
//Tile* GameState::getTile(int x, int y) {
//    if (y >= tiles.size() || x >= tiles[y].size()) {
//        return nullptr; // Out of bounds
//    }
//    return &tiles[y][x];
//}
//
//GameState::PlayStatus GameState::getPlayStatus() const {
//    return playStatus;
//}
//
//void GameState::setPlayStatus(PlayStatus status) {
//    playStatus = status;
//}
//
//void GameState::handleClick(const sf::Vector2f& position, bool isLeftClick) {
//    int tileX = position.x / 800;
//    int tileY = position.y / 600;
//
//    Tile* clickedTile = getTile(tileX, tileY);
//    if (clickedTile) {
//        if (isLeftClick) {
//            clickedTile->onClickLeft();
//        } else {
//            clickedTile->onClickRight();
//        }
//    }
//}