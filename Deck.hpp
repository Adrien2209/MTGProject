#ifndef DECK_H
#define DECK_H

#include "Carte.hpp"
#include <vector>

class Deck {
    private : 
        vector<Carte> deck;
        string nom;

    public :
    // -- -- -- Constructeur -- -- -- 
    Deck(string nom, vector<Carte> deck); 

    // -- -- -- Destructeur -- -- -- 
    ~Deck() {};

    // -- -- -- les gets -- -- --
    string getNom();
    vector<Carte> getDeck();
};

#endif