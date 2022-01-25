#include "../Headers/Joueur.hpp"
#include "../Headers/Creature.hpp"
#include "../Headers/Terrain.hpp"
#include "../Headers/Partie.hpp"
#include "../Headers/Deck.hpp"
#include "../Headers/printAffichage.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
     
     printAffichage p = printAffichage();
     srand(time(NULL));
     // int tour = 0;
     string name1;
     string name2;

     p.printLogo();

     cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;

     cout << " Veuillez choisir le nom du premier Joueur" << endl;
     getline(cin, name1);
     cout << " Veuillez choisir le nom du deuxieme Joueur" << endl;
     getline(cin, name2);

     // -- Creation Joueur --
     Joueur J1 = Joueur(name1, 5, 1); // Joueur1
     Joueur J2 = Joueur(name2, 5, 2); // Joueur2
     // -- Creation de la partie --
     Partie game = Partie(J1, J2, 1); // Creation de la partie. OK.
     game.PartieDeMagic(J1, J2);

     
     return 0;
}

/* ------------------------------------------------- */
/* TEST DE : MELANGE BIBLI + PHASE DE PIOCHE */
/* ------------------------------------------------- */

/*  cout << "--------------------------------------------------------------------" << endl;
  cout << " TEST DE : MELANGE BIBLI + PHASE DE PIOCHE  " << endl;
  cout << "--------------------------------------------------------------------" << endl;
  Deck dPioche = Deck("DeckTestPioche"); // Creation du Deck. OK.
  J1.setBibli(dPioche);
  cout << "--------------------------------------------------------------------" << endl;
  cout << " BIBLI AVANT MELANGE " << endl;
  cout << "--------------------------------------------------------------------" << endl;
  J1.printBibli();
  J1.MelangeBibli();
  cout << "--------------------------------------------------------------------" << endl;
  cout << " BIBLI APRES MELANGE " << endl;
  cout << "--------------------------------------------------------------------" << endl;
  J1.printBibli();
  J1.setInitialHand();
  cout << "--------------------------------------------------------------------" << endl;
  cout << " HAND EN COMMENCANT LA PARTIE " << endl;
  cout << "--------------------------------------------------------------------" << endl;
  J1.printHand();
  J1.PhaseDePioche();
  cout << "--------------------------------------------------------------------" << endl;
  cout << " HAND APRES AVOIR PIOCHER " << endl;
  cout << "--------------------------------------------------------------------" << endl;
  J1.printHand();
  */

/* ------------------------------------------------- */
/* TEST DE : PHASE DESENGAGEMENT + PHASE PRINCIPALE */
/* ------------------------------------------------- */
/*
Deck dPrinciapal = Deck("DeckTest"); // Creation du Deck. OK.
     J1.setBibli(dPrinciapal);
     J1.MelangeBibli();
     J1.setInitialHand();
     J1.PhaseDePioche();

     Terrain *t1 = new Terrain("Plains", "White", "Board", true, 1);
     Terrain *t2 = new Terrain("Island", "Blue", "Board", true, 2);
     Terrain *t3 = new Terrain("Swamp", "Black", "Board", true, 3);
     Terrain *t4 = new Terrain("Mountain", "Red", "Board", true, 4);
     Terrain *t5 = new Terrain("Forest", "Green", "Board", true, 5);

     vector<Carte *> v = {t1, t2, t3, t4, t5};
     J1.setBoard(v);

     cout << "--------------------------------------------------------------------" << endl;
     cout << " HAND AVANT PHASE PRINCIPALE " << endl;
     cout << "--------------------------------------------------------------------" << endl
          << endl;
     J1.printHand();
     cout << "--------------------------------------------------------------------" << endl;
     cout << " BOARD AVANT PHASE PRINCIPALE " << endl;
     cout << "--------------------------------------------------------------------" << endl
          << endl;
     J1.printBoard();

     J1.PhaseDeDesengagement();
     cout << "--------------------------------------------------------------------" << endl;
     cout << " Phase de desengament tout les terrains pour le test on etait engager " << endl;
     cout << "--------------------------------------------------------------------" << endl;
     J1.printBoard();
     J1.PhasePrincipale();

     cout << "--------------------------------------------------------------------" << endl;
     cout << " HAND APRES PHASE PRINCIPALE " << endl;
     cout << "--------------------------------------------------------------------" << endl
          << endl;
     J1.printHand();
     cout << "--------------------------------------------------------------------" << endl;
     cout << " BOARD APRES PHASE PRINCIPALE " << endl;
     cout << "--------------------------------------------------------------------" << endl
          << endl;
     J1.printBoard();

     cout << "--------------------------------------------------------------------" << endl;
     cout << " Phase secondaire " << endl;
     cout << "--------------------------------------------------------------------" << endl
          << endl;

     J1.PhaseSecondaire();

*/