//
// Created by Karan Faldu on 3/1/24.
//
#pragma once

#include "Cow.h"
class Dragon: public Cow
{
public:
    Dragon(string _name, string _image);

    bool canBreatheFire();
};

