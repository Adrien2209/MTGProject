#include "Deck.hpp"

Deck::Deck(string nom, vector<Carte> deck) { 
    this -> nom = nom;
    this -> deck = deck;
}

string Deck::getNom() {
    return nom;
}

vector<Carte> Deck::getDeck() {
    return deck;
}
