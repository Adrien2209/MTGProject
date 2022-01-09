#include "Joueur.hpp"


int Joueur::HP = 20;

// Deck deck = ;

// Constructeur 
/* Joueur::Joueur(Deck d, int HP) {
    this-> d = d;
    this-> HP = HP;
}*/


Joueur::Joueur(string nom, int HP) {
    this -> nom = nom;
    this -> HP = HP;
}

int Joueur::getHP() {
        return HP;
}


// Renvoie le nombre d'HP du joueur
int Joueur::NombreHP()
{
    return HP;
}  


