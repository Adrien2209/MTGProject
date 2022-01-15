#include "Terrain.hpp"
#include <iostream>

Terrain::Terrain(string nom, string couleur, string lieu, bool etat, int numero) : Carte(nom, couleur, lieu, etat, numero)
{
    this->idTerrain = 1;
}

int Terrain::getID()
{
    cout << "Methode getID() de Terrain " << endl;
    return idTerrain;
}

int Terrain::getCost()
{
    cout << "Methode getCost() de Terrain " << endl;
    return 0;
}

vector<string> Terrain::getCout_Couleur()
{
    cout << "Methode getCout_Couleur() de Terrain " << endl;
    return {};
}
