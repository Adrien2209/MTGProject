#include "Creature.hpp"
#include "Joueur.hpp"
Creature::Creature(string nom, string couleur, string lieu , bool etat) : Carte(nom, couleur, lieu, etat)
{
  this->cout_couleur = {""};
  this->capacite = {""};
  this->cout = 1;
  this->force = 2;
  this->endurance = 4;
}

Creature::Creature(string nom, string couleur, string lieu , bool etat, vector<string> capacite, vector<string> cout_couleur, int cout, int force, int endurance) : Carte(nom, couleur, lieu, etat)
{
  this->cout_couleur = cout_couleur;
  this->capacite = capacite;
  this->cout = cout;
  this->force = force;
  this->endurance = endurance;
}

// -- -- -- Les gets -- -- --

vector<string> Creature::getCapacite() { return capacite; }

vector<string> Creature::getCout_Couleur() { return cout_couleur; }

int Creature::getCout() { return cout; }

int Creature::getForce() { return force; }

int Creature::getEndurance() { return endurance; }

// -- -- -- Les sets -- -- --

void Creature::setCout(int i) { cout = i; }

void Creature::setForce(int i) { force = i; }

void Creature::setEndurance(int i) { endurance = i; }

// -- -- -- Les méthodes -- -- --
void Creature::RecevoirDegat(int nbDegat)
{
  endurance -= nbDegat;

  if (endurance <= 0)
  {
    endurance = 0;
    this->Death();
  }
}

void Creature::AttaqueCarte(Creature &creature)
{
  creature.RecevoirDegat(force);
  this->RecevoirDegat(creature.getForce());
}

void Creature::AttaqueJoueur(Joueur &joueur)
{
  joueur.RecevoirDegat(this->getForce());
}
