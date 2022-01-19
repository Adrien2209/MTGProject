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
    // int tour = 0;
    string name1;
    string name2;
    cout << "Lancement du jeu ... [||||||||||||||||||||||||||||||||||||||___________] 70 %" << endl;
    cout << "                     [|||||||||||||||||||||||||||||||||||||||||||||||||] 100 %" << endl;
    cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    getline(cin, name1);
    cout << " Veuillez choisir le nom du deuxieme Joueur" << endl;
    getline(cin, name2);

    // -- Creation Joueur --
    Joueur J1 = Joueur(name1, 20, 1); // Joueur1
    Joueur J2 = Joueur(name2, 20, 2); // Joueur2

    // -- Creation de la partie --
    Partie game = Partie(J1, J2, 1); // Creation de la partie. OK.

    game.PartieDeMagic(J1, J2);


        return 0;
}

/* cout << "-------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "                AVANT MELANGE J1                       " << endl;
  J1.printBibli();

  cout << "-------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "-------------------------------------------------------" << endl;
  cout << "                AVANT MELANGE J2                       " << endl;
  J2.printBibli();
  */

/*
    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "                APRES MELANGE J1                       " << endl;
    J1.printBibli();



    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "-------------------------------------------------------" << endl;
    cout << "                APRES MELANGE J2                       " << endl;
    J2.printBibli();
    */

/*
        while (J1.getHP() > 0 && J2.getHP() > 0) {
            if (J1.VerifMort()) {
                cout << " Bravo au joueur  " << J2.getNom() << " Pour la victoire UHO ! " << endl;
                                    return 0; }
            if (J2.VerifMort()) { cout << " Bravo au joueur  " << J1.getNom() << " Pour la victoire UHO ! " << endl;
                                    return 0; }
            c3.AttaqueJoueur(J2);
            }

    */
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
