// File name: CalTest.cpp
// Author: Ayush Pathak
// VUnetid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Date: 02/26/2022
// Honor statement:I attest that I understand the honor code for this class and have neither
//                 given nor received any unauthorized aid on this assignment.
// Assignment Number: 3
// Description: These methods will implement the calendar class.

#include <string>
#include <stdexcept>
#include <cassert>
#include "Calendar.h"


// Default Constructor
// Create an empty Calendar (one with zero Reminders)
Calendar::Calendar() : numRem(0),
                       remList(nullptr)
{

}
// Copy ctor
Calendar::Calendar(const Calendar &rhs) : numRem(rhs.numRem),
                                          remList(nullptr)
{
    if (rhs.remList == nullptr)
        return;

    RemNodePtr tmp = rhs.remList;
    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;

    remList = new RemNode;
    remList->rem = tmp->rem;
    remList->next = nullptr;

    prev = remList;
    tmp = tmp->next;

    while (tmp != nullptr){
        curr = new RemNode;
        curr->rem = tmp->rem;
        curr->next = nullptr;

        prev->next = curr;
        prev = curr;

        tmp = tmp->next;
    }
}


// Destructor
Calendar::~Calendar() {
    RemNodePtr curr = remList;
    RemNodePtr prev = nullptr;

    while (curr != nullptr){
        prev = curr;
        curr = curr->next;
        delete prev;
    }
    remList = nullptr;
}


// Assignment operator
const Calendar &Calendar::operator=(const Calendar &rhs) {
    if(this == &rhs){
        return *this;}

    Calendar tmp(rhs);
    std::swap(this->numRem, tmp.numRem);
    std::swap(this->remList, tmp.remList);
    return *this;
}


// getNumRem
// Return the total number of Reminders in the Calendar
size_t Calendar::getNumRem() const {
    return numRem;
}


//addRem(const Reminder &rem)
//
//Purpose: add/insert a reminder in the list of reminder objects
//Parameters: Reminder rem - the reminder to be added
//Returns: size_t - the index position of the inserted reminder
//
//Behavior:
//1. In case of the list being empty: insert as the first element
//2. In case of a non-empty Calendar: insert Reminder in sorted order
//3. In case of already existing Reminder with same date: insert new reminder
//    before (ahead of) the existing one
//4. Return the index of the inserted reminder, using zero-based indexing
//5. Operates in linear time.
size_t Calendar::addRem(const Reminder &rem) {
    numRem++;
    size_t idx = 0;
    RemNodePtr newNode = new RemNode;
    newNode->rem = rem;
    newNode->next = nullptr;

    if (remList == nullptr) { // numRem is 0
        remList = newNode;
        newNode = nullptr;
        return idx;
    }
    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;

    curr = remList;
    while (curr != nullptr){
        idx++;
        if (rem <= curr->rem) {
            if (idx == 1){
                remList = newNode;
                newNode->next = curr;
                return idx;
            }
            prev->next = newNode;
            newNode->next = curr;
            return idx;
        }
        prev = curr;
        curr = curr->next;
    }
    prev->next = newNode;
    return idx;
}


//getRem(size_t index)
//
//Purpose: returns the reminder at the specified index in the Calendar, throw
//   exception if index is bad
//Parameters: size_t index - the index of the desired reminder; using zero-based
//   indexing
//Returns: Reminder - the reminder at the specified index
//
//Behavior:
//1.	If the index is invalid, throw an std::invalid_argument exception
//2.	Otherwise, return the reminder at the specified index
Reminder Calendar::getRem(size_t index) const {
    if (index >= numRem){
        throw std::invalid_argument("Invalid index into the calendar");
    }
    if (remList == nullptr){
        throw std::invalid_argument("Invalid index into the calendar");
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx != index){
        curr = curr->next;
        idx++;
    }
    return curr->rem;
}


//toString()
//
//Purpose: Return a string representation of the Calendar; ie, a string of all
//   reminders
//Parameters: None
//Return: string containing all the reminders in sorted order with each reminder
//   followed immediately by a newline character. Returns an empty string if the
//   Calendar is empty
std::string Calendar::toString() const {
    std::string final_string;
    if (numRem == 0){
        return final_string;
    }
    RemNodePtr curr = nullptr;
    curr = remList;
    while(curr != nullptr){
        final_string += curr->rem.toString() + '\n';
        curr = curr->next;
    }
    return final_string;
}


