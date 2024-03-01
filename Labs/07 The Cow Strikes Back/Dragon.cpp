//
// Created by Karan Faldu on 3/1/24.
//

#include "Dragon.h"

Dragon::Dragon(string _name, string _image): Cow(_name)
{
    Cow::setImage(_image);
}

bool Dragon::canBreatheFire()
{
    return true;
}