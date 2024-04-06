//
// Created by jreyn on 4/5/2024.
//

#ifndef MEMEIFY_MEMER_H
#define MEMEIFY_MEMER_H


#include <SFML/Graphics.hpp>


class memer {
public:
    sf::Image generateMeme(sf::Image base, sf::String topText, sf::String bottomText = "",
                          int topX = -1, int topY = -1, int bottomX = -1, int bottomY = -1) {
        sf::Texture texture;
        texture.loadFromImage(base);

        sf::Sprite sprite;
        sprite.setTexture(texture);

        sf::RenderTexture window;
        window.draw(sprite);
        int width = window.getSize().x;
        int height = window.getSize().y;


        sf::Font font;
        font.loadFromFile("Cave-Story.ttf");

        sf::Text text;
        text.setFont(font);


        if (topX == -1 && topY == -1 && bottomX == -1 && bottomY == -1) {

            text.setPosition(width / 2 - (topX - bottomX) / 2, height / 3);
        } else {
            text.setPosition(int(topX), int(topY));
        };

        window.draw(text);

        sf::Image imageRe = texture.copyToImage();

        imageRe.flipHorizontally();
        return imageRe;
    };










};


#endif //MEMEIFY_MEMER_H
