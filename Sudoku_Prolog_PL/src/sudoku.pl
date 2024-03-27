% Name: Ayush Pathak
% VUnetID: pathaa3
% Email: ayush.pathak@vanderbilt.edu 
% Class: CS 3270
% Date: 04/10/2023
% Honor Statement: I have been abided by the honor code in completion of this assignment

% Complete description:  This file has rules and predicate that open up a soduoku problem and
% solve the maze if possible based on the guidelines provided.


% Use routines from the Constraint Logic Programming over Finite Domains library.
:- use_module(library('clpfd')).


% The main entry point. Enter "go." at the Prolog prompt.
% 
go :-
    File = 'txt/sudoku-test1.txt',
    start(File).


% The absolute path of the root folder of the project.
% NOTE: MUST BE CHANGED TO THE ABSOLUTE PATH OF ROOT FOLDER OF YOUR PROJECT ON YOUR LOCAL COMPUTER.
%       MAC USERS: USE FORWARD SLASH '/'
%
project_root(Dir) :-
    Dir = '/Users/legend/Documents/PL/project3-AkLegend26'.



% To test other than 'sudoku-test1.txt', pass the text file name preceded by 'txt/'.
% For example, enter "start('txt/sudoku-test2.txt')."
%
start(File) :-
    project_root(Dir),                       % Get absolute path to root folder of project.
    atom_concat(Dir, File, PuzzleFile),      % Concatenate path with text file relative location.
    see(PuzzleFile),                         % Open file.
    write(trying_file(PuzzleFile)), nl, nl,  % Display puzzle.
    read(Board),                             % Read board.
    seen,                                    % Close file.
    time(sudoku(Board)),                     % Call solver (with timer).
    pretty_sudo_print(Board), nl.            % Printed solution.


% Print the board to the screen, where each row printed using printsudorow.
%
pretty_sudo_print(Board) :-
    Board = [R1, R2, R3, R4, R5, R6, R7, R8, R9],
    nl, nl,
    printsudorow(R1),
    printsudorow(R2),
    printsudorow(R3),
    write('-------+-------+-------'), nl,
    printsudorow(R4),
    printsudorow(R5),
    printsudorow(R6),
    write('-------+-------+-------'), nl,
    printsudorow(R7),
    printsudorow(R8),
    printsudorow(R9).


% Print row by printing each column.
%
printsudorow(Row) :-
    Row = [C1,C2,C3,C4,C5,C6,C7,C8,C9],
    write(' '),
    write(C1), write(' '),
    write(C2), write(' '),
    write(C3), write(' '), write('|'), write(' '),
    write(C4), write(' '),
    write(C5), write(' '),
    write(C6), write(' '), write('|'), write(' '),
    write(C7), write(' '),
    write(C8), write(' '),
    write(C9), write(' '), nl.


