// File name: TrieNode.cpp
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file implements the TrieNode class used to build the functions of Trie class.
// Last Changed: 4/29/2022

#include "iostream"
#include "TrieNode.h"

//TrieNode Default Constructor
//post: creates a base node with blank char and false flag with pointer arrays.
TrieNode::TrieNode(char c, bool b) : word(c),
                                     flag(b)
{
    for (size_t i = 0; i < NUM_LETTERS; i++){
        letterArr[i] = nullptr;
    }
}


//The Copy Constructor
//Pre: class object, TrieNode exists.
//Post: object is initialized to be a copy of the parameter
TrieNode::TrieNode(const TrieNode &rhs) : word(rhs.word),
                                          flag(rhs.flag){
    for (size_t i = 0; i < NUM_LETTERS; i++){
        if (rhs.letterArr[i] != nullptr){
            letterArr[i] = new TrieNode(*rhs.letterArr[i]);
        }
        else {
            letterArr[i] = nullptr;
        }
    }
}

//The Destructor
//destroys a TrieNode
//pre: TrieNode object exists
//post: TrieNode object doesn't exist
TrieNode::~TrieNode() {
    for (size_t i = 0; i < NUM_LETTERS; i++){
        if (letterArr[i] != nullptr){
            delete letterArr[i];
            letterArr[i] = nullptr;
        }
    }
}

//Assignment operator
//Assigns a TrieNode to another
//pre: both TrieNode object exist
//post:this TrieNode object gets assigned a copy of the parameter class object
const TrieNode &TrieNode::operator=(const TrieNode &rhs) {
    if (this != &rhs) {
        TrieNode tmp(rhs);
        std::swap(word, tmp.word);
        std::swap(flag, tmp.flag);
        std::swap(letterArr, tmp.letterArr);
    }
    return *this;
}

//insert
//inserts a string into the Trie object
//pre: Trie object exists
//post: the given string has been added to Trie object
void TrieNode::insert(const std::string &str) {

    size_t length = str.length();

    if (length == 0){
        flag = true;
        return;
    }

    char inLex = tolower(str[0]);
    size_t index = inLex - 'a';

    if (letterArr[index] == nullptr){
        letterArr[index] = new TrieNode(str[0],false);
    }

    letterArr[index]->insert(str.substr(1,length-1));

}

//isWord
//checks if the word exists in the Lexicon
//Pre: Trie object exists
//post: returns boolean value based on if the string exists in the Lexicon
bool TrieNode::isWord(const std::string &str) const {
    size_t length = str.length();

    if (length == 0){
        return flag;
    }

    char inLex = tolower(str[0]);
    size_t index = inLex - 'a';

    if (letterArr[index] == nullptr){
        return false;
    }

    return letterArr[index]->isWord(str.substr(1,length-1));

}

//isPrefix
//checks if the prefix exists in the Lexicon
//Pre: Trie object exists
//post: returns a boolean value based on if the prefix exists in the Lexicon
bool TrieNode::isPrefix(const std::string &pre) const {
    size_t length = pre.length();

    if (length == 0){
        return true;
    }

    char inLex = tolower(pre[0]);
    size_t index = inLex - 'a';

    if (letterArr[index] == nullptr){
        return false;
    }

    return letterArr[index]->isPrefix(pre.substr(1,length-1));
}

//print
//Prints all the words in Lexicon to the terminal
//pre:Trie object exists.
//post: all the strings in the lexicon are printed to the terminal
void TrieNode::print(const std::string &str) const {
    if (flag){
        std::cout<<str << word<< std::endl;
    }

    for (size_t i = 0; i < NUM_LETTERS; i++){
        if (letterArr[i] != nullptr) {
            std::string ans = str;
            letterArr[i]->print(ans + word);
        }
    }
}

//wordCount
//computes the number of string in the TrieNode object
//Pre: TrieNode object exists
//post:returns number of words in the Lexicon
size_t TrieNode::wordCount() const {
    size_t count = 0;
    if (flag){
        count = 1;
    }
    for (size_t i = 0; i < NUM_LETTERS; i++){
        if (letterArr[i] != nullptr){
            count += letterArr[i]->wordCount();
        }
    }
    return count;
}

