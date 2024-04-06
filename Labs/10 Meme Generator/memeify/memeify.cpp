#include "memer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

int main(int argc, char* argv[]) {


    cout << "hello there" << endl;
    // Check for minimum number of arguments
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <image_file> <top_text> [bottom_text] [top_x] [top_y] [bottom_x] [bottom_y]" << endl;
        return 1;
    }

    // Parse arguments
    string imageFilePath = argv[1];
    String topText = argv[2];
    String bottomText = argc > 3 ? argv[3] : "";
    int topX = argc > 4 ? stoi(argv[4]) : -1;
    int topY = argc > 5 ? stoi(argv[5]) : -1;
    int bottomX = argc > 6 ? stoi(argv[6]) : -1;
    int bottomY = argc > 7 ? stoi(argv[7]) : -1;

    // Load the image
    Image baseImage;
    baseImage.loadFromFile(imageFilePath);

    // Create a memer instance and generate the meme
    memer myMemer;
    Image memeImage = myMemer.generateMeme(baseImage, topText, bottomText, topX, topY, bottomX, bottomY);

    // Display the image in a window
    RenderWindow window(VideoMode(memeImage.getSize().x, memeImage.getSize().y), "Memeify");
    Texture texture;
    texture.loadFromImage(memeImage);
    Sprite sprite(texture);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    // Save the new meme image
    string newFileName = imageFilePath.substr(0, imageFilePath.find_last_of('.')) + "-meme" + imageFilePath.substr(imageFilePath.find_last_of('.'));
    if (!memeImage.saveToFile(newFileName)) {
        cerr << "Failed to save meme image: " << newFileName << endl;
        return 1;
    }

    cout << "Meme saved as: " << newFileName << endl;
    return 0;
}
