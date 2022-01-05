#include "Deck.hpp"
#include "Endroit.hpp"

Deck::Deck(string nom, vector<pair<Carte,Endroit>> deck) { 
    this -> nom = nom;
    this -> deck = deck;
}

string Deck::getNom() {
    return nom;
}

vector<pair<Carte,Endroit>> Deck::getDeck() {
    return deck;
}
