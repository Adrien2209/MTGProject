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