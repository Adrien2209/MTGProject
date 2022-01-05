#include "Joueur.hpp"

int Joueur::HP = 20;
// Deck deck = ;

// Constructeur 
/* Joueur::Joueur(Deck d, int HP) {
    this-> d = d;
    this-> HP = HP;
}
*/

Joueur::Joueur( int HP) {
    this-> HP = HP;
}

Joueur::Joueur(string nom, int ID) {
    this -> nom = nom;
    this -> ID = ID;
    HP = 20;
}

int Joueur::getHP() {
        return HP;
    }

/*
    int  Joueur::getDeck() {
        return d;
    }
*/

void Joueur::setHP(int s) {
         HP = s;
}

// Renvoie le nombre d'HP du joueur
int Joueur::NombreHP()
{
    return HP;
}  


