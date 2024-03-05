//
// Created by Karan Faldu and  Jose Reynaldo
//

#include "IceDragon.h"
IceDragon::IceDragon(string _name, string _image): Dragon(_name, _image){}

bool IceDragon::canBreatheFire()
{
    return false;
}