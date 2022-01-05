#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Deck.hpp"

using namespace std;

class Joueur {
    private : 
    Deck d;
    int static sante;
  
    public :
    Joueur(Deck d, int sante); // Constructeur
    ~Joueur() {}; // Destructeur

    Joueur CreeJoueur();
    int NombreHP();
    int PerdHP();





};

#endif