#ifndef CREATURE_H
#define CREATURE_H

#include "Carte.hpp"
#include "Joueur.hpp"
#include <vector>
#include <map>

class Joueur;

class Creature : public Carte
{
private:
    vector<string> capacite;
    map<string, int> cout_couleur;
    int cost, force, endurance, idCreature, base_endurance;
    bool peutAttaquer;

public:
    Creature(string nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, map<string, int> cout_couleur, int cost, int force, int endurance, bool peutAttaquer); // Constructeur à faire
    ~Creature(){};                                                                                                                                                        // Destructeur

    // les gets
    int getCost();
    int getForce();
    int getEndurance();
    int getBaseEndurance();
    vector<string> getCapacite();
    map<string, int> getCout_Couleur();
    int getID();
    bool getPeutAttaquer();

    // les sets
    void setCost(int i);
    void setForce(int i);
    void setEndurance(int i);
    void setBaseEndurance(int i);
    void minusEndurance(int i);
    void setPeutAttaquer();
    // les methodes
    void print();
    void printCouleur();
    int CoutTotale();
    string SpaceName();
    string SpaceLieu();

};

#endif