//displayRem(size_t index)
//
//Purpose: Return a string of the reminder at a particular index in the Calendar
//Parameters: size_t index
//Return: string containing the reminder
//
//Behavior:
//1. Returns string containing the reminder at the given index (no newline
//      character added)
//2. Follows 0-indexing
//3. If list is empty or the index is invalid, returns an empty string
std::string Calendar::displayRem(size_t index) const {
    std::string final_string;
    if (index >= numRem){
        return final_string;
    }
    if (remList == nullptr){
        return final_string;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx != index){
        curr = curr->next;
        idx++;
    }
    final_string += curr->rem.toString();
    return final_string;
}


//displayRem(const string& str)
//
//Purpose: Return a string of all reminders whose message matches the provided string
//Parameters: string str - the string we are supposed to check for match
//Return: string containing all the matching reminders, in sorted order, each reminder
//   followed immediately by a newline character.
//
//Behavior:
//1. Finds any reminders having its message same as the provided string (in a case
//    sensitive manner)
//2. If no match is found, returns an empty string
//3. If matches are found, append them on the return string in sorted order each
//    followed by a newline character.
std::string Calendar::displayRem(const std::string &str) const {
    std::string final_string;
    if (remList == nullptr){
        return final_string;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx <= numRem-1){
        if (str.compare(curr->rem.getMsg()) ==0 ){
            final_string += curr->rem.toString() +'\n';
        }
        curr = curr->next;
        idx++;
    }
    return final_string;
}


//displayRem(const Date& d)
//
//Purpose: Return a string of all reminders for a given date
//Parameters: Date d - the date we are supposed to check for match
//Return: string containing all the matching reminders, in sorted order, each reminder
//        followed immediately by a newline character.
//
//Behavior:
//1. Finds any reminders on the provided date
//2. If no match is found, returns an empty string
//3. If matches are found, append them on the return string in sorted order each
//     followed by a newline character.
//
//Note: see addRem() for the definition of sorted order of Reminders with the
//  same date.
std::string Calendar::displayRem(const Date &d) const    // searches reminders by date
{
    return displayRem(d,d);
}


//displayRem(const Date& d1, const Date& d2)
//
//Purpose: Displays reminders in a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: string containing all the matching reminders, in sorted order, each reminder
//   followed immediately by a newline character.
//
//Behavior:
//1. If the Calendar contains no dates in the given range, return an empty string
//2. Create a string containing all the reminders, in sorted order, which are later
//    than or equal to the smaller of the two dates and are earlier than or equal to
//    the larger of the two dates, with each reminder followed immediately by a
//    newline character.
std::string Calendar::displayRem(const Date &d1, const Date &d2) const {
    std::string final_string;
    if (remList == nullptr){
        return final_string;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx <= numRem-1){
        if ((curr->rem > d1) && (curr->rem > d2)){// efficient
            return final_string;
        }
        if((d1 <= curr->rem || d2 <= curr->rem) && (curr->rem <= d2 || curr->rem <= d1))  {
            // Checks if any of the provided dates are less or greater than the ones in array.
            final_string += curr->rem.toString() + '\n';
        }
        curr = curr->next;
        idx++;
    }

    return final_string;
}


//findRem(const Date& d)
//
//Purpose: Find first reminder for the given date and return its index
//Parameters: Date d, the date to search for
//Return: int value containing the index of the first reminder with the specified date,
//        or -1 if no reminders with that date exist
int Calendar::findRem(const Date &d) const {
    if (remList == nullptr){
        return -1;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx <= numRem-1){
        if (d == curr->rem.getDate()){
            return idx;
        }
        curr = curr->next;
        idx++;
    }
    return -1;
}


