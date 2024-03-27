// File name: Stack_t.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 7
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file defines the template stack.
// Last Changed: 4/15/2022



#ifndef STACK_T_H
#define STACK_T_H
#include <stdexcept>

template <typename ItemType>


class DblStack
{
private:

    struct Data
    {
        ItemType dat;
        Data *next;
    };
    typedef Data* DataPtr;

    DataPtr datList;
    size_t size_stack;

public:
    // Class Constructor
    // post: stack is created & initialized to be empty
    DblStack();

    // Copy Constructor
    // pre: parameter object, rhs, exists
    // post: stack is created to be a copy of the parameter stack
    DblStack(const DblStack& rhs);

    // Class Destructor
    // pre: the stack exists
    // post: the stack is destroyed and any dynamic memory is returned to the system
    ~DblStack();

    // Assignment operator
    // Assigns a stack to another
    // pre: both class objects exist
    // post: this class object gets assigned a copy of the parameter class object
    const DblStack& operator= (const DblStack& rhs);

    // isEmpty
    // Checks if the stack is empty
    // pre:  A stack exists.
    // post: Returns true if it IS empty, false if NOT empty.
    bool isEmpty() const;

    // push
    // Pushes an item on top of the stack.
    // pre:  Stack exists and item is passed.
    // post: the item is placed on top of the stack, and size is incremented.
    void push(const ItemType& item);

    // pop
    // Pops the top item off the stack.
    // pre:  Stack exists.
    // post: Removes item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    void pop();

    // top
    // Returns the top item of the stack without popping it.
    // pre:  Stack exists.
    // post: Returns item on top of stack.  If the stack
    //       was already empty, throws a std::underflow_error exception.
    ItemType top() const;

    // size
    // Returns the number of items on the stack.
    // post: Returns size from the private section of class.
    size_t size() const;

};

#include "Stack_t.cpp"
#endif
