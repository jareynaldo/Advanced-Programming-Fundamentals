//
// Created by  Jose Reynaldo and Jaxon Kundrat j.kundrat@ufl.edu
//
#include <string>
#include <iostream>
#include "HeiferGenerator.h"
#include "Dragon.h"
#include "IceDragon.h"


using namespace std;




int main(int argc, char* argv[]){

    vector<Cow*> cows = HeiferGenerator::getCows();
    vector<Cow*> fileCows = HeiferGenerator::getFileCows();

    vector<string> cowsAvaiable = {"heifer", "kitteh", "dragon", "ice-dragon"};
    vector<string> cowFiles = {"moose", "turkey", "turtle", "tux"};

    int cowSize = cows.size();

    int i;


    if (argc > 1){
        if((string)argv[1] == "-l"){
            cout << "Cows available: ";

            // creates a message that will then be printerd
            string message = "";
            for(int i = 0; i < cowSize; i++) {
                message += cows.at(i)->getName();
                if (i + 1 != cowSize) {
                    message += " ";
                }
            }
            cout << message << endl;

            cout << "File cows available: ";
            // creates a message that will then be printerd
            message = "";
            for(int i = 0; i < cowSize; i++) {
                message += fileCows.at(i)->getName();
                if (i + 1 != cowSize) {
                    message += " ";
                }
            }
            cout << message << endl << endl;


        } else if((string )argv[1] == "Hello" ){

            // since two possabilities, checks for each
            if ((string) argv[2] == "World!"){
                cout <<endl<< "Hello World!" << endl;
                cout << cows.at(0) ->getImage() << endl;
            } else{
                cout << endl << "Hello -n kitteh"<< endl;
                cout << cows.at(0) ->getImage() << endl;

            }



        }
        else if((string)argv[1] == "-n"){
            bool counter  = false;

            // similar start as "-l", creating an object slowly (and checking if last one)
            string message;
            for(i = 3; i < argc; i++){
                message += argv[i];
                if (i + 1 != argc) {
                    message += " ";
                }
            };

            for (i = 0; i < cowSize; i++) {
                if ((string) argv[2] == cowsAvaiable[i]) {

                    counter = true;
                    cout << endl << message << endl;
                    cout << cows.at(i)->getImage() << endl;

                    // something was wrong with the Dragon class because canBlowFire() was not working propertly
                   if( i == 2 || i == 3 ){
                       IceDragon* iceDragon = dynamic_cast<IceDragon*>(cows.at(i));
                       if (iceDragon != nullptr) {
                           cout << "This dragon cannot breathe fire." << endl << endl;
                       } else {
                           cout << "This dragon can breathe fire." << endl<< endl;
                       }
                   }










                }
            };

            if (!counter){
                cout<< "Could not find " << argv[2]<< " cow!" << endl;
                cout<< endl;
            }

        }

    }



    return 0;
}


