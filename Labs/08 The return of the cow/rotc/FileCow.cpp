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


    image =  "";

    try {
        ifstream instream(filename);
        string line;
        while (getline(instream, line)) {
            image += line + "\n";
        }

    }
    catch(const std::ifstream::failure &oops){
        cerr << "MOOOOO!!!!!!" << endl;

    }
}

void setImage(){
    throw runtime_error("Cannot reset FileCow Image");
}


