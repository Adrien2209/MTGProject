#ifndef ENCHANTEMENT_HPP
#define ENCHANTEMENT_HPP

#include "Carte.hpp"

class Enchantement : public Carte
{
private:
    int ForceBonus;
    int EnduranceBonus;
    int idEnchantement;
    string Target;

    map<string, int> cout_couleur;
    vector<string> cout_couleur_str;
    int cost;

public:
    Enchantement(string nom, string couleur, string lieu, bool etat, int numero, map<string, int> cout_couleur, int cost, int ForceBonus, int EnduranceBonus, string Target, vector<string> cout_couleur_str); // Constructeur
    ~Enchantement(){};                                                                                                                                                                                         // Destructeur

    // Tous les gets
    int getID();
    int getCost();
    map<string, int> getCout_Couleur();
    void getDesengage();
    int getForceBonus();
    int getEnduranceBonus();
    string getTarget();

    void printCouleur();
    string printCoutCouleur();

    string SpaceName();
    string SpaceLieu();
    string SpaceTarget();
};

#endif