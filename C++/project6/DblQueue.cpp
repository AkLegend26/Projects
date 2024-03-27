// File name: DblQueue.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201 @ Vanderbilt U.
// Assignment Number: PA 6
// Description:
// Honor statement: I have been abided by Vanderbilt honor code in completion of this assignment.
// Last Changed: 4/7/2022

#include "DblQueue.h"
#include <stdexcept>


DblQueue::DblQueue() : myHead(nullptr),
                        myBack(nullptr),
                        size_queue(0){

}

DblQueue::DblQueue(const DblQueue& rhs) : myHead(nullptr),
                                            myBack(nullptr),
                                            size_queue(rhs.size_queue)
{
    if(rhs.myHead == nullptr){
        return;
    }
    DataPtr tmp =rhs.myHead;
    DataPtr curr = nullptr;

    myHead = new Data;
    myHead->dat = tmp->dat;
    myHead->next = nullptr;
    DataPtr prev =myHead;
    tmp = tmp->next;
    myBack = prev;

    while (tmp!= nullptr ){
        curr = new Data;
        curr->dat = tmp->dat;
        curr->next = nullptr;

        prev->next =curr;
        prev = curr;

        tmp = tmp->next;
    }
    myBack = curr;

}

DblQueue::~DblQueue() {
    while(!isEmpty()){
        dequeue();
    }
}

const DblQueue &DblQueue::operator=(const DblQueue &rhs) {
    if (this == &rhs){
        return *this;
    }
    DblQueue tmp(rhs);
    std::swap(this->myHead, tmp.myHead);
    std::swap(this->myBack, tmp.myBack);
    std::swap(size_queue, tmp.size_queue);
    return *this;
}

bool DblQueue::isEmpty() const {
    return myHead == nullptr;
}

void DblQueue::enqueue(const ItemType &item) {
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

void DblQueue::dequeue() {
    if (isEmpty()){
        throw std::underflow_error("Queue is empty.");
    }
    size_queue--;


        DataPtr tmp = myHead;
        myHead = myHead->next;
        delete tmp;
        tmp = nullptr;

}

ItemType DblQueue::front( ) const{
    if (isEmpty()){
        throw std::underflow_error("Queue is empty.");
    }
    return myHead->dat;
}

size_t DblQueue::size( ) const{
    return size_queue;
}

