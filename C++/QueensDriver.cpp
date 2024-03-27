//*******************************************************
// Source file queensdriver.cpp containing main driver
// author: Roth
//*******************************************************

#include <iostream>
#include "Queens.h"


int main() {
    std::cout << "Welcome to the " << BOARD_SIZE << " queens problem\n";

    EightQueens myQueens;   // create a puzzle

    myQueens.solve();       // solve it

    std::cout << "Press enter to exit." << std::endl;
    std::cin.get();
    return 0;
}
