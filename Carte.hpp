#ifndef CARTE_H
#define CARTE_H

#include <string>
using namespace std;

class Carte {
    private : 
    string nom, couleur;
    bool est_engage;
    
    public :
    Carte(string  nom, string couleur); // Constructeur
    ~Carte() {}; // Destructeur

    // Les gets

    string Carte::getCouleur();
    string Carte::getNom();
    
    // Les methodes

    bool est_Engage(Carte c1) {
        return est_engage;
        
    }


    





};

#endif