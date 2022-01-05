#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.hpp"
#include <vector>

class Partie {
    private : 
    Joueur static J1, J2;
    int static tour;

    public :
    Partie();
    Partie(Joueur, Joueur, int tour); // Constructeur à faire
    ~Partie() {}; // Destructeur

    //les gets
    Joueur getJoueur1();
    Joueur getJoueur2();
    int getTour();
    
    // les sets 

    void setTour(int t);
    void setJoueur1(Joueur J);
    void setJoueur2(Joueur J);
    // méthodes

    string FinDePartie(); // renvoie si la partie est finie




};

#endif