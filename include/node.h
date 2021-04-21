/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

//

#include <string>
#include <iostream>
using namespace std;
#ifndef NODE_H
#define NODE_H

class Node //node used to hold data in trie tree structure
{
    friend class Trie;
private:
    char character;
    int recent, usage;
    bool endOfWord; //true = marks end of word
    Node* child[128]; //points to next node; each pointer for each char in ASCII table (0-127)
public:
    Node();
    ~Node() {}
    void setWord(bool endOfWord);
    bool isWord();
    void setChar(char character);
    char getChar() const;
    void usageIncrement();
};

#endif