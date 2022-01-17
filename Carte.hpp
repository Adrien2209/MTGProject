#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>
#include <map>
using namespace std;

class Carte {
    private : 
    string nom, couleur, lieu;
    bool etat;
    int numero;
    

    public :
    Carte(string  nom, string couleur, string lieu, bool etat, int numero); // Constructeur
    ~Carte() {}; // Destructeur

    int virtual getCost() = 0;
    map<string,int> virtual getCout_Couleur() = 0;
    int virtual getID() = 0;
    int virtual getForce();
    int virtual getEndurance();
    int virtual getBaseEndurance();

    void virtual setForce(int i);
    void virtual setEndurance(int i);
    void virtual setBaseEndurance(int i);
    void virtual minusEndurance(int i);
    void virtual print();
    int virtual CoutTotale() { return 0;}
    
    // Les gets

    string getCouleur();
    string getNom();
    string getLieu();
    int getNumero();
    
    // Les sets
    void setLieu(string l);
    void setEngage();
    void setDesengage();

    // Les methodes
    
    bool getEtat();

    void Death();

};

#endif