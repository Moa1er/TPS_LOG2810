#include <iostream>

#include "../include/partie1.h"

using namespace std;

void creerGrapheExposition(string nomFichierIndividus, string nomFichierContacts){
    cout << "Option a\n";
}

void afficherGrapheExposition(){
    cout << "Option b\n";
}

void identifierExposition(string origine, string destination){}

void notifierExposition(string nomPersonne){
    cout << "Option c\n";
}


void partie1(){
    char valeurEntree;
    bool estAChoisie = false;
    bool estDChoisie = false;

    //option a
    string nomFichierIndividus;
    string nomFichierContacts;

    //option c
    string nomPersonne;
    
    while(!estDChoisie){
        cout << "\n(a) Créer le graphe d’exposition.\n(b) Afficher le graphe d’exposition.\n(c) Afficher notification COVID\n(d) Quitter\n";
        cout << "Entree l'option voulue ( a, b, c, d) : ", cin >> valeurEntree;

        switch (valeurEntree)
        {
            case 'a':
                cout << "Entree le nom du fichier regroupant les individus : ", cin >> nomFichierIndividus;
                cout << "Entree le nom du fichier regroupant les contacts : ", cin >> nomFichierContacts;
                creerGrapheExposition(nomFichierIndividus, nomFichierContacts);
                estAChoisie = true;
                break;
            case 'b':
                if(estAChoisie)
                    afficherGrapheExposition();
                break;
            case 'c':
                if(estAChoisie){
                    cout << "Entree le nom de la personne à vérifier : ", cin >> nomPersonne;
                    notifierExposition(nomPersonne);
                }
                break;
            case 'd':
                estDChoisie = true;
                break;
            default:
                cout << "\nCette option n'existe pas ! Les options existantes sont ( a, b, c, d ) !\n";
                break;
        }
    }
}