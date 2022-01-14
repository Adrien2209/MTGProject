    
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

    void Partie::PhaseDeCombat(Joueur &J1, Joueur &J2){
        vector<Carte&> liste_Attaque = {};

        for(unsigned int i = 0; i < J1.getBoard().size(); i++){
            if (J1.getBoard()[i].getID() == 2 || J1.getBoard()[i].getEtat() = false){
                liste_Attaque.push_back(J1.getBoard()[i]);
            }
        }

        cout << "Sac a viande " << J1.getNom() << "\n";
        cout << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer. Quand tu as fini, rentre OK, ET EN MAJUSCULE !! :\n";
        
        for(Carte& carte : liste_Attaque){
            carte.print();
        }

        string safeword = "";
        vector<int> choix_attaquant = {};
        vector<Carte&> Attacking_Cards = {};

        while(safeword != "OK"){
            cin >> safeword;
            if(safeword != "OK"){
                choix_attaquant.push_back(stoi(safeword));
                safeword = "";
            }
        }

        for(int i : choix_attaquant){
            Attacking_Cards.push_back(liste_Attaque[i]);
        }

        cout << "Tu as donc selectionne les cartes suivantes : \n";

        for(Carte& carte : Attacking_Cards){
            carte.print();
        }

        cout << "Enfin !! Maintenant fumier " << J2.getNom() << "\n";

        vector<Carte&> liste_Defense = {};

        for(unsigned int i = 0; i < J1.getBoard().size(); i++){
            if (J1.getBoard()[i].getID() == 2 || J1.getBoard()[i].getEtat() = false){
                liste_Defense.push_back(J1.getBoard()[i]);
            }
        }

        while(safeword != "OK"){
            for(Carte& carte : Attacking_Cards){
                cout << "Quelle carte va protéger ton fessier de poule mouille contre :\n";
                carte.print();
                cout << "Allez choisi une carte : \n";
                for(Carte& carte : liste_Defense){
                    carte.print();
                }
                cin >> safeword;
                if(safeword != "OK"){
                choix_attaquant.push_back(stoi(rep));
                }
            }

            cin >> safeword;
            if(safeword != "OK"){
                choix_attaquant.push_back(stoi(rep));
            }
        }


    }

    bool Partie::FinDePartie() {
        if ( this->getJoueur1().getHP() <= 0 || this->getJoueur2().getHP() <= 0) {
            return false;
        }
        return true;
    
        // Ajouter plus tard les autres règles
    }

