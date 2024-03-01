//Brandon and Jose

#include <iostream>
#include <string>
#include <cmath>
#include "ConsoleGfx.h"
#include "Image.h"

using namespace std;

int selection;

//Function to print menu and returns selection
int printMenu(){
    cout << "\nScaler Menu\n" << "-----------\n" << "0. Exit\n1. Load File\n2. Load Test Image\n3. Display Image\n4. Enlarge Image\n5. Shrink Image\n6. Show Image Properties" << endl;
    cout << "\nSelect a Menu Option: ";
    cin >> selection;
    return selection;
}

//Image Scaling Function (Only capable of scaling up)
unsigned char *scaledImage(unsigned char *imageData, int orders){ //Works to enlarge by 2 but not by 1
    auto *im1 = new Image(imageData); //Create image object with imageData
    int image_width = im1->getWidth(); //Get Height and Width of image
    int image_height = im1->getHeight();
    int data_length = image_width * image_height;
    orders = int(pow(2, orders)); //Initialize orders to be a power of 2
    if (((image_width * orders) > 256) || ((image_height * orders) > 256)){ //Limit max size of any dimension to 256
        int max_order = 0;
        int max_dimension = max(image_width, image_height);
        for (int i = 0; i <= 4; i++){
            if ((pow(2, max_order) * max_dimension) <= 256){
                max_order = i;
            }
        }
        orders = int(pow(2, max_order));
    }
    int scaled_length = data_length * orders * orders + 2;
    auto *scaled_image= new unsigned char[scaled_length]; //Initialize scaled image
    int index_counter = 2;
    scaled_image[0] = image_width * orders;
    scaled_image[1] = image_height * orders;
    for (int i = image_width + 2; i <= data_length + 2; i += image_width){
        for (int k = 0; k < orders; k++){
            for (int j = i - image_width; j < i; j++){
                for (int ii = 0; ii < orders; ii++){
                    scaled_image[index_counter] = imageData[j];
                    index_counter++;
                }
            }
        }
    }
    delete[] imageData; //Deallocate memory to avoid leaks
    return scaled_image;
}

int main(){
    ConsoleGfx* console = ConsoleGfx::getInstance();
    cout << "Welcome to the Image Scaler!" << endl;
    cout << "\nDisplaying Spectrum Image:" << endl;
    console->displayImage(console->testRainbow);
    printMenu();
    string file;
    unsigned char* current_file = nullptr;
    int scale_value;
    while (selection != 0){
        switch(selection){
            case 0:
                cout << "Exiting Program. Thank You!";
                break;
            case 1:
                cout << "Enter name of file to load: ";
                cin >> file;
                current_file = console->loadFile(file);
                if (current_file == nullptr){
                    cout << "Error: could not load file.\n";
                    selection = printMenu();
                    break;
                }else{
                    cout << "File loaded.\n";
                    selection = printMenu();
                    break;
                }
            case 2:
                current_file = console->testImage;
                cout << "Test image data loaded." << endl;
                selection = printMenu();
                break;
            case 3:
                if (current_file == nullptr){
                    cout << "Error: no image loaded.\n";
                }
                console->displayImage(current_file);
                cout << "" << endl;
                selection = printMenu();
                break;
            case 4:
                cout << "Enter orders of magnitude for enlargement: ";
                cin >> scale_value;
                current_file = scaledImage(current_file, scale_value);
                cout << "Image enlarged";
                selection = printMenu();
                break;
            default:
                cout << "Error: Not an option";
                selection = printMenu();
                break;
        }
    }
    return 0;
}

