//
// Created by  Jose Reynaldo and Jaxon Kundrat j.kundrat@ufl.edu
//
#include <string>
#include <iostream>
#include "HeiferGenerator.h"





using namespace std;

void printMessage(int startIndex, vector <string> args){

    string message;
    if (startIndex >= (int)args.size()){
        // if message is left blank
        return;
    }
    for (int i = startIndex; i < (int)args.size(); i++){
        message += args.at(i) + " ";

    }
    message = message.erase(message.length()- 1);
    cout << "\n" << message << endl;
    return;

}
void printCow(int index, vector<Cow*> cows){
    Cow cow = *cows.at(index);
    cout << cow.getImage() << endl;
    if(index == 2 && cows.at(index) -> getImage() == "dragon"){
        cout << "This dragon can breathe fire." << "\n" << endl;
    }
    if(index == 3 && cows.at(index)->getName() == "ice-dragon"){
        cout << "This dragon cannot breathe fire." << "\n" << endl;
    }

    return;
}






int main(int argc, char* argv[]){



    vector<string> args (argv, argv + argc);

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
        if (argv[1] == "-f"){
            if(args.at(2) == "moose"){
                printMessage(3, args);
                printCow(0, fileCows);
            }else  if(args.at(2) == "turkey"){
                printMessage(3, args);
                printCow(1, fileCows);
            }
            else if(args.at(2) == "turtle"){
                printMessage(3, args);
                printCow(1, fileCows);
            }
            else if(args.at(2) == "tux") {
                printMessage(3, args);
                printCow(3, fileCows);
            }else{


                // error message
                cout << "Could not find " << args.at(2) << " cow!"<< "\n" << endl;
            }

        }

    }



    return 0;
}


