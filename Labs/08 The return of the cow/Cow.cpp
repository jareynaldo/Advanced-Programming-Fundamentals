//
// Created by Karan Faldu and Jose Reynaldo
//
#include "Cow.h"
    //Constructs a Cow object
    Cow::Cow(string _name): name(_name) {}

    string& Cow::getName()
    {
        return name;
    }
    string& Cow::getImage()
    {
        return image;
    }
    void Cow::setImage(string _image)
    {
        image=_image;
    }

Cow::Cow() {

}
