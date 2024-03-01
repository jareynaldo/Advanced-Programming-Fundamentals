//
// Created brandon and jose
//
#include "Image.h"

//Image file that defines each image method
Image::Image(unsigned char *imageData){
    image_data = imageData;
}
unsigned char* Image::getImageData(){
        return image_data;
    }
unsigned char* Image::getPixelData(){
        return image_data + 2;
    }
unsigned char Image::getWidth(){
        return image_data[0];
    }
unsigned char Image::getHeight(){
        return image_data[1];
    }
void Image::setImageData(unsigned char *newData){
        image_data = newData;
}