//// Button.cpp
//
//#include "Button.h"
//
//Button::Button(sf::Vector2f position, sf::Texture& texture, std::function<void()> onClick)
//        : position(position), clickCallback(onClick) {
//    // Assign the texture to the sprite and set its position
//    sprite.setTexture(texture);
//    sprite.setPosition(position);
//}
//
//sf::Vector2f Button::getPosition() const {
//    return position;
//}
//
//void Button::setSprite(sf::Sprite& newSprite) {
//    sprite = newSprite;
//}
//
//sf::Sprite& Button::getSprite() {
//    return sprite;
//}
//
//void Button::onClick() {
//    // Call the callback function if it's set
//    if (clickCallback) {
//        clickCallback();
//    }
//}
//
//void Button::draw(sf::RenderWindow& window) {
//    // Draw the sprite associated with this button
//    window.draw(sprite);
//}
//bool Button::handleClick(const sf::Vector2f& position) {
//    if (sprite.getGlobalBounds().contains(position)) {
//        onClick();
//        return true;
//    }
//    return false;
//}
//
//// ... other member function definitions ...
