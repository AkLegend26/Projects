// Name: Ayush Pathak
// Email: ayush.pathak@vanderbilt.edu
// VUnetid: pathaa3
// Class: CS 2201
// Date: 03/29/2022
// Honor statement: "I have been abided by the Vanderbilt honor code in completion of this
// assignment."
// Description:
// This program tests the DblStack class.

#include <iostream>
#include <string>
#include <cstdlib>
#include "DblStack.h"

int main()
{
    DblStack wav;
    DblStack check;


    try {
        wav.top();
        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn underflow exception was not thrown!!" << std::endl;
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }

    try {
        wav.pop();
        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn underflow exception was not thrown!!" << std::endl;
    }
    catch (std::underflow_error &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }

    if (wav.size() != 0){
        std::cout << "Stack_s-ze is not initialized right."<<std::endl;
    }

    if (!(wav.isEmpty())){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    wav.push(3.49277);
    double aa = 2.34645;

    if (wav.top() != 3.49277){
        std::cout << "The first value was not added to the stack."<<std::endl;
    }
    if (wav.size() != 1){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    wav.push(aa);

    if ((wav.isEmpty())){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }
    if (wav.top() != aa){
        std::cout << "The top value is not the value recently added."<<std::endl;
    }
    wav.pop();
    if (wav.size() != 1){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }
    wav.pop();
    if (wav.size() != 0){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    wav.push(3.436);
    wav.push(324.4354);
    wav.push(12.23124);
    wav.push(aa);

    if (check.size() != 0){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    check = wav;
    if (check.top() != aa){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    if (wav.top() != aa){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    if (check.size() != 4){
        std::cout << "Stack_s-ze is not right."<<std::endl;
    }

    size_t i = 0;
    while (i < 1000){
        wav.push(aa);
        i++;
    }
    check = wav;
    while (i != 0){
        wav.pop();
        i--;
    }

    if (check.top() != wav.top()){
        std::cout << "copy operator not workin";
    }
    return 0;
}