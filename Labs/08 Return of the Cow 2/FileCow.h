//
// Created by jreyn on 3/22/2024.
//
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

#ifndef INC_07_THE_COW_STRIKES_BACK_FILECOW_H
#define INC_07_THE_COW_STRIKES_BACK_FILECOW_H

#endif //INC_07_THE_COW_STRIKES_BACK_FILECOW_H
