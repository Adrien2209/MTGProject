#include "Joueur.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"
#include "Partie.hpp"
#include "Deck.hpp"
#include <iostream>
#include <stdlib.h>

using namespace std;

int main() {
    
    srand(time(NULL));
 

    string name1;
	string name2;
	cout << "Lancement du jeu ... [||||||||||||||||||||||||||||||||||||||___________] 100 %" << endl;
    cout << "                     [|||||||||||||||||||||||||||||||||||||||||||||||||] 100 %" << endl;
    cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    getline(cin,name1);
    cout << " Veuillez choisir le nom du deuxieme Joueur" << endl;
    getline(cin,name2);
    
    // -- Creation Joueur -- 
    Joueur J1 = Joueur(name1, 20, 1); // Joueur1
    Joueur J2 = Joueur(name2, 2, 2); // Joueur2
    
    // -- Creation Creature et Terrain -- 
    Terrain land1("Forest", "G","Bibli", true);
    Terrain land2("Island", "L","Bibli", true);
    Terrain land3("Mountain", "R","Bibli", true);
    Terrain land4("Plains", "W","Bibli", true);
    Terrain land5("Swamp", "B","Bibli", true);
    //-----------------------------------------------------------------------
    Creature c1 = Creature("Zebi", "White", "Board", true);
    Creature c2 = Creature("Zebi2", "White", "Board", true, {""}, {""}, 1, 1,10);
    Creature c3 = Creature("Soldier", "White", "Board", true, {""}, {""}, 1, 2, 3);
    Creature c4 = Creature("Armored_Pegasus", "white", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c5 = Creature("White_Knight", "White", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c6 = Creature("Angry_Bear", "Green", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c7 = Creature("Guard", "White", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c8 = Creature("WereWolf", "Green", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c9 = Creature("Skeleton", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c10 = Creature("Ghost", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c11 = Creature("Black_Knight", "Black","Board", true, {""}, {""}, 1, 3, 3);
    Creature c12 = Creature("Orc_Maniac", "Red", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c13 = Creature("Hobgoblin", "Red", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c14 = Creature("Vampire", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c15 = Creature("WassLaMenace", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c16 = Creature("AdLaCisaille", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c17 = Creature("BilouLeLoup", "Black", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c18 = Creature("RayaneLane", "Black", "Board", true, {""}, {""}, 1, 3, 3);

    Carte c = Carte("zub", "Blue", "Board", true);

    c.print();
    c2.print();

    // -- Creation Deck -- 
    Deck d = Deck("Wass", {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11,c12,c13,c14,c15,c16,c17,c18,land1, land2, land3,land4, land5,land1, land2, land3,land4, land5,land1, land2});
    Deck d1 = Deck("DeckTest");
    
    vector<Carte> Bibli = J1.setBibli(d);
    J1.MelangeBibli(Bibli);

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


    //------------------------ DECK ------------------------

/*
    cout << "HP de " << J1.getNom() << " " << J1.getHP() << endl; 
    cout << "HP du " << J2.getNom() << " " << J2.getHP() << endl;
    
    cout << " -- -- -- TEST PERTE HP -- -- --" << endl;
    cout << " HP Joueur1 avant attaque = " << J1.getHP() << endl;
    c1.AttaqueJoueur(J1);
    cout << " HP Joueur1 apres attaque = " << J1.getHP() << endl;
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
   

    return 0;  
}