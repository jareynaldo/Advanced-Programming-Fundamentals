#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class Toolbox {
public:
    static Toolbox& getInstance() {
        static Toolbox instance;
        return instance;
    }

    sf::RenderWindow *window;
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;
    Button *testButton3;

    Toolbox(const Toolbox&) = delete;
    Toolbox& operator=(const Toolbox&) = delete;

private:
    Toolbox();


};
