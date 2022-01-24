#include "../Headers/Creature.hpp"
#include "../Headers/Joueur.hpp"
#include <iostream>
using namespace std;

Creature::Creature(string nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, map<string, int> cout_couleur, int cost, int force, int endurance, bool peutAttaquer, string type, vector<string> cout_couleur_str) : Carte(nom, couleur, lieu, etat, numero)
{
  this->cout_couleur = cout_couleur;
  this->cout_couleur_str = cout_couleur_str;
  this->capacite = capacite;
  this->cost = cost;
  this->force = force;
  this->endurance = endurance;
  this->idCreature = 2;
  this->base_endurance = endurance;
  this->peutAttaquer = false;
  this->type = type;
}

// -- -- -- Les gets -- -- --

vector<string> Creature::getCapacite() { return capacite; }

map<string, int> Creature::getCout_Couleur()
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

string Creature::getType(){ return type;}

int Creature::getID()
{
  return idCreature;
}

bool Creature::getPeutAttaquer()
{
  return peutAttaquer;
}

// -- -- -- Les sets -- -- --

void Creature::setCost(int i) { cost = i; }

void Creature::setForce(int i) { force = i; }

void Creature::setEndurance(int i) { endurance = i; }
void Creature::setBaseEndurance(int i) { base_endurance = i; }
void Creature::minusEndurance(int i) { endurance -= i; }
void Creature::setPeutAttaquer() { peutAttaquer = true; }
// -- -- -- Les méthodes -- -- --


int Creature::CoutTotale()
{
  map<string, int>::iterator it;
  int res = cost;
  for (it = cout_couleur.begin(); it != cout_couleur.end(); ++it)
  {
    res += it->second;
  }
  return res;
}

void Creature::printCouleur()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::CouleurChoisie(this->getCouleur());
  int n = 0;

  cout << c << "\t " << "_____________________________________" << endl;
  cout << c << "\t |" << couleurDefaut << this->getNom() << this->SpaceName() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << type << this->SpaceType() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << "Cout : " + to_string(cost) + "                           "<< c <<"|" << endl;
  cout << c << "\t |" << couleurDefaut << "Cout Color : " << printCoutCouleur() << c <<"|" << endl;
  cout << c << "\t |" << couleurDefaut << this->getLieu() + this->SpaceLieu() << c << "| " << endl;
  for(string capa : capacite){
    cout << c << "\t |" << couleurDefaut << capa + this->SpaceCapa(n) << c <<"|" << endl;
    n+=1;
  }
  cout << c << "\t |" << couleurDefaut << "Attack : " + to_string(force) + " HP : " + to_string(endurance) + "                  " << c << "|" << endl;
  cout << c << "\t |" <<"___________________________________|" << endl;
  cout << couleurDefaut;
}

string Creature::SpaceCapa(int n) {

  string res = "                                   ";
  int i = 0;

  for ( i = 0; i < (int)this->capacite[n].length(); i++) {
      res.pop_back();
  }
  return res;
}

string Creature::printCoutCouleur(){
  string res = "                      ";
  int i = 0;
  string retour = "";
  for(string coutcolor : cout_couleur_str){
    if(coutcolor == "White"){
      retour += "W ";
    }
    if(coutcolor == "Blue"){
      retour += "Blu ";
    }
    if(coutcolor == "Red"){
      retour += "R ";
    }
    if(coutcolor == "Green"){
      retour += "G ";
    }
    if(coutcolor == "Black"){
      retour += "Bla ";
    }
  }

  for ( i = 0; i < (int)retour.length(); i++) {
      res.pop_back();
  }
  return retour + res;
}

string Creature::SpaceName() {

  string res = "                                   ";
  int i = 0;

  for ( i = 0; i < (int)this->getNom().length(); i++) {
      res.pop_back();
  }
  return res;
}

string Creature::SpaceType() {

  string res = "                                   ";
  int i = 0;

  for ( i = 0; i < (int)this->type.length(); i++) {
      res.pop_back();
  }
  return res;
}

string Creature::SpaceLieu() {

  string res = "                                   ";
  int i = 0;
  for ( i = 0; i < (int)this->getLieu().length(); i++) {
       res.pop_back();
  }

  return res;
}