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

    // ------------------------------ LES GETS ------------------------------
    virtual int getCost() = 0;
    virtual map<string, int> getCout_Couleur() = 0;
    virtual int getID() = 0;
    virtual int getForce();
    virtual int getEndurance();
    virtual int getBaseEndurance();
    virtual vector<string> getCapacite();
    virtual int getForceBonus();
    virtual int getEnduranceBonus();
    virtual string getTarget();
    virtual string getType();
    string getCouleur();
    string getNom();
    string getLieu();
    int getNumero();
    virtual bool getPeutAttaquer();
    virtual bool getEtat();

    // ------------------------------ LES SETS ------------------------------
    void virtual setForce(int i);
    void virtual setEndurance(int i);
    void virtual setBaseEndurance(int i);
    void virtual minusEndurance(int i);

    virtual void setPeutAttaquer();
    virtual void setPeutPasAttaquer();
    virtual int CoutTotale() { return 0; }
    virtual void setLieu(string l);
    virtual void setEngage();
    virtual void setDesengage();

    // ------------------------------ LES METHODES ------------------------------
    void Death();
    virtual void printCouleur();
    virtual string SpaceName();
    virtual string SpaceLieu();
    friend bool operator==(Carte const &c, Carte const &c1);

};

#endif