#include <iostream>
#include <fstream>
#include <string>    
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>

#include "../include/partie1.h"
#include "../include/Personne.h"
#include "../include/Graph.h"
#include "../include/StringOperations.h"


using namespace std;

Graph graph = Graph();
Personnes personnes;

void creerGrapheExposition(string nomFichierIndividus, string nomFichierContacts){
    ifstream fluxIndividus(nomFichierIndividus + ".txt");
    ifstream fluxContacts(nomFichierContacts + ".txt");

    if(!fluxIndividus){
        cout << "Fichiers individus mal ouvert, retour au menu." << endl;
        return;
    }
    else if(!fluxContacts){
        cout << "Fichiers contacts mal ouvert, retour au menu." << endl;
        return;
    }

    cout << "Fichiers ouverts\n";

    string ligne;
    Personne personne;
    char delimiteurIndividus = ',';
    char delimiteurContacts = ' ';
    StringOperations operationsObject;

    // ON STOCKE TOUS LES INDIVIDUS
    while(getline(fluxIndividus, ligne)){
        vector<string> ligneCoupe = operationsObject.split(ligne, delimiteurIndividus);
        personne.name_ = ligneCoupe[0];
        personne.diagnostique_ = ligneCoupe[1][0]; //index 0 car on veut juste le chiffre

        personnes.addPersonne(personne);
    }

    personnes.setNbPersonnes(personnes.getPersonnes().size());

    graph.setNbVectices(personnes.getNbPersonnes());
    graph.setList(personnes.getNbPersonnes());

    string personneFrom;
    string personneTo;
    double distance;
    
    // ON STOCKE TOUS LES CONTACTS
    while(getline(fluxContacts, ligne)){
        
        vector<string> v = operationsObject.split(ligne, delimiteurContacts);
        personneFrom = v[0];
        distance = std::stod(v[1]);
        personneTo = v[2];
        
        //On enleve les charactères invisibles de la fin du string
        operationsObject.trimRight(personneTo);

        int indexPersonneFrom(0);
        int indexPersonneTo(0);

        //On cherche l'index de la personne
        indexPersonneFrom = personnes.findIndex(personneFrom);
        indexPersonneTo = personnes.findIndex(personneTo);

        graph.addEdge(indexPersonneFrom, indexPersonneTo, distance);
        graph.addEdge(indexPersonneTo, indexPersonneFrom, distance);
    }
}

void afficherGrapheExposition(){
    graph.printGraph(personnes.getPersonnes());
}

bool identifierExposition(string origine, string destination){
    int indexPersonneFrom(0);
    int indexPersonneTo(0);

    //On cherche l'index de la personne
    indexPersonneFrom = personnes.findIndex(origine);
    indexPersonneTo = personnes.findIndex(destination);

    vector<double> djikstraOutput = graph.getDjikstraOut();

    for(int i = 0; i < personnes.getNbPersonnes(); i++){
        if(djikstraOutput[i] <= 2 && i == indexPersonneTo && personnes.getDiagnostique(i) == '1'){
            return true;
        }   
    }
    return false;
}

void notifierExposition(string nomPersonne){
    int indexPersonneFrom = personnes.findIndex(nomPersonne);
    bool isFound = false;

    graph.setDjikstraOutput(graph.shortestPath(indexPersonneFrom));

    for(int i = 0; i < personnes.getNbPersonnes(); i++){
        if(identifierExposition(nomPersonne, personnes.getName(i))){
            isFound = true;
            cout << endl << "Vous avez été exposé au cours des 14 derniers jours !" << endl;
            break;
        }
    }
    if(!isFound)
        cout << endl << "Aucune exposition détectée !" << endl; 
}

void partie1(){
    char valeurEntree;
    bool estAChoisie = false;
    bool estDChoisie = false;

    //option a
    string nomFichierIndividus, nomFichierContacts;

    //option c
    string nomPersonne;
    
    while(!estDChoisie){
        cout << "\n(a) Créer le graphe d’exposition.\n(b) Afficher le graphe d’exposition.\n(c) Afficher notification COVID\n(d) Quitter\n";
        cout << "Entree l'option voulue ( a, b, c, d ) : ", cin >> valeurEntree;

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
                else
                    cout << endl << "Il faut d'abord choisir l'option a pour creer le graph !" << endl;
                break;
            case 'c':
                if(estAChoisie){
                    cout << "Entree le nom de la personne à vérifier : ", cin >> nomPersonne;
                    notifierExposition(nomPersonne);
                }
                else
                    cout << endl << "Il faut d'abord choisir l'option a pour creer le graph !" << endl;
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