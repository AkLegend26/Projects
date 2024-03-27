// File name: Calendar.cpp
// Author: Ayush Pathak
// VUnetid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Date: 02/09/2022
// Honor statement:I attest that I understand the honor code for this class and have neither
//                 given nor received any unauthorized aid on this assignment.
// Assignment Number: 1
// Description: These methods implement the Calendar class

#include <string>
#include <stdexcept>
#include <cassert>
#include "Calendar.h"


// Default Constructor
// Create an empty Calendar (one with zero Reminders)
Calendar::Calendar() : numRem(0){
}

// getNumRem
// Return the total number of Reminders in the Calendar
size_t Calendar::getNumRem() const {
    return numRem;
}


//addRem(const Reminder &r)
//
//Purpose: add/insert a reminder in the array of reminder objects
//Parameters: Reminder r - the reminder to be added
//Returns: size_t - the index position of the inserted reminder
//
//Behavior:
//1. In case of the array being empty: insert as the first element
//2. In case the array is full: throw an overflow_error exception
//3. In case of a non-empty array with space available: insert Reminder in sorted
//      order, shifting other items up to make space
//4. In case of already existing Reminder with same date: insert new reminder
//      before (ahead of) the existing one.
//5. Return the index of the inserted reminder, using zero-based indexing
//6. Operates in linear time.
size_t Calendar::addRem(const Reminder &r) {
    size_t idx = 0;
    /*numRem++;
    if (numRem == 1){
        remArr[0] = r;
    }
    else if(numRem >= 51){
        numRem--;
        throw std::overflow_error("Array is full.");
    }



    else {
        for (size_t i = numRem-2; i>=0; i--){
            remArr[i+1] = remArr[i];
            if (remArr[i] > r){
                remArr[i] = r;
                idx =i;
                return idx;
            }
        }*/
    if (numRem >= 50) {// 50 is maxsize
        throw std::overflow_error("Array is full.");
    }
    if (numRem == 0){
        remArr[0] = r;
        numRem++;
        return idx;
    }
    for (size_t i = numRem; i > 0; i--) {

        if (remArr[i-1] < r) {
            remArr[i] = r;
            idx = i-1;
            numRem++;
            return idx;
        }
        remArr[i] = remArr[i-1];
        if (remArr[i-1] < r) {
            remArr[i] = r;
            numRem++;
            return idx;
        }
    }
    remArr[0] = r;
    numRem++;
    return idx;
}

    /*for (size_t i = 0; i < numRem; i++) { //loops from 0 to numRem-1 looking for condition.
        if (remArr[i] >= r) {
            for (size_t z = numRem-1; z > i; z--){ //loops from end to idx with conditions met.
                remArr[z] = remArr[z-1];
            }
            remArr[i] = r; //Inserts reminder after moving every element up 1.
            idx = i;
            return idx;
        }
    }*/
    //remArr[numRem-1] = r; // if condition isn't met then this reminder is the latest date.
    //idx = numRem-1;
    //}



