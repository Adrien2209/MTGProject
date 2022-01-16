#ifndef CREATURE_H
#define CREATURE_H

#include "Carte.hpp"
#include "Joueur.hpp"
#include <vector>

class Joueur;

class Creature : public Carte {
    private : 
    vector<string> capacite, cout_couleur;
    int cost,  force, endurance, idCreature, base_endurance;

    public :
    Creature(string nom, string couleur, string lieu, bool etat, int numero);
    Creature(string  nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, vector<string> cout_couleur, int cost, int force, int endurance); // Constructeur à faire
    ~Creature() {}; // Destructeur

    //les gets
    int getCost();
    int getForce();
    int getEndurance();
    int getBaseEndurance();
    vector<string> getCapacite();
    vector<string> getCout_Couleur();
    int getID();

    //les sets 
    void setCost(int i);
    void setForce(int i);
    void setEndurance(int i);
    void setBaseEndurance(int i);

    // les methodes 
    void print();
};

#endif