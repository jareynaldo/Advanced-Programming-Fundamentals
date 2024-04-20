//
//#ifndef TOOLBOX_H
//#define TOOLBOX_H
//
//#include <SFML/Graphics.hpp>
//#include "Button.h"
//#include "GameState.h"
//
//
//class Toolbox {
//public:
//
//    sf::RenderWindow window;
//
//    GameState* gameState;
//
//    Button* debugButton;
//    Button* newGameButton;
//    Button* testButton1;
//    Button* testButton2;
//
//    // Get the singleton instance of the Toolbox
//    static Toolbox& getInstance() {
//        static Toolbox instance;
//        return instance;
//    }
//
//    // Deleted copy constructor and assignment operator to ensure singleton status
//    Toolbox(Toolbox const&) = delete;
//    void operator=(Toolbox const&) = delete;
//    ~Toolbox() {
//        // Clean up dynamically allocated memory if not using smart pointers
//        delete gameState;
//        delete debugButton;
//        delete newGameButton;
//        // Similar for testButton1 and testButton2...
//
//        // If you loaded textures within this class, don't forget to delete those too
//    }
//
//
//private:
//    // Private constructor for singleton pattern
//    Toolbox() {
//        // Initialize the game state
//        // Assuming GameState takes dimensions and number of mines as parameters
//        gameState = new GameState(sf::Vector2i(25, 16), 50); // Example values
//
//        // Assuming Button takes a position, texture, and a callback function
//        // You'll need to have loaded your textures somewhere appropriate before this
//        sf::Texture* debugTexture = new sf::Texture();
//        debugTexture->loadFromFile("images/debug.png");
//        debugButton = new Button(sf::Vector2f(100, 550), *debugTexture, [this](){ toggleDebugMode(); });
//
//        sf::Texture* newGameTexture = new sf::Texture();
//        newGameTexture->loadFromFile("path/to/new_game_button_texture.png");
//        newGameButton = new Button(sf::Vector2f(200, 550), *newGameTexture, [this](){ restart(); });
//
//        // Similar for testButton1 and testButton2...
//    }
//
//
//};
//
//#endif // TOOLBOX_H
