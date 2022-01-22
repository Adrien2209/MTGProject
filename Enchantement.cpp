#include "Enchantement.hpp"

#include <iostream>

Enchantement::Enchantement(string nom, string couleur, string lieu, bool etat, int numero, map<string,int> cout_couleur, int cost, int ForceBonus, int EnduranceBonus, string Target) : Carte(nom, couleur, lieu, etat, numero)
{
  this->idEnchantement = 3;
  this->cout_couleur = cout_couleur;
  this->cost = cost;
  this-> ForceBonus = ForceBonus;
  this-> EnduranceBonus = EnduranceBonus;
  this->Target = Target;
}

int Enchantement::getID()
{
  return idEnchantement;
}

map<string,int> Enchantement::getCout_Couleur()
{
  return cout_couleur;
}

int Enchantement::getCost()
{
  return cost;
}

int Enchantement::getForceBonus(){return ForceBonus;}

int Enchantement::getEnduranceBonus(){return EnduranceBonus;}

string Enchantement::getTarget(){return Target;}

void Enchantement::print()
{

  cout << this->getCouleur() << endl
       << " ____________________________________ " << endl
       << "| Name : " + this->getNom() + "  Cout : 0 |" << endl
       << "|                                   |" << endl
       << "|                                   |" << endl
       << "|___________________________________|" << endl;
}