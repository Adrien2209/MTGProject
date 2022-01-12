#ifndef CARTE_H
#define CARTE_H

#include <string>
using namespace std;

class Carte {
    private : 
    string nom, couleur, lieu;
    bool etat;
    
    public :
    Carte(string  nom, string couleur, string lieu, bool etat); // Constructeur
    ~Carte() {}; // Destructeur

    void virtual print();
    
    // Les gets

    string getCouleur();
    string getNom();
    string getLieu();
    
    // Les sets
    void setLieu(string l);
    void setEngage();
    void setDesengage();
    // Les methodes
    
    bool getEtat();

    void Death();

};

#endif