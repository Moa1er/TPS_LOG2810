#ifndef PARTIE1_H
#define PARTIE1_H

#include <string>


void partie1();
void creerGrapheExposition(std::string nomFichierIndividus, std::string nomFichierContacts);
void afficherGrapheExposition();
void identifierExposition(std::string origine, std::string destination);
void notifierExposition(std::string nomPersonne);

#endif