% Main solver containing the rules to solve Sudoku.
%
sudoku(Board) :-
    % Variables representing the Sudoku board
    Board = [
        [A_1, A_2, A_3, A_4, A_5, A_6, A_7, A_8, A_9],
        [B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9],
        [C_1, C_2, C_3, C_4, C_5, C_6, C_7, C_8, C_9],
        [D_1, D_2, D_3, D_4, D_5, D_6, D_7, D_8, D_9],
        [E_1, E_2, E_3, E_4, E_5, E_6, E_7, E_8, E_9],
        [F_1, F_2, F_3, F_4, F_5, F_6, F_7, F_8, F_9],
        [G_1, G_2, G_3, G_4, G_5, G_6, G_7, G_8, G_9],
        [H_1, H_2, H_3, H_4, H_5, H_6, H_7, H_8, H_9],
        [I_1, I_2, I_3, I_4, I_5, I_6, I_7, I_8, I_9]
    ],
    Board = [Row_1, Row_2, Row_3, Row_4, Row_5, Row_6, Row_7, Row_8, Row_9],
    % Variables representing rows of the board
    Row_1 = [A_1, A_2, A_3, A_4, A_5, A_6, A_7, A_8, A_9],
    Row_2 = [B_1, B_2, B_3, B_4, B_5, B_6, B_7, B_8, B_9],
    Row_3 = [C_1, C_2, C_3, C_4, C_5, C_6, C_7, C_8, C_9],
    Row_4 = [D_1, D_2, D_3, D_4, D_5, D_6, D_7, D_8, D_9],
    Row_5 = [E_1, E_2, E_3, E_4, E_5, E_6, E_7, E_8, E_9],
    Row_6 = [F_1, F_2, F_3, F_4, F_5, F_6, F_7, F_8, F_9],
    Row_7 = [G_1, G_2, G_3, G_4, G_5, G_6, G_7, G_8, G_9],
    Row_8 = [H_1, H_2, H_3, H_4, H_5, H_6, H_7, H_8, H_9],
    Row_9 = [I_1, I_2, I_3, I_4, I_5, I_6, I_7, I_8, I_9],

    % Enforcing all different values in each row
    all_different(Row_1),
    all_different(Row_2),
    all_different(Row_3),
    all_different(Row_4),
    all_different(Row_5),
    all_different(Row_6),
    all_different(Row_7),
    all_different(Row_8),
    all_different(Row_9),

    % Variables representing column of the board
    Col_1 = [A_1, B_1, C_1, D_1, E_1, F_1, G_1, H_1, I_1],
    Col_2 = [A_2, B_2, C_2, D_2, E_2, F_2, G_2, H_2, I_2],
    Col_3 = [A_3, B_3, C_3, D_3, E_3, F_3, G_3, H_3, I_3],
    Col_4 = [A_4, B_4, C_4, D_4, E_4, F_4, G_4, H_4, I_4],
    Col_5 = [A_5, B_5, C_5, D_5, E_5, F_5, G_5, H_5, I_5],
    Col_6 = [A_6, B_6, C_6, D_6, E_6, F_6, G_6, H_6, I_6],
    Col_7 = [A_7, B_7, C_7, D_7, E_7, F_7, G_7, H_7, I_7],
    Col_8 = [A_8, B_8, C_8, D_8, E_8, F_8, G_8, H_8, I_8],
    Col_9 = [A_9, B_9, C_9, D_9, E_9, F_9, G_9, H_9, I_9],
    
    % Enforcing all different values in each column
    all_different(Col_1),
    all_different(Col_2),
    all_different(Col_3),
    all_different(Col_4),
    all_different(Col_5),
    all_different(Col_6),
    all_different(Col_7),
    all_different(Col_8),
    all_different(Col_9),

    % Variables representing each subgrid on the board
    Grid1 = [A_1, A_2, A_3, B_1, B_2, B_3, C_1, C_2, C_3],
    Grid2 = [A_4, A_5, A_6, B_4, B_5, B_6, C_4, C_5, C_6],
    Grid3 = [A_7, A_8, A_9, B_7, B_8, B_9, C_7, C_8, C_9],
    Grid4 = [D_1, D_2, D_3, E_1, E_2, E_3, F_1, F_2, F_3],
    Grid5 = [D_4, D_5, D_6, E_4, E_5, E_6, F_4, F_5, F_6],
    Grid6 = [D_7, D_8, D_9, E_7, E_8, E_9, F_7, F_8, F_9],
    Grid7 = [G_1, G_2, G_3, H_1, H_2, H_3, I_1, I_2, I_3], 
    Grid8 = [G_4, G_5, G_6, H_4, H_5, H_6, I_4, I_5, I_6],
    Grid9 = [G_7, G_8, G_9, H_7, H_8, H_9, I_7, I_8, I_9],

    % Enforcing all different values in each subgrid
    all_different(Grid1),
    all_different(Grid2),
    all_different(Grid3),
    all_different(Grid4),
    all_different(Grid5),
    all_different(Grid6),
    all_different(Grid7),
    all_different(Grid8),
    all_different(Grid9),

    %List of all elements that is not nested
    flatten(Board, Flat_Board),
    %Range of all variables.
    Flat_Board ins 1..9,
    
    label(Flat_Board).