#ifndef CREATURE_H
#define CREATURE_H

#include "Carte.hpp"
#include "Joueur.hpp"
#include <vector>

class Joueur;

class Creature : public Carte {
    private : 
    vector<string> capacite, cout_couleur;
    int cost,  force, endurance, idCreature;

    public :
    Creature(string nom, string couleur, string lieu, bool etat, int numero);
    Creature(string  nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, vector<string> cout_couleur, int cost, int force, int endurance); // Constructeur à faire
    ~Creature() {}; // Destructeur

    //les gets
    int getCost();
    int getForce();
    int getEndurance();
    vector<string> getCapacite();
    vector<string> getCout_Couleur();
    int getID();

    //les sets 
    void setCost(int i);
    void setForce(int i);
    void setEndurance(int i);

    // les methodes 
    void RecevoirDegat(int nbDegat);
    void AttaqueCarte(Creature &creature);
    void AttaqueJoueur(Joueur &joueur);
    void print();
};

#endif