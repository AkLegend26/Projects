// File name: CalTest.cpp
// Author: Ayush Pathak
// VUnetid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Date: 02/01/2020
// Honor statement:I attest that I understand the honor code for this class and have neither
//                 given nor received any unauthorized aid on this assignment.
// Assignment Number: 0
// Description: This program will test the Calendar class

#include <iostream>
#include <string>
#include <stdexcept>
#include "Calendar.h"


void to_string_test() {

    Calendar cal;

    if (cal.toString() != "") {
        std::cout << "No reminders means no string. !!!" << std::endl;
    }

    Date d1("01/18/2022");
    Date d2("01/20/2022");
    Date d3("01/22/2022");
    Reminder rem1(d1, "First class of the day is in the morning");
    Reminder rem2(d1, "First class on da first day");
    Reminder rem3(d2, "Third reminder for the test");
    Reminder rem4(d3, "fourth reminder for the test");

    cal.addRem(rem1);

    if (!cal.toString().compare(rem1.toString())) {
        std::cout << "to_string didn't print the current reminder in the calendar." << std::endl;
    }

    cal.addRem(rem2);

    std::string final = rem1.toString() + '\n' + rem2.toString()+ '\n';

    if (!cal.toString().compare(final)) {
        std::cout << "The strings aren't seperated by a newline." << std::endl;
        std::cout << "The strings aren't arranged in the correct order." << std::endl;
    }
/*
    cal.addRem(rem4);
    cal.addRem(rem3);

    std::string final_1 = final + '\n' + rem3.toString() + '\n' + rem4.toString() +'\n';

    if (!cal.toString().compare(final_1)) {
        std::cout << "The strings aren't seperated by a newline." << std::endl;
        std::cout << "The strings aren't sorted." << cal.toString() << std::endl;
    }*/
}


void add_rem_test_get_test() {

    Calendar cal;

    Date d1("01/18/2022");
    Date d2("01/19/2022");
    Date d3("01/20/2022");

    Reminder rem2(d1, "Second day of classes");
    Reminder rem20(d1, "First class of the day is in the morning");
    Reminder rem21(d1, "Second class of the day is in the afternoon");
    Reminder rem22(d1, "Third class of the day is in the afternoon");
    Reminder rem23(d1, "Fourth class of the day is in the afternoon");
    Reminder rem3(d1, "Third day of classes");
    Reminder rem4(d2,"Another day at school");
    Reminder rem5(d3,"Is it really almost a week");

    cal.addRem(rem2);
    cal.addRem(rem20);
/*
    if (cal.getNumRem() != 2){
        std::cout << "Numbers of reminder in the calendar are wrong" << std::endl;
    }

    if (cal.getRem(0) != rem20 or cal.getRem(1) != rem2) {
        std::cout << "addRem failed to add reminders in chronological order." << std::endl;
        std::cout << "New reminder wasn't moved up on the index when added." << std::endl;
    }

    cal.addRem(rem21);
    cal.addRem(rem22);
    cal.addRem(rem23);

    if (cal.getRem(0) != rem23 or cal.getRem(1) != rem22) {
        std::cout << "addRem failed to add reminders in chronological order." << std::endl;
        std::cout << "New reminder wasn't moved up on the index when added." << std::endl;
    }

    if (cal.getRem(2) != rem21 or cal.getRem(3) != rem20) {
        std::cout << "addRem failed to add reminders in chronological order." << std::endl;
        std::cout << "New reminder wasn't moved up on the index when added." << std::endl;
    }

    if (cal.getRem(4) != rem2) {
        std::cout << "addRem failed to add reminders in chronological order." << std::endl;
        std::cout << "New reminder wasn't moved up on the index when added." << std::endl;
    }

    if (cal.getNumRem() != 5){
        std::cout << "Numbers of reminder in the calendar are wrong" << std::endl;
    }

    try {
        cal.getRem(51);

        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn overflow exception was not thrown!!" << std::endl;
    }
    catch (std::invalid_argument) {
        std::cout << "Exception of invalid indexing was successfully thrown & caught."
                  << std::endl;
    }

    if (cal.getRem(0) != rem23){
        std::cout << "This is not a zero based indexing." << std::endl;
    }

    cal.addRem(rem5);
    cal.addRem(rem4);

    if (cal.getRem(5) != rem4){
        std::cout<<"Reminders aren't sorted with different dates"<<std::endl;
    }

    if (cal.getRem(6) != rem5){
        std::cout<<"Reminders aren't sorted with different dates"<<std::endl;
    }

    try {
        cal.getRem(-1);

        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn overflow exception was not thrown!!" << std::endl;
    }
    catch (std::invalid_argument) {
        std::cout << "Exception of invalid indexing was successfully thrown & caught."
                  << std::endl;
    }*/
}


