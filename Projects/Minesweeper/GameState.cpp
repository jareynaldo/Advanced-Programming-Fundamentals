
#include "GameState.h"
GameState::GameState(sf::Vector2i _dimensions, int _numberOfMines): mineCount(_numberOfMines), flagCount(0) {
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
    digitsTexture.loadFromFile("images/digits.png");
    for (int i = 0; i < digitSprites.size(); ++i) {
        digitSprites[i].setTexture(digitsTexture);
        digitSprites[i].setTextureRect(sf::IntRect(0, 0, 21, 32));
        digitSprites[i].setPosition(sf::Vector2f(21*i, 513));
    }
}

GameState::GameState(const char* filepath): mineCount(50), flagCount(0) {

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

            if (ch == '1') {
                tileRow.back().setMine(true);
            }
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
    digitsTexture.loadFromFile("images/digits.png");
    for (int i = 0; i < digitSprites.size(); ++i) {
        digitSprites[i].setTexture(digitsTexture);
        // Initially set them all to '0'
        digitSprites[i].setTextureRect(sf::IntRect(0, 0, 21, 32));
        digitSprites[i].setPosition(sf::Vector2f(21*i, 513));
    }
}


void GameState::draw(sf::RenderWindow& window) {
    for (auto& row : board) {
        for (auto& tile : row) {
            tile.draw(window);
        }
    }
    updateMineCounterDisplay();
    for (const auto& sprite : digitSprites) {
        window.draw(sprite);
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
void GameState::updateMineCounterDisplay() {
    int remainingMines = mineCount - flagCount;
    std::string countStr = std::to_string(std::abs(remainingMines));

    // Ensure there are no more than 3 digits
    if (countStr.length() > 3) {
        countStr = countStr.substr(countStr.length() - 3);
    }


    if (countStr.length() < 3) {
        countStr = std::string(3 - countStr.length(), '0') + countStr;
    }

    for (size_t i = 0; i < countStr.size(); ++i) {
        int digit = countStr[i] == '-' ? 10 : countStr[i] - '0';
        digitSprites[i].setTextureRect(sf::IntRect(21 * digit, 0, 21, 32));
    }
}



void GameState::placeFlag(int x, int y) {
    Tile& tile = board[y][x];
    if (tile.getState() == Tile::State::HIDDEN && tile.getState() != Tile::State::FLAGGED) {
        tile.setState(Tile::State::FLAGGED);
        flagCount++;
        updateMineCounterDisplay();
    }
}

void GameState::removeFlag(int x, int y) {
    Tile& tile = board[y][x];
    if (tile.getState() == Tile::State::FLAGGED) {
        tile.setState(Tile::State::HIDDEN);
        flagCount--;
        updateMineCounterDisplay();
    }
}
sf::Vector2i GameState::getDimensions() {
    return {25, 16};
}

Tile& GameState::getTile(int x, int y) {
    return board[y][x];
}

void GameState::updateFlagCount() {
    flagCount = countFlags();
    updateMineCounterDisplay();
}

int GameState::countFlags() const {
    int flags = 0;
    for (const auto& row : board) {
        for (const auto& tile : row) {
            if (tile.getState() == Tile::State::FLAGGED) {
                ++flags;
            }
        }
    }
    return flags;
}