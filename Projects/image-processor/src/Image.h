//
// Created by Jose Reynaldo on 4/6/2024.
//

#ifndef IMAGE_PROCESSOR_IMAGE_H
#define IMAGE_PROCESSOR_IMAGE_H


#include "source.h"
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

    struct Image {
        TGAHeader header;
        vector<unsigned char> pixels;

        // Method to apply operations
        void applyMultiply(const Image& other);
        void applySubtract(const Image& other);
        void applyScreen(const Image& other);
        void applyOverlay(const Image& other);
        void addGreenChannel(unsigned char valueToAdd);
        void scaleRedChannel();
        void clear();
        void seperateValues(Image& a, Image& b, Image& c);
        void combineValues(Image& green, Image& red);

        unsigned char multiplyPixels(unsigned char a, unsigned char b) {

            // normalise, then multiply, then return to 255 range.
            float fa = a / 255.0f;
            float fb = b / 255.0f;

            float result = (fa * fb) * 255.0f + 0.5f;
            return static_cast<unsigned char>(result);
        }
        unsigned char screenPixels(unsigned char a, unsigned char b) {
            // normalise, do the calc, then return to 255 range
            float fa = a / 255.0f;
            float fb = b / 255.0f;

            float result = 1.0f - (1.0f - fa) * (1.0f - fb);
            return static_cast<unsigned char>(result * 255.0f + 0.5f);
        }

    };






#endif //IMAGE_PROCESSOR_IMAGE_H
