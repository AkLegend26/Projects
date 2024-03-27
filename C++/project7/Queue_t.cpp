// File name: Queue_t.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 7
// Description:This file implements the DblQueue class.
// Last Changed: 04/15/2022

// Class Constructor
template <typename ItemType>
DblQueue<ItemType>::DblQueue() : myHead(nullptr),
                       myBack(nullptr),
                       size_queue(0){
}

// Copy Constructor
// pre:  Class object, aQueue, exists
// post: Object is initialized to be a copy of the parameter
template <typename ItemType>
DblQueue<ItemType>::DblQueue(const DblQueue& rhs) : myHead(nullptr),
                                          myBack(nullptr),
                                          size_queue(0)
{
    if(rhs.myHead == nullptr){
        return;
    }
    DataPtr tmp =rhs.myHead;
    while (tmp!= nullptr) {
        this->enqueue(tmp);
        tmp = tmp->next;
    }
}

// Class Destructor
// Destroys a queue
// pre:  Class object exists
// post: Class object does not exist
template <typename ItemType>
DblQueue<ItemType>::~DblQueue() {
    while(!isEmpty()){
        dequeue();
    }
}

// Assignment operator
// Assigns a queue to another
// pre: both class objects exist
// post: this class object gets assigned a copy of the parameter class object
template <typename ItemType>
const DblQueue<ItemType> &DblQueue<ItemType>::operator=(const DblQueue<ItemType> &rhs) {
    if (this == &rhs){
        return *this;
    }
    DblQueue<ItemType> tmp(rhs);
    std::swap(this->myHead, tmp.myHead);
    std::swap(this->myBack, tmp.myBack);
    std::swap(size_queue, tmp.size_queue);
    return *this;
}

// isEmpty
// Checks if the queue is empty
// pre:  A queue exists.
// post: Returns true if it IS empty, false if NOT empty.
template <typename ItemType>
bool DblQueue<ItemType>::isEmpty() const {
    return myHead == nullptr;
}

// enqueue
// enqueues an item to back of the queue.
// pre:  DblQueue exists and item is passed.
// post: adds the given item to the end of the queue.
template <typename ItemType>
void DblQueue<ItemType>::enqueue(const ItemType &item) {
    DataPtr tmp = new Data;
    tmp->dat = item;
    tmp->next = nullptr;
    size_queue++;
    if (myHead == nullptr){
        myHead = tmp;
        myBack = tmp;
        return;
    }
    myBack->next = tmp;
    myBack = tmp;
    tmp = nullptr;
}

// dequeue
// dequeues the front item off the queue
// pre:  DblQueue exists.
// post: Removes item on front of the queue. If the queue
//       was already empty, throws an std::underflow_error exception.
template <typename ItemType>
void DblQueue<ItemType>::dequeue() {
    if (isEmpty()){
        throw std::underflow_error("Queue is empty.");
    }
    size_queue--;


    DataPtr tmp = myHead;
    myHead = myHead->next;
    delete tmp;
    tmp = nullptr;
}

// front
// Returns the front item of the queue without dequeueing it.
// pre:  DblQueue exists.
// post: Returns item at front of queue.  If the queue is empty,
//       throws an std::underflow_error exception.
template <typename ItemType>
ItemType DblQueue<ItemType>::front( ) const{
    if (isEmpty()){
        throw std::underflow_error("Queue is empty.");
    }
    return myHead->dat;
}

// size
// Returns the number of items on the queue.
template <typename ItemType>
size_t DblQueue<ItemType>::size( ) const{
    return size_queue;
}