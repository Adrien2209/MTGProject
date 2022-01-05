#include "Creature.hpp"

Creature::Creature(string  nom, string couleur, vector<string> capacite, vector<string> cout_couleur, int cout, int force, int endurance) :  Carte(nom, couleur) {
        this ->  capacite = capacite; 
        this ->  cout_couleur = cout_couleur; 
        this ->  capacite = capacite; 
        this ->  cout = cout; 
        this ->  force = force; 
        this -> endurance = endurance; 

}

vector<string> Creature::getCapacite() {
    return capacite;
}

vector<string>  Creature::getCout_Couleur() {
    return cout_couleur;
}

int Creature::getCout() {
    return cout;
}

int Creature::getForce() {
    return force;
}

int Creature::getEndurance() {
    return endurance;
}
