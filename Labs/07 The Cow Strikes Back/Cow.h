//
// Created by Karan Faldu on 3/1/24.
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

    string& getName();

    string& getImage();

    virtual void setImage(string _image);

};
