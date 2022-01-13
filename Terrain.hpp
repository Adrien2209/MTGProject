#ifndef TERRAIN_H
#define TERRAIN_H

#include "Carte.hpp"

class Terrain : public Carte {
    private : 
    int idTerrain ;
    public :
    Terrain(string nom, string couleur, string lieu, bool etat); // Constructeur
    ~Terrain() {}; // Destructeur

    int getID();



};

#endif