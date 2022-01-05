#include "Joueur.hpp"
#include "Carte.hpp"
#include <iostream>

int main() {

    string name1;
	string name2;
	cout << "Lancement du jeu ... [||||||||||||||||||||||||||||||||||||||___________] 100 %" << endl;
    cout << "                     [|||||||||||||||||||||||||||||||||||||||||||||||||] 100 %" << endl;
    cout << " Bienvenue dans Magic : THE CLAQUÉ" << endl;
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    getline(cin,name1);
    cout << " Veuillez choisir le nom du premier Joueur" << endl;
    getline(cin,name2);


    Joueur J1 = Joueur("Wass", 1, 20); // Joueur1
    Joueur J2 = Joueur("AD", 2, 20); // Joueur2

    cout << J1.NombreHP() << endl;
    cout << J2.NombreHP() << endl;

    return 0;  
}