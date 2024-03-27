// File name: DblStack.cpp
// Name: Ayush Pathak
// VUnetid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS 2201
// Assignment Number: PA 5
// Honor statement: "I have been abided by the Vanderbilt honor code in completion of this
// assignment."
// Description:  Maintains a stack of ItemType. Implements functions to
//     push, pop, retrieve top, and retrieve size of the stack.
// Last Changed: 03/29/2022

#include <cstddef>
#include <stdexcept>
#include "DblStack.h"


DblStack::DblStack() : datList(nullptr),
                       size_stack(0)
{

}

DblStack::DblStack(const DblStack& rhs) : datList(nullptr),
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

DblStack::~DblStack() {
    while (!isEmpty()) {
        pop();
    }
}

const DblStack &DblStack::operator=(const DblStack &rhs){
    if (this == &rhs){
        return *this;
    }
    DblStack tmp(rhs);
    std::swap(this->datList, tmp.datList);
    std::swap(this->size_stack, tmp.size_stack);
    return *this;
}

bool DblStack::isEmpty() const {
    if (datList == nullptr){
        return true;
    }
    else
        return false;
}

void DblStack::push(const ItemType& item){

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

void DblStack::pop(){
    if (datList == nullptr){
        throw std::underflow_error("The Stack is Empty");
    }
    DataPtr tmp = datList;
    datList = datList->next;
    delete tmp;
    tmp = nullptr;
    size_stack--;
}

ItemType DblStack::top() const{
    if (datList == nullptr){
        throw std::underflow_error("The Stack is Empty");
    }
    return datList->dat;
}

size_t DblStack::size() const{
    return size_stack;
}
