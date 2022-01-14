#include "Terrain.hpp"
#include <iostream>

Terrain::Terrain(string nom, string couleur, string lieu, bool etat, int numero) : Carte(nom, couleur, lieu, etat, numero) {
    this->idTerrain = 1;
}

int Terrain::getID() { cout << "Terrain" << endl;
return idTerrain; }

