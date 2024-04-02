//
// Created by jreyn on 3/22/2024.
//
#pragma once

#include "Cow.h"


class FileCow: public Cow {

protected:
    string name;
    string image;

public:

    FileCow();
    FileCow (const string& _name, const string& filename);

    void setImage();



};

