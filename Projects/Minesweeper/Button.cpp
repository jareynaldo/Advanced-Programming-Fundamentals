#include "Button.h"


Button::Button(sf::Vector2f position, std::function<void()> onClick)  : position(position), sprite()  {
   sprite.setPosition(position);
    onClickCallback = onClick;


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
bool Button::contains(int mouseX, int mouseY) const {

    return mouseX >= position.x && mouseX < position.x + 64 &&
           mouseY >= position.y && mouseY < position.y + 64;
}

sf::Vector2<float> Button::getPosition(){
    return position;
}

sf::Sprite *Button::getSprite() {
    return &sprite;
}
