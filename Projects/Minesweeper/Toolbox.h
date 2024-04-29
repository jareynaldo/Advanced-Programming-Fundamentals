#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"
#ifndef TOOLBOX_H
#define TOOLBOX_H
class Toolbox {
public:
    static Toolbox& getInstance() {
        static Toolbox instance;
        return instance;
    }

    sf::RenderWindow *window{};
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;
    Button* testButton3;

    Toolbox(const Toolbox&) = delete;
    Toolbox& operator=(const Toolbox&) = delete;
    sf::Texture newGameTexture, debugTexture, test1Texture, test2Texture, test3Texture;
    sf::Sprite newGameSprite, debugSprite, test1Sprite, test2Sprite,test3Sprite;


private:
    Toolbox();


};
#endif // TOOLBOX_H
