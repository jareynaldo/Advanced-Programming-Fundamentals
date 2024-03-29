//
// Created by jreyn on 3/22/2024.
//

#include "FileCow.h"
#include <iostream>
#include <fstream>

using namespace  std;

FileCow::FileCow(){
        name = "";
        image = "";

}

FileCow::FileCow (const string& _name, const string& filename){


    name = _name;
    image =  "";

    try {
        ifstream in_file(filename);
        string line;
        while (getline(in_file, line)) {
            image += line;
        }

    }
    catch(const std::ifstream::failure &oops){
        cerr << "MOOOOO!!!!!!";

    }
}

void setImage(){
    cerr << "Cannot reset FileCow Image";
}


