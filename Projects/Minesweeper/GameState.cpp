
#include "GameState.h"
GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines) {
    int width = _dimensions.x;
    int height = _dimensions.y;
    std::vector<std::vector<int>> minePositions(height, std::vector<int>(width, 0));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, width * height - 1);
    tileTexture.loadFromFile("images/tile_hidden.png");
    // Place mines
    int placedMines = 0;
    while (placedMines < _numberOfMines) {
        int randPos = distrib(gen);
        int x = randPos % width;
        int y = randPos / width;

        if (minePositions[y][x] == 0) {
            minePositions[y][x] = 1;
            placedMines++;
        }
    }

    // Set up the tiles based on minePositions
    for (int y = 0; y < height; y++) {
        std::vector<Tile> tileRow;
        for (int x = 0; x < width; x++) {
            sf::Vector2f position(x * 32, y * 32);
            tileRow.emplace_back(position, tileTexture, y, x);
            if (minePositions[y][x] == 1) {
                tileRow.back().setMine(true);
            }
        }
        board.push_back(tileRow);
    }

    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[y].size(); ++x) {
            std::array<Tile*, 8> neighbors = {}; // Initialize all to nullptr

            // Loop through all the possible neighbors
            for (int ny = y - 1; ny <= y + 1; ++ny) {
                for (int nx = x - 1; nx <= x + 1; ++nx) {
                    // Skip the tile itself
                    if (ny == y && nx == x) continue;

                    // Check bounds
                    if (ny >= 0 && ny < board.size() && nx >= 0 && nx < board[ny].size()) {
                        // Calculate the index in the neighbors array
                        int neighborIndex = (ny - y + 1) * 3 + (nx - x + 1) - 1;
                        neighbors[neighborIndex] = &board[ny][nx];
                    }
                }
            }

            // Assign the neighbors
            board[y][x].setNeighbors(neighbors);
        }
    }
}

GameState::GameState(const char* filepath) {

    if (!tileTexture.loadFromFile("images/tile_hidden.png")) {
        std::cerr << "Failed to load tile texture!" << std::endl;
    }
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
            tileRow.emplace_back(position, tileTexture, x, y);

            if(ch == 1){
                tileRow[x].setMine(ch);
            };
            x++;
        }
        board.push_back(tileRow);
        y++;
    }
    for (int y = 0; y < board.size(); ++y) {
        for (int x = 0; x < board[y].size(); ++x) {
            std::array<Tile*, 8> neighbors = {}; // Initialize all to nullptr

            // Loop through all the possible neighbors
            for (int ny = y - 1; ny <= y + 1; ++ny) {
                for (int nx = x - 1; nx <= x + 1; ++nx) {
                    // Skip the tile itself
                    if (ny == y && nx == x) continue;

                    // Check bounds
                    if (ny >= 0 && ny < board.size() && nx >= 0 && nx < board[ny].size()) {
                        // Calculate the index in the neighbors array
                        int neighborIndex = (ny - y + 1) * 3 + (nx - x + 1) - 1;
                        neighbors[neighborIndex] = &board[ny][nx];
                    }
                }
            }

            // Assign the neighbors
            board[y][x].setNeighbors(neighbors);
        }
    }
}


void GameState::draw(sf::RenderWindow& window) {
    for (auto& row : board) {
        for (auto& tile : row) {
            tile.draw(window);
        }
    }
}
int GameState::countAdjacentMines(int x, int y) {
    int count = 0;
    for (int i = -1; i <= 1; ++i) {
        for (int j = -1; j <= 1; ++j) {
            int neighborX = x + i;
            int neighborY = y + j;
            // Check if the neighbor is within the bounds of the board
            if (neighborX >= 0 && neighborX < 800 && neighborY >= 0 && neighborY < 600) {
                if (board[neighborY][neighborX].hasMine) {
                    count++;
                }
            }
        }
    }
    return count;
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