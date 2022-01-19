#ifndef JOUEUR_H
#define JOUEUR_H

#include <vector>
#include <map>
#include "Carte.hpp"
#include "Deck.hpp"

using namespace std;

class Deck;

class Joueur
{
private:
    vector<Carte*> Hand, Bibli, Board, GraveYard; // Voir si on specifie Creature ou Terrain au lieu de Carte
    int HP = 20;
    string nom;
    bool mort = false;
    int ID;

public:
    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP);
    Joueur(string nom, int HP, int ID, vector<Carte*> Hand, vector<Carte*> Bibli, vector<Carte*> Board, vector<Carte*> GraveYard);
    Joueur(string nom, int HP, int ID);
    Joueur();
    // -- -- -- -- DESTRUCTEUR -- -- -- --
    ~Joueur(){};

    // -- -- -- -- Les gets -- -- -- --
    int getHP();
    int getId();
    string getNom();
    bool getMort();
    vector<Carte*> getBibli();
    vector<Carte*> getHand();
    vector<Carte*> getGraveYard();
    vector<Carte*> getBoard();

    //-- -- -- -- Les sets -- -- -- --
    void setNom(string n);
    void setHP(int s);
    void setBibli(Deck v);
    void setInitialHand();
    vector<Carte*> setBoard(vector<Carte*> c);

    //-- -- -- -- methodes -- -- -- --
    void printBibli();
    void printHand();
    void printGraveYard();
    void printBoard();

    void addToBibli(Carte* carte);
    void addToHand(Carte* carte);
    void addToGraveYard(Carte* carte);
    void addToBoard(Carte* carte);

    void NettoyageBibli();
    void NettoyageHand();
    void NettoyageGraveYard();
    void NettoyageBoard();

    void RecevoirDegat(int nbDegat);
    bool VerifMort();
    void MelangeBibli();
    int ParcourirBoard(vector<Carte*> v);
    
    //-- -- -- -- Phases -- -- -- --
    vector<Carte*> ChoixCreature();
    void PhaseDePioche();
    int PhaseDeDesengagement();
    void PhasePrincipale();
    int PhaseSecondaire();
    int FinDeTour();
    map<string, int> CoutDisponibleEnJeu();
    int CoutTotalDispoEnJeu();
    void PoserTerrain();
    vector<Carte*> TerrainDispo();
};

#endif