//
// Created by jreyn on 4/6/2024.
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

        unsigned char multiplyPixels(unsigned char a, unsigned char b) {


            float fa = a / 255.0f;
            float fb = b / 255.0f;

            // Multiply and scale back to range [0, 255], adding 0.5f to round to nearest integer
            float result = (fa * fb) * 255.0f + 0.5f;

            // Truncate by casting to unsigned char, which will round down
            return static_cast<unsigned char>(result);
        }

    };






#endif //IMAGE_PROCESSOR_IMAGE_H
