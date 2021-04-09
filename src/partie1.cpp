#include <iostream>
#include <fstream>
#include <string>    
#include "../include/partie1.h"
#include <sstream>
#include <list>
#include <vector>
using namespace std;
#define TAILLE_MAX 1000

vector<vector<string>> listeContacts;
void creerGrapheExposition(string nomFichierIndividus, string nomFichierContacts){
    cout << "Option a\n";
    ifstream fluxContacts("./"+ nomFichierContacts +".txt");     
    
    if(fluxContacts)  //On teste si tout est OK
    {   
        cout << "Fichier "+nomFichierContacts+".txt ouvert" << endl;
        string ligne;
        while(getline(fluxContacts, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {      
            string arr[3];
            int i = 0;
            stringstream ssin(ligne);
            vector<string> line ;
            while (ssin.good() && i < 3){
                ssin >> arr[i];
                line.push_back(arr[i]);
                ++i;
                
            }
            listeContacts.push_back(line);
            
        }
         
    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

}

void afficherGrapheExposition(){
     cout << "Option b\n";
    for(int h = 0 ; h<listeContacts.capacity(); h++){            
        cout << "(" +listeContacts.at(h).at(0)+" " + listeContacts.at(h).at(2) + " (" +listeContacts.at(h).at(1)+"))"<< endl;            
    }  
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