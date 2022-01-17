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
    //int tour = 0;
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

    Deck d1 = Deck("DeckTest2"); // Creation du Deck. OK.
    Deck d2 = Deck("DeckTest2");

    // Bibliotheques des deux joueurs. OK.
    J1.setBibli(d1);
    cout << J1.getBibli().size();
    cout << "-- -- -- -- -- Affichage de la bibliothèque de J1 -- -- -- --" << endl << endl;
    //J1.printBibli();
    
    // On melange au prealables les Bibliothèques des deux joueurs. OK.
    J1.MelangeBibli();
    cout << "-- -- -- -- -- Affichage de la bibliothèque de J1 apres melange -- -- -- --" << endl << endl;
    //J1.printBibli();

    // Creation des mains avant le dubut du premier tour. OK.
    J1.setInitialHand();
    cout << "-- -- -- -- -- Affichage de la main de J1 apres melange -- -- -- --" << endl << endl;
    //J1.printHand();
    cout << "-- -- -- -- -- Fin -- -- -- --" << endl << endl;
    // Tirage au sort joueur qui commence
  
    /*
    // PHASE DE PIOCHE OK.
    J1.PhaseDePioche(); 
    game.PhaseDeCombat(J1, J2);
    
    cout << endl << " ----------------- Cimetierre de J1 ----------------- " << endl;
    J1.printGraveYard();
    cout << endl << " ----------------- Cimetierre de J2 ----------------- " << endl;
    J2.printGraveYard();

      Terrain* Plains = new Terrain("Plains", "White", "", false);
    Terrain* Island = new Terrain("Island", "Blue", "", false);
    Terrain* Swamp = new Terrain("Swamp", "Black", "", false);
    Terrain* Mountain = new Terrain("Island", "Red","", false);
    Terrain* Forest = new Terrain("Island", "Green", "", false);

    vector<Carte*> BoardJ1 = { Plains, Island, Swamp, Mountain, Forest,Plains, Island, Swamp, Mountain, Forest, Plains, Island, Swamp, Mountain, Forest};
    vector<Carte*> BoardFinal = J1.setBoard(BoardJ1);

    vector<Carte*> CreaturePoser = J1.ChoixCreature();

    for ( Carte* c : CreaturePoser) {
        c->print();
    }
    //JoueurQuiJoue.PhaseDePioche();
    //cout << " ----------------- MAIN APRES LA PHASE DE PIOCHE ----------------- " << endl;
    //JoueurQuiJoue.printHand();
    */

    // Phase de Pioche

    /*while (J1.getHP() > 0 && J2.getHP() > 0)
    {
        // On augmente change le tour :
        game.setTour(tour);
        cout << "LE TOUR " << game.getTour() << " COMMENCE ! " << JoueurQuiJoue.getNom() << " a votre tour. PHASE DE PIOCHE " << endl;

        // HP de chaque Joueur :
        cout << "LES HPs de : " << game.getJoueur1().getNom() << " = " << game.getJoueur1().getHP() << endl;
        cout << "LES HPs de : " << game.getJoueur2().getNom() << " = " << game.getJoueur2().getHP() << endl;

        // Phase de pioche
        if (game.getTour() != 1) // Au tout premier tour le premier joueur ne pioche pas !
        {

        }

        // Phase de desengagement
        JoueurQuiJoue.PhaseDeDesengagement();
        // Phase Principale
        // JoueurQuiJoue.PhasePrincipale();
        // Phase de combat

        // phase secondaire

        // Fin de tour
        tour++;
        JoueurQuiJoue = game.ChangementDeJoueur();
}*/

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
