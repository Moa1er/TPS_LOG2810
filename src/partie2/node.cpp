/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

//node.cpp

#include "node.hpp"

Node::Node() //Node constructor
{
    this->setChar('\0');
    this->setWord(false);
    for (int i = 0; i < 128; i++)
        this->child[i] = nullptr;
}

void Node::setWord(bool endOfWord)
{
    this->endOfWord = endOfWord;
}

bool Node::isWord()
{
    return this->endOfWord;
}

void Node::setChar(char character)
{
    this->character = character;
}

char Node::getChar() const
{
    return this->character;
}