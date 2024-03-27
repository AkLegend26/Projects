// File name: GuitarStringTest.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description: This program tests the GuitarString class.
// Honor statement: I have been abided by Vanderbilt honor code in completion of this assignment.
// Last Changed: 4/7/2022

#include "GuitarString.h"
#include <iostream>

int main()
{

    // TODO -- Test your GuitarString class here
    GuitarString a(.0567);

    if (a.getTime() != 0){
        std::cout<<" tik count not initialized."<<std::endl;
    }


    if (a.getFrequency() != .0567){
        std::cout<< "do sum bout get freq."<<std::endl;
    }
    a.pluck();

    if (-0.5<=a.sample() && a.sample() <= 0.5){
        std::cout<<"pluck passed"<<std::endl;
    }
    double c = a.sample();
    a.tic();
    if (a.getTime() != 1){
        std::cout<<"time didn't work"<<std::endl;
    }
    if (a.sample() == c){
        std::cout<<"tic didn't enque"<<std::endl;
    }
    a.tic();
    if (a.getTime() != 2){
        std::cout<<"time didn't work"<<std::endl;
    }
    if (a.getFrequency() != .0567 ){
        std::cout<<"freq changed"<<std::endl;
    }

    a.tic();
    try {
        GuitarString b(-.09875);
    }
    catch (std::invalid_argument &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }


    return 0;
}
