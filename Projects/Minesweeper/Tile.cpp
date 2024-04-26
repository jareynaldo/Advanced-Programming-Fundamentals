//
// Created by jreyn on 4/16/2024.


#include "Tile.h"




Tile::Tile(sf::Vector2f poss, const sf::Texture& texture, int x, int y) : hasMine(false), gridX(x), gridY(y) {

    state = State::HIDDEN;
    position = poss;
    sprite.setTexture(texture);
    sprite.setPosition(poss);
}
void Tile::setMine(bool mine) {
    hasMine = mine;

}

void Tile::draw(sf::RenderWindow& window) {
    window.draw(sprite);

}
void Tile::setNeighbors(const std::array<Tile *, 8> &newNeighbors) {
    neighbors = newNeighbors;
}

void Tile::reveal() {
    // Implement reveal logic, including checking the state and revealing neighbors if needed
    if (state == State::HIDDEN) {
        setState(State::REVEALED);
        if (countAdjacentMines() == 0) {
            for (Tile* neighbor : neighbors) {
                if (neighbor) {
                    neighbor->reveal();
                }
            }
        }
    }
}

int Tile::countAdjacentMines() {
    int mineCount = 0;
    for (int i = 0; i < neighbors.size(); ++i) {
        if (neighbors[i] && neighbors[i]->hasMine) {
            mineCount++;
        }
    }
    return mineCount;
}


void Tile::onClickLeft() {
    if (state == State::HIDDEN) {
        state = hasMine ? State::EXPLODED : State::REVEALED;
        if (!hasMine && countAdjacentMines() == 0) {
            revealNeighbors();
        }
    }
}
void Tile::revealNeighbors() {
    for (Tile* neighbor : neighbors) {
        if (neighbor != nullptr && !neighbor->hasMine && neighbor->getState() == Tile::State::HIDDEN) {
            neighbor->setState(Tile::State::REVEALED);
            // If the neighbor also has no adjacent mines, recurse and reveal its neighbors
            if (neighbor->countAdjacentMines() == 0) {
                neighbor->revealNeighbors();
            }
        }
    }
}

void Tile::onClickRight() {
    if (state == State::HIDDEN) {
        state = State::FLAGGED;
    } else if (state == State::FLAGGED) {
        state = State::HIDDEN;
    }
}



sf::Vector2f Tile::getLocation() const {
    return position;
}


Tile::State Tile::getState() const {
    return state;
}


void Tile::setState(State newState) {
    state = newState;
}
//
//void Tile::setNeighbors(const std::array<Tile*, 8>& newNeighbors) {
//    neighbors = newNeighbors;
//}
//
//void Tile::onClickLeft() {
//    // Handle left-click behavior:
//    // If the tile is hidden, reveal it; if it's a mine, explode
//
//}
//
//void Tile::onClickRight() {
//    // Handle right-click behavior:
//    // Toggle the tile state between FLAGGED and HIDDEN
//}
//
//void Tile::draw(sf::RenderWindow& window) {
//    // Set the sprite's texture and position, then draw it to the window
//    window.draw(sprite);
//}
//
//bool Tile::hasMine() const {
//    return mine;
//}
//
//void Tile::revealNeighbors() {
//    // If the tile has no adjacent mines, call reveal on each neighbor
//}
