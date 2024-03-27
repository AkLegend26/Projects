// Name: Ayush Pathak
// Email: ayush.pathak@vanderbilt.edu
// VUnetid: pathaa3
// Class: CS 2201
// Date: 03/29/2022
// Honor statement: I have been abided by the Vanderbilt honor code in completion of this
// assignment.
// Description:
// Reverse a sound data file by reading in all the data samples,
// pushing them onto stacks, and then creating a new sound data
// file while popping values off the stacks.

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "DblStack.h"


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile);


int main() {

    // open input & output data files
    std::ifstream infile;
    std::ofstream outfile;
    openFiles(infile, outfile);

    std::cout << "Reading the input file..." << std::endl;

    // read in the data on the first line of the file
    std::string firstLine, secondLine;

    getline(infile, firstLine);    // read in the first line
    getline(infile, secondLine);   // read in the second line


    double val;

    DblStack value;
    DblStack time_rev;
    DblStack time;
    size_t i = 1;

    while (infile >> val && i != 0){
        i++;
        if ((i%2) != 0) {
            value.push(val);
        }
        else
            time_rev.push(val);
    }

    while (!(time_rev.isEmpty())){
        time.push(time_rev.top());
        time_rev.pop();
    }


    std::cout << "There were " << value.size() <<" samples in the file." << std::endl;
    std::cout << "Creating output file... wait for Done message." << std::endl;


    //
    // Now we are ready to output the data values to output file.
    // But first, we need to output the header lines
    //
    outfile.setf(std::ios::fixed, std::ios::floatfield);
    outfile.precision(10);
    outfile << firstLine << std::endl;
    outfile << secondLine << std::endl;

    while (!(time.isEmpty())){
        outfile << "  " << time.top() << "\t" << value.top()<< std::endl;
        time.pop();
        value.pop();
    }

    // Your job is to write the rest of the output file.
    // Each line should start with two blanks, then the time-step
    // value, then a single tab character \t, then the sound data value.
    // close the files
    infile.close();
    outfile.close();

    std::cout << "Done." << std::endl;
}


// open input and output files
// pre: user is prepared to enter file names at the keyboard
// post: files have been opened
void openFiles(std::ifstream &infile, std::ofstream &outfile) {

    // open input data file
    std::string inFileName;
    std::cout << "Enter the name of the input file: ";
    std::cin >> inFileName;
    infile.open(inFileName.c_str());
    if (infile.fail()) {
        std::cout << "Error opening input data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }

    // open output data file
    std::string outFileName;
    std::cout << "Enter the name of the output file: ";
    std::cin >> outFileName;
    outfile.open(outFileName.c_str());
    if (outfile.fail()) {
        std::cout << "Error opening output data file" << std::endl;
        std::cout << "press enter to exit";
        std::cin.get();
        std::cin.get();
        exit(1);
    }
}
