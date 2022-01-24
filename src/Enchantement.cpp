#include "../Headers/Enchantement.hpp"

#include <iostream>

Enchantement::Enchantement(string nom, string couleur, string lieu, bool etat, int numero, map<string,int> cout_couleur, int cost, int ForceBonus, int EnduranceBonus, string Target, vector<string> cout_couleur_str) : Carte(nom, couleur, lieu, etat, numero)
{
  this->idEnchantement = 3;
  this->cout_couleur_str = cout_couleur_str;
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

void Enchantement::printCouleur()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::quelleCouleur(this->getCouleur());

  cout << c << "\t " << "_____________________________________" << endl;
  cout << c << "\t |" << couleurDefaut << this->getNom() << this->SpaceName() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << Target << this->SpaceTarget() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << "Cout : " + to_string(cost) + "                           "<< c <<"|" << endl;
  cout << c << "\t |" << couleurDefaut << "Cout Color : " << printCoutCouleur() << c <<"|" << endl;
  cout << c << "\t |" << couleurDefaut << this->getLieu() + this->SpaceLieu() << c << "| " << endl;
  cout << c << "\t |" << couleurDefaut << "Force Bonus : " + to_string(ForceBonus) + " Endurance Bonus : " + to_string(EnduranceBonus) + "" << c << "|" << endl;
  cout << c << "\t |" <<"___________________________________|" << endl;
  cout << couleurDefaut;
}

string Enchantement::printCoutCouleur(){
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

string Enchantement::SpaceName() {

  string res = "                                   ";
  int i = 0;

  for ( i = 0; i < (int)this->getNom().length(); i++) {
      res.pop_back();
  }
  return res;
}

string Enchantement::SpaceTarget() {

  string res = "                                   ";
  int i = 0;

  for ( i = 0; i < (int)this->Target.length(); i++) {
      res.pop_back();
  }
  return res;
}

string Enchantement::SpaceLieu() {

  string res = "                                   ";
  int i = 0;
  for ( i = 0; i < (int)this->getLieu().length(); i++) {
       res.pop_back();
  }

  return res;
}