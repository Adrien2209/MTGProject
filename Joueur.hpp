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
    vector<Carte *> Hand, Bibli, Board, GraveYard; // Voir si on specifie Creature ou Terrain au lieu de Carte
    int HP = 20;
    string nom;
    bool mort = false;
    bool APoserTerrain = false;
    int ID;
    Color c1 = Color::quelleCouleur("Red");
    Color c2 = Color::quelleCouleur("Green");
    Color c3 = Color::quelleCouleur("Blue");

public:
    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP);
    Joueur(string nom, int HP, int ID, vector<Carte *> Hand, vector<Carte *> Bibli, vector<Carte *> Board, vector<Carte *> GraveYard, bool APoserTerrain);
    Joueur(string nom, int HP, int ID);
    Joueur();
    // -- -- -- -- DESTRUCTEUR -- -- -- --
    ~Joueur(){};

    // -- -- -- -- Les gets -- -- -- --
    int getHP();
    int getId();
    string getNom();
    bool getMort();
    vector<Carte *> getBibli();
    vector<Carte *> getHand();
    vector<Carte *> getGraveYard();
    vector<Carte *> getBoard();

    //-- -- -- -- Les sets -- -- -- --
    void setNom(string n);
    void setHP(int s);
    void setBibli(Deck v);
    void setInitialHand();
    void setAPoserTerrain();
    void setPasPoserTerrain();
    vector<Carte *> setBoard(vector<Carte *> c);

    //-- -- -- -- methodes -- -- -- --
    void printBibli();
    void printHand();
    void printGraveYard();
    void printBoard();

    void addToBibli(Carte *carte);
    void addToHand(Carte *carte);
    void addToGraveYard(Carte *carte);
    void addToBoard(Carte *carte);

    void NettoyageBibli();
    void NettoyageHand();
    void NettoyageGraveYard();
    void NettoyageBoard();

    void RecevoirDegat(int nbDegat);
    bool VerifMort();
    void MelangeBibli();
    int ParcourirBoard(vector<Carte *> v);

    //-- -- -- -- Phases -- -- -- --
    void PoserCreature();
    void PhaseDePioche();
    int PhaseDeDesengagement();
    void PhasePrincipale();
    void PhaseSecondaire();
    void FinDeTour();
    map<string, int> CoutDisponibleEnJeu();
    int CoutTotalDispoEnJeu();
    void PoserTerrain();
    vector<Carte *> TerrainDispo();
    vector<Carte *> MAJTerrainDispo();
    vector<Carte *> TerrainEnMain();
    vector<Carte *> CreatureEnMain();
    bool VerifCout(Carte *CarteChoisie);
    void EngageTerrainCouleur(Carte *CarteChoisie);
    void EngageTerrainQuelconque(Carte *CarteChoisie);
    vector<string> TerrainAEngager(Carte *CarteChoisie);
    vector<Carte *> TerrainCouleurAEngage(Carte *c);

};
#endif