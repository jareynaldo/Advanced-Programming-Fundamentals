//
// Created by jreyn on 4/16/2024.


#include "Tile.h"
#include <iostream>



Tile::Tile(sf::Vector2f position) : hasMine(false) {

    if (!texture.loadFromFile("images/tile_hidden.png")) {
        std::cerr << "Failed to load tile texture!" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(position);
}
void Tile::setMine(bool mine) {
    hasMine = mine;

}

void Tile::draw(sf::RenderWindow& window) {
    window.draw(sprite);

}


//
//Tile::Tile(sf::Vector2f position, bool hasMine)
//        : position(position), mine(hasMine), state(State::HIDDEN) {
//    // Load the texture and set up the sprite for the tile
//    // You need to load the appropriate texture based on the tile's initial state
//}
//
//sf::Vector2f Tile::getLocation() const {
//    return position;
//}
//
//Tile::State Tile::getState() const {
//    return state;
//}
//
//void Tile::setState(State newState) {
//    state = newState;
//    // Update the sprite to reflect the new state
//}
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
