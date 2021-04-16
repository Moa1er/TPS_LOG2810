#include "../include/Personne.h"

int Personnes::findIndex(std::string nomPersonne){
    int indexPersonne(0);
    for(int i = 0; i < personnes_.size() && (indexPersonne == 0) ; i++){
        if(personnes_[i].name_ == nomPersonne)
            indexPersonne = i;
    }
    return indexPersonne;
}

void Personnes::addPersonne(Personne personne){
    personnes_.push_back(personne);
}