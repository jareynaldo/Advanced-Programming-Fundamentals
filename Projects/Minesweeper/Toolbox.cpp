#include "Toolbox.h"
Toolbox::Toolbox() {
    // The button positions should be replaced with the actual positions where you want them
    debugButton = new Button(sf::Vector2f(550, 700), []() {

    });
    newGameButton = new Button(sf::Vector2f(565, 700), []() {

    });

}

