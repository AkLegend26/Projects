//Name: Ayush Pathak
//Email: ayush.pathak@vanderbilt.edu
//Class: PL
//Honor code: I have been abided by honor code in completion of this assignment.
//Project 4 sudoku tests file

#[cfg(test)]
mod tests {
    use crate::Sudoku;

    #[test]
    /**
     * Test Sudoku solving algorithm by loading puzzle & solution from file, solving, 
     * and comparing results.
     * 
     * @return prints if the puzzle is solved or not
     */
    fn test1(){
        let filename = "txt/sudoku-test1.txt";
        let mut sudoku = Sudoku::load_from_file(filename).unwrap();

        let filename_solution = "txt/sudoku-test1-solution.txt";
        let solution = Sudoku::load_from_file(filename_solution).unwrap();
        if sudoku.solve(){
            
            if sudoku == solution {
                println!("Solved sudoku");
            }
            else{
                println!("Solved but wrong solution!!!!");
            }
        } else {
            println!("Unable to solve sudoku.");
        }
        assert!(sudoku.solve());
        assert_eq!(sudoku, solution);
    }

    #[test]
    /**
     * Similar to test1(), but uses a different puzzle & solution file.
     * 
     * @return prints if the puzzle is solved or not
     */
    fn test2(){
        let filename = "txt/sudoku-test2.txt";
        let mut sudoku = Sudoku::load_from_file(filename).unwrap();

        let filename_solution = "txt/sudoku-test2-solution.txt";
        let solution = Sudoku::load_from_file(filename_solution).unwrap();
        if sudoku.solve(){
            
            if sudoku == solution {
                println!("Solved sudoku");
            }
            else{
                println!("Solved but wrong solution!!!!");
            }
        } else {
            println!("Unable to solve sudoku.");
        }
        assert!(sudoku.solve());
        assert_eq!(sudoku, solution);
    }

    #[test]
    /**
     * Test behavior of solve() method on an impossible puzzle.
     * 
     * @return prints if the puzzle is solved or not
     */
    fn test3(){
        let filename = "txt/sudoku-impossible.txt";
        let mut sudoku = Sudoku::load_from_file(filename).unwrap();

        if sudoku.solve(){
            println!("It shouldn't be solvable...");
        } else {
            println!("Unable to solve sudoku.");
        }
        assert!(!sudoku.solve());
    }
}