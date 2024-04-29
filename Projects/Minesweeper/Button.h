#ifndef BUTTON_H
#define BUTTON_H

#include <SFML/Graphics.hpp>
#include <functional>

class Button {
public:
    Button(sf::Vector2f position, std::function<void()> onClick);

    void setSprite(sf::Sprite* _sprite);
    sf::Sprite* getSprite();
    sf::Vector2<float> getPosition();
    void draw(sf::RenderWindow& window);
    void onClick();
    void handleEvent(const sf::Event& event);
    bool contains(int mouseX, int mouseY) const;


private:
    sf::Vector2<float> position;
    sf::Sprite sprite;
    std::function<void()> onClickCallback;

    bool contains(const sf::Vector2i &point) const;
};

#endif