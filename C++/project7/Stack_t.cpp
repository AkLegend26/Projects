// File name: Stack_t.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 7
// Description:  Maintains stack of ItemType and implements the function of stack.
// Last Changed: 04/15/2022


// Class Constructor
// post: stack is created & initialized to be empty
template <typename ItemType>
DblStack<ItemType>::DblStack() : datList(nullptr),
                       size_stack(0)
{
}

// Copy Constructor
// pre: parameter object, rhs, exists
// post: stack is created to be a copy of the parameter stack
template <typename ItemType>
DblStack<ItemType>::DblStack(const DblStack<ItemType>& rhs) : datList(nullptr),
                                          size_stack(rhs.size_stack)
{
    if (rhs.datList == nullptr)
        return;

    DataPtr tmp = rhs.datList;
    DataPtr curr = nullptr;
    DataPtr prev = nullptr;

    datList = new Data;
    datList->dat = tmp->dat;
    datList->next = nullptr;

    prev = datList;
    tmp = tmp->next;

    while (tmp!= nullptr){
        curr = new Data;
        curr->dat = tmp->dat;
        curr->next = nullptr;

        prev->next = curr;
        prev = curr;

        tmp = tmp->next;

    }
}

// Class Destructor
// pre: the stack exists
// post: the stack is destroyed and any dynamic memory is returned to the system
template <typename ItemType>
DblStack<ItemType>::~DblStack() {
    while (!isEmpty()) {
        pop();
    }
}

// Assignment operator
// Assigns a stack to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const DblStack<ItemType> &DblStack<ItemType>::operator=(const DblStack<ItemType> &rhs){
    if (this == &rhs){
        return *this;
    }
    DblStack tmp(rhs);
    std::swap(this->datList, tmp.datList);
    std::swap(this->size_stack, tmp.size_stack);
    return *this;
}

// isEmpty
// Checks if the stack is empty
// pre:  A stack exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool DblStack<ItemType>::isEmpty() const {
    return datList == nullptr;
}

// push
// Pushes an item on top of the stack.
// pre:  Stack exists and item is passed.
// post: the item is placed on top of the stack, and size is incremented.
template <typename ItemType>
void DblStack<ItemType>::push(const ItemType& item){

    DataPtr tmp = new Data;
    tmp->dat = item;
    tmp->next = nullptr;
    size_stack++;
    if (datList == nullptr){
        datList = tmp;
        return;
    }
    tmp->next = datList;
    datList = tmp;
    tmp = nullptr;

}

// pop
// Pops the top item off the stack.
// pre:  Stack exists.
// post: Removes item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
void DblStack<ItemType>::pop(){
    if (datList == nullptr){
        throw std::underflow_error("The Stack is Empty");
    }
    DataPtr tmp = datList;
    datList = datList->next;
    delete tmp;
    tmp = nullptr;
    size_stack--;
}

// top
// Returns the top item of the stack without popping it.
// pre:  Stack exists.
// post: Returns item on top of stack.  If the stack
//       was already empty, throws a std::underflow_error exception.
template <typename ItemType>
ItemType DblStack<ItemType>::top() const{
    if (datList == nullptr){
        throw std::underflow_error("The Stack is Empty");
    }
    return datList->dat;
}

// size
// Returns the number of items on the stack.
// post: Returns size from the private section of class.
template <typename ItemType>
size_t DblStack<ItemType>::size() const{
    return size_stack;
}


// Ignore the message from CLion telling you this file does not belong to any project target
