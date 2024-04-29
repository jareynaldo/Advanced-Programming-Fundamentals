//
// Created by jreyn on 4/16/2024.


#include "Tile.h"




Tile::Tile(sf::Vector2f poss, const sf::Texture& texture, int x, int y) : hasMine(false), gridX(x), gridY(y) {

    state = State::HIDDEN;
    position = poss;
    baseSprite.setTexture(texture);
    baseSprite.setPosition(poss);
    overlaySprite.setPosition(poss);

}
void Tile::setMine(bool mine) {
    hasMine = mine;

}

void Tile::draw(sf::RenderWindow& window) {
    window.draw(baseSprite);
    if (overlaySprite.getTexture()) {
        window.draw(overlaySprite);
    }
}
void Tile::setNeighbors(const std::array<Tile *, 8> &newNeighbors) {
    neighbors = newNeighbors;
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




sf::Vector2f Tile::getLocation() const {
    return position;
}


Tile::State Tile::getState() const {
    return state;
}


void Tile::setState(State newState) {
    state = newState;
}

void Tile::onClickLeft() {
    if (state == State::FLAGGED || state == State::REVEALED) {
        return;
    }

    if (hasMine) {


        overlayTexture.loadFromFile("images/mine.png");
        overlaySprite.setTexture(overlayTexture);

        state = State::EXPLODED;

    } else {
        
        reveal();
    }

}

void Tile::onClickRight() {
    if (state == State::REVEALED || state == State::EXPLODED) {
        return;
    }

    if (state == State::HIDDEN) {
        state = State::FLAGGED;
        texture.loadFromFile("images/flag.png");
    } else if (state == State::FLAGGED) {
        state = State::HIDDEN;
        texture.loadFromFile("images/tile_hidden.png");
    }
    overlaySprite.setTexture(texture);
}
void Tile::reveal() {
    if (state == State::FLAGGED || state == State::REVEALED) {
        return;
    }

    state = State::REVEALED; // Set the state to revealed.
    int mines = countAdjacentMines();

    // Update the base texture to the revealed state.
    texture.loadFromFile("images/tile_revealed.png");
    baseSprite.setTexture(texture);

    if (mines > 0) {
        // Set the overlay texture to the number corresponding to the count of adjacent mines.
        overlayTexture.loadFromFile("images/number_" + std::to_string(mines) + ".png");
        overlaySprite.setTexture(overlayTexture);
    } else {
        // If there are no adjacent mines, recursively reveal the neighbors.
        for (Tile* neighbor : neighbors) {
            if (neighbor != nullptr) {
                neighbor->reveal();
            }
        }
    }
    // Note: Ensure you have logic to draw both the baseSprite and the overlaySprite.
}