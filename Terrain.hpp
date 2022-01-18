#ifndef TERRAIN_H
#define TERRAIN_H

#include "Carte.hpp"

class Terrain : public Carte {
    private : 
    int idTerrain ;
    public :
    Terrain(string nom, string couleur, string lieu, bool etat, int numero); // Constructeur
    ~Terrain() {}; // Destructeur
    void print();
    int getID();
    int getCost();
    map<string,int> getCout_Couleur();
    void getDesengage();
};

#endif