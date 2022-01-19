#include "Creature.hpp"
#include "Joueur.hpp"
#include <iostream>
using namespace std;

Creature::Creature(string nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, map<string,int> cout_couleur, int cost, int force, int endurance) : Carte(nom, couleur, lieu, etat, numero)
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

map<string,int> Creature::getCout_Couleur()
{
  return cout_couleur;
}

int Creature::getCost()
{
  return cost;
}

int Creature::getForce() { return force; }

int Creature::getEndurance() { return endurance; }

int Creature::getBaseEndurance() { return base_endurance; }

int Creature::getID()
{
  return idCreature;
}

// -- -- -- Les sets -- -- --

void Creature::setCost(int i) { cost = i; }

void Creature::setForce(int i) { force = i; }

void Creature::setEndurance(int i) { endurance = i; }
void Creature::setBaseEndurance(int i) { base_endurance = i; }
void Creature::minusEndurance(int i) { endurance -= i;}

// -- -- -- Les méthodes -- -- --

void Creature::print()
{
  cout << this->getCouleur() << endl
       << " ____________________________________ " << endl
       << "| Name : " + this->getNom() + "  Cout : " + to_string(cost) + + "  Lieu : " + this->getLieu() + "|" << endl
       << "|                                   |" << endl
       << "| Attack : " + to_string(force) + " HP : " + to_string(endurance) + " |" << endl
       << "|___________________________________|" << endl;
}

int Creature::CoutTotale() {
  map<string,int>::iterator it;
  int res;
  for (it = cout_couleur.begin(); it != cout_couleur.end(); ++it) {
    res += it -> second;
  }
  return res + this->getCost();
}