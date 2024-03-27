// File name: MazeSolver.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS 2201
// Assignment Number: PA 7
// Honor Statement: I have been abided by HFA honor code in completion of this assignment/
// Description:   This file is the header file of MazeSolver/\.
// Last Changed:  04/15/2022


#ifndef MAZESOLVER_H
#define MAZESOLVER_H
#include "Maze.h"
#include "PointAgenda.h"


class MazeSolver
{
private:
    Maze &maze;
    PointAgenda &agenda;
    size_t nodes_visited;

    //addAdjacent
    //Adds adjacent points of the current point to the agenda to visit later.
    void addAdjacent(Point curr);

    //visitPoint
    //Prints current point to the screen and marks the current point as visited.
    //Calls addAdjacent to add points adjacent to the curr points to be in agenda.
    void visitPoint(Point curr);


public:

    //Constructor
    //Accepts newMaze and newAgenda as a parameter
    //Initializes maze and agenda to the parameters and nodes_visited to zero.
    MazeSolver(Maze& newMaze, PointAgenda& newAgenda );

    //solve
    //Determines if the maze has a solution or not.
    bool solve(bool trace);
};

#endif