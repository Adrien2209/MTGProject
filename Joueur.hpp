#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Carte.hpp"

using namespace std;

class Joueur {
    private : 
    vector<Carte> main;
    int static sante;
  
    public :
    Joueur(vector<Carte> main, int sante); // Constructeur
    ~Joueur() {}; // Destructeur

    Joueur CreeJoueur();
    int NombreHP();
    int PerdHP();





};

#endif