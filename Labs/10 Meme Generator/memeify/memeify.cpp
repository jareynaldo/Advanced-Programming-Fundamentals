//
// By Jose Reynaldo and Karan Faldu
//
#include "memer.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace sf;

int main(int argc, char* argv[]) {

    // when i run directly from main func it runs how it's mean to and
    // works. But when i attmept to excecute form command line it
    // doesn't work at all. Not even the "hello there prints".

//    char* argv[2];
//    argv[1] = "doge.jpg";
//    argv[2] = "Such memes";
    cout << "hello there" << endl;
//    int argc = 2;

    if (argc < 2) {
        cerr << "need more than 2 arguments" << endl;
        return 1;
    }

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
            if (event.type == Event::Closed) {
                window.close();
            }

        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    // Save the new meme image
    string newFileName = imageFilePath.substr(0, imageFilePath.find_last_of('.')) + "-meme" + imageFilePath.substr(imageFilePath.find_last_of('.'));
    memeImage.saveToFile(newFileName);

    cout << "Meme saved as: " << newFileName << endl;
    return 0;
}
