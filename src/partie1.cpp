#include <iostream>
#include <fstream>
#include <string>    
#include "../include/partie1.h"
#include <sstream>
#include <list>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;


struct Personne{
    string name;
    char diagnostique;
};

vector<Personne> personnes;

vector<string> split (string s, char delimiter) {
    size_t pos_start = 0, pos_end, delim_len = 1;
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

void trimRight(string &str)
{
	if (str.empty())
		return;
 
	string::const_iterator ch = str.end() - 1;
	while (' ' == *ch || '\r' == *ch || '\n' == *ch || '\t' == *ch || '\f' == *ch)
	{
		str.erase(str.find_last_not_of(*ch) + 1);
		ch = str.end() - 1;
	}
}

double** creerGrapheExposition(string nomFichierIndividus, string nomFichierContacts){

    //A DECOMMENTER PLUS TARD
    //ifstream fluxIndividus(nomFichierIndividus + ".txt");
    //ifstream fluxContacts(nomFichierContacts + ".txt");    
    

    ifstream fluxIndividus("Individus.txt");
    ifstream fluxContacts("Contacts.txt");

    if(!fluxIndividus){
        cout << "Fichiers individus mal ouvert, retour au menu." << endl;
        return nullptr;
    }
    else if(!fluxContacts){
        cout << "Fichiers contacts mal ouvert, retour au menu." << endl;
        return nullptr;
    }

    cout << "Fichiers ouverts\n";

    

    string ligne;
    Personne personne;

    char delimiteurIndividus = ',';
    char delimiteurContacts = ' ';


    //Get tout les individus et en fait un vecteur de Personne
    while(getline(fluxIndividus, ligne)){
        vector<string> ligneCoupe = split(ligne, delimiteurIndividus);
        personne.name = ligneCoupe[0];
        personne.diagnostique = ligneCoupe[1][0]; //index 0 car on veut juste le chiffre

        personnes.push_back(personne);
    }


    int nbPersonnes = personnes.size();

    double **edgesOfGraph = new double*[nbPersonnes];
    for(int i = 0; i < nbPersonnes; i++){
        //On initialise toute les valeurs à zero sinon on a des problèmes par la suite
        edgesOfGraph[i] = new double[nbPersonnes]{{0}};
    }


    string personneFrom;
    string personneTo;
    double distance;
    
    while(getline(fluxContacts, ligne)){
        
        vector<string> v = split(ligne, delimiteurContacts);
        personneFrom = v[0];
        distance = std::stod(v[1]);
        personneTo = v[2];
        
        //On enleve les charactères invisibles de la fin du string
        trimRight(personneTo);

        int indexPersonneFrom(0);
        int indexPersonneTo(0);
        //On cherche l'index de la personne
        for(int i = 0; i < personnes.size() && (indexPersonneFrom == 0 || indexPersonneTo == 0) ; i++){
            if(personnes[i].name == personneFrom)
                indexPersonneFrom = i;
                
            if(personnes[i].name == personneTo)
                indexPersonneTo = i;
        }
        //cout << "PersonneFrom : " << indexPersonneFrom << "   PersonneTo : " << indexPersonneTo << "   Weight : " << distance << endl;
        edgesOfGraph[indexPersonneFrom][indexPersonneTo] = distance;
        edgesOfGraph[indexPersonneTo][indexPersonneFrom] = distance;
    }

    // cout << endl << "tableau : " << endl;
    // for(int i = 0; i < nbPersonnes; i ++){
    //     for(int j = 0; j < nbPersonnes; j++){
    //         cout << edgesOfGraph[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    return edgesOfGraph;
}

void afficherGrapheExposition(double** graph){
    cout << "Option b\n";
    cout << endl << "GrapheExposition : " << endl;
    int nbIndividus = personnes.size();

    for(int i = 0; i < nbIndividus; i ++){
        for(int j = 0; j < nbIndividus; j++){
            if(graph[i][j] != 0)
                cout << "(" << personnes[i].name << " " << personnes[j].name << " (" << graph[i][j] << "))" << endl;
        }
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
    double** graph;

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
                //A DECOMMENTER
                //cout << "Entree le nom du fichier regroupant les individus : ", cin >> nomFichierIndividus;
                //cout << "Entree le nom du fichier regroupant les contacts : ", cin >> nomFichierContacts;
                graph = creerGrapheExposition(nomFichierIndividus, nomFichierContacts);
                estAChoisie = true;
                break;
            case 'b':
                if(estAChoisie)
                    afficherGrapheExposition(graph);
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