//
// Created by jreyn on 3/1/2024.
//
#include <string>
#include <iostream>
#include "HeiferGenerator.h"

using namespace std;




int main(int argc, char* argv[]){

    vector<Cow* > cows = HeiferGenerator::getCows();


    std::string userChoice = argv[1];
    int i;


    if(userChoice == "-l"){
        cout << "Cows available: ";

        for (i = 0; i < cows.size(); i++){
            cout << cows.at(i)->getName() << " ";
        }
    }

    else {
        for(i = 0; i < argc;i++ ){
            cout<< argv[i];
        }
    }



    return 0;
}


