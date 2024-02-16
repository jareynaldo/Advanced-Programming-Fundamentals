//
// Created by jose reynaldo and Karan Faldu
//

#include <iostream>
#include <ctime>
#include "StringData.h"

using namespace std;
int linearSearch(std::vector<std::string> container, std::string element);
int binarySearch(std::vector<std::string> container, std::string element);

int main()
{

    std::vector<std::string> cont = getStringData();
    string checks[3] = {"not_here", "mzzzz","aaaaa"};

    int counter = 3;
    for (int i = 0; i < counter; i++)
    {
        float start = time(NULL);
        cout << "Testing Linear Search for:" << checks[i] ;
        int index = linearSearch(cont, checks[i]);
        float end = time(NULL);
        if (index== -1)
        {
            cout << checks[i] << "not found";
        }
        else
        {
            cout << checks[i] << "found at" << index;
        }
        cout << "Linear Search Time:" << end;

        start = time(NULL);
        cout << "Testing Binary Search for:" << checks[i];
        index = binarySearch(cont, checks[i]);
        end = time(NULL);

        if (index == -1) {
            cout << checks[i] << "not found";
        } else {
            cout << checks[i] << "found at" << index;
        }
        cout << "Binary Search Time:" << end;
    }

    return 0;
}

int linearSearch(std::vector<std::string> container, std::string element) {
    for(int i = 0; i< container.size(); i++){
        if (container[i] == element){
            return i;
        }
    }
    return -1;
}

int binarySearch(std::vector<std::string> container, std::string element)
{
    int min = 0;
    int max = container.size() - 1;
    int mid = min + (max - min) / 2;
    while (min <= max)
    {
        mid = min + (max - min) / 2;
        if (element<container[mid])
        {
            max=mid-1;
        }
        else if (element > container[mid])
        {
            min=mid+1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}