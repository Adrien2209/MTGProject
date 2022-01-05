#ifndef CARTE_H
#define CARTE_H

#include <string>

class Carte {
    private : 
    string nom, type;
    int cout, capacite, endurance;
    public 
    Carte(string  nom, int cout, string type, int capacite, int endurance); // Constructeur
    ~Carte() {}; // Destructeur



};

#endif