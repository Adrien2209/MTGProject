#ifndef CARTE_H
#define CARTE_H

#include <string>
using namespace std;

class Carte {
    private : 
    string nom, type;
    int cout, force, endurance;
    bool est_engage;
    
    public :
    Carte(string  nom, int cout, string type, int force, int endurance, bool est_engage); // Constructeur
    ~Carte() {}; // Destructeur

    // Les gets
    int Carte::getForce();
    string Carte::getNom();
    int Carte::getCout();
    string Carte::getType();
    int Carte::getEndurance();

    // Les methodes

    bool est_Engage(Carte c1) {
        return est_engage;
        
    }


    





};

#endif