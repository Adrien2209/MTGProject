#include "Joueur.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"
#include "Partie.hpp"
#include "Deck.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{

    srand(time(NULL));

    string name1;
    string name2;
    cout << "Lancement du jeu ... [||||||||||||||||||||||||||||||||||||||___________] 100 %" << endl;
    cout << "                     [|||||||||||||||||||||||||||||||||||||||||||||||||] 100 %" << endl;
    cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    getline(cin, name1);
    cout << " Veuillez choisir le nom du deuxieme Joueur" << endl;
    getline(cin, name2);

    // -- Creation Joueur --
    Joueur J1 = Joueur(name1, 20, 1); // Joueur1
    Joueur J2 = Joueur(name2, 2, 2);  // Joueur2

    // -- Creation de la partie --
    Partie game = Partie(J1, J2, 0);

    // -- Creation Deck --
    Deck d1 = Deck("DeckTest");

    // Les deux joueurs
    vector<Carte> Bibli1 = J1.setBibli(d1);
    vector<Carte> Bibli2 = J2.setBibli(d1);

    // On melange au prealables les Bibliothèques des deux joueurs
    J1.MelangeBibli(Bibli1);
    J2.MelangeBibli(Bibli2);

    // Tirage au sort joueur qui commence 
    game.JoueurCommence();
    
    // Phase de Pioche
    J1.PhaseDePioche();
    /*
        // Creation de la Partie
        Partie game = Partie(J1,J2,0);
        cout << "Le Joueur qui commence sera le joueur numéro : " << game.JoueurCommence() << endl;
        int tour = 0;
        while (J1.getHP() > 0 && J2.getHP() > 0) {
            if (J1.VerifMort()) {
                cout << " Bravo au joueur  " << J2.getNom() << " Pour la victoire UHO ! " << endl;
                                    return 0; }
            if (J2.VerifMort()) { cout << " Bravo au joueur  " << J1.getNom() << " Pour la victoire UHO ! " << endl;
                                    return 0; }
            c3.AttaqueJoueur(J2);
            }

    */
    //------------------------ DECK ------------------------

    /*
        cout << "HP de " << J1.getNom() << " " << J1.getHP() << endl;
        cout << "HP du " << J2.getNom() << " " << J2.getHP() << endl;

        cout << " -- -- -- TEST PERTE HP -- -- --" << endl;
        cout << " HP Joueur1 avant attaque = " << J1.getHP() << endl;
        c1.AttaqueJoueur(J1);
        cout << " HP Joueur1 apres attaque = " << J1.getHP() << endl;
    */

    return 0;
}

/*
    cout << " zebi 2 attaque zebi 1" << endl;
    c2.AttaqueCarte(c1);
    cout << " zebi 2 endurance" << endl;
    cout << c2.getEndurance() << endl;
    cout << " zebi 1 endurance" << endl;
    cout << c1.getEndurance() << endl;
    cout << "zebi 2 attaque zebi 1" << endl;
    c2.Attaque(c1);
    cout << " zebi 2 endurance" << endl;
    cout << c2.getEndurance() << endl;
    cout << " zebi 1 endurance" << endl;
    cout << c1.getEndurance() << endl;
    cout << " zebi 1 lieu et zebi 2 lieu" << endl;
    cout << c1.getLieu() << endl;
    cout << c2.getLieu() << endl;
*/
