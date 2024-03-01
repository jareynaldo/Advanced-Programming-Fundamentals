//
// Created by Karan Faldu on 3/1/24.
//
#pragma once


#include "Dragon.h"

class IceDragon: public Dragon
{
public:
    IceDragon(string _name, string _image);
    bool canBreatheFire();
};