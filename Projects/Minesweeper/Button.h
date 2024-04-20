//
//#ifndef BUTTON_H
//#define BUTTON_H
//
//#include <SFML/Graphics.hpp>
//#include <functional>
//
//class Button {
//public:
//    // Constructor for a button
//    Button(sf::Vector2f position, sf::Texture& texture, std::function<void()> onClick);
//
//    // Get the position of the button
//    sf::Vector2f getPosition() const;
//
//    // Set the sprite for the button
//    void setSprite(sf::Sprite& sprite);
//
//    // Get the sprite for the button
//    sf::Sprite& getSprite();
//
//    // Invoke the button's callback function
//    void onClick();
//
//    // Draw the button on the screen
//    void draw(sf::RenderWindow& window);
//
//    bool handleClick(const sf::Vector2f& position);
//
//private:
//    // The position of the button on the screen
//    sf::Vector2f position;
//
//    // The sprite for the button
//    sf::Sprite sprite;
//
//    // The callback function to be called when the button is clicked
//    std::function<void()> clickCallback;
//
//    // ... other private members and helper functions ...
//};
//
//#endif // BUTTON_H
