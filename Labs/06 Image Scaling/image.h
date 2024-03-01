//
// Created by brandon and jose
//
#ifndef LAB_6_IMAGE_H
#define LAB_6_IMAGE_H

#endif //LAB_6_IMAGE_H

//Image class that initializes methods and attributes
class Image{
public:
    Image(unsigned char *imageData);

    unsigned char *getImageData();

    unsigned char *getPixelData();

    unsigned char getWidth();

    unsigned char getHeight();

    void setImageData(unsigned char *newData);

private:
    unsigned char *image_data;

};

