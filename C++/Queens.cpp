//*******************************************************
// Source file queens.cpp for class EightQueens
// author: Roth
//*******************************************************


#include <iostream>
#include "Queens.h"


// Default ctor. Creates any empty board.
EightQueens::EightQueens() {
    clearBoard();
}


// Solve the queens problem by calling recursive solver
void EightQueens::solve() {
    if (placeQueens(0)) {
        std::cout << "\nSolution found:" << std::endl;
        displayBoard();
    } else {
        std::cout << "\nNo solution found." << std::endl;
    }
    clearBoard();
}


//Sets all squares to empty
void EightQueens::clearBoard() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = EMPTY;   //Sets all squares to empty
        }
    }
}


//Displays board
void EightQueens::displayBoard() {
    std::cout << std::endl;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == QUEEN) {
                std::cout << "Q ";
            } else {
                std::cout << "_ ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Places queens in columns of the board beginning at 
// the column numbered Column.
//Precondition: Queens are placed correctly in cols
// 1 through column-1.
//Postcondtion: If a solution is found, each column of
// the board contains one queen and true is returned;
// otherwise, false is returned (no solution exists for a
// queen anywhere in the column).
bool EightQueens::placeQueens(int column) {
    if (column >= BOARD_SIZE) {
        return true;
    }
    for (int row = 0; row < BOARD_SIZE; row++) {
        if (!isUnderAttack(row, column)) {
            setQueen(row, column);
            if (placeQueens(column + 1)) {
                return true;
            }
            removeQueen(row, column);
        }
    }
    return false;
}


// Sets the square on the board in a given row and column
// to QUEEN
void EightQueens::setQueen(int row, int column) {
    board[row][column] = QUEEN;
}


// Sets the square on the board in a given row and column
// to EMPTY
void EightQueens::removeQueen(int row, int column) {
    board[row][column] = EMPTY;
}


// Determines whether the square on the board at a given
// row and column is under attack by any queens
// in cols 1 through column-1.
//Precondition: Each col between 1 and column-1 has a
//queen placed in a square at a specific row.   None of
//these queens can be attacked by any other queen.
//Postcondition: If the designated square is under
// attack, returns true; otherwise, returns false.
bool EightQueens::isUnderAttack(int row1, int column) {
    int row = row1, col = column;

    while (row >= 0 && col >= 0) { // Checks upper diagonal
        if (board[row][col] == QUEEN) {
            return true;
        }
        row--;
        col--;
    }

    row = row1;
    col = column;
    while (row < BOARD_SIZE && col >= 0) {  // Checks lower diagonal
        if (board[row][col] == QUEEN) {
            return true;
        }
        row++;
        col--;
    }

    row = row1;
    for (col = column - 1; col >= 0; col--) {  // Checks same row
        if (board[row][col] == QUEEN) {
            return true;
        }
    }

    return false; // If !isUnderAttack
}



