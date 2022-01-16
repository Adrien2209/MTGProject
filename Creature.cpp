#include "Creature.hpp"
#include "Joueur.hpp"
#include <iostream>
using namespace std;
Creature::Creature(string nom, string couleur, string lieu, bool etat, int numero) : Carte(nom, couleur, lieu, etat, numero)
{
  this->cout_couleur = {""};
  this->capacite = {""};
  this->cost = 1;
  this->force = 2;
  this->endurance = 4;
  this->idCreature = 2;
  this->base_endurance = 4;
}

Creature::Creature(string nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, vector<string> cout_couleur, int cost, int force, int endurance) : Carte(nom, couleur, lieu, etat, numero)
{
  this->cout_couleur = cout_couleur;
  this->capacite = capacite;
  this->cost = cost;
  this->force = force;
  this->endurance = endurance;
  this->idCreature = 2;
  this->base_endurance = endurance;
}

// -- -- -- Les gets -- -- --

vector<string> Creature::getCapacite() { return capacite; }

vector<string> Creature::getCout_Couleur()
{
  cout << "Methode getCout_Couleur() de Creature " << endl;
  return cout_couleur;
}

int Creature::getCost()
{
  cout << "Methode getCost() de Creature " << endl;
  return cost;
}

int Creature::getForce() { return force; }

int Creature::getEndurance() { return endurance; }

int Creature::getBaseEndurance() { return base_endurance; }

int Creature::getID()
{
  cout << "Methode getID() de Creature " << endl;
  return idCreature;
}

// -- -- -- Les sets -- -- --

void Creature::setCost(int i) { cost = i; }

void Creature::setForce(int i) { force = i; }

void Creature::setEndurance(int i) { endurance = i; }
void Creature::setBaseEndurance(int i) { base_endurance = i; }

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

void Creature::print()
{
  cout << this->getCouleur() << endl
       << " ____________________________________ " << endl
       << "| Name : " + this->getNom() + "  Cout : " + to_string(cost) + "|" << endl
       << "|                                   |" << endl
       << "| Attack : " + to_string(force) + " HP : " + to_string(endurance) + " |" << endl
       << "|___________________________________|" << endl;
}