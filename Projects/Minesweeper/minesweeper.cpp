//
// Created by jreyn on 4/16/2024.
//
#include "minesweeper.h"


int launch() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "P4 – Minesweeper, Jose Reynaldo");

    Toolbox& toolbox = Toolbox::getInstance();
    toolbox.window = &window;


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed) {
                // Convert the mouse position to grid coordinates
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2i gridPos(mousePos.x / 32, mousePos.y / 32);

                if (toolbox.newGameButton->contains(mousePos.x, mousePos.y)) {
                    toolbox.newGameButton->onClick();
                }else if (toolbox.testButton1->contains(mousePos.x, mousePos.y)) {
                    toolbox.testButton1->onClick();
                } else if (toolbox.testButton2->contains(mousePos.x, mousePos.y)) {
                    toolbox.testButton2->onClick();
                } else if (toolbox.testButton3->contains(mousePos.x, mousePos.y)) {
                    toolbox.testButton3->onClick();
                }  else if (toolbox.debugButton->contains(mousePos.x, mousePos.y)) {
                    toolbox.debugButton->onClick();
                } else {

                // Check if the click is within the grid bounds
                if (isValidPosition(gridPos, toolbox.gameState->getDimensions())) {
                    // Get the tile at the grid position
                    Tile& clickedTile = toolbox.gameState->getTile(gridPos.x, gridPos.y);

                    if (clickedTile.hasMine) {
                        toolbox.gameState->currentFaceState = GameState::PlayStatus::LOSS;
                        toolbox.gameState->faceTexture.loadFromFile("images/face_lose.png");
                        toolbox.gameState->faceSprite.setTexture(toolbox.gameState->faceTexture);
                    }

                    if (toolbox.gameState->checkVictory()) {
                        toolbox.gameState->currentFaceState = GameState::PlayStatus::WIN;
                        toolbox.gameState->faceTexture.loadFromFile("images/face_win.png");
                        toolbox.gameState->faceSprite.setTexture(toolbox.gameState->faceTexture);
                    }
                    // Left-click on tile
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        clickedTile.onClickLeft();
                    }
                        // Right-click on tile
                    else if (event.mouseButton.button == sf::Mouse::Right) {
                        clickedTile.onClickRight();
                        toolbox.gameState->updateFlagCount();
                    }

                }}

            }





            toolbox.window->clear();
            toolbox.gameState->draw(*toolbox.window);
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
    debugMode = false;
}

void render(sf::RenderWindow& window) {

}

void toggleDebugMode(Toolbox *toolbox) {

    std::cout << "I hate this project" << std::endl;
    if(debugMode){
        debugMode = false;

    }else{
        debugMode = true;
        sf::Vector2i boardDimensions = toolbox->gameState->getDimensions();
        for(i = 0; i < boardDimensions.y; i++){
            for(j = 0; j < boardDimensions.x; i++){
                Tile tile = toolbox->gameState->getTile(i, j);
                tile.reveal();
            }
        }

    }

}

bool getDebugMode() {
    return debugMode;
}
bool isValidPosition(const sf::Vector2i& pos, const sf::Vector2i& dimensions) {
    return pos.x >= 0 && pos.y >= 0 && pos.x < dimensions.x && pos.y < dimensions.y;
}
bool constains( sf::Vector2<float> pos, const sf::Vector2i& dimensions) {
    return pos.x >= 0 && pos.y >= 0 && pos.x < dimensions.x && pos.y < dimensions.y;
}

int main() {
    return launch();
}