//
// Created by Jose Reynaldo
//
#pragma once

#include "Cow.h"
class Dragon: public Cow
{
public:
    Dragon(string _name, string _image);

    bool canBreatheFire();
};

