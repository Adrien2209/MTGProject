
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
Joueur Partie::getJoueur1() { return J1; }
Joueur Partie::getJoueur2() { return J2; }
int Partie::getTour() { return tour; }

// -- -- -- les sets -- -- --
void Partie::setTour(int t) { tour = t + 1; } // Voir si on garde
void Partie::setJoueur1(Joueur j) { J1 = j; }
void Partie::setJoueur2(Joueur p) { J2 = p; }

//  -- -- -- les methodes -- -- --
int Partie::TourSuivant()
{
    return this->tour + 1;
}

Joueur Partie::ChangementDeJoueur()
{
    if (this->JoueurCommence().getNom() == J1.getNom())
    {
        return J2;
    }
    else
    {
        return J1;
    }
}

Joueur Partie::JoueurCommence()
{
    srand(time(NULL));
    int IdJoueur = rand() % 2 + 1;
    if (J1.getId() == IdJoueur)
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
    vector<Carte> liste_Attaque = {}; // Liste qui donne toutes les cartes avec lesquelles l'attaque est possible

    for (unsigned int i = 0; i < J1.getBoard().size(); i++)
    {
        if (J1.getBoard()[i].getID() == 2 || J1.getBoard()[i].getEtat() == false)
        {
            liste_Attaque.push_back(J1.getBoard()[i]);
        }
    }

    cout << "Sac a viande " << J1.getNom() << "\n";
    cout << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer. Quand tu as fini, rentre OK, ET EN MAJUSCULE !! :\n";

    for (Carte carte : liste_Attaque)
    { // J'affiche les cartes avec lesquelles l'attaque est possible
        carte.print();
    }

    string safeword = "";                 // Mot clé défini à OK qui permet à l'utilisateur de terminer son action
    vector<int> choix_attaquant = {};     // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite attaquer
    vector<Carte> Attacking_Cards = {}; // Vecteur de carte qui contient les cartes qui vont attaquer

    while (safeword != "OK")
    { // Tant que l'utilisateur n'a pas écrit ok, il rentre les cartes avec lesquelles il compte attaquer
        cin >> safeword;
        if (safeword != "OK")
        {
            choix_attaquant.push_back(stoi(safeword));
            safeword = "";
        }
    }

    for (int i : choix_attaquant)
    { // Ajout des cartes dans le vecteur de carte qui contient les cartes qui vont attaquer
        Attacking_Cards.push_back(liste_Attaque[i]);
    }

    cout << "Tu as donc selectionne les cartes suivantes : \n";

    for (Carte carte : Attacking_Cards)
    { // Affichage des cartes selectionne par le joueur
        carte.print();
    }
/*
    cout << "Enfin !! Maintenant fumier " << J2.getNom() << "\n";

    vector<Carte> liste_Defense = {}; // Liste qui donne toutes les cartes avec lesquelles la defense est possible
    safeword = "";
    vector<int> choix_defenseur = {}; // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite defendre

    for (unsigned int i = 0; i < J1.getBoard().size(); i++)
    { // Liste qui donne toutes les cartes avec lesquelles la defense est possible
        if (J1.getBoard()[i].getID() == 2 || J1.getBoard()[i].getEtat() = false)
        {
            liste_Defense.push_back(J1.getBoard()[i]);
        }
    }

    while (safeword != "OK")
    {
        for (Carte &carte : Attacking_Cards)
        {
            cout << "Quelle carte va protéger ton fessier de poule mouille contre :\n";
            carte.print();
            cout << "Allez choisi une carte : \n";
            for (Carte &carte : liste_Defense)
            {
                carte.print();
            }
            cin >> safeword;
            if (safeword != "OK")
            {
                choix_attaquant.push_back(stoi(safeword));
                safeword = "";
            }
        }

        cin >> safeword;
        if (safeword != "OK")
        {
            choix_attaquant.push_back(stoi(safeword));
        }
    }
    */
}
bool Partie::FinDePartie()
{
    if (this->getJoueur1().getHP() <= 0 || this->getJoueur2().getHP() <= 0)
    {
        return false;
    }
    return true;

    // Ajouter plus tard les autres règles
}