void display_rem_test(){

    Calendar cal;

    Date d1("01/18/2022");
    Date d2("01/19/2022");
    Date d3("01/20/2022");
    Date d4("01/29/2022");
    Date d5("02/26/2022");

    Reminder rem2(d1, "Second day of classes");
    Reminder rem20(d1, "First class of the day is in the morning");
    Reminder rem21(d1, "Second class of the day is in the afternoon");
    Reminder rem22(d1, "Third class of the day is in the afternoon");
    Reminder rem23(d1, "Fourth class of the day is in the afternoon");
    Reminder rem3(d1, "Third day of classes");
    Reminder rem30 (d2, "Second day of classes");
    Reminder rem4(d2,"Another day at school");
    Reminder rem40(d3, "Second day of classes");
    Reminder rem5(d3,"Is it really almost a week");

    if (cal.displayRem(0) != ""){
        std::cout<<"With no reminders empty string wasn't displayed."<<std::endl;
    }

    if (cal.displayRem(76) != ""){
        std::cout<<"With no reminders empty string wasn't displayed."<<std::endl;
    }

    cal.addRem(rem2);
    cal.addRem(rem20);

    if (cal.displayRem(0).compare(rem20.toString())){
        std::cout<<"String at the specified index wasn't provided."<<std::endl;
    }

    if (cal.displayRem(1).compare(rem2.toString())){
        std::cout<<"String at the specified index wasn't provided."<<std::endl;
    }
    if (cal.displayRem(50) != "") {
        std::cout<<"String at the specified index wasn't provided."<<std::endl;
    }

    if (cal.displayRem("Howdy brother gl grading")!= ""){
        std::cout<<"Without a match display rem found a reminder."<<std::endl;
    }

    cal.addRem(rem30);

    std::string final = rem2.toString() + '\n' + rem30.toString() + '\n';

    if (cal.displayRem("Second day of classes") != final){
        std::cout<<"Display rem didn't display all reminders in a string,"
                   " each followed by newline."<<std::endl;
    }

    if (cal.displayRem("second day of classes") == final){
        std::cout<<"Display rem wasn't case sensitive,"<<std::endl;
    }

    cal.deleteRem(2);

    cal.addRem(rem40);
    cal.addRem(rem30);

    std::string test = rem2.toString() + '\n' + rem30.toString() + '\n' + rem40.toString() + '\n';


    if (cal.displayRem("Second day of classes") != test){
        std::cout<<"Display rem didn't display all reminders in a string,"
                   " each followed by newline or in a sorted manner."<<std::endl;
    }

    std::string date = rem20.toString() + '\n' + rem2.toString() + '\n';

    if (cal.displayRem(d1) != (date)){
        std::cout<<"The reminders are not in a proper format or sorted properly."<<std::endl;
    }

    if (cal.displayRem(d2) != rem30.toString()+'\n'){
        std::cout<<"The correct reminder wasn't displayed according to the date."<<std::endl;
    }

    if (cal.displayRem(d2) == rem30.toString()){
        std::cout<<"The Newline wasn't displayed after the reminder."<<std::endl;
    }

    if (cal.displayRem(d4) != ""){
        std::cout<<"Reminder showed up with a date it shouldn't have."<<std::endl;
    }

    if (cal.displayRem(d4,d5) != ""){
        std::cout<<"With wrong range of date an empty list wasn't provided"<<std::endl;
    }


    // format for the display rem between ranges to be correct is rem20,rem2,rem30,rem40.
    std::string z = {rem20.toString() + '\n' + rem2.toString() + '\n' + rem30.toString() +
                     '\n' + rem40.toString()+'\n'};

    if (cal.displayRem(d1,d3) != z){
        std::cout<<"Between date ranges, the function wasn't sorted correctly or followed the "
                   "wring format."<<std::endl;
    }
    if (cal.displayRem(d3,d1) != z){
        std::cout<<"Between date ranges, the function wasn't sorted correctly or followed the "
                   "wring format."<<std::endl;
    }
    /*Failed to test displayRem(Date, Date)
function with the first Date parameter
being a later date than the second Date
parameter*/
    if (cal.displayRem(d3,d1) != z){
        std::cout<<"Between date ranges, the function wasn't sorted correctly or followed the "
                   "wring format."<<std::endl;
    }

}

