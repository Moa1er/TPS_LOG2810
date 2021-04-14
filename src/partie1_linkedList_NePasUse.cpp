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
#define TAILLE_MAX 1000

vector<vector<string>> listeContacts;

// struct Node{
//     unsigned int data_;
//     double weight_;
//     Node* next_;
// };


class Node{
    private :
        unsigned int data_;
        double weight_;
        Node* next_;
    public:
        unsigned int getData(){
            return data_;
        }
        double getWeight(){
            return weight_;
        }
        Node* getNext(){
            return next_;
        }
        void setData(unsigned int data){
            data_ = data;
        }
        void setWeight(double weight){
            weight_ = weight;
        }
        void setNext(Node* next){
            next_ = next;
        }
};


class LinkedList
{
private:
    Node *head_,*tail_;
public:
    LinkedList()
    {
        head_ = nullptr;
        tail_ = nullptr;
    }

    void add_node(unsigned int data, double weight)
    {
        Node *tmp = new Node;
        tmp->setData(data);
        tmp->setWeight(weight);
        tmp->setNext(nullptr);

        if(head_ == nullptr)
        {
            head_ = tmp;
            tail_ = tmp;
        }
        else
        {
            tail_->setNext(tmp);
            tail_ = tail_->getNext();
        }
    }

    double getNode()
    {
        double retour = head_->getWeight();
        return retour;
    }
};


struct Personne{
    string name;
    char diagnostique;
};


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

void creerGrapheExposition(string nomFichierIndividus, string nomFichierContacts){

    //A DECOMMENTER PLUS TARD
    //ifstream fluxIndividus(nomFichierIndividus + ".txt");
    //ifstream fluxContacts(nomFichierContacts + ".txt");
    
    ifstream fluxIndividus("Individus.txt");
    ifstream fluxContacts("Contacts.txt");

    if(fluxIndividus && fluxContacts){
        cout << "Fichiers ouverts\n";

        vector<Personne> personnes;

        string ligne;
        Personne personne;

        char delimiteurIndividus = ',';
        char delimiteurContacts = ' ';


        //Get tout les individus et en fait un vecteur de Personne
        while(getline(fluxIndividus, ligne)){
            vector<string> ligneCoupe = split(ligne, delimiteurIndividus);

            personne.name = ligneCoupe[0];
            personne.diagnostique = ligneCoupe[1][0]; //index 0 car on veut juste le chiffre

            //cout << personne.name << personne.diagnostique << endl;

            personnes.push_back(personne);
        }

        //LinkedList *edgesOfGraph = new LinkedList[personnes.size()];
        vector<LinkedList> edgesOfGraph(personnes.size());
        //LinkedList[] edgesOfGraph = new LinkedList[personnes.size()]l;
        //constexpr int nbPersonnes = personnes.size();
        //std::array<LinkedList, nbPersonnes> edgesOfGraph;
        //Node edge;


        size_t start = 0;
        size_t end = 0;

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
            edgesOfGraph[indexPersonneFrom].add_node(indexPersonneTo, distance);
            cout << "data" << edgesOfGraph[indexPersonneFrom].getNode() << endl;

        }

        // for(int i = 0; i < personnes.size(); i++){
        //     cout << "data" << edgesOfGraph[i].getNode();
        // }
    }
    else
        cout << "Fichiers ne sont pas ouvert";
    

        
    // if(fluxContacts)  //On teste si tout est OK
    // {   
    //     cout << "Fichier " + nomFichierContacts + ".txt ouvert" << endl;
    //     string ligne;
    //     while(getline(fluxContacts, ligne)) //Tant qu'on n'est pas à la fin, on lit
    //     {      
    //         string arr[3];
    //         int i = 0;
    //         stringstream ssin(ligne);
    //         vector<string> line ;
    //         while (ssin.good() && i < 3){
    //             ssin >> arr[i];
    //             line.push_back(arr[i]);
    //             ++i;
                
    //         }
    //         listeContacts.push_back(line);
            
    //     }
         
    // }
    // else
    // {
    //     cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    // }

}

void afficherGrapheExposition(){
     cout << "Option b\n";
    for(int h = 0 ; h < listeContacts.capacity(); h++){            
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
        cout << "Entree l'option voulue ( a, b, c, d ) : ", cin >> valeurEntree;

        switch (valeurEntree)
        {
            case 'a':
                //A DECOMMENTER PLUS TARD
                //cout << "Entree le nom du fichier regroupant les individus : ", cin >> nomFichierIndividus;
                //cout << "Entree le nom du fichier regroupant les contacts : ", cin >> nomFichierContacts;

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