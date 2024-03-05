//
// Created by Karan Faldu and  Jose Reynaldo
//
#pragma once


#include "Dragon.h"

class IceDragon: public Dragon
{
public:
    IceDragon(string _name, string _image);
    bool canBreatheFire();
};