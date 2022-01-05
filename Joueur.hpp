#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Deck.hpp"


const int HP_START = 20;
const int MAX_HAND = 7;


using namespace std;

class Joueur {
    private : 
    /* Deck d; */
    int static HP;
    int ID;
    string nom;
  
    public :

    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP); 
    Joueur(string nom, int ID);
    Joueur(int HP);

    // -- -- -- -- DESTRUCTEUR -- -- -- --
    virtual ~Joueur();

    // -- -- -- -- Les gets -- -- -- --
    int getHP();
    string getNom();
    int getID();
    // Deck getDeck();

    //-- -- -- -- Les sets -- -- -- -- 
    void setNom(string n);
    void setID(int i);
    void setHP(int s);
    void setDeck();
    

    //-- -- -- -- methodes -- -- -- -- 

    int NombreHP();



    // VOIR SI ON GARDE 

    // Returns size of Player's deck 
    int getDeckSize();

    // Returns size of Player's hand 
    int getHandSize();

    int getGraveyardSize();
};

#endif