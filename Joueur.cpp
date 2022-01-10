#include "Joueur.hpp"
#include "Carte.hpp"
// Constructeur 
Joueur::Joueur(string nom, int HP) {
    this -> nom = nom;
    this -> HP = HP;
}

// Les gets
string Joueur::getNom() { return nom;}
int Joueur::getHP() { return HP;}
bool Joueur::getMort() { return mort;}
// Les sets
void Joueur::setNom( string n) { nom = n;}
void Joueur::setHP(int s) { HP = s;}

// Les Methodes
void Joueur::setMort() { mort = true;}

void Joueur::RecevoirDegat( int nbDegat) 
{
    HP -= nbDegat;
    if (HP <= 0)
  {
    HP = 0;
    this->setMort();
  }
}

