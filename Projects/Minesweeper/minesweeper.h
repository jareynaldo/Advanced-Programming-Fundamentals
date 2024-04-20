#ifndef MINESWEEPER_H
#define MINESWEEPER_H

#include <SFML/Graphics.hpp>
#include "GameState.h"
#include "Tile.h"
#include "Button.h"
#include "Toolbox.h"

// Function to start the game, which will be called by main
int launch();

// Function to restart the game, resetting all states and generating a new game state
void restart();

// Function to render the game's UI elements based on the current game state and debug mode
void render(sf::RenderWindow& window);

// Function to toggle debug mode on or off
void toggleDebugMode();

// Function to check if debug mode is active
bool getDebugMode();

// Additional functions as needed...

#endif // MINESWEEPER_H
