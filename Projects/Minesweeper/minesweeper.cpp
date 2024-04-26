//
// Created by jreyn on 4/16/2024.
//
#include "minesweeper.h"
bool debugMode = false;


int launch() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "P4 – Minesweeper, Jose Reynaldo");

    Toolbox& toolbox = Toolbox::getInstance();
    toolbox.window = &window;


    GameState gameState("boards/randomBoard.brd");

    sf::Texture newGameTexture, debugTexture, test1Texture, test2Texture;
    sf::Sprite newGameSprite, debugSprite, test1Sprite, test2Sprite;
    newGameTexture.loadFromFile("images/face_happy.png");
    debugTexture.loadFromFile("images/debug.png");
    test1Texture.loadFromFile("images/test_1.png");
    test2Texture.loadFromFile("images/test_2.png");

    newGameSprite.setTexture(newGameTexture);
    debugSprite.setTexture(debugTexture);
    test1Sprite.setTexture(test1Texture);
    test2Sprite.setTexture(test2Texture);

    Button newGameButton(sf::Vector2f(360, 513), [&toolbox]() {
        if(toolbox.gameState != nullptr) {
            delete toolbox.gameState;
        }
        toolbox.gameState = new GameState(sf::Vector2i(25, 16), 50);

    });
    Button debugButton(sf::Vector2f(488, 513), [&]() {
        // Code to toggle debug mode
        toggleDebugMode(); // Assuming you have this function implemented
    });

    Button test1Button(sf::Vector2f(552, 513), [&]() {
        if(toolbox.gameState != nullptr) {
            delete toolbox.gameState;
        }
        toolbox.gameState = new GameState("boards/testboard1.brd");
    });

    Button test2Button(sf::Vector2f(616, 513), [&]() {
        if(toolbox.gameState != nullptr) {
            delete toolbox.gameState;
        }
        toolbox.gameState = new GameState("boards/testboard2.brd");
    });

    newGameButton.setSprite(&newGameSprite);
    debugButton.setSprite(&debugSprite);
    test1Button.setSprite(&test1Sprite);
    test2Button.setSprite(&test2Sprite);
    toolbox.newGameButton = &newGameButton;
    toolbox.debugButton = &debugButton;
    toolbox.testButton1 = &test1Button;
    toolbox.testButton2 = &test2Button;



    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        toolbox.debugButton->handleEvent(event);
        toolbox.newGameButton->handleEvent(event);


        toolbox.window->clear();
        gameState.draw(window);

        toolbox.newGameButton->draw(window);
        toolbox.debugButton->draw(window);
        toolbox.testButton1->draw(window);
        toolbox.testButton2->draw(window);


        toolbox.window->display();

    }
    delete toolbox.gameState;
    delete toolbox.debugButton;
    delete toolbox.newGameButton;
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