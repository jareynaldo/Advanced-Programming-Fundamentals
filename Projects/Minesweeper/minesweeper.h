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

void toggleDebugMode();

bool getDebugMode();
#endif
