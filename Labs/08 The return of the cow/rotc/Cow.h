//
// Created by Jose Reynaldo
//

#pragma once

#include <string>
using namespace std;

class Cow
{
    string name;
    string image;

public:
    Cow(string _name);

    Cow();

    string& getName();

    string& getImage();

    virtual void setImage(string _image);

};
