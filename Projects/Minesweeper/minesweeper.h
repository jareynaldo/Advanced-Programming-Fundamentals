#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Tile.h"
#include "Button.h"
#include "Toolbox.h"
#include <vector>


int launch();

void restart();

void render(sf::RenderWindow& window);

void toggleDebugMode(Toolbox *toolbox);
bool isValidPosition(const sf::Vector2i& pos, const sf::Vector2i& dimensions);
bool constains( sf::Vector2<float> pos, const sf::Vector2i& dimensions);

bool getDebugMode();
bool debugMode = false;
int i;
int j;
#endif
