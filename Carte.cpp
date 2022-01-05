#include "Carte.hpp"

// Constructeur
Carte::Carte(string  nom, int cout, string type, int force, int endurance, bool est_engage) {
    this-> nom = nom;
    this-> cout = cout;
    this-> type = type;
    this-> force = force;
    est_engage = false; 
}

// Les Gets
int Carte::getForce() {
    return force;
}

string Carte::getNom() {
    return nom;
}

int Carte::getCout() {
    return cout;
}

string Carte::getType() {
    return type;
}

int Carte::getEndurance() {
    return endurance;
}


bool est_Engage(Carte c1) {
        return 
}