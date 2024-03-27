// File name: RepairDriver.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file implements the Repair class to fix a input string.
// Last Changed: 4/29/2022

#include "Repair.h"
#include "iostream"


// Class Constructor
// post:Repair class is created and initialized with a dictionary
Repair::Repair(){
    load_dictionary();
}

// load_dictionary
// loads the dictionary into the Trie data structures
void Repair::load_dictionary() {
    Dictionary.loadFromFile("dictionary.txt");
}

// print_vector
// prints the elements of the vector
void Repair::print_vector() {
    for (size_t i = 0; i < words.size();i++){
        std::cout << words[i] << " ";
    }
    std::cout<<"\n";
}

// solve
// parameter: unrepaired string that needs to be repaired
// Constructs the repaired strings from the parameter
void Repair::solve(std::string str) {
    if (str.length() == 1){
        return;
    }
    if (str.length()==0){
        print_vector();
    }
    for (size_t i = 1; i <= str.length(); i++){
        if (Dictionary.isWord(str.substr(0,i))){
            words.push_back(str.substr(0,i));
            if (Dictionary.isPrefix(str.substr(i,2))){
                solve(str.substr(i,str.length()-1));
            }
            words.pop_back();
        }
    }
}