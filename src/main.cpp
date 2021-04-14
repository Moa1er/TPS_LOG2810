#include <iostream>
#include <string>
#include <fstream>

#include "../include/partie1.h"
#include "../include/partie2.h"

using namespace std;

int main(){
    char valeurEntree = ' ';
    bool estDChoisie = false;

    while(!estDChoisie){
        cout << "\n(a) Alerte COVID\n(b) Jeu Instructif\n(c) Quitter\n";
        cout << "Entree l'option voulue ( a, b, c ) : ", cin >> valeurEntree;
        switch (valeurEntree)
        {
            case 'a':
                partie1();
                break;
            case 'b':
                partie2();
                break;
            case 'c':
                estDChoisie = true;
                break;
            default:
                cout << "\nCette option n'existe pas ! Les options existantes sont ( a, b, c ) !\n";
                break;
        }
    }

    cout << "\nFIN DU PROGRAMME !\n";   
}