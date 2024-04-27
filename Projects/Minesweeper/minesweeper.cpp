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


    sf::Texture newGameTexture, debugTexture, test1Texture, test2Texture, test3Texture;
    sf::Sprite newGameSprite, debugSprite, test1Sprite, test2Sprite,test3Sprite;
    newGameTexture.loadFromFile("images/face_happy.png");
    debugTexture.loadFromFile("images/debug.png");
    test1Texture.loadFromFile("images/test_1.png");
    test2Texture.loadFromFile("images/test_2.png");
    test2Texture.loadFromFile("images/test_3.png");


    newGameSprite.setTexture(newGameTexture);
    debugSprite.setTexture(debugTexture);
    test1Sprite.setTexture(test1Texture);
    test2Sprite.setTexture(test2Texture);
    test3Sprite.setTexture(test3Texture);

    GameState* gameState = new GameState("boards/testboard3.brd");


    auto resetGame = [&window, &gameState](const char* boardPath) {
        delete gameState;
        gameState = new GameState(boardPath);
        window.clear();
        gameState->draw(window);
        window.display();
    };
    Button newGameButton(sf::Vector2f(360, 513), [&]() { resetGame("boards/testboard.brd"); });
    Button test1Button(sf::Vector2f(552, 513), [&]() { resetGame("boards/testboard1.brd"); });
    Button test2Button(sf::Vector2f(616, 513), [&]() { resetGame("boards/testboard2.brd"); });
    Button test3Button(sf::Vector2f(680, 513), [&]() { resetGame("boards/testboard3.brd"); });


    Button debugButton(sf::Vector2f(488, 513), [&]() {

        toggleDebugMode();
    });

    newGameButton.setSprite(&newGameSprite);
    debugButton.setSprite(&debugSprite);
    test1Button.setSprite(&test1Sprite);
    test2Button.setSprite(&test2Sprite);

    toolbox.newGameButton = &newGameButton;
    toolbox.debugButton = &debugButton;
    toolbox.testButton1 = &test1Button;
    toolbox.testButton2 = &test2Button;
    toolbox.testButton3 = &test3Button;

    toolbox.gameState = new GameState("boards/testboard3.brd");


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                // Convert the mouse position to grid coordinates
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2i gridPos(mousePos.x / 32, mousePos.y / 32); // Assuming a 32x32 tile size


                if (newGameButton.contains(mousePos.x, mousePos.y)) {
                    newGameButton.onClick();
                } else if (test1Button.contains(mousePos.x, mousePos.y)) {
                    test1Button.onClick();
                } else if (test2Button.contains(mousePos.x, mousePos.y)) {
                    test2Button.onClick();
                } else if (test3Button.contains(mousePos.x, mousePos.y)) {
                    test3Button.onClick();
                } else {



                // Check if the click is within the grid bounds
                if (isValidPosition(gridPos, toolbox.gameState->getDimensions())) {
                    // Get the tile at the grid position
                    Tile& clickedTile = toolbox.gameState->getTile(gridPos.x, gridPos.y);

                    // Left-click on tile
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        clickedTile.onClickLeft();
                    }
                        // Right-click on tile
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        clickedTile.onClickRight();
                        toolbox.gameState->updateFlagCount();
                    }
                    toolbox.gameState->draw(*toolbox.window);
                }}
            }

            toolbox.debugButton->handleEvent(event);
            toolbox.newGameButton->handleEvent(event);
            toolbox.testButton1->handleEvent(event);
            toolbox.testButton2->handleEvent(event);
            toolbox.testButton3->handleEvent(event);



            toolbox.window->clear();
            toolbox.gameState->draw(*toolbox.window);
            toolbox.newGameButton->draw(*toolbox.window);
            toolbox.debugButton->draw(*toolbox.window);
            toolbox.testButton1->draw(*toolbox.window);
            toolbox.testButton2->draw(*toolbox.window);
            toolbox.testButton3->draw(*toolbox.window);


            toolbox.window->display();
        }
    }

    delete toolbox.gameState;
    delete toolbox.debugButton;
    delete toolbox.newGameButton;
    delete toolbox.window;
    delete toolbox.testButton1;
    delete toolbox.testButton2;
    delete toolbox.testButton3;


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
bool isValidPosition(const sf::Vector2i& pos, const sf::Vector2i& dimensions) {
    return pos.x >= 0 && pos.y >= 0 && pos.x < dimensions.x && pos.y < dimensions.y;
}


int main() {
    return launch();
}