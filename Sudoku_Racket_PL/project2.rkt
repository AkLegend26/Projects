#lang racket

(provide test-checkpoint-code)
(provide solve-sudoku)

(require racket/lazy-require)
(lazy-require ["main.rkt" (print-board get-value set-value run-sudoku)])

; Name: Ayush Pathak
; VUnetID: pathaa3
; Email: ayush.pathak@vanderbilt.edu
; Course: CS 3270 - Vanderbilt University
; Date: 03/16/2023
; Honor Stetement: I have been abided by the honor code in completion of this assignment

; Description: This file implements the Sudoku solver


; Define some global constants.
(define BOARD-SIZE 9)       ; The size of the board.
(define ROWS 9)             ; The number of rows.
(define COLS 9)             ; The number of columns.
(define GRID-SIZE 3)        ; The size of a subgrid.


; Returns the result of checking if a value can be placed at
; a specific row and column on a board.
;
; It is your job to call your implemented "checker" functions
; from this function so it can be tested for the checkpoint
; requirements.
;
; DO NOT change the name/signature of this function, as our
; testing script depends upon it.
;
; @param  board The board to check.
; @param  row   The row where the value will be placed.
; @param  col   The column where the value will be placed.
; @param  num   The number to be placed.
; @return Whether value can be placed at row and col in board.
(define (test-checkpoint-code board row col num)
  (and (row-checker board row num)
       (col-checker board col num)
       (grid-checker board row col num)))


; returns if a value is exists in a row
;
; @param  board the board
; @param  row   row in the board
; @param  val   the value needed to be checked
; @return true if the value is not in the row and else false
(define (row-checker board row num)
  (not (member num (list-ref board row))))


; returns if a value exists in a column
;
; @param  board the board
; @param  col   column in the board
; @param  num   the value needed to be checked
; @return true if the value is not in the column and else false
(define (col-checker board col num)
  (cond ((null? board) #t)
        ((= num (list-ref (car board) col)) #f)
        (else (col-checker (cdr board) col num))))



; returns if a value dosen't exists in a subgrid
;
; @param  board the board
; @param  row   row in the board
; @param  col   column in the board
; @param  num   the value needed to be checked
; @return true if the value is not in the column and else false
(define (grid-checker board row col num)
  (define (grid-checker-helper board row col start-row start-col end-row end-col)
    (cond ((= row end-row) #t)
          ((< col end-col)
           (let ((grid-value (list-ref (list-ref board row) col)))
             (if (= grid-value num)
                 #f
                 (grid-checker-helper board row (+ col 1) start-row start-col end-row end-col))))
          (else
           (grid-checker-helper board (+ row 1) start-col start-row start-col end-row end-col))))
  (letrec ((grid-row (quotient row GRID-SIZE))
         (grid-col (quotient col GRID-SIZE))
         (start-row (* grid-row GRID-SIZE))
         (start-col (* grid-col GRID-SIZE))
         (end-row (+ start-row GRID-SIZE))
         (end-col (+ start-col GRID-SIZE)))
    (grid-checker-helper board start-row start-col start-row start-col end-row end-col)))


; This function should call your recursive backtracking solver
; and, depending upon the result, either return the solved puzzle
; or return null if the puzzle has no solution.
;
; It is your job to write this and necessary helper functions.
;
; DO NOT change the name/signature of this function, as our
;
(define (solve-sudoku board)
  (define( solve-helper board row col num);helper with row, col need to be filled with the num
  (cond [(equal? row ROWS) board]
    [(equal? col COLS) (solve-helper board (+ 1 row ) 0 1)]
    [(zero? (get-value board row col)) 
     (cond  [(> num 9) '()]
       [(test-checkpoint-code board row col num) 
        (letrec ([updated-board (set-value board row col num)]
                 [solution (solve-helper updated-board row (+ 1 col) 1)])
          (if (null? solution) 
              (solve-helper board row col (+ 1 num))
              solution))]
       [else (solve-helper board row col (+ 1 num))])]
     [else (solve-helper board row (add1 col) 1)]))
    (solve-helper board 0 0 1));called with 0 row, 0 col, and 1 num

