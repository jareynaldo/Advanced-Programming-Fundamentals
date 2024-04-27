#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameState.h"

class Toolbox {
public:
    static Toolbox& getInstance() {
        static Toolbox instance; // Guaranteed to be destroyed and instantiated on first use
        return instance;
    }

    sf::RenderWindow *window;
    GameState* gameState;
    Button* debugButton;
    Button* newGameButton;
    Button* testButton1;
    Button* testButton2;
    Button *testButton3;
    // Delete copy constructor and assignment operator to enforce singleton property
    Toolbox(const Toolbox&) = delete;
    Toolbox& operator=(const Toolbox&) = delete;

private:
    Toolbox();


};
