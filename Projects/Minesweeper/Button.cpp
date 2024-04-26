#include "Button.h"


Button::Button(sf::Vector2f position, std::function<void()> onClick)  : position(position), sprite()  {
   sprite.setPosition(position);

}

void Button::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}
void Button::setSprite(sf::Sprite* _sprite) {
    sprite = *_sprite;
    sprite.setPosition(position);


}
void Button::onClick() {

    if(onClickCallback) {
        onClickCallback();
    }

}

void Button::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        // Check if the button is clicked and invoke the callback
        if (sprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            onClick();
        }
    }
}


