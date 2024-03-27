// File name: FifoPointAgenda.h
// Author:Ayush Pathak
// userid:pathaa3
// Email:ayush.pathak@vanderbilt.edu
// Class:CS2201
// Assignment Number: PA 7
// Honor Statement:I have been abided by vanderbilt honor code in completion of this assignment.
// Description: Maintains an agenda of point to be visited in a stack with its functions.
// Last Changed:04/15/2022


#ifndef LifoPointAgenda_H
#define LifoPointAgenda_H
#include "Stack_t.h"

class LifoPointAgenda: public PointAgenda{

private:

    DblStack<Point> LifoAgenda;

public:
    // virtual Class Destructor
    virtual ~LifoPointAgenda() {}

    // isEmpty
    // Checks if the agenda is empty
    virtual bool isEmpty() const{return LifoAgenda.isEmpty();}

    // add (pure virtual)
    // adds a Point to the agenda.
    virtual void add(const Point& item){LifoAgenda.push(item);}

    // remove
    // removes the next Point from the agenda.
    virtual void remove(){LifoAgenda.pop();}

    // peek
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{return LifoAgenda.top();}

    // size
    // Returns the number of Points in the agenda.
    virtual size_t size() const{return LifoAgenda.size();}

};

#endif

