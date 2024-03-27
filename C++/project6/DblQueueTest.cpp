// File name: DblQueueTest.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: Ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description: This file tests the implementation of DblQueue class.
// Honor statement: I have been abided by vanderbilt honor code in completion of this assignment.
// Last Changed: 4/7/2022

#include "DblQueue.h"
#include <iostream>

int main()
{

    // TODO -- Test your DblQueue class here
    DblQueue a;
    if (!(a.isEmpty())){
        std::cout<< "Queue is not empty without any data inside of it."<<std::endl;
    }
    if (a.size() != 0){
        std::cout<< " empty queue has a size."<<std::endl;
    }

    a.enqueue(.045);
    if (a.size() != 1){
        std::cout<< " Wrong size returned."<<std::endl;
    }

    if (a.size() != 1){
        std::cout<< " Wrong size returned."<<std::endl;
    }
    if (a.front() != .045){
        std::cout << "enq item wasn't upfront."<<std::endl;
    }
    a.dequeue();
    if (a.size() != 0){
        std::cout<< " empty queue has a size."<<std::endl;
    }
    a.enqueue(.045);
    a.enqueue(.045);
    a.enqueue(.023);
    DblQueue b;

    b = a;
    if (b.size() != 3){
        std::cout<< "some went wrong"<<std::endl;
    }

    if (b.front() != a.front()){
        std::cout<<"copy cons bad."<<std::endl;
    }
    b.dequeue();
    b.dequeue();

    if (b.front() != .023){
        std::cout<< "enq dosen't enque at the end of the q."<<std::endl;
    }
    b.dequeue();
    try {
        b.dequeue();
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }
    try {
        b.front();
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }

    if (a.size() == b.size()){
        std::cout<< "Copy cons did not create two copy."<<std::endl;
    }
    if (b.size() != 0){
        std::cout<< "wrong size"<<std::endl;
    }
    return 0;
}
