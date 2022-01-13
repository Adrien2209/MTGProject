#include "Terrain.hpp"
#include <iostream>

Terrain::Terrain(string nom, string couleur, string lieu, bool etat) : Carte(nom, couleur, lieu, etat) {
    this->idTerrain = 1;
}

int Terrain::getID() { cout << "Terrain" << endl;
return idTerrain; }

