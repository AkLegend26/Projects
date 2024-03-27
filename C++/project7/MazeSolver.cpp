// File name: MazeSolver.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS 2201
// Assignment Number: PA 7
// Honor Statement: I have been abided by Vanderbilt honor code in completion of this assignment.
// Description:  This file implements the MazeSolver class.
// Last Changed:  04/15/2022


#include "MazeSolver.h"
#include <thread>


//Constructor
//Accepts newMaze and newAgenda as a parameter
//Initializes maze and agenda to the parameters and nodes_visited to zero.
MazeSolver::MazeSolver(Maze &newMaze, PointAgenda &newAgenda) : maze(newMaze),
                                                                  agenda(newAgenda),
                                                                  nodes_visited(0){
}

//visitPoint
//Prints current point to the screen and marks the current point as visited.
//Calls addAdjacent to add points adjacent to the curr points to be in agenda.
void MazeSolver::visitPoint(Point prev) {
    if (maze.hasBeenVisited(prev)){
    agenda.remove();// remove the already visited point
    }
    else{
        maze.markVisited(prev);
        Point tmp = prev; //temp variable to hold the value of current point
        agenda.remove();
        addAdjacent(tmp);// adding adjacent points to agenda after removing the prev point
        operator<<(std::cout, prev);
        std::cout<<"->";
        nodes_visited++;
    }
}

//addAdjacent
//Adds adjacent points of the current point to the agenda to visit later.
void MazeSolver::addAdjacent(Point curr){
    Point north= Point(curr.x+0,curr.y+1); // one up of current
    Point south= Point(curr.x+0,curr.y-1); // one down from current
    Point west= Point(curr.x-1,curr.y+0); // one left of current
    Point east= Point(curr.x+1,curr.y+0); // one right of current

    if (maze.isOpen(west)){// if the point isn't a wall
        agenda.add(west);
    }

    if (maze.isOpen(north)){
        agenda.add(north);
    }

    if (maze.isOpen(south)){
        agenda.add(south);
    }

    if (maze.isOpen(east)){
        agenda.add(east);
    }
}

//solve
//Determines if the maze has a solution or not.
bool MazeSolver::solve(bool trace) {

    Point curr = maze.getStartLocation();
    agenda.add(curr);
    nodes_visited++; // first node

    while (curr != maze.getEndLocation() && (!(agenda.isEmpty()))){

        visitPoint(curr); // check the current point
        curr = agenda.peek(); //update the current point

        if (trace){ //if user wants to visualize the tracking
            system("cls");
            maze.printVisitedMaze();
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    if (curr == maze.getEndLocation()){ //if loop ended because there was a solution.
        operator<<(std::cout, curr);
        std::cout<<"->Solution Found!"<<std::endl;
        std::cout<<"Number of nodes visited: " << nodes_visited<<std::endl;
    }
    else{ // if loop ended without the solution.
        std::cout<<"There was no solution for the Maze"<<std::endl;
        return false;
    }
    return true;
}

