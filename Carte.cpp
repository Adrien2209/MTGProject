#include "Carte.hpp"

// Constructeur
Carte::Carte(string  nom, string couleur) {
    this-> nom = nom;
    this-> couleur = couleur;
}

// Les Gets

string Carte::getNom() {
    return nom;
}

string Carte::getCouleur() {
    return couleur;
}