void extra_test() {
    Date d1("01/18/2022");
    Date d2("01/02/2022");
    Date today;
    Date tomorrow(today + 1);

    Reminder rem1(d1, "Second day of classes");
    Reminder rem2(d1, "First class on second day");
    Reminder rem3(d2, "First class on second day");
    Reminder rem30(today, "today's reminder");
    Reminder rem40(tomorrow, "Tomorrow's reminder");
    Reminder rem301(today, "today's second reminder");
    Reminder rem302(today, "today's third reminder");
    Reminder rem303(today, "today's fourth reminder");


    Calendar a;
    a.addRem(rem30);
    a.addRem(rem40);
/*Failed to test displayRem(Date, Date)
function with the larger Date parameter
being smaller than all dates in the
calendar*/

    if (a.displayRem(d1, d2) != "") {
        std::cout << "deleteRem with large date not in calendar." << std::endl;
    }


/*Failed to test deleteRem() function w/o
params such that all dates in the
calendar are equal or later than current
date(ie, nothing will be deleted)*/

    if (a.deleteRem() != 0) {
        std::cout << "Dates in calendar should only be greater." << std::endl;
    }

    /*Failed to test deleteRem(string)
function on an empty calendar*/
    Calendar b;
    if (b.deleteRem("wow come on now") != 0) {
        std::cout << "Deleting strings from an empty calendar" << std::endl;
    }
/*Failed to test deleteRem(Date, Date)
function on an empty calendar*/

    if (b.deleteRem(d1, d2) != 0) {
        std::cout << "The calendar is deleting something in range of dates when its empty."
                  << std::endl;
    }
/*Failed to test deleteRem(Date, Date)
function with the two date parameters
out of order(the first one being later
than the second one)*/

    a.addRem(rem1);
    a.addRem(rem3);

    if (a.deleteRem(d2, d1) != 2) {
        std::cout << "something in delete rem with range" << std::endl;
    }
/*Failed to test deleteRem(Reminder) on an
empty calendar*/
    if (b.deleteRem(rem1) != 0) {
        std::cout << "delete rem with a reminder on empty calendar gave output." << std::endl;
    }
    b.addRem(rem1);
    b.deleteRem();


    Calendar c;
    c.addRem(rem1);
    c.deleteRem(0);
}

