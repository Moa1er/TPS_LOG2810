/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

//trie.cpp

#include "../include/trie.h"
#include "../include/node.h"

//TODO: insert attributes in child node (item) after each insertion/read

void Trie::insert(string data) //constructions trie tree structure
{
    Node* tmp = root;
    char cstr[data.length()];

    data.copy(cstr, data.length()); //create char array containing data from string object
    for (int i = 0; i < data.length(); i++)
    {
        if (tmp->child[static_cast<int>(cstr[i])] != NULL) //walk ptr through struct, preventing duplicate nodes (prefix)
            tmp = tmp->child[static_cast<int>(cstr[i])];
        else
        {
            tmp->child[static_cast<int>(cstr[i])] = new Node(); //create new node
            tmp = tmp->child[static_cast<int>(cstr[i])];
            tmp->setChar(cstr[i]); //insert char in new node
        }
    }
    tmp->setWord(true); //mark word
}

void Trie::print_tree(Node* root, string data, string str) //method that prints query options to completing the prefix
{
    for (int i = 0; i < 128; i++) //loops through all 128 pointers in node to check if there's a child
    {
        Node* adv = root;
        if (adv->child[i] != NULL) //child exists
        {
            adv = adv->child[i]; //advance pointer
            str += adv->getChar(); //append char to end of prefix
            if (adv->isWord()) //if point at end of word, print word
            {
                cout << str << endl;
            }
            print_tree(adv, str); //recursive call to keep moving down tree
        }
        str = data; //reset prefix string
    }
}

void Trie::print_tree(Node* root, string str) //overloaded function for recursive calls
{
    string str_tmp = str;

    for (int i = 0; i < 128; i++)
    {
        Node* adv = root;
        if (adv->child[i] != NULL)
        {
            adv = adv->child[i];
            str += adv->getChar();
            if (adv->isWord())
            {
                cout << str << endl;
            }
            print_tree(adv, str);
        }
        str = str_tmp;
    }
}

void Trie::search(string data) //wrapper for function that completes the prefix, generating search options
{
    Node* tmp = root;
    char cstr[data.length()];

    data.copy(cstr, data.length(), 0);
    for (int i = 0; i < data.length(); i++) //for loop advances point through tree structure stopping at node containing last char in user's search prefix
    {
        if (tmp->child[static_cast<int>(cstr[i])] == NULL) //lets user know if prefix not in dictionary (next char not a child)
        {
            cout << "error:  string not found" << endl;
            return;
        }
        else
            tmp = tmp->child[static_cast<int>(cstr[i])];
        if (tmp->getChar() != cstr[i]) //lets user know if prefix not in dictionary (char does not match corresponding char in prefix)
        {
            cout << "error:  string not found" << endl;
            return;
        }
    }
    string str = data; //copy user's query prefix into generic string used for appending operations to complete query prefix in print_tree method
    print_tree(tmp, data, str);	//passes pointer that has advanced to last char in query prefix to printing method
}