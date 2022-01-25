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
    vector<string> cout_couleur_str;
    map<string, int> cout_couleur;
    int cost, force, endurance, idCreature, base_endurance;
    bool peutAttaquer;
    string type;

public:
    Creature(string nom, string couleur, string lieu, bool etat, int numero, vector<string> capacite, map<string, int> cout_couleur, int cost, int force, int endurance, bool peutAttaquer, string type, vector<string> cout_couleur_str); // Constructeur à faire
    ~Creature(){};                                                                                                                                                                                                                         // Destructeur

    // les gets
    int getCost();
    int getForce();
    int getEndurance();
    int getBaseEndurance();
    vector<string> getCapacite();
    map<string, int> getCout_Couleur();
    int getID();
    bool getPeutAttaquer();
    string getType();

    // les sets
    void setCost(int i);
    void setForce(int i);
    void setEndurance(int i);
    void setBaseEndurance(int i);
    void minusEndurance(int i);
    void setPeutAttaquer();
    void setPeutPasAttaquer();

    // Les prints
    void printCouleur();
    string printCoutCouleur();

    
    // Gere les espaces pour afficher les cartes.
    string SpaceName();
    string SpaceLieu();
    string SpaceCapa(int n);
    string SpaceType();

    int CoutTotale();
};

#endif