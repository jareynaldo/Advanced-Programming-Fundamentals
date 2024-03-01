//
// Created by Karan Faldu on 3/1/24.
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