#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <array>
#include <iostream>

class Tile {
public:

    Tile(sf::Vector2f position, const sf::Texture& texture,int x, int y);

    enum class State { REVEALED, HIDDEN, FLAGGED, EXPLODED };
    void setMine(bool mine);
    void draw(sf::RenderWindow& window);
    int countAdjacentMines();
    void reveal();
    void revealNeighbors();

    void setNeighbors(const std::array<Tile*, 8>& newNeighbors);
    std::array<Tile*, 8>& getNeighbors();
    sf::Vector2f getLocation();
    State getState() const;
    void setState(State _state);

    void onClickLeft();
    void onClickRight();


    bool hasMine;

private:
    sf::Vector2f position;
    int gridX, gridY;
    std::array<Tile*, 8> neighbors;
    sf::Sprite baseSprite;
    sf::Sprite overlaySprite;
    sf::Texture texture;
    sf::Texture overlayTexture;

    State state;


};

#endif
