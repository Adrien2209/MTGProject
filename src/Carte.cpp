#include "../Headers/Carte.hpp"

#include <iostream>
#include <cstring>

// Constructeur
Carte::Carte(string nom, string couleur, string lieu, bool etat, int numero)
{
    this->nom = nom;
    this->couleur = couleur;
    this->lieu = lieu;
    this->etat = etat;
    this->numero = numero;
}

// Les Gets
string Carte::getNom() { return nom; }
string Carte::getCouleur() { return couleur; }
string Carte::getLieu() { return lieu; }

// -- -- -- -- Virtual des GET -- -- -- --

int Carte::getID() { return 0; }

int Carte::getForce() { return 0; }

int Carte::getEndurance() { return 0; }

int Carte::getBaseEndurance() { return 0; }

// -- -- -- -- Virtual des SET -- -- -- --

void Carte::setForce(int i) {}
void Carte::setEndurance(int i) {}
void Carte::setBaseEndurance(int i) {}
void Carte::minusEndurance(int i) {}

// -- -- -- --

int Carte::getNumero() { return numero; }
bool Carte::getEtat() { return etat; }
int Carte::getCost() { return 0; }
map<string, int> Carte::getCout_Couleur() { return {}; }
vector<string> Carte::getCapacite() { return {}; }

// ------------------------------ LES SETS ------------------------------
void Carte::setLieu(string l) { lieu = l; }
void Carte::setEngage() { etat = true; }
void Carte::setDesengage() { etat = false; }
void Carte::setPeutAttaquer() { return; }
void Carte::setPeutPasAttaquer() { return; }
int Carte::getForceBonus() { return 0; }
int Carte::getEnduranceBonus() { return 0; }
bool Carte::getPeutAttaquer() { return false; }
string Carte::getTarget() { return ""; }
string Carte::getType() { return ""; }

// ------------------------------ LES METHODES ------------------------------

void Carte::Death() { lieu = "GraveYard"; }

void Carte::printCouleur() { return; }

bool operator==(Carte const &c, Carte const &c1) { return c.numero == c1.numero; }

string Carte::SpaceName()
{
    string res = "                         ";
    int i = 0;

    for (i = 0; i < (int)this->getNom().length(); i++)
    {
        res.pop_back();
    }
    return res;
}

string Carte::SpaceLieu()
{
    string res = "                         ";
    int i = 0;
    for (i = 0; i < (int)this->getLieu().length(); i++)
    {
        res.pop_back();
    }

    return res;
}