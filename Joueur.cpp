#include "Joueur.hpp"

int Joueur::sante = 20;
// Deck deck = ;

// Constructeur 
Joueur::Joueur(Deck d, int sante) {
    this-> d = d;
    this-> sante = sante;
}

// Crée un joueur
Joueur Joueur::CreeJoueur() {
}
// Renvoie le nombre d'HP du joueur
int Joueur::NombreHP()
{
    return sante;
}  

// Renvoie le nombre de HP que le joueur a perdu.
int Joueur::PerdHP() {}

// Renvoie si fin de partie ou non 

