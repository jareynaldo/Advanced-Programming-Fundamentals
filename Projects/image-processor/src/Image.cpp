//
// Created by jreyn on 4/6/2024.
//
#pragma once
#include "Image.h"



void Image::applyMultiply(const Image& other) {
    for (size_t i = 0; i < this->pixels.size(); i += 3) {
        // Multiply blue channel and add 0.5f before casting to unsigned char for rounding

        this->pixels[i] = multiplyPixels(this->pixels[i], other.pixels[i]);
        // Multiply green channel and add 0.5f before casting to unsigned char for rounding
        this->pixels[i + 1] = multiplyPixels(this->pixels[i + 1], other.pixels[i + 1] );
        // Multiply red channel and add 0.5f before casting to unsigned char for rounding
        this->pixels[i + 2] = multiplyPixels(this->pixels[i + 2], other.pixels[i + 2]);
    }
}

void Image::applySubtract(const Image& other) {
    // Assuming both images are the same size and imageData is a vector<unsigned char>
    // holding the image's pixel data in a flat array.
    for (size_t i = 0; i < this->pixels.size(); i++) {
        // Perform subtraction for each color component and clamp the result to 0 if negative.
        int subtractionResult = static_cast<int>(this->pixels[i]) - static_cast<int>(other.pixels[i]);
        this->pixels[i] = (subtractionResult < 0) ? 0 : subtractionResult;
    }
}