#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include "Carte.hpp"
#include "Deck.hpp"

using namespace std;

class Deck;

class Joueur {
    private : 
    vector<Carte> Hand, Bibli, Board, GraveYard; // Voir si on specifie Creature ou Terrain au lieu de Carte
    int HP = 20;
    string nom;
    bool mort = false;
    int ID;
    public :

    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP); 
    Joueur(string nom, int HP, int ID, vector<Carte> Hand , vector<Carte> Bibli , vector<Carte> Board , vector<Carte> GraveYard);
    Joueur(string nom, int HP, int ID);
    Joueur(); 
    // -- -- -- -- DESTRUCTEUR -- -- -- --
    ~Joueur() {};

    // -- -- -- -- Les gets -- -- -- --
    int getHP();
    string getNom();
    bool getMort();
    vector<Carte> getBibli();
    vector<Carte> getHand();
    vector<Carte> getGraveYard();
    vector<Carte> getBoard();

    //-- -- -- -- Les sets -- -- -- -- 
    void setNom(string n);
    void setHP(int s);
    vector<Carte> setBibli(Deck v);
   
    //-- -- -- -- methodes -- -- -- -- 
    void RecevoirDegat(int nbDegat);
    bool VerifMort();
    void MelangeBibli(vector<Carte> v );
    void printBibli();
    void printHand();
    int ParcourirBoard(vector<Carte> v);
    //-- -- -- -- Phases -- -- -- --
    Carte ChoixCreature();
    int PhaseDePioche();
    int PhaseDeDesengagement();
    bool PhasePrincipale();
    int PhaseSecondaire();
    int FinDeTour();

};

#endif