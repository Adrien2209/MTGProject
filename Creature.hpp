#ifndef CREATURE_H
#define CREATURE_H

#include "Carte.hpp"
#include <vector>

class Creature : public Carte {
    private : 
    vector<string> capacite, cout_couleur;
    int cout,  force, endurance;

    public :
    Creature(string  nom, string couleur, vector<string> capacite, vector<string> cout_couleur, int cout, int force, int endurance); // Constructeur à faire
    ~Creature() {}; // Destructeur

    //les gets
    int getCout();
    int getForce();
    int getEndurance();
    vector<string>  getCapacite();
    vector<string> getCout_Couleur();


};

#endif