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
    Color c1 = Color::CouleurChoisie("Red");
    Color c2 = Color::CouleurChoisie("Green");
    Color c3 = Color::CouleurChoisie("Blue");

public:
    // -- -- -- -- CONSTRUCTEUR -- -- -- --
    // Joueur(Deck d, int HP);
    Joueur(string nom, int HP, int ID, vector<Carte *> Hand, vector<Carte *> Bibli, vector<Carte *> Board, vector<Carte *> GraveYard, bool APoserTerrain, bool mort);
    Joueur(string nom, int HP, int ID);
    Joueur();
    // -- -- -- -- DESTRUCTEUR -- -- -- --
    ~Joueur(){};

    // ------------------------------ LES GETS ------------------------------
    int getHP();
    int getId();
    string getNom();
    bool getMort();
    vector<Carte *> getBibli();
    vector<Carte *> getHand();
    vector<Carte *> getGraveYard();
    vector<Carte *> getBoard();

    // ------------------------------ LES SETS ------------------------------
    void setNom(string n);
    void setHP(int s);
    void setBibli(Deck v);
    void setInitialHand();
    void setAPoserTerrain();
    void setPasPoserTerrain();
    void setMort();
    vector<Carte *> setBoard(vector<Carte *> c);

    // ------------------------------ LES PRINTS ------------------------------
    // Print des cartes.
    void printBibli();
    void printHand();
    void printGraveYard();
    void printBoard();

    // ------------------------------ LES ADDS ------------------------------
    // Ajout de cartes.
    void addToBibli(Carte *carte);
    void addToHand(Carte *carte);
    void addToGraveYard(Carte *carte);
    void addToBoard(Carte *carte);

    // ------------------------------ LES NETYOYAGES ------------------------------
    // Methodes qui permettent de replacer les cartes au bon endroit grace a l'attribut lieu.
    void NettoyageBibli();
    void NettoyageHand();
    void NettoyageGraveYard();
    void NettoyageBoard();

    // ------------------------------ METHODE UTILES  ------------------------------
    vector<Carte *> TerrainEnMain();  // Renvoie les terrains qui sont dans la main.
    vector<Carte *> CreatureEnMain(); // Renvoie les creatures qui sont dans la main.
    int VerifCin(int i);              // Verifie si l'entrer dans le terminal respecte bien les regles. Evite les erreurs
    void RecevoirDegat(int nbDegat);  // Fait en sorte que le joueur recoit les degats.
    bool VerifMort();                 // Verifie les HP du joueurs
    void MelangeBibli();              // Melange la bibli du joueur.
    int ParcourirBoard(vector<Carte *> v);

    // ------------------------------ POSER CARTES ------------------------------
    void PoserCreature();     // Methode qui permet de poser les creatures selon le cout.
    void PoserTerrain();      // Methode qui permet de poser un terrain par tour.
    void PoserEnchantement(); // Methode qui permet de poser les cartes d'enchantements selon le cout.

    // ------------------------------ PHASES ------------------------------
    void PhaseDePioche();
    int PhaseDeDesengagement();
    void PhasePrincipale();
    void PhaseSecondaire();
    void FinDeTour();

    // ------------------------------ GESTION DE COUT  ------------------------------
    bool VerifCout(Carte *CarteChoisie);
    map<string, int> CoutDisponibleEnJeu(); // renvoie une map qui pour chaque couleur donne le nb de terrains dispo.
    int CoutTotalDispoEnJeu();              // renvoie le nb total de terrain dispo en jeu.
    vector<Carte *> TerrainDispo();         // Renvoie les terrains sur le board qui ne sont pas engager.
    vector<Carte *> MAJTerrainDispo();      // Met a jours les terrains qui sont encores disponibles.

    // ------------------------------ ENGAGEMENT TERRAINS  ------------------------------
    vector<string> TerrainAEngager(Carte *CarteChoisie); // Renvoie les couleurs a engager pour une carte donner
    vector<Carte *> TerrainCouleurAEngage(Carte *c);     // Renvoie les terrains a engager pour respecter le cout de couleur d'une carte donner
    void EngageTerrainCouleur(Carte *CarteChoisie);      // Methode pour engager automatiquement les terrains de couleurs dont la carte a besoin
    void EngageTerrainQuelconque(Carte *CarteChoisie);   // Methode pour engager les terrains d'une carte donner, pour remplir le commonCost
};
#endif
