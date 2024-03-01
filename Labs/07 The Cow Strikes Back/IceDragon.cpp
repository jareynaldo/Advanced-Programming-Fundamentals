//
// Created by Karan Faldu on 3/1/24.
//

#include "IceDragon.h"
IceDragon::IceDragon(string _name, string _image): Dragon(_name, _image){}

bool IceDragon::canBreatheFire()
{
    return false;
}