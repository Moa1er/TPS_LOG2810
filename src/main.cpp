#include <iostream>
#include <string>
#include <fstream>

#include "../include/partie1.h"
#include "../include/partie2.h"

using namespace std;

int main(){
    partie1();
    string const nomFichier("../Individus.txt");
    ofstream monFlux(nomFichier.c_str());

    if(monFlux)    
    {
        
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }
    return 0;
}