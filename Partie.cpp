    
    #include "Partie.hpp"
    #include <ctime>
    #include <stdlib.h>
    #include <iostream>


    // -- -- -- Constructeur -- -- --
    Partie::Partie(Joueur J1, Joueur J2, int tour) {
        this-> J1 = J1;
        this-> J2 = J2;
        this -> tour = 0;
    }

    // -- -- -- les gets -- -- -- 
    Joueur Partie::getJoueur1() { return J1;}
    Joueur Partie::getJoueur2() { return J2;}
    int Partie::getTour() { return tour; }
    
    // -- -- -- les sets -- -- --
    void Partie::setTour(int t) { tour = t; } // Voir si on garde
    void Partie::setJoueur1(Joueur j) { J1 = j; }
    void Partie::setJoueur2(Joueur p) { J2 = p; }

    //  -- -- -- les methodes -- -- --
    int Partie::TourSuivant() {
        return this-> tour + 1;
    }

    int Partie::JoueurCommence() {
         srand(time(NULL));
         return rand()%2 + 1;
    }

    bool Partie::FinDePartie() {
        if ( this->getJoueur1().getHP() <= 0 || this->getJoueur2().getHP() <= 0) {
            return false;
        }
        return true;
    
        // Ajouter plus tard les autres règles
    }

