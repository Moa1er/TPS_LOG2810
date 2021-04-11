/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

//trie.h

#ifndef TRIE_H
#define TRIE_H

#include "node.hpp"

using namespace std;

class Trie
{
    friend class Node;
private:
    Node* root;
public:
    Trie() {root = new Node();}
    ~Trie() {}
    void insert(string data); //builds trie tree struction
    void search(string data); //wrapper for main auto-completion method; advances to last char in user's prefix
    void print_tree(Node* root, string data, string str); //prints suggested queries
    void print_tree(Node* root, string str); //overloaded print_tree method used for recursion
};

#endif