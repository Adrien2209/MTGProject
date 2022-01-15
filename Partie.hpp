#ifndef PARTIE_H
#define PARTIE_H

#include "Joueur.hpp"
#include <vector>

class Partie {
    private : 
    Joueur J1, J2;
    int tour;

    public :

    Partie(Joueur J1, Joueur J2, int tour = 0); // Constructeur à faire
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
    Joueur JoueurCommence();
    Joueur ChangementDeJoueur();
    int TourSuivant();
    void PhaseDeCombat(Joueur &J1, Joueur &J2);
    bool FinDePartie();

};

#endif