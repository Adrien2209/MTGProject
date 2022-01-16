#include "Carte.hpp"
#include <iostream>

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


int Carte::getID()
{
    cout << "Methode getID() de Carte " << endl;
    return 0;
}

int Carte::getForce()
{
    cout << "Methode getForce() de Carte " << endl;
    return 0;
}

int Carte::getEndurance()
{
    cout << "Methode getEndurance() de Carte " << endl;
    return 0;
}

int Carte::getBaseEndurance()
{
    cout << "Methode getBaseEndurance() de Carte " << endl;
    return 0;
}


// -- -- -- -- Virtual des SET -- -- -- --


void Carte::setForce()
{
    cout << "Methode setForce() de Carte " << endl;
}

void Carte::setEndurance()
{
    cout << "Methode setEndurance() de Carte " << endl;
}

void Carte::setBaseEndurance()
{
    cout << "Methode setBaseEndurance() de Carte " << endl;
}

// -- -- -- --


int Carte::getNumero() { return numero; }
bool Carte::getEtat() { return etat; }
int Carte::getCost()
{
    cout << "Methode getCost() de Carte " << endl;
    return 0;
}
vector<string> Carte::getCout_Couleur()
{
    cout << "Methode getCout_Couleur() de Carte " << endl;
    return {};
}

// Les sets
void Carte::setLieu(string l) { lieu = l; }
void Carte::setEngage() { etat = true; }
void Carte::setDesengage() { etat = false; }

// Les méthodes


void Carte::Death()
{
    lieu = "GraveYard";
}

void Carte::print()
{
    cout
        << "                       " + this->getCouleur() << endl
        << " ____________________________________ " << endl
        << "| Name : " + this->getNom() + "                        |" << endl
        << "|                                   |" << endl
        << "|___________________________________|" << endl;
}
