#ifndef CARTE_H
#define CARTE_H

#include <string>
#include <vector>
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
    vector<string> virtual getCout_Couleur() = 0;
    int virtual getID() = 0;
    void virtual print();
   
    
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