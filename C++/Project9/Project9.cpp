// File name: Project9.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 9
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file tests the Trie class.
// Last Changed: 4/21/2022

#include "Trie.h"
#include <iostream>

int main(){

    Trie Yolo;

    if (Yolo.isWord("wow")){
        std::cout<< "It's not even in the lexicon"<<std::endl;
    }

    if (Yolo.isPrefix("pre")){
        std::cout<< "It's not even in the lexicon"<<std::endl;
    }

    std::cout<<Yolo.wordCount()<<std::endl;

    if (Yolo.wordCount() != 0){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }

    //Yolo.loadFromFile();

    Yolo.insert("what");

    if (!(Yolo.isWord("what"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    std::cout<<Yolo.wordCount()<<std::endl;



    Yolo.insert("o");
    if (Yolo.wordCount() != 2){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }
    Yolo.insert("ok");
    if (Yolo.wordCount() != 3){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }
    Yolo.insert("oko");
    if (Yolo.wordCount() != 4){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }
    Yolo.insert("o");
    if (Yolo.wordCount() != 4){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }
    Yolo.insert("ok");
    if (Yolo.wordCount() != 4){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }
    Yolo.insert("OK");
    if (Yolo.wordCount() != 4){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }

    Yolo.insert("ok");
    Yolo.insert("ok");
    Yolo.insert("ok");
    Yolo.insert("OK");
    if (Yolo.wordCount() != 4){
        std::cout<< "Word count is not working properly or insert"<<std::endl;
    }

    if (Yolo.isWord("wow")){
        std::cout<< "It's not even in the lexicon"<<std::endl;
    }

    if (!(Yolo.isWord("what"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    if (!(Yolo.isWord("o"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    if (!(Yolo.isWord("ok"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    if (!(Yolo.isWord("oko"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    if (Yolo.isWord("ok") == false){
        std::cout<<"we have it";
    }

    Yolo.insert("okoh");

    /*if (!(Yolo.isPrefix("oko"))){
        std::cout<<"prefix should be there"<<std::endl;
    }*/

    Yolo.insert("okyu");

    if (!(Yolo.isWord("okyu"))){
        std::cout<< "It's in the lexicon but not shown"<<std::endl;
    }

    if (!(Yolo.isPrefix("oky"))){
        std::cout<<"prefix should be there"<<std::endl;
    }

    if (!(Yolo.isPrefix("okyu"))){
        std::cout<<"prefix should be there"<<std::endl;
    }

    if ((Yolo.isPrefix("okyuo"))){
        std::cout<<"prefix should be there"<<std::endl;
    }

    std::cout<<Yolo.wordCount()<<std::endl;
    Trie Bolo;

    if (Bolo.wordCount() != 0){
        std::cout<<"error in Constructor or word count"<<std::endl;
    }

    if (!(Bolo.wordCount() != Yolo.wordCount())){
        std::cout<<"error in Constructor or word count"<<std::endl;
    }

    Bolo = Yolo;

    if ((Bolo.wordCount() == Yolo.wordCount())){
        std::cout<<"error in Constructor or word count"<<std::endl;
    }

    std::cout<<Yolo.wordCount()<<std::endl;
    std::cout<<Bolo.wordCount()<<std::endl;

    Yolo.print();
    Bolo.print();

    Bolo.loadFromFile("testsubject.txt");
    std::cout<<Bolo.wordCount()<<std::endl;
    try {
        Bolo.loadFromFile("pewpew.txt");
        std::cout << "\nTHIS MESSAGE SHOULD NOT BE SEEN."
                  << "\nAn overflow exception was not thrown!!" << std::endl;
    }
    catch (std::invalid_argument &excpt) {
        std::cout << "Exception successfully thrown & caught:: " << excpt.what()
                  << std::endl;
    }
    std::string zu = "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i<26; i++){
        Yolo.insert(zu);
    }
}