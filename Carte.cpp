#include "Carte.hpp"
#include <iostream>

// Constructeur
Carte::Carte(string  nom, string couleur, string lieu, bool etat) {
    this-> nom = nom;
    this-> couleur = couleur;
    this-> lieu = lieu;
    this-> etat = etat;
}

void Carte::print() {
cout           
            << "                       " + this -> getCouleur() << endl
            << " ____________________________________ " << endl
            << "| Name : " + this->getNom() + "                        |" << endl
            << "|                                   |" << endl
            << "|___________________________________|" << endl;
}
// Les Gets

string Carte::getNom() {
    return nom;
}

string Carte::getCouleur() {
    return couleur;
}

string Carte::getLieu(){
    return lieu;
}

// Les sets
void Carte::setLieu(string l){lieu = l;}

void Carte::setEngage(){etat = true;}

void Carte::setDesengage(){etat = false;}

// Les méthodes
bool Carte::getEtat() {return etat;}

void Carte::Death(){
    lieu = "GraveYard";
}
    

