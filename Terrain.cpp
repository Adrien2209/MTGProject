#include "Terrain.hpp"

#include <iostream>

Terrain::Terrain(string nom, string couleur, string lieu, bool etat, int numero) : Carte(nom, couleur, lieu, etat, numero)
{
  this->idTerrain = 1;
}

int Terrain::getID()
{
  return idTerrain;
}

int Terrain::getCost()
{
  return 0;
}

map<string, int> Terrain::getCout_Couleur()
{
  return {{"", 0}};
}

void Terrain::print()
{

  cout << this->getCouleur() << endl
       << " ____________________________________ " << endl
       << "| Name : " + this->getNom() + "  Cout : 0 |" << endl
       << "|                                   |" << endl
       << "|                                   |" << endl
       << "|___________________________________|" << endl;
}


void Terrain::printCouleur() {
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::quelleCouleur(this->getCouleur());

  cout << c << "\t " << "___________________________" << endl;
  cout << c << "\t |" << couleurDefaut << this->getNom() << this->SpaceName() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << this->getLieu() << this->SpaceLieu() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << "Etat : " << this->getEtat() << "                 " << c << "| " << endl;
  cout << c << "\t |" <<"_________________________|" << endl;
  cout << couleurDefaut;

}

string Terrain::SpaceName() {

  string res = "                         ";
  int i = 0;

  for ( i = 0; i < (int)this->getNom().length(); i++) {
      res.pop_back();
  }
  return res;
}

string Terrain::SpaceLieu() {

  string res = "                         ";
  int i = 0;
  for ( i = 0; i < (int)this->getLieu().length(); i++) {
       res.pop_back();
  }

  return res;
}


string Terrain::SpaceEtat() {

  string res = "                         ";
  int i = 0;
  for ( i = 0; i < 5; i++) {
       res.pop_back();
  }

  return res;
}