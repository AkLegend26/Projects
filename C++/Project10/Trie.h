// File name: Trie.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file defines the Trie ADT.
// Last Changed: 4/29/2022

#ifndef PROJECT9_TRIE_H
#define PROJECT9_TRIE_H
#include <string>
#include "TrieNode.h"

class Trie
{
private:
    TrieNode myRoot; // Root node

public:
    //Default Constructor
    //Creates an empty Trie Class with one node.
    Trie( );

    //insert (const std::string& word)
    //inserts a string into the lexicon implemented with Trie structure.
    //word is the parameter string that will be added to Lexicon.
    //Pre: The word is not in the Lexicon.
    //Post: The word parameter has been added to the Lexicon.
    void insert (const std::string& word);

    //loadFromFile
    //Opens all words from a specified file into the Trie.
    //throws an exception if the file couldn't be opened.
    //Pre: words from the file are not in the Trie
    //Post: words from the file are in the Trie
    void loadFromFile (const std::string& filename);

    //isWord
    //Checks if a word is in the Lexicon.
    //word is the parameter string that will be checked for being in Lexicon
    //Post: returns a bool value based on if string exists in the Lexicon
    bool isWord (const std::string& word) const;

    //isPrefix
    //checks if a prefix is in the Lexicon
    //pre is the parameter string that will be checked for being in Lexicon
    //Post: returns a bool value based on if string exists in the Lexicon
    bool isPrefix (const std::string& pre) const;

    //print
    //prints the words existing in the Lexicon to the screen
    //post: Words in the Lexicon are displayed in the terminal.
    void print ( ) const;

    //wordCount
    //displays the word count of the words in the Lexicon
    //post: returns the number of words in the Trie Lexicon
    size_t wordCount ( ) const;

};

#endif //PROJECT9_TRIE_H
