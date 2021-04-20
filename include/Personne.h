#ifndef PERSONNE_H
#define PERSONNE_H

#include <string>
#include <vector>

struct Personne{
    std::string name_;
    char diagnostique_;
};

class Personnes{
private: 
    std::vector<Personne> personnes_;
    int nbPersonnes_;
public:
    Personnes() = default;
    
    int findIndex(std::string nomPersonne);
    void addPersonne(Personne personne);
    void setNbPersonnes(int nbPersonnes){nbPersonnes_ = nbPersonnes;};

    std::vector<Personne> getPersonnes(){return personnes_;};
    int getNbPersonnes(){return nbPersonnes_;};
    std::string getName(int indexPersonne){return personnes_[indexPersonne].name_;};
    char getDiagnostique(int indexPersonne){return personnes_[indexPersonne].diagnostique_;};
};

#endif