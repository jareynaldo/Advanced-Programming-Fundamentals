//
// Created by Jose reynaldo on 4/6/2024.
//
#include "Image.h"



void Image::applyMultiply(const Image& other) {
    for (size_t i = 0; i < this->pixels.size(); i += 3) {
        // use the normalisation multiplyPixels method then reassign for each
        this->pixels[i] = multiplyPixels(this->pixels[i], other.pixels[i]);
        this->pixels[i + 1] = multiplyPixels(this->pixels[i + 1], other.pixels[i + 1] );
        this->pixels[i + 2] = multiplyPixels(this->pixels[i + 2], other.pixels[i + 2]);
    }
}

void Image::applySubtract(const Image& other) {
    for (size_t i = 0; i < this->pixels.size(); i++) {
        // just substract one element form another
        int subtractionResult = static_cast<int>(this->pixels[i]) - static_cast<int>(other.pixels[i]);
        this->pixels[i] = (subtractionResult < 0) ? 0 : subtractionResult;


    }
}
void Image::applyScreen(const Image& other) {
    // same logic used for multiply, apply the screen func and reassign value
    for (size_t i = 0; i < this->pixels.size(); i += 3) {
        this->pixels[i] = screenPixels(this->pixels[i], other.pixels[i]);
        this->pixels[i + 1] = screenPixels(this->pixels[i + 1], other.pixels[i + 1]);
        this->pixels[i + 2] = screenPixels(this->pixels[i + 2], other.pixels[i + 2]);
    }
}

void Image::applyOverlay(const Image& other) {
    for (size_t i = 0; i < this->pixels.size(); i++) {
        float base = this->pixels[i] / 255.0f;  // normalized base color
        float blend = other.pixels[i] / 255.0f; // normalized blend color
        float result;

        if (base <= 0.5f) {
            result = 2 * base * blend; // if base = dark
        } else {
            result = 1 - 2 * (1 - base) * (1 - blend); //if base = light
        }
        this->pixels[i] = static_cast<unsigned char>(result * 255.0f + 0.5f); // Round and scale back to [0, 255]
    }
}

void Image::addGreenChannel(unsigned char valueToAdd) {
    for (size_t i = 1; i < this->pixels.size(); i += 3) {
        unsigned int newValue = static_cast<unsigned int>(this->pixels[i]) + valueToAdd;
        this->pixels[i] = (newValue > 255) ? 255 : static_cast<unsigned char>(newValue);
    }
}

void Image::scaleRedChannel() {
    for (size_t i = 0; i < this->pixels.size(); i += 3) {
        float redValue = (this->pixels[i + 2] / 255.0f ) * 4;
        redValue = (redValue > 1) ? 1 : redValue;
        this->pixels[i + 2] = static_cast<unsigned char>(redValue * 255.0f + 0.5f);
        this->pixels[i] = static_cast<unsigned char>(0) ;
    }
}

void Image::clear(){
    for (size_t i = 0; i < this->pixels.size(); i += 1) {
        this->pixels[i] =  0;
    }
}

void Image::seperateValues(Image& a, Image& b, Image& c){
    for (size_t i = 0; i < this->pixels.size(); i += 3) {

        a.pixels[i] = this->pixels[i];
        a.pixels[i + 1] = this->pixels[i];
        a.pixels[i + 2] = this->pixels[i];

        b.pixels[i] = this->pixels[i +1];
        b.pixels[i + 1] = this->pixels[i + 1];
        b.pixels[i + 2] = this->pixels[i +1];

        c.pixels[i] = this->pixels[i + 2];
        c.pixels[i + 1] = this->pixels[i + 2];
        c.pixels[i + 2] = this->pixels[i + 2];
    }
}

void Image::combineValues(const Image& green, const Image& red){
    for (size_t i = 0; i < this->pixels.size(); i += 3) {
        this->pixels[i+ 1] = green.pixels[i + 1];
        this->pixels[i+2] = red.pixels[i+2];
    }
}