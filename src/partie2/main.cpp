/******************************************
Mohamed Fenjiro <mohamed.fenjiro@polymtl.ca>
 ******************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "trie.hpp"
#include "items.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    string name, type, id, line;
    fstream inventaire;
    Trie queryName, queryType, queryId;
    
    inventaire.open("Lexique.txt", fstream::in); //read inventaire file into trie tree structure

    //TODO: do this for each attributes

    if (inventaire.is_open())
    {
        while (getline(inventaire, line) && line != "")
        {
            stringstream ss(line);
            ss >> name;
            ss.ignore();
            ss >> id;
            ss.ignore();
            ss >> type;
            queryName.insert(name);
            queryId.insert(id);
            queryType.insert(type);
        }
    }
    else
    {
        cout << "error:  file not open." << endl;
        return -1;
    }
    inventaire.close();

    string enteredLetter;
    cout << "Enter search query (end the search by typing ';') : " << endl << "Mot : ";
    while(true){
        enteredLetter += cin.get();
        if(enteredLetter[enteredLetter.size() - 1] == ';')
            break;
        cin.ignore(256, '\n');
        queryName.search(enteredLetter);
        cout << endl << "Mot : " << enteredLetter;
    }
    return 0;
}