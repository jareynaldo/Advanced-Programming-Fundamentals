#include "Toolbox.h"
#pragma once

void resetGame(const sf::Vector2i& boardSize, int mineCount, const char*  boardPath) {
    Toolbox& toolbox = Toolbox::getInstance();
    delete toolbox.gameState;
    if (boardPath == "mark") {
        toolbox.gameState = new GameState(boardSize, mineCount);
    } else {
        toolbox.gameState = new GameState(boardPath);
    }
}
void onNewGameClick() {
    resetGame(sf::Vector2i(26, 16), 50, "mark");
}
void onTest1Click() {
    resetGame(sf::Vector2i(26, 16), 50, "boards/testboard1.brd");
}
void onTest2Click() {
    resetGame(sf::Vector2i(26, 16), 50, "boards/testboard2.brd");
}
void onTest3Click() {
    resetGame(sf::Vector2i(26, 16), 50, "boards/testboard3.brd");
}

Toolbox::Toolbox() {
    // Load textures

    newGameTexture.loadFromFile("images/face_happy.png");
    debugTexture.loadFromFile("images/debug.png");
    test1Texture.loadFromFile("images/test_1.png");
    test2Texture.loadFromFile("images/test_2.png");
    test3Texture.loadFromFile("images/test_3.png");


    newGameSprite.setTexture(newGameTexture);
    debugSprite.setTexture(debugTexture);
    test1Sprite.setTexture(test1Texture);
    test2Sprite.setTexture(test2Texture);
    test3Sprite.setTexture(test3Texture);

    // Initialize buttons with textures, positions, and callback functions
    newGameButton = new Button(sf::Vector2f(360, 513), &onNewGameClick);
    newGameButton->setSprite(&newGameSprite);

    testButton1 = new Button(sf::Vector2f(552, 513), &onTest1Click);
    testButton1->setSprite(&test1Sprite);

    testButton2 = new Button(sf::Vector2f(616, 513), &onTest2Click);
    testButton2->setSprite(&test2Sprite);

    testButton3 = new Button(sf::Vector2f(680, 513), &onTest3Click);
    testButton3->setSprite(&test3Sprite);

    debugButton = new Button(sf::Vector2f(488, 513), &onTest3Click);
    debugButton->setSprite(&debugSprite);

    gameState = new GameState(sf::Vector2i(26, 16), 50);

}
