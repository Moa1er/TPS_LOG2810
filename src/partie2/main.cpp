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
    id.clear(); //clear string variable used for file input; string variable will read in user input
    cout << "enter search query:" << endl;
    cin >> id;
    cout << "your search options are:  " << endl;
    queryName.search(id);
    return 0;
}