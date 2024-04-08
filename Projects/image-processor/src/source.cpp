//
// Created by jreyn on 4/6/2024.
//

#include "source.h"
#include "Image.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;




bool readTGA(const string& filename, TGAHeader& header, vector<unsigned char>& imageData) {
    ifstream file(filename, ios::binary);
    // attempt to open file
    if (!file.is_open()) {
        cerr << "File "  << filename << " couldn't be opened" << endl;
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



bool writeTGA(const string& filename, const TGAHeader& header, const vector<unsigned char>& imageData) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Could not open the file: " << filename << endl;
        return false;
    }

    // Write the header
    file.write(reinterpret_cast<const char*>(&header), sizeof(TGAHeader));

    // Write the image data
    file.write(reinterpret_cast<const char*>(imageData.data()), imageData.size());


    return true;
}




int main(int argc, char** argv) {
    vector<string> args(argv, argv + argc);

    if (args.size() < 4) {
        cerr << "Usage: " << args[0] << " <input_file> <output_file> <operation>" << endl;
        return 0;
    }




    string inputFileName = args[1];
    string otherFileName = args[2];
    string operation = args[3];

    // Load the input image
    Image inputImage;
    if (readTGA(inputFileName, inputImage.header, inputImage.pixels)) {
        cout << "Succesfully read " << inputFileName << endl;

    }

    // Perform the operation
    if (operation == "multiply") {
        Image otherImage;
        readTGA(otherFileName, otherImage.header, otherImage.pixels);
        inputImage.applyMultiply(otherImage);

    } else if (operation == "subtract") {
        // ... handle subtract
    }



    string outputFilename = "../output/part1.tga";




   if(writeTGA(outputFilename, inputImage.header, inputImage.pixels)){
       cout << "Succesfully wrote the file! " ;
   }



    return 0;
}
