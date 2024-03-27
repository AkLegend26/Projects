// File name: RepairDriver.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file declares the Repair class
// Last Changed: 4/29/2022

#ifndef PROJECT10_REPAIR_H
#define PROJECT10_REPAIR_H
#include "Trie.h"
#include "vector"

class Repair{

private:
    // vector that holds completed words from the unrepaired string to be printed
    std::vector<std::string> words;

    // Dictionary that consists of all the possible words
    Trie Dictionary;

    // load_dictionary
    // loads the dictionary into the Trie data structures
    void load_dictionary();

    // print_vector
    // prints the elements of the vector
    void print_vector();

public:
    // Class Constructor
    // post:Repair class is created and initialized with a dictionary
    Repair();

    // solve
    // parameter: unrepaired string that needs to be repaired
    // Constructs the repaired strings from the parameter
    void solve(std::string str);

};

#endif //PROJECT10_REPAIR_H
