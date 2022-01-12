#include "Joueur.hpp"
#include "Carte.hpp"

#include <algorithm>
#include <iostream>
#include <random>       // std::default_random_engine
#include <chrono>       // std::chrono::system_clock

// Constructeur 
Joueur::Joueur(string nom, int HP, int ID, vector<Carte> Hand , vector<Carte> Bibli , vector<Carte> Board , vector<Carte> GraveYard) {
    this -> nom = nom;
    this -> HP = HP;
    this -> ID = ID;
    this -> Hand = Hand;
    this -> Bibli = Bibli;
    this -> Board = Board;
    this -> GraveYard = GraveYard;
}

Joueur::Joueur(string nom, int HP, int ID) {
    this -> nom = nom;
    this -> HP = HP;
    this -> ID = ID;
}

Joueur::Joueur() {};

// Les gets
string Joueur::getNom() { return nom;}
int Joueur::getHP() { return HP;}
bool Joueur::getMort() { return mort;}

// Les sets
void Joueur::setNom( string n) { nom = n;}
void Joueur::setHP(int s) { HP = s;}
vector<Carte> Joueur::setBibli(Deck v) { 
  Bibli = v.getDeck();
  return Bibli; }

// Les Methodes
bool Joueur::VerifMort() { 
  if (this->getHP()  <= 0 ){
      cout << "Le joueur " << this->getNom() << " est mort ! C'est CIAO !!" << endl ;
       return mort = true;}
    return mort;
}

void Joueur::RecevoirDegat( int nbDegat) 
{
    HP -= nbDegat;
    if (HP <= 0)
  {
    HP = 0;
    this->VerifMort();
  }
}

void Joueur::MelangeBibli(vector<Carte> v ) {
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  shuffle (v.begin(),v.end(),std::default_random_engine(seed));
}