void find_rem_del_test(){
    Calendar cal;

    Date d1("01/18/2022");
    Date d2("01/02/2022");
    Date today;
    Date tomorrow(today+1);
    Date yesterday_1(today-1);
    Date yesterday_2(today-2);
    Date tomorrow_1(today+2);

    Reminder rem1(d1, "Second day of classes");
    Reminder rem2(d1, "First class on second day");
    Reminder rem3(d2, "First class on second day");
    Reminder rem10(yesterday_1, "Yesterday's old reminder");
    Reminder rem20(yesterday_2, "Yesterday's old reminder");
    Reminder rem30(today,"today's reminder");
    Reminder rem40(tomorrow, "Tomorrow's reminder");
    Reminder rem50(tomorrow_1, "Yesterday's old reminder");
    Reminder rem301(today, "today's second reminder");
    Reminder rem302(today,"today's third reminder");
    Reminder rem303(today, "today's fourth reminder");

    if (cal.findRem(d1) != -1){
        std::cout<<"Find rem returned an index with no reminders."<<std::endl;
    }

    cal.addRem(rem1);

    if (cal.findRem(d1)!= 0){
        std::cout<<"The first and only reminder wasn't displayed at index 0."<<std::endl;
    }

    cal.addRem(rem2);

    if (cal.displayRem(cal.findRem(d1)) != rem2.toString()){
        std::cout<<"Find rem didn't show the latest reminder on the given index."<<std::endl;
    }

    if (cal.findRem("Who goes to college....") != -1){
        std::cout<<"finRem didn't return -1 when there were 0 reminder with the string"<<std::endl;
    }

    if (cal.findRem("First class on second day") != 0){
        std::cout<<"findRem didn't return index 0 for the only reminder with that string."
                 <<std::endl;
    }

    cal.addRem(rem3);

    if (cal.displayRem(cal.findRem("First class on second day")) != rem3.toString()){
        std::cout<<"findRem didn't display the first reminder at the specified index."
                 <<std::endl;
    }

    if (cal.deleteRem() != 3){
        std::cout<<"deleterem didn't delete all the reminder earlier than today."<<std::endl;
    }

    if (cal.getNumRem() != 0){
        std::cout<<"Reminder exist after using delete rem and deleting every reminder."
                 <<std::endl;
    }

    cal.addRem(rem10);
    cal.addRem(rem30);


    if (cal.deleteRem() != 1){
        std::cout<<"delete rem deleted a reminder that was today"<<std::endl;
    }
    if (cal.displayRem(0) != rem30.toString()){
        std::cout<<"The reminders weren't moved down in the array to fill vacated space"
                 <<std::endl;
    }

    cal.deleteRem(0);

    if(cal.deleteRem() != 0){
        std::cout<<"delete rem shouldn't have deleted reminders in empty calenedar"<<std::endl;
    }

    cal.addRem(rem10);
    cal.addRem(rem30);
    cal.addRem(rem20);
    cal.addRem(rem40);

    if (cal.getRem(3) != rem40){
        std::cout<<"reminder wasn't added on the 3 index (0 indexing)."
                 <<std::endl;
    }
    if (cal.deleteRem() != 2){
        std::cout<<"reminders older than today weren't deleted"<<std::endl;
    }
    if (cal.displayRem(1) != rem40.toString()){
        std::cout<<"reminder wasn't moved down the array to fill vacated after deletion"
                 <<std::endl;
    }

    if (cal.deleteRem(4) != 0 or cal.getNumRem() != 2){
        std::cout<<"deleteRem at the wrong index didn't return 0 or deleted a reminder"
                 <<std::endl;
    }

    if (cal.deleteRem(0) != 1){
        std::cout<<"deleteRem index didn't delete the reinder at the index provided"<<std::endl;
    }

    if (cal.displayRem(0) != rem40.toString()){
        std::cout<<"After deleting an earlier index, the array didn't move down to vacated location"
                 <<std::endl;
    }
    cal.deleteRem(0);

    cal.addRem(rem10);
    cal.addRem(rem30);
    cal.addRem(rem20);
    cal.addRem(rem50);
    cal.addRem(rem40);

    if (cal.deleteRem("howdy brotha!!! HEEEHAWWW!! DONKEYYYYY") != 0){
        std::cout<<"delteRem with string didn't return 0 when there was no matching string."
                 <<std::endl;
    }

    if (cal.deleteRem("Yesterday's old reminder") != 3){
        std::cout<<"deleteRem didn't delete all the reminders with the phrase chosen."
                 <<std::endl;
    }

    if (cal.displayRem(0) != rem30.toString()){
        std::cout<<"deleteRem didn't vacate empty spots on the array after deletion."<<std::endl;
    }

    if (cal.displayRem(1) != rem40.toString()){
        std::cout<<"delteRem didn't move array down after deletion."<<std::endl;
    }

    if (cal.displayRem(4) == rem50.toString()){
        std::cout<<"the value of the index after deletion wasn't deleted (moved down)"<<std::endl;
    }

    cal.addRem(rem10);
    cal.addRem(rem20);
    cal.addRem(rem50);

    if (cal.deleteRem("yesterday's old reminder") != 0){
        std::cout<<"deleteRem deleted ignoring the case sensitivity of the reminder string."
                 <<std::endl;
    }

    if (cal.deleteRem("today's reminder") != 1){
        std::cout<<"deleteRem didn't delete the string reminder."<<std::endl;
    }

    if (cal.displayRem(2) == rem30.toString() or cal.displayRem(2) != rem40.toString()){
        std::cout<<"after deletion the reminder wasn't moved or relocated one below."<<std::endl;
    }

    if (cal.deleteRem(rem3) != 0){
        std::cout<<"delete rem didn't return 0 while deleting a non existent reminder"
                 <<std::endl;
    }

    cal.addRem(rem50);
    cal.addRem(rem50);
    cal.addRem(rem50);

    if (cal.deleteRem(rem50) != 4){
        std::cout<<"deleteRem didn't delete all occurrences of the reminder"<<std::endl;
    }

    if (cal.displayRem(6) != ""){
        std::cout<<"after deleting rem with reminder, the reminders weren't removed."<<std::endl;
    }

    if (cal.deleteRem(rem10)!=1){
        std::cout<<"deleteRem wiht reminder didn't delete at index 0."<<std::endl;
    }

    if (cal.displayRem(0)!= rem20.toString()){
        std::cout<<"delete rem didn't move all the reminders 1 index down to fill vacate spot"
                 <<std::endl;
    }

    cal.deleteRem(0);
    cal.deleteRem(0);

    cal.addRem(rem10);
    cal.addRem(rem20);
    cal.addRem(rem50);
    cal.addRem(rem30);
    cal.addRem(rem40);

    cal.deleteRem(rem20);
    cal.deleteRem(rem40);

    if (cal.displayRem(2) != rem50.toString() and cal.displayRem(1)!= rem30.toString()){
        std::cout<<"deleting reminder from two seperate indeces using rem, array didn't shift down."
                 <<std::endl;
    }

    if (cal.deleteRem(today+3)!= 0){
        std::cout<<"deleteRem with date didn't return 0 when deleting a non-existent reminder"
                 <<std::endl;
    }
    cal.addRem(rem301);
    cal.addRem(rem302);
    cal.addRem(rem303);
    cal.addRem(rem30);

    if (cal.deleteRem(today)!= 5){
        std::cout<<"deleteRem with date couldn't remove all the reminder."<<std::endl;
    }

    if (cal.displayRem(1)!=rem50.toString()){
        std::cout<<"deleteRem with date didn't shift the reminders down."<<std::endl;
    }


    cal.addRem(rem301);
    cal.addRem(rem302);
    cal.addRem(rem303);
    cal.addRem(rem30);
    cal.addRem(rem20);

    if(cal.deleteRem(today+4,today+6) != 0){
        std::cout<<"deleteRem with range didn't return when given range with no reminders"
                 <<std::endl;
    }

    if(cal.getNumRem()!= 7){
        std::cout<<"deleteRem with range deleted a reminder while given a false range."
                 <<std::endl;
    }

    if ((cal.deleteRem(yesterday_2, today) != 6 or
         cal.deleteRem(yesterday_2, today) == 5 or
         cal.deleteRem(yesterday_2,today) == 2 or
         cal.deleteRem(yesterday_2,today) == 1)){
        std::cout<<"delete rem with range didn't delete all the reminders in range."
                   "or it didn't include the end values."<<std::endl;
    }

    if(cal.displayRem(0)!=rem50.toString()){
        std::cout<<"deleteRem with range didn't shift all the values to vacated spots"
                 <<std::endl;
    }

    if (cal.getNumRem() != 1){
        std::cout<<"deleterem with range didn't delete all the rem in range."<<std::endl;
    }
}

