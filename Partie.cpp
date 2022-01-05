    
    #include "Partie.hpp"
    
    int Partie::tour = 0;
    Joueur Partie::J1 = Joueur("J1",1);
    Joueur Partie::J2 = Joueur("J2",2);

    // -- -- -- Constructeur -- -- --
    Partie::Partie() {
        this-> J1 = J1;
        this-> J2 = J2;
        tour++;
    }

    // -- -- -- les gets -- -- -- 
    Joueur Partie::getJoueur1() { return J1;}
    Joueur Partie::getJoueur2() { return J2;}
    int Partie::getTour() { return tour; }
    
    // -- -- -- les sets -- -- --
    void Partie::setTour(int t) { tour = t; }
    void Partie::setJoueur1(Joueur J) { J1 = J; }
    void Partie::setJoueur1(Joueur J) { J2 = J; }