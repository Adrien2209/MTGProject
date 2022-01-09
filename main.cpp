//#include "Joueur.hpp"
#include "Creature.hpp"
#include <iostream>

int main() {

    string name1;
	string name2;
	cout << "Lancement du jeu ... [||||||||||||||||||||||||||||||||||||||___________] 100 %" << endl;
    cout << "                     [|||||||||||||||||||||||||||||||||||||||||||||||||] 100 %" << endl;
    cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    //getline(cin,name1);
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    //getline(cin,name2);
    cout << " Creation premiere creature" << endl;
    Creature c1 = Creature("Zebi", "White", "Board", true);
    cout << " Creation deuxieme creature" << endl;
    Creature c2 = Creature("Zebi2", "White", "Board", true, {""}, {""}, 1, 3, 3);

    cout << " zebi 2 attaque zebi 1" << endl;
    c2.Attaque(c1);
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

    //Joueur J1 = Joueur(name1, 1, 20); // Joueur1
    //Joueur J2 = Joueur(name2, 2, 20); // Joueur2

    //cout << J1.NombreHP() << endl;
    //cout << J2.NombreHP() << endl;

    return 0;  
}