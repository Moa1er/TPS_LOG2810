#include "../include/partie2.h"

#include <iostream>
#include <string>

using namespace std;

void partie2(){
    char valeurEntree;
    bool estDChoisie = false;
    bool estAChoisie = false;

    string nomFichierLexique;
    
    while(!estDChoisie){
        cout << "\n(d) Créer automate.\n(e) Saisir mot.\n(f) Afficher statistiques.\n(g) Quitter\n";
        cout << "Entree l'option voulue ( d, e, f, g ) : ", cin >> valeurEntree;

        switch (valeurEntree)
        {
            case 'd':
                //Creer AUTOMATE
                break;
            case 'e':
                if(estAChoisie){}
                    //SAISIR MOT
                else
                    cout << endl << "Il faut d'abord choisir l'option d pour creer l'automate !" << endl;
                break;
            case 'f':
                if(estAChoisie){
                    //AFFICHER STATISTIQUES
                }
                else
                    cout << endl << "Il faut d'abord choisir l'option d pour creer l'automate !" << endl;
                break;
            case 'g':
                estDChoisie = true;
                break;
            default:
                cout << "\nCette option n'existe pas ! Les options existantes sont ( d, e, f, g ) !\n";
                break;
        }
    }
}