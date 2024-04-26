#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(sf::Vector2f position, std::function<void()> onClick);

    void setSprite(sf::Sprite* _sprite);
    void draw(sf::RenderWindow& window);
    void onClick();
    void handleEvent(const sf::Event& event);

private:
    sf::Vector2f position;
    sf::Sprite sprite;
    std::function<void()> onClickCallback; // Callback function for click events
};

#endif