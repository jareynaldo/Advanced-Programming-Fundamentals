//
// Created by Jose Reynaldo  4/6/2024.
//

#include "source.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;




bool readTGA(const string& fileName, TGAHeader& header, vector<unsigned char>& imageData) {
    ifstream file(fileName, ios::binary);
    if (!file.is_open()) {
        cerr << "File "  << fileName << " couldn't be opened" << endl;
        return false;
    }

    // Read the header
    file.read(reinterpret_cast<char*>(&header), sizeof(TGAHeader));
    int imageSize = header.width * header.height * (header.bitsPerPixel / 8);
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
        Image red;
        readTGA("../input/layer_red.tga", red.header, red.pixels);
        inputImage.combineValues(otherImage, red);
    }else if (part == "part10") {
        inputImage.rotate180();
    }

    string outputFilename = "../output/" + part + ".tga";
    if(part != "part8"){
        writeTGA(outputFilename, inputImage.header, inputImage.pixels);

    }

}
void test(const string &outputFileName, const string &exampleFileName, const int &testNumber){
    Image output;
    readTGA(outputFileName, output.header, output.pixels);

    Image example;
    readTGA(exampleFileName, example.header, example.pixels);
    bool checker = true;

    for(int i = 0; i < output.pixels.size(); i++){
        if(output.pixels[i] != example.pixels[i]){
            checker = false;
        }
    }
    if(checker){
        cout << "Test For test " << testNumber << "....Passed!" << endl;
    } else{
        cout << "Test For test " << testNumber << " ....Failed" <<endl;
    }
}
void testExecute(){
    vector<string> output = {"part1.tga", "part2.tga", "part3.tga", "part4.tga", "part5.tga", "part6.tga", "part7.tga", "part8_r.tga", "part8_g.tga", "part8_b.tga", "part9.tga", "part10.tga"};
    vector<string> example = output;
    for(int i  = 0; i < output.size(); i++){
        output.at(i) = "../output/" +  output.at(i);\
        example.at(i) = "../examples/EXAMPLE_" +  example.at(i);
        test(output.at(i), example.at(i), i + 1);
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
    executeOperation("layer_blue.tga", "layer_green.tga", "part9");
    executeOperation("text2.tga", "text2.tga", "part10");

    cout << endl;
    //testExecute();

    return 0;
}
