//
// Created by Jose Reynaldo on 4/6/2024.
//

#include "source.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;




bool readTGA(const string& fileName, TGAHeader& header, vector<unsigned char>& imageData) {
    ifstream file(fileName, ios::binary);
    // attempt to open file
    if (!file.is_open()) {
        cerr << "File "  << fileName << " couldn't be opened" << endl;
        return false;
    }

    // Read the header
    file.read(reinterpret_cast<char*>(&header), sizeof(TGAHeader));
    // reinterpret_cast will change the pointer type to header type


    // Calculate the size of the image data in bytes
    int imageSize = header.width * header.height * (header.bitsPerPixel / 8);

    // Resize the vector to fit
    imageData.resize(imageSize);
    file.read(reinterpret_cast<char*>(imageData.data()), imageSize);


    return true;
}



bool writeTGA(const string& fileName, const TGAHeader& header, const vector<unsigned char>& imageData) {
    ofstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "Could not open the file: " << fileName << endl;
        return false;
    }

    // Write the header
    file.write(reinterpret_cast<const char*>(&header), sizeof(TGAHeader));

    // Write the image data
    file.write(reinterpret_cast<const char*>(imageData.data()), imageData.size());
    cout << "Succesfully wrote " << fileName << endl;

    return true;
}


void executeOperation(const string& shortInFileName, const string& shortOutFileName, const string& part) {
    // since there are always at least two files those get passed in always

    string inputFileName = "../input/" + shortInFileName;
    string otherFileName = "../input/" + shortOutFileName;
    Image inputImage, otherImage;
    readTGA(inputFileName, inputImage.header, inputImage.pixels);
    readTGA(otherFileName, otherImage.header, otherImage.pixels);


    if (part == "part1") {
        inputImage.applyMultiply(otherImage);

    } else if (part == "part2") {
        inputImage.applySubtract(otherImage);

    } else if (part == "part3"){
        inputImage.applyMultiply(otherImage);
        Image text;
        readTGA("../input/text.tga", text.header, text.pixels);
        inputImage.applyScreen(text);
    }else if (part == "part4") {
        inputImage.applyMultiply(otherImage);

        Image pattern2;
        readTGA("../input/pattern2.tga", pattern2.header, pattern2.pixels);
        inputImage.applySubtract(pattern2);

    } else if (part == "part5") {
        inputImage.applyOverlay(otherImage);

    } else if (part == "part6") {
        inputImage.addGreenChannel(200);
    }else if (part == "part7") {
        inputImage.scaleRedChannel();
    }else if (part == "part8") {
        Image _b;
        readTGA(inputFileName, _b.header, _b.pixels);
        _b.clear();

        Image _g;
        readTGA(inputFileName, _g.header, _g.pixels);
        _g.clear();

        Image _r;
        readTGA(inputFileName,  _r.header,  _r.pixels);
        _r.clear();

        inputImage.seperateValues(_b, _g, _r);
        writeTGA("../output/part8_r.tga", _r.header, _r.pixels);
        writeTGA("../output/part8_g.tga", _g.header, _g.pixels);
        writeTGA("../output/part8_b.tga", _b.header, _b.pixels);
    }else if(part == "part9"){

    }

    string outputFilename = "../output/" + part + ".tga";
    if(part != "part8"){
        writeTGA(outputFilename, inputImage.header, inputImage.pixels);

    }

}


int main() {

    executeOperation("layer1.tga", "pattern1.tga", "part1");
    executeOperation("car.tga", "layer2.tga", "part2");
    executeOperation("layer1.tga", "pattern2.tga", "part3");
    executeOperation("layer2.tga", "circles.tga", "part4");
    executeOperation( "pattern1.tga", "layer1.tga", "part5");
    executeOperation( "car.tga", "pattern1.tga", "part6");
    executeOperation("car.tga", "car.tga", "part7");
    executeOperation("car.tga", "car.tga", "part8");
    executeOperation("layer_red.tga", "layer_blue.tga", "part9");




    return 0;
}
