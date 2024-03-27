// File name: GuitarString.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description: This file defines the Guitar String class.
// Honor statement: I have been abided by Vanderbilt honor code in completion of this assignment.
// Last Changed: 4/7/2022

#ifndef GUITARSTRING_H
#define GUITARSTRING_H

#include "DblQueue.h"
#include<chrono>
#include <random>

typedef double ItemType;
const size_t SAMPLE_RATE = 44100;
const double DECAY_FACTOR = 0.996;

class GuitarString {
private :
    size_t tic_count;
    double freq;
    DblQueue string;


public:
    // The constructor for a string of the given frequency.
    // pre: frequency is positive.
    // post: object is initialized to represent a string at rest.
    // Throws a std::invalid_argument exception if the frequency is not positive.
    GuitarString(double frequency);

    // Pluck the string.
    // post: replaced all elements in the ring buffer with the same number of
    // random values between -0.5 and +0.5
    void pluck();

    // Tic the clock by advancing the simulation one step.
    // post: the Karplus-Strong update has been applied to the string.
    void tic();

    // Return the current sound sample of the string.
    double sample() const;

    // Return the number of time steps executed == number of calls to tic().
    size_t getTime() const;

    // Return the frequency of the string.
    double getFrequency() const;

};

#endif
