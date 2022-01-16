
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

void Partie::PhaseDeCombat(Joueur& J1, Joueur& J2)
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

    cout << "Sac a viande " << J1.getNom() << endl;

    for (Carte *carte : liste_Attaque)
    { // J'affiche les cartes avec lesquelles l'attaque est possible
        carte->print();
    }

    cout << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer. Quand tu as fini, rentre OK, ET EN MAJUSCULE !! :\n";

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

    cout << "Tu as donc selectionne les cartes suivantes : \n";

    for (Carte *carte : Attacking_Cards)
    { // Affichage des cartes selectionne par le joueur
        carte->print();
    }

    // -- -- -- -- -- Partie choix du defenseur -- -- -- -- --

    cout << "Enfin !! Maintenant fumier " << J2.getNom() << "\n";

    vector<Carte *> liste_Defense = {}; // Liste qui donne toutes les cartes avec lesquelles la defense est possible
    safeword = "";
    vector<int> choix_defenseur = {}; // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite defendre

    for (unsigned int i = 0; i < J2.getHand().size(); i++)
    {
        if (J2.getHand()[i]->getID() == 2 && J2.getHand()[i]->getEtat() == false)
        {
            liste_Defense.push_back(J2.getHand()[i]);
        }
    }

    for (Carte *carte : Attacking_Cards)
    {
        cout << "Quelle carte va proteger ton fessier de poule mouille contre :\n";
        carte->print();
        cout << "Allez choisi une carte, si tu ne veux pas defendre, entre NON : \n";
        for (Carte *carte : liste_Defense)
        {
            carte->print();
        }
        cin >> safeword;
        if (safeword != "NON")
        {
            choix_defenseur.push_back(stoi(safeword));
            safeword = "";
        }
        if (safeword == "NON")
        {
            cout << "Ok, celle-ci va te percuter de plein fouet" << endl;
            cout << "HP de defenseur avant attaque : " << J2.getHP() << endl;
            J2.setHP((J2.getHP())-(carte->getForce()));
            cout << "HP de defenseur apres attaque : " << J2.getHP() << endl;
            safeword = "";
        }
    }
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
