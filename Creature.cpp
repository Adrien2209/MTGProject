#include "Creature.hpp"

Creature::Creature(string  nom, string couleur, vector<string> capacite, vector<string> cout_couleur, int cout, int force, int endurance) :  Carte(nom, couleur) {
        this ->  capacite = capacite; 
        this ->  cout_couleur = cout_couleur; 
        this ->  capacite = capacite; 
        this ->  cout = cout; 
        this ->  force = force; 
        this ->  endurance = endurance; 

}

// -- -- -- Les gets -- -- --

vector<string> Creature::getCapacite() { return capacite;}

vector<string>  Creature::getCout_Couleur() { return cout_couleur;}

int Creature::getCout() { return cout;}

int Creature::getForce() { return force;}

int Creature::getEndurance() {return endurance; }

// -- -- -- Les sets -- -- --

void Creature::setCout(int i) { cout = i; }

void Creature::setForce(int i) { force = i; }

void Creature::setEndurance(int i) { endurance = i; }

// -- -- -- Les méthodes -- -- -- 

void Creature::Attaque(Creature c1) {
    if (this->force > c1.getEndurance()) {
       return J1.getSante() - this->force;
       c1.get
    }
    if (this->force = c1.getEndurance() || ) {
        
    } 
    if (this->force < c1.getEndurance()) {
         
    }
}


