#ifndef DECK_H
#define DECK_H

#include "Carte.hpp"
#include "Endroit.hpp"
#include <vector>

class Deck {
    private : 
        vector<pair<Carte , Endroit>> deck;
        string nom;

    public :
    // -- -- -- Constructeur -- -- -- 
    Deck(string nom, vector<pair<Carte,Endroit>> deck); 

    // -- -- -- Destructeur -- -- -- 
    ~Deck() {};

    // -- -- -- les gets -- -- --
    string getNom();
    vector<pair<Carte,Endroit>> getDeck();
};

#endif