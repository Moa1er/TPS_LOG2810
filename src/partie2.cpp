#include <iostream>
#include <fstream>
#include <sstream>

#include "../include/partie2.h"
#include "../include/trie.h"
#include "../include/StringOperations.h"

using namespace std;

Trie queryName, queryType, queryId;
StringOperations test;

void creerAutomate(string nomFichierLexique){
    string name, type, id, line;
    //fstream inventaire;

    //inventaire.open("Lexique.txt", fstream::in); //read inventaire file into trie tree structure
    ifstream inventaire(nomFichierLexique + ".txt");

    //TODO: do this for each attributes
    if (inventaire){
        while (getline(inventaire, line) && line != ""){

            //A quoi sert cette partie ?
            // stringstream ss(line);
            // ss >> name;
            // ss.ignore();
            // ss >> id;
            // ss.ignore();
            // ss >> type;
            // queryId.insert(id);
            // queryType.insert(type);

            queryName.insert(line);
        }
    }
    else{
        cout << "Erreur : fichier non-ouvert." << endl;
        return;
    }
    inventaire.close();
    cout << "Le lecture/écriture a bien été effectuée !" << endl;
    return;
}   

void saisirMot(){
    string enteredLetter;
    cout << "Enter search query (end the search by typing ';') : " << endl << "Mot : ";
    cin.ignore();
    while(true){
        enteredLetter += cin.get();
        if(enteredLetter[enteredLetter.size() - 1] == ';')
            break;
        cin.ignore(256, '\n');
        queryName.search(enteredLetter);
        cout << endl << "Mot : " << enteredLetter;
    }
    return;
}


void partie2(){
    char valeurEntree;
    bool estDChoisie = false;
    bool estGChoisie = false;

    string nomFichierLexique;
    
    while(!estGChoisie){
        cout << "\n(d) Créer automate.\n(e) Saisir mot.\n(f) Afficher statistiques.\n(g) Quitter\n";
        cout << "Entrez l'option voulue ( d, e, f, g ) : ", cin >> valeurEntree;

        switch (valeurEntree)
        {
            case 'd':
                cout << "Entrez le nom du fichier lexique (sans le .txt): ", cin >> nomFichierLexique;
                creerAutomate(nomFichierLexique);
                estDChoisie = true;
                break;
            case 'e':
                if(estDChoisie)
                    saisirMot();
                else
                    cout << endl << "Il faut d'abord choisir l'option d pour creer l'automate !" << endl;
                break;
            case 'f':
                if(estDChoisie){
                    //AFFICHER STATISTIQUES
                }
                else
                    cout << endl << "Il faut d'abord choisir l'option d pour creer l'automate !" << endl;
                break;
            case 'g':
                estGChoisie = true;
                break;
            default:
                cout << "\nCette option n'existe pas ! Les options existantes sont ( d, e, f, g ) !\n";
                break;
        }
    }
}