//
// Created by jreyn on 2/23/2024.
// brandonjacobson0@gmail.com
//

#include "image.h"
#include <iostream>
#include "consoleGfx.h"

using namespace std;




int printMenu(){
    cout << "Scaler Menu"<< endl;
    cout << "-----------" << endl;
    cout << "0. Exit" << endl;
    cout << "1. Load File" << endl;
    cout << "2. Load Test Image" << endl;
    cout << "3. Display Image" << endl;
    cout << "4. Enlarge Image" << endl;
    cout << "5. Shrink Image" << endl;
    cout << "6. Show Image Properties" << endl;

    return 0;
}



int main(){


    ConsoleGfx* object = ConsoleGfx::getInstance();
    cout << "Welcome to the Image Scaler!"<< endl;
    (*object).displayImage( (*object).testRainbow);
    printMenu();

    int userChoice = 3;
    while (userChoice != 0){

        cout << "Select a Menu Option: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                string fileName = cin >> filename;
                cout << "Enter name of file to load: ";
                loadFile(filename)




        }
    }




}