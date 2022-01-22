
#include "Partie.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

// -- -- -- Constructeur -- -- --
Partie::Partie(Joueur J1, Joueur J2, int tour)
{
    this->J1 = J1;
    this->J2 = J2;
    this->tour = tour;
}

// -- -- -- les gets -- -- --
Joueur *Partie::getJoueur1() { return &J1; }
Joueur *Partie::getJoueur2() { return &J2; }
int Partie::getTour() { return tour; }

// -- -- -- les sets -- -- --
void Partie::setTour(int t) { tour = t + 1; } // Voir si on garde
void Partie::setJoueur1(Joueur j) { J1 = j; }
void Partie::setJoueur2(Joueur p) { J2 = p; }

//  -- -- -- les methodes -- -- --
void Partie::PartieDeMagic(Joueur J1, Joueur J2){
    //Selection du deck
    //cout << J1.getNom() << ", veuillez choisir votre deck en rentrant son nom :" << endl;
    string deckJ1 = "DeckTest2";
    //getline(cin, deckJ1);
    //cout << J2.getNom() << ", veuillez choisir votre deck en rentrant son nom :" << endl;
    string deckJ2 = "DeckTest2";
    //getline(cin, deckJ2);

    // -- Creation Deck --
    Deck d1 = Deck(deckJ1); // Creation du Deck. OK.
    Deck d2 = Deck(deckJ2);

    // Bibliotheques des deux joueurs. OK.
    J1.setBibli(d1);
    J2.setBibli(d2);

    // On melange au prealables les Bibliothèques des deux joueurs. OK.
    J1.MelangeBibli();
    J2.MelangeBibli();

    // Creation des mains avant le dubut du premier tour. OK.
    J1.setInitialHand();
    J2.setInitialHand();
    //J1.NettoyageBibli();
    //J2.NettoyageBibli();
    cout << " -------------------------------------------------------------------------------------" << endl;
    cout << " -------------------------------------------------------------------------------------" << endl;
    cout << " -------------------------------------------------------------------------------------" << endl;
    cout << " -------------------------------------------------------------------------------------" << endl;
    cout << " -------------------------------------------------------------------------------------" << endl;
    for ( Carte * c : J1.getHand()) {
        c->printCouleur();
    }

    int n = rand()%2;

    while(J1.getHP()>0 || J2.getHP()>0){
        if( n % 2 == 0){
            J1.PhaseDePioche();
            //J1.PhaseDeDesengagement();
            //J1.PhasePrincipale();
            PhaseDeCombat(J1, J2);
            J1.NettoyageHand();
            J2.NettoyageHand();
            cout << "Cimetiere de : " << J1.getNom() << endl;
            J1.printGraveYard();
            cout << "Cimetiere de : " << J2.getNom() << endl;
            J2.printGraveYard();

            cout << "Main de : " << J1.getNom() << endl;
            J1.printHand();
            cout << "Main de : " << J2.getNom() << endl;
            J2.printHand();
            // Ajouter phase secondaire
            // Ajouter fin de tour */
            n += 1;
            
        }

        if( n % 2 == 1){
            J2.PhaseDePioche();
            //J2.PhaseDeDesengagement();
            //J2.PhasePrincipale();
            PhaseDeCombat(J2, J1);
            J1.NettoyageHand();
            J2.NettoyageHand();
            cout << "Cimetiere de : " << J1.getNom() << endl;
            J1.printGraveYard();
            cout << "Cimetiere de : " << J2.getNom() << endl;
            J2.printGraveYard();

            cout << "Main de : " << J1.getNom() << endl;
            J1.printHand();
            cout << "Main de : " << J2.getNom() << endl;
            J2.printHand();

            // Ajouter phase secondaire
            // Ajouter fin de tour */
            n += 1;
        }
    }
}

int Partie::TourSuivant()
{
    return this->tour + 1;
}

Joueur *Partie::ChangementDeJoueur()
{
    if (this->JoueurCommence().getNom() == this->getJoueur2()->getNom())
    {
        return this->getJoueur1();
    }
    else
    {
        return this->getJoueur2();
    }
}

Joueur &Partie::JoueurCommence()
{
    srand(time(NULL));
    int IdJoueur = rand() % 2 + 1;
    if (this->getJoueur1()->getId() == IdJoueur)
    {
        cout << "Le Joueur qui commence sera : " << J1.getNom() << endl;
        return J1;
    }
    else
    {
        cout << "Le Joueur qui commence sera : " << J2.getNom() << endl;
    }
    return J2;
}

