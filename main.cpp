#include "Joueur.hpp"
#include "Carte.hpp"


int main() {
    Carte C1 = Carte("TEST", 2, "Feu", 4, 4);
    Carte C2 = Carte("WAF", 2, "EAU", 4, 4);
    vector<Carte> M = {C1,C2};

    Joueur J1 = Joueur(M, 20); // Joeuur1
    Joueur J2 = Joueur(M, 20); // Joeuur2

    J1.NombreHP();








    return 0;  
}