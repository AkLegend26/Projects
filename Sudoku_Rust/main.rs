//Name: Ayush Pathak
//Email: ayush.pathak@vanderbilt.edu
//Class: PL
//Honor code: I have been abided by honor code in completion of this assignment.
//Project 4 sudoku implementation file

use std::fs::File;
use std::io::{BufRead, BufReader};
use std::fmt;
use std::io;

#[cfg(test)]
mod test;

#[derive(Debug)]

/**
A struct representing a Sudoku board.
*/
struct Sudoku {
    board: [[u8; 9]; 9],
}

impl Sudoku {
/**
 * Loads a Sudoku board from a file.
 * 
 * @param filename The name of the file to load the board from.
 * @return Result<Sudoku, std::io::Error> A Result containing either the loaded Sudoku board
 * or an error if the file could not be opened or contained invalid data.
 */
fn load_from_file(filename: &str) -> std::io::Result<Self> {
    let file = File::open(filename)?;
    let reader = BufReader::new(file);
    let mut board = [[0; 9]; 9];
    for (i, line) in reader.lines().enumerate() {
        let line = line?;
        let mut j = 0;
        for c in line.chars() {
            if let Some(digit) = c.to_digit(10) {
                board[i][j] = digit as u8;
                j += 1;
            } else if !c.is_whitespace() && j < 9 {
                // Ignore non-numeric and non-whitespace characters
                continue;
            }
            if j >= 9 {
                // Exit the loop if we have read 9 digits in the current line
                break;
            }
        }
        if j != 9 {
            return Err(std::io::Error::new(
                std::io::ErrorKind::InvalidData,
                format!("expected 9 digits"),
            ));
        }
    }
    Ok(Sudoku { board })
}
    
/**
 * Checks whether a given number can be placed in a given row and column of the Sudoku board.
 * 
 * @param num The number to check.
 * @param row The row to check.
 * @param col The column to check.
 * @return bool true if the number can be placed in the given row and column, false otherwise.
 */
    fn is_valid(&self, num: u8, row: usize, col: usize) -> bool {
        // check row and column
        for i in 0..9 {
            if self.board[row][i] == num || self.board[i][col] == num {
                return false;
            }
        }

        // check 3x3 box
        let box_row = row - (row % 3);
        let box_col = col - (col % 3);
        for i in 0..3 {
            for j in 0..3 {
                if self.board[box_row + i][box_col + j] == num {
                    return false;
                }
            }
        }
        true
    }

/**
 * Attempts to solve the Sudoku board.
 * 
 * @return bool true if the board was solved, false if no solution could be found.
 */
    fn solve(&mut self) -> bool {
        let mut row = 0;
        let mut col = 0;

        // check if there are any unassigned cells
        if self.is_assigned(&mut row, &mut col) {
            return true;
        }

        // try to assign a number to the current cell
        for num in 1..=9 {
            if self.is_valid(num, row, col) {
                self.board[row][col] = num;

                if self.solve() {
                    return true;
                }

                // backtrack if solution cannot be found
                self.board[row][col] = 0;
            }
        }

        false
    }

/**
 * Checks if there are any unassigned cells in the Sudoku board.
 * 
 * @param row A mutable reference to a usize that will be set to the row of the first 
   unassigned cell found.
 * @param col A mutable reference to a usize that will be set to the column of the first
   unassigned cell found.
 * @return bool true if there are no unassigned cells, false otherwise.
 */
    fn is_assigned(&self, row: &mut usize, col: &mut usize) -> bool {
        for i in 0..9 {
            for j in 0..9 {
                if self.board[i][j] == 0 {
                    *row = i;
                    *col = j;
                    return false;
                }
            }
        }
        true
    }
}

/**
* Formats the Sudoku board as a string for display.
*
* @param f A mutable reference to a formatter to which the formatted string should be written.
* @return Result<(), fmt::Error> Ok(()) if the formatting was successful, or an error if it 
failed.
*/
impl fmt::Display for Sudoku {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        for (i, row) in self.board.iter().enumerate() {
            if i % 3 == 0 && i != 0 {
                writeln!(f, "------+-------+------")?;
            }
            for (j, &cell) in row.iter().enumerate() {
                if j % 3 == 0 && j != 0 {
                    write!(f, "| ")?;
                }
                write!(f, "{} ", cell)?;
            }
            writeln!(f)?;
        }
        Ok(())
    }
}

/**
 * Compares two Sudoku objects for equality by iterating over their 9x9 grids.
 *
 * @param other The other Sudoku object to compare with.
 * @return True if the two Sudoku objects are equal, false otherwise.
 */
impl PartialEq for Sudoku {
    fn eq(&self, other: &Self) -> bool {
        for i in 0..9 {
            for j in 0..9 {
                if self.board[i][j] != other.board[i][j] {
                    return false;
                }
            }
        }
        true
    }
}

fn main() {

    println!("Please enter the filepath of the puzzle:");

    let mut input = String::new();
    io::stdin().read_line(&mut input).expect("Failed to read line");
    let filename = input.trim();

    let mut sudoku = Sudoku::load_from_file(filename).unwrap();

    if sudoku.solve() {
        println!("Sudoku Solved");
        println!("{}", sudoku);
    } else {
        println!("Unable to solve sudoku.");
    }
}