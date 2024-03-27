// File name: DblQueue.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: auysh.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description:  This is the header file for the DblQueue class.
// Honor statement:I have been abided by Vanderbilt honor code in completion of this assignment.
// Last Changed: 4/7/2022



#ifndef DBLQUEUE_H
#define DBLQUEUE_H

#include <cstddef>   // make gcc & CLion happy

typedef double ItemType;

class DblQueue
{
  private:
    struct Data
    {
        ItemType dat;
        Data *next;
    };
    typedef Data* DataPtr;

    DataPtr myHead;
    DataPtr myBack;
    size_t size_queue;



  public:
    // Class Constructor
    DblQueue();

    // Copy Constructor
    // pre:  Class object, aQueue, exists
    // post: Object is initialized to be a copy of the parameter
    DblQueue(const DblQueue& aQueue);

    // Class Destructor
    // Destroys a queue
    // pre:  Class object exists
    // post: Class object does not exist
    ~DblQueue();

    // Assignment operator
    // Assigns a queue to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const DblQueue& operator= (const DblQueue& rhs);

    // isEmpty
    // Checks if the queue is empty
    // pre:  A queue exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // enqueue
    // enqueues an item to back of the queue.
    // pre:  DblQueue exists and item is passed.
	// post: adds the given item to the end of the queue.
    void enqueue(const ItemType& item);

    // dequeue
    // dequeues the front item off the queue 
    // pre:  DblQueue exists.
    // post: Removes item on front of the queue. If the queue
    //       was already empty, throws an std::underflow_error exception.
    void dequeue();

    // front
    // Returns the front item of the queue without dequeueing it.
    // pre:  DblQueue exists.
    // post: Returns item at front of queue.  If the queue is empty,
    //       throws an std::underflow_error exception.
    ItemType front() const;

    // size
    // Returns the number of items on the queue.
    size_t size() const;

};

#endif