//findRem(const std::string& str)
//
//Purpose: Find first reminder with the given message and return its index
//Parameters: string str, the message to search for
//Return: int value containing the index of the first reminder with the specified
//        message, or -1 if no reminders with that message exist
int Calendar::findRem(const std::string &str) const
{
    if (remList == nullptr){
        return -1;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    curr = remList;
    while (idx <= numRem-1){
        if (str == curr->rem.getMsg()){
            return idx;
        }
        curr = curr->next;
        idx++;
    }
    return -1;
}


// deleteRem()
//
//Purpose: Deletes all reminders earlier than today's date
//Parameters: None
//Return: the number of reminders deleted (a size_t value)
//
// Implementation Notes:
// 1. The default constructor of the Date class initializes a Date object to
//    today's date.
size_t Calendar::deleteRem() {
    size_t total_del = 0;
    if (remList == nullptr) { // numRem is 0
        return total_del;
    }
    RemNodePtr prev = nullptr;
    RemNodePtr curr = remList;

    while(curr != nullptr && (curr->rem < Date()) ){
        prev = curr;
        curr = curr->next;
        remList = curr;
        delete prev;
        prev = nullptr;
        total_del++;
    }
    numRem -= total_del;
    return total_del;
}


// deleteRem(size_t index)
//
//Purpose: Deletes reminder object at a provided index position
//Parameters: size_t index
//Return: the number of reminders deleted (a size_t value)
//
// Notes:
// 1. If the index is invalid, no deletions will be performed and zero is returned
size_t Calendar::deleteRem(size_t index) {
    size_t num_del = 0;
    if (index >= numRem){
        return num_del;
    }
    if (remList == nullptr){
        return num_del;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;
    curr = remList;
    num_del++;
    numRem--;
    if (index == 0){
        prev = curr;
        remList = curr->next;
        delete prev;
        prev = nullptr;
        return num_del;
    }

    while (idx < index){
        prev = curr;
        curr = curr->next;
        idx++;
    }
    prev->next = curr->next;
    delete curr;
    return num_del;
}


// deleteRem(const string& str)
//
//Purpose: Delete all reminders whose message matches a given string
//Parameters: string str (whose match we want to find, case sensitive)
//Return: number of reminders deleted (size_t value)
size_t Calendar::deleteRem(const std::string &str) {
    size_t num_del = 0;
    if (remList == nullptr) {
        return num_del;
    }
    size_t idx = 0;
    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;
    curr = remList;
    while (idx < numRem) {
        if ((curr->rem.getMsg()) == str) {
            num_del++;
            if (prev == nullptr) {
                remList = curr->next;
                delete curr;
                curr = remList;
            }
            else{
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
        idx++;
    }
    numRem -= num_del;
    return num_del;
}


// deleteRem(const Reminder& rem)
//
//Purpose: Delete all occurrences of the given reminder
//Parameters: Reminder rem
//Return: number of reminders deleted (size_t value)
size_t Calendar::deleteRem(const Reminder &rem) {
    size_t num_del = 0;
    if (remList == nullptr) {
        return num_del;
    }
    size_t idx = 0;

    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;
    curr = remList;

    while (idx < numRem) {
        if (curr->rem == rem) {
            num_del++;
            if (prev == nullptr) {
                remList = curr->next;
                delete curr;
                curr = remList;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
        idx++;
    }
    numRem -= num_del;
    return num_del;
}


// deleteRem(const Date& d)
//
//Purpose: Deletes all reminders on a particular date
//Parameters: Date d
//Return: number of reminders deleted (size_t value)
size_t Calendar::deleteRem(const Date &d) {
    return deleteRem(d,d);
}


// deleteRem(const Date& d1, const Date& d2)
//
//Purpose: Deletes all reminders between a range of two given dates
//Parameters: Date d1, Date d2 (the range of Dates)
//Return: number of reminders deleted (size_t value)
//
//Behavior:
//1. If the Calendar contains no dates in the given range, perform no deletions &
//      return zero
//2. Delete all Reminders which are later than or equal to the smaller of the two
//      dates and are earlier than or equal to the larger of the two dates. Return the
//      number deleted.
size_t Calendar::deleteRem(const Date &d1, const Date &d2) {
    size_t num_del = 0;
    if (remList == nullptr) {
        return num_del;
    }
    size_t idx = 0;

    RemNodePtr curr = nullptr;
    RemNodePtr prev = nullptr;
    curr = remList;

    while (idx < numRem) {
        if ((d1 <= curr->rem || d2 <= curr->rem) && (curr->rem <= d2 || curr->rem <= d1)){
            num_del++;
            if (prev == nullptr) {
                remList = curr->next;
                delete curr;
                curr = remList;
            } else {
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
        }
        else {
            prev = curr;
            curr = curr->next;
        }
        idx++;
    }
    numRem -= num_del;
    return num_del;
}