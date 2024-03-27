// File name: GuitarString.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description: This file implements the Guitar string class.
// Honor statement: I have been abided by Vanderbilt honor code in completion of this assignment.
// Last Changed:

#include "GuitarString.h"
#include <cmath>
#include <fstream>


GuitarString::GuitarString(double frequency) :tic_count(0),
                                                freq(frequency){
    if (frequency < 0){
        throw std::invalid_argument("Frequency is not positive");
    }

    size_t N = round(SAMPLE_RATE/frequency);
    while (string.size() < N){
        string.enqueue(0);
    }
}

void GuitarString::pluck() {
    unsigned seed = (unsigned) std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_real_distribution<double> distribution(-0.5, 0.5);

    for (size_t i = 0; i < round(SAMPLE_RATE/freq); i++){
        string.dequeue();
        double num = distribution(generator);
        string.enqueue(num);
    }
}

void GuitarString::tic() {
    double last = string.front();
    string.dequeue();
    double last_second = string.front();
    string.enqueue(DECAY_FACTOR*(.5)*((last + last_second)));
    tic_count++;
}

double GuitarString::sample() const {
    return string.front();
}

size_t GuitarString::getTime() const{
    return tic_count;
}

double GuitarString::getFrequency() const{
    return freq;
}