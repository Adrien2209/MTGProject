#ifndef TERRAIN_H
#define TERRAIN_H

#include "Carte.hpp"

class Terrain : public Carte {
    public :
    Terrain(string nom, string couleur, string lieu, bool etat); // Constructeur
    ~Terrain() {}; // Destructeur



};

#endif