void loop_test(){

    Calendar a;
    Calendar b;
    Calendar c;
    Calendar d;
    Calendar e;
    Calendar f;
    Calendar g;
    Calendar h;
    Calendar i;

    Date d1("01/18/2022");
    Date d2("01/02/2022");
    Date today;
    Date tomorrow(today+1);
    Date yesterday_1(today-1);
    Date yesterday_2(today-2);
    Date tomorrow_1(today+2);

    Reminder rem1(d1, "Second day of classes");
    Reminder rem2(d1, "First class on second day");
    Reminder rem3(d2, "First class on second day");
    Reminder rem10(yesterday_1, "Yesterday's old reminder");
    Reminder rem20(yesterday_2, "Yesterday's old reminder");
    Reminder rem30(today,"today's reminder");
    Reminder rem40(tomorrow, "Tomorrow's reminder");
    Reminder rem50(tomorrow_1, "Yesterday's old reminder");
    Reminder rem301(today, "today's second reminder");
    Reminder rem302(today,"today's third reminder");
    Reminder rem303(today, "today's fourth reminder");

    if (
            a.getNumRem() != 0 or
            b.getNumRem() != 0 or
            c.getNumRem() != 0 or
            d.getNumRem() != 0 or
            e.getNumRem() != 0 or
            f.getNumRem() != 0 or
            g.getNumRem() != 0 or
            h.getNumRem() != 0 or
            i.getNumRem() != 0){
        std::cout<<"New calendar created class has more than 0 reminders."<<std::endl;
    }

    for (int x = 0; x < 50; x++) {
        a.addRem(rem1);
    }

    for (int y = 0; y < 50; y++) {
        if (a.displayRem(y) != rem1.toString()){
            std::cout<<"reminder wasn't added at every index"<<std::endl;
        }
    }

    for (int z = 49; z >= 0; z--) {
        if (a.deleteRem(z) != 1){
            std::cout<<"reminder wasn't deleted from the specified index."<<std::endl;
        }
    }

    if (a.getNumRem() != 0){
        std::cout<<"delete rem index failed to delete at all indeces."<<std::endl;
    }

    for (int x = 0; x < 25; x++) {
        a.addRem(rem1);
    }
    for (int x = 0; x < 25; x++) {
        a.addRem(rem3);
    }

    std::string l;

    for (int x = 0; x < 25; x++) {
        l = l + rem3.toString() + '\n';
    }

    for (int x = 0; x < 25; x++) {
        l = l + rem1.toString() + '\n';
    }

    if (a.toString() != l){
        std::cout<<"String didn't print all reminders sorted on calendar with newline."<<std::endl;
    }

    if (a.displayRem(0) != rem3.toString()){
        std::cout<<"It should follow 0 based indexing. It didn't print reminder at idx0"<<std::endl;
    }
    if (a.displayRem(49) != rem1.toString()){
        std::cout<<"It didn't print reminder at idx 49"<<std::endl;
    }
    if (a.displayRem(24) != rem3.toString()){
        std::cout<<"It didn't print reminder at middle index."<<std::endl;
    }

    if (a.displayRem(50) != ""){
        std::cout<<"at invalid indeces it display rem should be empty."<<std::endl;
    }

    if (a.displayRem("lolololol") != ""){
        std::cout<<"with no reminder string an empty string wasn't printed."<<std::endl;
    }
    for (int x = 0; x < 25; x++) {
        a.deleteRem(rem3);
    }

    if (a.getRem(24) != rem1){
        std::cout<<"after deleting reminder with rem it wasn't sorted."<<std::endl;
    }

    if (a.displayRem(25) != ""){
        std::cout<<"after deleting reminder, reminder is still there"<<std::endl;
    }

    for (int x = 0; x < 25; x++) {
        a.addRem(rem3);
    }

    if (a.deleteRem("First class on second day")!= 25){
        std::cout<<"all reminder weren't deleted from the calendar with the string"<<std::endl;
    }
    if (a.displayRem(25) != ""){
        std::cout<<"after deleting reminder, reminder is still there"<<std::endl;
    }

    for (int x = 0; x < 25; x++) {
        a.addRem(rem3);
    }

    if (a.deleteRem(d2)!= 25){
        std::cout<<"all reminder weren't deleted from the calendar with the date"<<std::endl;
    }
    if (a.getRem(24) != rem1){
        std::cout<<"after deleting reminder with rem it wasn't sorted."<<std::endl;
    }
}


