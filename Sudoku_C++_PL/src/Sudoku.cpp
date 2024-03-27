// Ayush Pathak
// CS 3270 Programming Languages
// I have been abided by honor code in completion of this assignment
// 02/01/2023
// Soduku.cpp: Defines the Sodoku class to solve a sudoku problem

#include "Sudoku.h"
#include "fstream"
#include <iostream>

Sudoku::Sudoku()
    : sud()
{
}

void Sudoku::loadFromFile(const std::string& filename)
{
    std::string str;
    std::ifstream infile;

    if (!infile) {
        std::cout << "Unable to open file. Press enter to exit program.";
        getline(std::cin, str); // consume existing line
        std::cin.get(); // get the key press
        exit(1);
    }

    infile.open(filename);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            infile >> sud[i][j];
        }
    }
}
bool Sudoku::isValid(int num, int row, int col) const
{
    for (int i = 0; i < 9; i++) {
        if (sud[row][i] == num || sud[i][col] == num) {
            return false;
        }
    }
    // generating a small 3x3 grid to ensure no same number has been used in this small grid

    int small_x = row - row % 3;
    int small_y = col - col % 3;

    for (int i = 0; i < 3; i++) { // checks the smaller 3x3 to ensure no number is reused
        for (int j = 0; j < 3; j++) {
            if (sud[i + small_x][j + small_y] == num) {
                return false;
            }
        }
    }
    return true;
}
bool Sudoku::solve()
{
    int row, col;
    if (isAssigned(row, col)) {
        return true;
    }

    for (int num = 1; num <= 9; num++) {
        if (isValid(num, row, col)) {
            sud[row][col] = num;
            if (solve()) { // recursively solves the sudoku problem
                return true;
            }
            sud[row][col] = 0;
        }
    }
    return false;
}

bool Sudoku::isAssigned(int& row, int& col) const
{
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (sud[row][col] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool Sudoku::equals(const Sudoku& other) const
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sud[i][j] != other.sud[i][j]) {
                return false;
            }
        }
    }
    return true;
}
std::ostream& operator<<(std::ostream& print, const Sudoku& sudoku)
{
    for (int i = 0; i < 9; i++) {
        if (i == 3 || i == 6) {
            print << "------+-------+------" << std::endl;
        }
        for (int j = 0; j < 9; j++) {
            if (sudoku.sud[i][j] != 0) {
                print << sudoku.sud[i][j] << " ";
            } else
                print << "  ";

            if (j == 2 || j == 5) {
                print << "| ";
            }
        }
        print << std::endl;
    }
    return print;
}
