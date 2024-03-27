// File name: TrieNode.h
// Author: Ayush Pathak
// userid: pathaa3
// Email: ayush.pathak@vanderbilt.edu
// Class: CS2201
// Assignment Number: PA 10
// Honor Statement: "I have been abided by Vanderbilt honor code in completion of this assignment"
// Description:  This file defines the TrieNode class used to build Trie class.
// Last Changed: 4/29/2022

#ifndef PROJECT9_TRIENODE_H
#define PROJECT9_TRIENODE_H
#include <string>


const size_t NUM_LETTERS = 26; // number of alphabets, used multiple times


typedef char ItemType;
class TrieNode
{

    typedef TrieNode* TrieNodePtr;

private:

    ItemType word; // char that is stored in one node
    bool flag;   // marks if the current node ends a string stored
    TrieNodePtr letterArr[26];  // Pointer arrays pointing to the successive node of the string.

public:
    //TrieNode Default Constructor
    //post: creates a base node with blank char and false flag with pointer arrays.
    TrieNode (char c, bool b);

    //The Copy Constructor
    //Pre: class object, TrieNode exists.
    //Post: object is initialized to be a copy of the parameter
    TrieNode(const TrieNode& rhs);

    //The Destructor
    //destroys a TrieNode
    //pre: TrieNode object exists
    //post: TrieNode object doesn't exist
    ~TrieNode( );

    //Assignment operator
    //Assigns a TrieNode to another
    //pre: both TrieNode object exist
    //post:this TrieNode object gets assigned a copy of the parameter class object
    const TrieNode& operator= (const TrieNode& rhs);

    //insert
    //inserts a string into the Trie object
    //pre: Trie object exists
    //post: the given string has been added to Trie object
    void insert (const std::string& str);

    //isWord
    //checks if the word exists in the Lexicon
    //Pre: Trie object exists
    //post: returns boolean value based on if the string exists in the Lexicon
    bool isWord (const std::string& str) const;

    //isPrefix
    //checks if the prefix exists in the Lexicon
    //Pre: Trie object exists
    //post: returns a boolean value based on if the prefix exists in the Lexicon
    bool isPrefix (const std::string& pre) const;

    //print
    //Prints all the words in Lexicon to the terminal
    //pre:Trie object exists.
    //post: all the strings in the lexicon are printed to the terminal
    void print (const std::string& str) const;

    //wordCount
    //computes the number of string in the TrieNode object
    //Pre: TrieNode object exists
    //post:returns number of words in the Lexicon
    size_t wordCount ( ) const;

};


#endif //PROJECT9_TRIENODE_H
