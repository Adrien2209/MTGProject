#include "Deck.hpp"
#include <fstream>
#include <iostream>

Deck::Deck(string nom) { 
    this -> nom = nom;
    this -> deck = Deck::getDeckFromFile(nom);
}
Deck::Deck(string nom, vector<Carte*> deck) { 
    this -> nom = nom;
    this -> deck = deck;
}

string Deck::getNom() {
    return nom;
}

vector<Carte*> Deck::getDeck() {
    return deck;
}

vector<Carte*> Deck::getDeckFromFile(string nomDeck) {
    std::vector<Carte*> DeckRetour = {};
    std::ifstream ifs(nomDeck + ".json");
    json deck;
    ifs >> deck;

    // Ajout des creatures dans le deck
    const auto& creature = deck["DeckTest"]["Creature"];
    for(const auto& liste_creature : creature.items())
    {
        string title = liste_creature.value()["Title"];
        int commoncost = liste_creature.value()["CommonCost"];
        vector<string> colorcost = liste_creature.value()["ColorCost"];
        string color = liste_creature.value()["Color"];
        string type = liste_creature.value()["Type"];
        int force = liste_creature.value()["Force"];
        int endurance = liste_creature.value()["Endurance"];
        vector<string> capacity = liste_creature.value()["Capacity"];
        int id = liste_creature.value()["ID"];
        string lieu = "Bibli";
        bool etat = false;
        DeckRetour.push_back(new Creature(title, color, lieu, etat, id, capacity, colorcost, commoncost, force, endurance));
    }

    // Ajout des terrains dans le deck
    const auto& terrain = deck["DeckTest"]["Terrain"];
    for(const auto& liste_terrain : terrain.items())
    {
        string title = liste_terrain.value()["Title"];
        string color = liste_terrain.value()["Color"];
        int id = liste_terrain.value()["ID"];
        string lieu = "Bibli";
        bool etat = false;
        DeckRetour.push_back(new Terrain(title, color, lieu, etat, id));
    }

    return DeckRetour;
}

void Deck::printDeck() {
    for ( auto e : this->deck) {
        e->print();
    }
}