void Partie::PhaseDeCombat(Joueur &J1, Joueur &J2)
{
    // -- -- -- -- -- Partie choix de l'attaquant -- -- -- -- --

    vector<Carte *> liste_Attaque = {}; // Liste qui donne toutes les cartes avec lesquelles l'attaque est possible

    for (unsigned int i = 0; i < J1.getHand().size(); i++)
    {
        if (J1.getHand()[i]->getID() == 2 && J1.getHand()[i]->getEtat() == false)
        {
            liste_Attaque.push_back(J1.getHand()[i]);
        }
    }

    cout << endl
         << "-- -- -- -- -- Sac a viande " << J1.getNom() << " -- -- -- -- -- " << endl
         << endl;

    for (Carte *carte : liste_Attaque)
    { // J'affiche les cartes avec lesquelles l'attaque est possible
        carte->printCouleur();
    }

    cout << endl
         << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer. Quand tu as fini, rentre OK, ET EN MAJUSCULE !! :\n";

    string safeword = "";                 // Mot cle defini a OK qui permet a l'utilisateur de terminer son action
    vector<int> choix_attaquant = {};     // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite attaquer
    vector<Carte *> Attacking_Cards = {}; // Vecteur de carte qui contient les cartes qui vont attaquer

    while (safeword != "OK")
    { // Tant que l'utilisateur n'a pas ecrit ok, il rentre les cartes avec lesquelles il compte attaquer
        cin >> safeword;
        if (safeword != "OK")
        {
            choix_attaquant.push_back(stoi(safeword));
            safeword = "";
        }
    }
    for (int i : choix_attaquant)
    { // Ajout des cartes dans le vecteur de carte qui contient les cartes qui vont attaquer
        Attacking_Cards.push_back(liste_Attaque[i - 1]);
    }

    cout << "-- -- -- -- -- Tu as donc selectionne les cartes suivantes -- -- -- -- --" << endl
         << endl;

    for (Carte *carte : Attacking_Cards)
    { // Affichage des cartes selectionne par le joueur
        carte->printCouleur();
    }

    // -- -- -- -- -- Partie choix du defenseur -- -- -- -- --

    cout << endl
         << "-- -- -- -- -- Enfin !! Maintenant fumier " << J2.getNom() << " -- -- -- -- --" << endl;

    vector<Carte *> liste_Defense = {}; // Liste qui donne toutes les cartes avec lesquelles la defense est possible
    safeword = "";

    for (unsigned int i = 0; i < J2.getHand().size(); i++)
    {
        if (J2.getHand()[i]->getID() == 2 && J2.getHand()[i]->getEtat() == false)
        {
            liste_Defense.push_back(J2.getHand()[i]);
        }
    }

    for (Carte *carte : Attacking_Cards)
    {
        cout << "-- -- -- -- -- Quelle carte va proteger ton fessier de poule mouille contre -- -- -- -- --" << endl << endl;
        carte->printCouleur();
        cout << endl << "-- -- -- -- -- Veux tu defendre sur cette carte ? Ci dessous les cartes avec lesquelles tu peux defendre -- -- -- -- --" << endl;
        cout << "-- -- -- -- -- Rentre OUI si tu veux defendre, NON sinon -- -- -- -- --" << endl << endl;
        
        for (Carte *carte_def : liste_Defense)
        {
            carte_def->printCouleur();
        }

        cin >> safeword;

        if (safeword == "NON")
        {
            cout << "Ok, celle-ci va te percuter de plein fouet" << endl;
            cout << "HP de defenseur avant attaque : " << J2.getHP() << endl;
            J2.setHP((J2.getHP()) - (carte->getForce()));
            cout << "HP de defenseur apres attaque : " << J2.getHP() << endl;
            safeword = "";
        }
        
        if (safeword == "OUI")
        {
            bool stop = false;
            cout << endl << "Tres bien, avec quelle carte compte tu defendre ? Rentre OK quand tu as fini" << endl;
            safeword = "";

            for (Carte *carte_def : liste_Defense)
            {
                carte_def->printCouleur();
            }

            cin >> safeword;

            if(safeword == "OK"){
                    stop = true;
                }

            while(stop == false){
                cout << endl << "-- -- -- -- -- Tu as choisi cette carte -- -- -- -- --" << endl << endl;
                liste_Defense[stoi(safeword)-1]->printCouleur();

                //Actualisation des points de vie
                liste_Defense[stoi(safeword)-1]->minusEndurance(carte->getForce());
                carte->minusEndurance(liste_Defense[stoi(safeword)-1]->getForce());

                if(liste_Defense[stoi(safeword)-1]->getEndurance() <= 0){
                    liste_Defense[stoi(safeword)-1]->setLieu("GraveYard");
                    
                    
                }
                if(carte->getEndurance() <= 0){
                    carte->setLieu("GraveYard");
                }
                liste_Defense.erase(liste_Defense.begin() + stoi(safeword)-1);

                cout << endl << "Tres bien, avec quelle carte compte tu defendre ? Rentre OK quand tu as fini" << endl;
                safeword = "";

                for (Carte *carte_def : liste_Defense)
                {
                    carte_def->printCouleur();
                }

                cin >> safeword;

                if(safeword == "OK"){
                    stop = true;
                }
            }
        }
        safeword = "";
    }
    cout << "fin de phase d'attaque" << endl;
}

bool Partie::FinDePartie()
{
    if (this->getJoueur1()->getHP() <= 0 || this->getJoueur2()->getHP() <= 0)
    {
        return false;
    }
    return true;

    // Ajouter plus tard les autres regles
}
