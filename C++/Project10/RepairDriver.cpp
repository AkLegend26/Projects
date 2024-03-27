// File name: RepairDriver.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file runs the repair class to repair the un-formatted strings.
// Last Changed: 4/29/2022

#include <iostream>
#include "Repair.h"


// get_input()
// This function gets the input from the user and returns the string
// post: returns a string that is a valid parameter for repair class
std::string get_input();


// case_check(std::string str)
// This function checks the case of the input string parameter
// post: returns bool true if input parameter is all lower
bool case_Check(std::string str);

int main(){
    std::cout << "Welcome to the sentence Reconstructor." << std::endl;

    std::string response;

    do {
        std::string str = get_input();
        Repair Reconstructor; // constructs a repair class
        Reconstructor.solve(str); // calls the solve method with the string to be repaired.


        std::cout << "\n" << "Do you want to do it again? (Y|N) ";
        std::cin >> response;
    }while(response.at(0) == 'Y' || response.at(0) == 'y');
    return 0;
}

// get_input()
// This function gets the input from the user and returns the string
// post: returns a string that is a valid parameter for repair class
std::string get_input(){
    std::string str;
    do {
        std::cout << "\n" << "Enter the letters of the sentence: ";
        std::cin >> str;
    }while (!(case_Check(str)));
    return str;
}


// case_check(std::string str)
// This function checks the case of the input string parameter
// post: returns bool true if input parameter is all lower
bool case_Check(std::string str){
    for (size_t i = 0; i < str.length(); i++){
        if (std::isupper(str[i])){
            std::cout<<"You must enter only lower case alphabetic characters."<<std::endl;
            return false;
        }
    }
    return true;
}