// File name: Trie.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file implements the Trie class and its functions.
// Last Changed: 4/29/2022

#include "Trie.h"
#include "fstream"
#include "iostream"

//Default Constructor
//Creates an empty Trie Class with one node.
Trie::Trie():myRoot(TrieNode(' ', false)) {
}

//insert (const std::string& word)
//inserts a string into the lexicon implemented with Trie structure.
//word is the parameter string that will be added to Lexicon.
//Pre: The word is not in the Lexicon.
//Post: The word parameter has been added to the Lexicon.
void Trie::insert(const std::string &word) {
    myRoot.insert(word);
}

//loadFromFile
//Opens all words from a specified file into the Trie.
//throws an exception if the file couldn't be opened.
//Pre: words from the file are not in the Trie
//Post: words from the file are in the Trie
void Trie::loadFromFile (const std::string& filename){
    std::string str;

    std::ifstream infile;
    infile.open(filename);

    if (infile.fail()){
        throw std::invalid_argument("Specified file cannot be opened");
    }

    while (infile >> str){
        myRoot.insert(str);
    }
    infile.close();
}

//isWord
//Checks if a word is in the Lexicon.
//word is the parameter string that will be checked for being in Lexicon
//Post: returns a bool value based on if string exists in the Lexicon
bool Trie::isWord(const std::string &word) const {
    return myRoot.isWord(word);
}

//isPrefix
//checks if a prefix is in the Lexicon
//pre is the parameter string that will be checked for being in Lexicon
//Post: returns a bool value based on if string exists in the Lexicon
bool Trie::isPrefix(const std::string &pre) const {
    return myRoot.isPrefix(pre);
}

//print
//prints the words existing in the Lexicon to the screen
//post: Words in the Lexicon are displayed in the terminal.
void Trie::print() const {
    myRoot.print("");
}

//wordCount
//displays the word count of the words in the Lexicon
//post: returns the number of words in the Trie Lexicon
size_t Trie::wordCount() const {
    return myRoot.wordCount();
}
