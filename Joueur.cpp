#include "Joueur.hpp"

int Joueur::sante = 20;

// Constructeur 
Joueur::Joueur(vector<Carte> main, int sante) {
    this-> main = main;
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

