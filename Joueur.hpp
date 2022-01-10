#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Carte.hpp"

using namespace std;

class Joueur {
    private : 
    vector<Carte> Hand, Bibli, Board, GraveYard; // Voir si on specifie Creature ou Terrain au lieu de Carte
    int HP = 20;
    string nom;
    bool mort = false;
  
    public :

    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP); 
    Joueur(string nom, int HP);

    // -- -- -- -- DESTRUCTEUR -- -- -- --
    ~Joueur() {};

    // -- -- -- -- Les gets -- -- -- --
    int getHP();
    string getNom();
    bool getMort();

    //-- -- -- -- Les sets -- -- -- -- 
    void setNom(string n);
    void setHP(int s);
    void setMort();
    //-- -- -- -- methodes -- -- -- -- 
    void RecevoirDegat(int nbDegat);

};

#endif