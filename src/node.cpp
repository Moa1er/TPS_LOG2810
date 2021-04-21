/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

//node.cpp

#include "../include/node.h"

Node::Node() //Node constructor
{
    this->setChar('\0');
    this->setWord(false);
    for (int i = 0; i < 128; i++)
        this->child[i] = nullptr;
    this->usage = 0;
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

void Node::usageIncrement()
{
    this->usage++;
}