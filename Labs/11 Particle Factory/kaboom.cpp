#include <cstdlib>
#include <list>
#include <chrono>
#include <thread>
#include <SFML/Graphics.hpp>

#include "ParticleFactory.h"

#define NUMBER_OF_PARTICLES 110
#define SLEEP_TIME_MS 1
#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

int main()
{
    // Prepare the texture for the explosion sprites
    sf::Texture texture;
    texture.loadFromFile("../explosion.png");
    sf::Vector2u imageSize = texture.getSize();
    sf::Sprite mySprite(texture);

    // Grab the reference to the factory and set up the active particle list
    ParticleFactory<sf::Sprite> &factory = ParticleFactory<sf::Sprite>::getInstance();
    std::list<sf::Sprite*> particles;

    // Make the window, then render!
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Kaboom!");
    while (window.isOpen())
    {
        // Remove the oldest particle if applicable
        if (particles.size() >= NUMBER_OF_PARTICLES)
        {
            factory.returnParticle(particles.front());
            particles.pop_front();
        }

        // Create a new particle at a random location and add it to the particle list.
        particles.push_back(factory.getParticle());
        particles.back()->setTexture(texture);
        particles.back()->setPosition(rand() % (SCREEN_WIDTH - imageSize.x), rand() % (SCREEN_HEIGHT - imageSize.y));

        // Draw the particles and display the window.
        window.clear();
       for (auto entry : particles)
            window.draw(*entry);
        window.display();

        // Check if the window should be closed.
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Sleep before next frame.
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME_MS));
    }

    for (auto entry : particles)
        factory.returnParticle(entry);

    return 0;
}