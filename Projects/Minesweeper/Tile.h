// Tile.h

#ifndef TILE_H
#define TILE_H

#include <SFML/Graphics.hpp>
#include <array>

class Tile {
public:

    Tile(sf::Vector2f position);

// Enum to represent the tile's state
    enum class State { REVEALED, HIDDEN, FLAGGED, EXPLODED };
    void setMine(bool mine);
    void draw(sf::RenderWindow& window);

//    Tile(sf::Vector2f position, bool hasMine = false);
//    sf::Vector2f getLocation() const;
//    State getState() const;
//    void setState(State state);
//    void setNeighbors(const std::array<Tile*, 8>& neighbors);
//    void onClickLeft();
//    void onClickRight();
//    bool hasMine() const;
//    void revealNeighbors();

private:
    sf::Sprite sprite;
    sf::Texture texture;

    bool hasMine;
//
//    sf::Vector2f position;
//    State state;
//
//    std::array<Tile*, 8> neighbors;
//    sf::Texture texture;



};

#endif // TILE_H
