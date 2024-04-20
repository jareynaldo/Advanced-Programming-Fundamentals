//
// Created by jreyn on 4/16/2024.
//
#include "minesweeper.h"
bool debugMode = false;


int launch() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "P4 – Minesweeper, Jose Reynaldo");


    GameState gameState("boards/testboard2.brd");


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        gameState.draw(window);  // Draw the board
        window.display();
    }
    return 0;
}


void restart() {
    // Reset the game state and board, potentially turn off debug mode
    // This function should create a new GameState object and set up the board
    debugMode = false;
}

void render(sf::RenderWindow& window) {
    // Draw all the game elements: board, tiles, buttons, etc.
    // This function will get the current game state and call the draw method on each game element
}

void toggleDebugMode() {
    // Toggle the debug mode state
    debugMode = !debugMode;
}

bool getDebugMode() {
    // Return the current state of the debug mode
    return debugMode;
}

int main() {
    return launch();
}