//getRem(size_t index)
//
//Purpose: returns the reminder at the specified index in the Calendar, throw
//   exception if index is bad
//Parameters: size_t index - the index of the desired reminder; using zero-based
//   indexing
//Returns: Reminder - the reminder at the specified index
//
//Behavior:
//1. If the index is invalid, throws a std::invalid_argument exception
//2. Otherwise, return the reminder at the specified index
Reminder Calendar::getRem(size_t index) const {
    if (!((0 <= index) && (index <= MAX_REM-1))){
        throw std::invalid_argument("Invalid index into the calendar");
    }
    return remArr[index];
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
    if (getNumRem() == 0){
        return final_string;
    }
    for (size_t i = 0; i < numRem; i++){
        final_string += remArr[i].toString() + '\n';
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
//3. If array is empty or the index is invalid, returns an empty string
std::string Calendar::displayRem(size_t index) const {
    std::string output_string;
    if (!(0 <= index && index < numRem)){
        return output_string;
    }
    output_string += remArr[index].toString();
    return output_string;
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
    std::string output_string;
    for (size_t i = 0; i < numRem; i++){
        if (str.compare(remArr[i].getMsg()) ==0) {
            output_string += remArr[i].toString() + '\n';
        }
    }
    return output_string;
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
std::string Calendar::displayRem(const Date &d) const {
    std::string rem_string;
    for (size_t i = 0; i < numRem; i++){
        if (d == remArr[i].getDate())   {
            rem_string += remArr[i].toString() + '\n'; // String concatenation with matches.
        }
    }
    return rem_string;
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
    std::string date_string;

    for (size_t i = 0; i < numRem; i++){
        if((d1 <= remArr[i] || d2 <= remArr[i]) && (remArr[i] <= d2 || remArr[i] <= d1))  {
            // Checks if any of the provided dates are less or greater than the ones in array.
            date_string += remArr[i].toString() + '\n';
        }
    }
    return date_string;
}


//findRem(const Date& d)
//
//Purpose: Find first reminder for the given date and return its index
//Parameters: Date d, the date to search for
//Return: int value containing the index of the first reminder with the specified date,
//        or -1 if no reminders with that date exist
int Calendar::findRem(const Date &d) const {
    for (size_t i = 0; i < numRem; i++){
        if (d == remArr[i].getDate()){
            return i;
        }
    }
    return -1;
}


//findRem(const std::string& str)
//
//Purpose: Find first reminder with the given message and return its index
//Parameters: string str, the message to search for
//Return: int value containing the index of the first reminder with the specified
//        message, or -1 if no reminders with that message exist
int Calendar::findRem(const std::string &str) const {
    for (size_t i = 0; i < numRem; i++){
        if (str == remArr[i].getMsg()){
            return i;
        }
    }
    return -1;
}


// deleteRem()
//
//Purpose: Deletes all reminders earlier than today's date
//Parameters: None
//Return: the number of reminders deleted (a size_t value)
//
//Behavior:
//1) Reminders are shifted down in the array to fill any vacated entries.
//
//Implementation Notes:
//1) The default constructor of the Date class initializes a Date object to today's
//   date.
size_t Calendar::deleteRem() {
    size_t delete_times = 0;
    if (numRem ==0){
        return delete_times;
    }
    for (size_t i = numRem-1; i >= 0 && i <numRem;i--){// Loops from end of the array.
        if (remArr[i].getDate() < Date()){
            delete_times++;
            for (size_t j = i; j <= numRem-1; j++){// Loops from idx to move one left.
                if (j == MAX_REM-1){// No shifting will be done with last idx.
                    remArr[j] = remArr[j];
                }
                else{
                    remArr[j] = remArr[j+1];
                    }
                }
            }
        }
    numRem -= delete_times;
    return delete_times;
}


// deleteRem(size_t index)
//
//Purpose: Deletes reminder object at a provided index position
//Parameters: size_t index
//Return: the number of reminders deleted (a size_t value)
//
//Notes:
//1) Reminders are shifted down in the array to fill any vacated entries.
//2) If the index is invalid, no deletions will be performed and zero is returned
size_t Calendar::deleteRem(size_t index) {
    size_t rem_deleted = 0;
    if (!(0 <= index && index < numRem)) { // Checking for out of index input.
        return rem_deleted;
    }
    if (index == MAX_REM-1){ // No shifting at last index only our numRem will go down.
        rem_deleted++;
    }
    else{
        rem_deleted++;
        for (size_t j = index; j <= numRem - 1; j++) {
            remArr[j] = remArr[j + 1];
        }
    }
    numRem -= rem_deleted;
    return rem_deleted;
}


// deleteRem(const string& str)
//
//Purpose: Delete all reminders whose message matches a given string
//Parameters: string str (whose match we want to find, case-sensitive)
//Return: number of reminders deleted (size_t value)
//
//Notes:
//1) Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const std::string &str) {
    size_t num_rem_deleted = 0;
    for (size_t i = numRem-1; i >= 0 && i <numRem;i--){// Iterates backward in the array.
        if (remArr[i].getMsg() == str){
            num_rem_deleted++;
            for (size_t j = i; j <= numRem-1; j++){
                if (j == MAX_REM-1){
                    remArr[j] = remArr[j];
                }
                else{
                remArr[j] = remArr[j+1];
                }
            }
        }
    }
    numRem -= num_rem_deleted;
    return num_rem_deleted;
}


// deleteRem(const Reminder& rem)
//
//Purpose: Delete all occurrences of the given reminder
//Parameters: Reminder rem
//Return: number of reminders deleted (size_t value)
//
//Notes:
//1) Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const Reminder &rem) {
    size_t num_rem_deleted = 0;
    for (size_t i = numRem-1; i >= 0 && i <numRem;i--){// Iterates backward in the array.
        if (remArr[i] == rem){
            num_rem_deleted++;
            for (size_t j = i; j <= numRem-1; j++){
                if (j == MAX_REM-1){
                    remArr[j] = remArr[j];
                }
                else{
                    remArr[j] = remArr[j+1];
                }
            }
        }
    }
    numRem -= num_rem_deleted;
    return num_rem_deleted;
}


// deleteRem(const Date& d)
//
//Purpose: Deletes all reminders on a particular date
//Parameters: Date d
//Return: number of reminders deleted (size_t value)
//
//Notes:
//1) Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const Date &d) {
    size_t num_rem_deleted = 0;
    for (size_t i = numRem-1; i >= 0 && i <numRem;i--){// Iterates backwards in the array.
        if (remArr[i] == d){
            num_rem_deleted++;
            for (size_t j = i; j <= numRem-1; j++){
                if (j == MAX_REM-1){
                    remArr[j] = remArr[j];
                }
                else{
                    remArr[j] = remArr[j+1];
                }
            }
        }
    }
    numRem -= num_rem_deleted;
    return num_rem_deleted;
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
//3. Reminders are shifted down in the array to fill any vacated entries.
size_t Calendar::deleteRem(const Date &d1, const Date &d2) {
    size_t num_rem_deleted = 0;
    for (size_t i = numRem-1; i >= 0 && i <numRem;i--){
        if ((d1 <= remArr[i] || d2 <= remArr[i]) && (remArr[i] <= d2 || remArr[i] <= d1)) {
            // Checks if any of the given date is lower or greater than the dates in array.
            num_rem_deleted++;
            for (size_t j = i; j <= numRem - 1; j++) {
                if (j == MAX_REM-1) {
                    remArr[j] = remArr[j];
                } else {
                    remArr[j] = remArr[j + 1];
                }
            }
        }
    }
    numRem -= num_rem_deleted;
    return num_rem_deleted;
}