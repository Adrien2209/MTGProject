#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.hpp"
#include <vector>

class Partie {
    private : 
    Joueur J1, J2;
    int tour;

    public :
    Partie(Joueur, Joueur, int tour); // Constructeur à faire
    ~Partie() {}; // Destructeur

    //les gets
    int get();
    int get();
    int get();
    

    // méthodes

    string FinDePartie(); // renvoie si la partie est finie




};

#endif