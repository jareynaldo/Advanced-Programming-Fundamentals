//
// Created by jose reynaldo and karan faldu
//

#ifndef MEMEIFY_MEMER_H
#define MEMEIFY_MEMER_H


#include <SFML/Graphics.hpp>
#include <iostream>


class memer {
    
public:
    sf::Image generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",
                          int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1) {
        sf::Texture texture;
        texture.loadFromImage(base);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        sf::RenderTexture window;
        window.create(base.getSize().x, base.getSize().y);
        window.clear();
        window.draw(sprite);
        int width = window.getSize().x;
        int height = window.getSize().y;


        sf::Font font;
        font.loadFromFile("Cave-Story.ttf");

        sf::Text text;
        text.setFont(font);
        text.setString(topText);



        if (topX == -1 || topY == -1) {
            sf::FloatRect textRect = text.getLocalBounds();
            text.setOrigin(textRect.left + textRect.width/2.0f,
                           textRect.top  + textRect.height/2.0f);
            text.setPosition(sf::Vector2f(base.getSize().x/2.0f, base.getSize().y/3.0f));
        } else {
            text.setPosition(static_cast<float>(topX), static_cast<float>(topY));
        }

        window.draw(text);
        if (!bottomText.isEmpty()) {
            sf::Text bottomTextElement;
            bottomTextElement.setFont(font);
            bottomTextElement.setString(bottomText);

            if (bottomX == -1 || bottomY == -1) {
                sf::FloatRect textRect = bottomTextElement.getLocalBounds();
                bottomTextElement.setOrigin(textRect.left + textRect.width / 2.0f,
                                            textRect.top + textRect.height / 2.0f);
                bottomTextElement.setPosition(sf::Vector2f(base.getSize().x / 2.0f, (2 * base.getSize().y) / 3.0f));
            } else {
                bottomTextElement.setPosition(static_cast<float>(bottomX), static_cast<float>(bottomY));
            }

            window.draw(bottomTextElement);
        }

        window.display();

        sf::Texture resultTexture = window.getTexture();
        sf::Image resultImage = resultTexture.copyToImage();

        sf::Image imageRe = resultTexture.copyToImage();

        return imageRe;
    };










};


#endif //MEMEIFY_MEMER_H
