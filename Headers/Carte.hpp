#ifndef CARTE_H
#define CARTE_H

#include "Color.hpp"

#include <string>
#include <vector>
#include <map>
using namespace std;

class Carte
{
private:
    string nom, couleur, lieu;
    bool etat;
    int numero;

public:
    Carte(string nom, string couleur, string lieu, bool etat, int numero); // Constructeur
    virtual ~Carte(){};                                                    // Destructeur

    virtual int getCost() = 0;
    map<string, int> virtual getCout_Couleur() = 0;
    int virtual getID() = 0;
    int virtual getForce();
    int virtual getEndurance();
    int virtual getBaseEndurance();
    vector<string> virtual getCapacite();

    int virtual getForceBonus();
    int virtual getEnduranceBonus();
    string virtual getTarget();
    string virtual getType();
    
    void virtual setForce(int i);
    void virtual setEndurance(int i);
    void virtual setBaseEndurance(int i);
    void virtual minusEndurance(int i);
    void virtual print();
    virtual void setPeutAttaquer();
    virtual int CoutTotale() { return 0; }

    // Les gets
    string getCouleur();
    string getNom();
    string getLieu();
    int getNumero();
    virtual bool getPeutAttaquer();

    // Les sets
    void setLieu(string l);
    void setEngage();
    void setDesengage();

    // Les methodes

    bool getEtat();

    void Death();

    // Affichage couleur
    virtual void printCouleur();
    virtual string SpaceName();
    virtual string SpaceLieu();

    friend bool operator==(Carte const &c, Carte const &c1);
};

#endif