#include "Joueur.hpp"
#include "Creature.hpp"
#include "Terrain.hpp"
#include <iostream>

int main() {

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
    Joueur J1 = Joueur(name1, 20); // Joueur1
    Joueur J2 = Joueur(name2, 20); // Joueur2
    
    // -- Creation Creature et Terrain -- 
    Terrain land1("Forest", "G","Bibli", true);
    Terrain land2("Island", "L","Bibli", true);
    Terrain land3("Mountain", "R","Bibli", true);
    Terrain land4("Plains", "W","Bibli", true);
    Terrain land5("Swamp", "B","Bibli", true);
    //-----------------------------------------------------------------------
    Creature c1 = Creature("Zebi", "White", "Board", true);
    Creature c2 = Creature("Zebi2", "White", "Board", true, {""}, {""}, 1, 3, 3);
    Creature c3 = Creature("Soldier", "White", "Board", true, {""}, {""}, 1, 3, 3);
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
    
    
    cout << "HP de " << J1.getNom() << " " << J1.getHP() << endl; 
    cout << "HP du " << J2.getNom() << " " << J2.getHP() << endl;
    
    cout << " -- -- -- TEST PERTE HP -- -- --" << endl;
    cout << " HP Joueur1 avant attaque = " << J1.getHP() << endl;
    c1.AttaqueJoueur(J1);
    cout << " HP Joueur1 apres attaque = " << J1.getHP() << endl;

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