void new_tests() {
    Calendar a;

    Date d1("01/18/2022");

    Reminder rem1(d1, "Second day of classes");
    Reminder rem2(d1, "First class on second day");


    a.addRem(rem1);
    a.addRem(rem2);
    std::cout << a.getRem(0) << std::endl;
    std::cout << a.getRem(1) << std::endl;
}

int main() {
    // Here is some sample code that does some simple testing of the Calendar class.
    // It creates an empty Calendar and performs some test on it.
    // It then adds a Reminder to the Calendar and performs some other tests on it.
    // This is only a simple sample, and is not considered to be very thorough.


    Calendar cal1;   // create an empty Calendar object via default ctor

    if (cal1.getNumRem() != 0) {  // test getNumRem()
        std::cout << "Default ctor failed to create an empty calendar" << std::endl;
        std::cout << "Reported that " << cal1.getNumRem() << " reminders exist" << std::endl;
    }

    if (cal1.toString() != "") {  // test toString()
        std::cout << "Default ctor should produce an empty calendar" << std::endl;
        std::cout << "toString returned the following reminders: " << cal1.toString() << std::endl;
    }


    Date d1("01/17/2022");
    Reminder rem1(d1, "First day of classes");

    size_t index = cal1.addRem(rem1);   // test addRem(); Calendar now has one Reminder


    if (index != 0) {
        std::cout << "addRem failed to return index 0 for first insertion" << std::endl;
        std::cout << "Returned index == " << index << std::endl;
    }

    if (cal1.getNumRem() != 1) {
        std::cout << "addRem/getNumRem failed after inserting one reminder" << std::endl;
        std::cout << "Reported that " << cal1.getNumRem() << " reminders exist"
                  << std::endl;
    }

    if (cal1.toString() != "On 01/17/2022: First day of classes\n") {
        std::cout << "Unexpected reminder in calendar" << std::endl;
        std::cout << "toString returned the following reminders: " << cal1.toString() << std::endl;
    }

    if (cal1.displayRem(index) != "On 01/17/2022: First day of classes") {
        std::cout << "Unexpected reminder in calendar" << std::endl;
        std::cout << "displayRem returned the following reminders: "
                  << cal1.displayRem(index) << std::endl;
    }


    // Add all your code here to fully test the Calendar class.
    // You can define helper functions if it would make your job easier or make
    // this file cleaner.

    Date d2("01/18/2022");
    Reminder rem2(d1, "Second day of classes");

    Date d3("01/19/2022");
    Reminder rem3(d1, "Third day of classes");


    cal1.addRem(rem2);
    cal1.addRem(rem3);


    if (cal1.getNumRem() != 3) {
        std::cout << "addRem/getNumRem failed after inserting one reminder" << std::endl;
        std::cout << "Reported that " << cal1.getNumRem() << " reminders exist"
                  << std::endl;
    }

    for (int i = 0; i < 47; i++) {
        cal1.addRem(rem1);
    }

    if (cal1.getNumRem() != 50) {
        std::cout << "addRem/getNumRem failed after inserting one reminder" << std::endl;
        std::cout << "Reported that " << cal1.getNumRem() << " reminders exist"
                  << std::endl;
    }

    // Here is an example of using a try-catch block to test exception throwing.
    // You place your code that should generate an exception in the "try" block, and you
    // specify the exception you are catching in the "catch" expression. If an exception is
    // thrown, control will branch immediately to the "catch" block. If an exception is not
    // thrown, the "try" block will fully execute and then control goes to whatever follows
    // the try-catch block.
    // Experiment: change the number of iterations of the loop and observe the behavior.
    // Try 10 & 100.
    try {
        for (int i = 0; i < 20; i++) { // attempt to insert 70 reminders (max is 50)
            cal1.addRem(rem1);
        }
        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn overflow exception was not thrown!!" << std::endl;
    }
    catch (std::overflow_error &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }
    add_rem_test_get_test();
    to_string_test();
    display_rem_test();
    find_rem_del_test();
    loop_test();
    extra_test();
    //new_tests();

// uncomment the following lines if you are running the program in a
// DOS or terminal window and you want the window to stay open when
// the testing is done.
//	std::cout << "\nEnd of tests. Press enter to exit.";
//	char tt;
//	tt = std::cin.get();

}
