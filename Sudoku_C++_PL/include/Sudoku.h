// Ayush Pathak
// CS 3270 Programming Languages
// I have been abided by honor code in completion of this assignment
// 02/01/2023
// Soduku.h: Defines the Sodoku class to solve a sudoku problem
#ifndef SUDOKU_H
#define SUDOKU_H

#include "string"

class Sudoku {

public:
    /**
     * Initializes the Sudoku class that will be used to solve the puzzle
     */
    Sudoku();

    /**
     * Loads a Sudoku puzzle from a file provided
     * @param filename : name of the file that contains the puzzle
     */
    void loadFromFile(const std::string& filename);

    /**
     * Method that has the algorithm to solve the Sudoku puzzle
     * @return : Boolean value representing if the puzzle is solvable or not
     */
    bool solve();

    /**
     * equals check the equality of Sudoku board provided with this one
     * @param other : other sudoku board to check for equality
     * @return : Boolean value if the board are equal
     */
    bool equals(const Sudoku& other) const;

    /**
     * Friend so it can access the private members of Sudoku
     * cout operator overload to print the Sudoku to the screen
     * @param out : the ostream operator that prints to screen
     * @param sudoku : the board that will be printed
     * @return : Prints the sudoku board to the screen
     */
    friend std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku);

private:
    // The matrix that contains the puzzle
    int sud[9][9];

    /**
     * Private method that checks if the number is available to place according to Sudoku rules
     * @param num : number that will be placed in the board
     * @param row : The row being worked on, on the board
     * @param col : The column being worked on, on the board
     * @return : Boolean value representing if the value can be placed
     */
    bool isValid(int num, int row, int col) const;

    /**
     * checks if all the boxes have been assigned
     * @param row : Row that is being worked on
     * @param col : Column that is being worked on
     * @return : Boolean value that represents if the value can be assigned
     */
    bool isAssigned(int& row, int& col) const;
};

std::ostream& operator<<(std::ostream& out, const Sudoku& sudoku); // declaration for overloading
#endif // SUDOKU_H