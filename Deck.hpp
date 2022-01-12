#ifndef DECK_H
#define DECK_H

#include "json.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"
#include <vector>
#include <string>

using json = nlohmann::json;

class Deck {
    private : 
        vector<Carte> deck;
        string nom;

    public :
    // -- -- -- Constructeur -- -- -- 
    Deck(string nom); 
    Deck(string nom, vector<Carte> deck); 

    // -- -- -- Destructeur -- -- -- 
    ~Deck() {};

    // -- -- -- les gets -- -- --
    string getNom();
    vector<Carte> getDeck();
    void printDeck();
    vector<Carte> getDeckFromFile(string nomDeck);
};

#endif