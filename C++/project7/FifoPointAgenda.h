// File name: LifoPointAgenda.h
// Author:Ayush Pathak
// userid:pathaa3
// Email:ayush.pathak@vanderbilt.edu
// Class:CS2201
// Assignment Number: PA 7
// Honor Statement:I have been abided by vanderbilt honor code in completion of this assignment.
// Description: Maintains an agenda of point to be visited in a queue with its functions.
// Last Changed:04/15/2022


#ifndef FifoPointAgenda_H
#define FifoPointAgenda_H
#include "Queue_t.h"

class FifoPointAgenda: public PointAgenda{

private:

    DblQueue<Point> FifoAgenda;

public:
    // virtual Class Destructor
    virtual ~FifoPointAgenda() {}

    // isEmpty
    // Checks if the agenda is empty
    virtual bool isEmpty() const{return FifoAgenda.isEmpty();}

    // add
    // adds a Point to the agenda.
    virtual void add(const Point& item){FifoAgenda.enqueue(item);}

    // remove
    // removes the next Point from the agenda.
    virtual void remove(){FifoAgenda.dequeue();}

    // peek
    // Returns the next Point from the agenda without removing it from the agenda.
    virtual Point peek() const{return FifoAgenda.front();}

    // size
    // Returns the number of Points in the agenda.
    virtual size_t size() const{return FifoAgenda.size();}

};


#endif


