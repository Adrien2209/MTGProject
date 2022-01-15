#include "Joueur.hpp"
#include "Carte.hpp"
#include "Terrain.hpp"

#include <algorithm>
#include <iostream>
#include <random> // std::default_random_engine
#include <stdlib.h>

// Constructeur
Joueur::Joueur(string nom, int HP, int ID, vector<Carte> Hand, vector<Carte> Bibli, vector<Carte> Board, vector<Carte> GraveYard)
{
  this->nom = nom;
  this->HP = HP;
  this->ID = ID;
  this->Hand = Hand;
  this->Bibli = Bibli;
  this->Board = Board;
  this->GraveYard = GraveYard;
}

Joueur::Joueur(string nom, int HP, int ID)
{
  this->nom = nom;
  this->HP = HP;
  this->ID = ID;
}

Joueur::Joueur(){};

// -- -- -- Les gets -- -- --
string Joueur::getNom() { return nom; }
int Joueur::getHP() { return HP; }
int Joueur::getId() { return ID; }
bool Joueur::getMort() { return mort; }
vector<Carte> Joueur::getBibli() { return Bibli; }
vector<Carte> Joueur::getBoard() { return Board; }
vector<Carte> Joueur::getGraveYard() { return GraveYard; }
vector<Carte> Joueur::getHand() { return Hand; }

// -- -- -- Les sets -- -- --
void Joueur::setNom(string n) { nom = n; }
void Joueur::setHP(int s) { HP = s; }
vector<Carte> Joueur::setBibli(Deck v)
{
  Bibli = v.getDeck();
  return Bibli;
}

vector<Carte> Joueur::setInitialHand(vector<Carte> v)
{
  int i = 0;
  while (i < 7)
  {
    Hand.push_back(v[i]);
    i++;
  }
  return Hand;
}

// -- -- -- Les Methodes -- -- --
bool Joueur::VerifMort()
{
  if (this->getHP() <= 0 || mort == true)
  {
    cout << "Le joueur " << this->getNom() << " est mort ! C'est CIAO !!" << endl;
    return mort;
  }
  return mort;
}

void Joueur::RecevoirDegat(int nbDegat)
{
  HP -= nbDegat;
  if (HP <= 0)
  {
    HP = 0;
    this->VerifMort();
  }
}

vector<Carte> Joueur::MelangeBibli(vector<Carte> v)
{
  random_device rd;
  default_random_engine rng(rd());
  shuffle(v.begin(), v.end(), rng);
  this->Bibli = v;
  cout << " Melange de la bibliotheques de : " << this->getNom() << " en cours... FAIT " << endl;
  return Bibli;
}

void Joueur::printHand()
{
  for (auto &e : Hand)
  {
    e.print();
  }
}

void Joueur::printBibli()
{
  for (auto &e : Bibli)
  {
    e.print();
  }
}

void Joueur::printGraveYard()
{
  for (auto &e : GraveYard)
  {
    e.print();
  }
}

void Joueur::printBoard()
{
  for (auto &e : Board)
  {
    e.print();
  }
}

void Joueur::PhaseDePioche()
{
  if (this->getBibli().empty())
  {
    mort = true;
    this->VerifMort();
  }
  else
  {
    Hand.push_back(Bibli.front());
    Bibli.erase(Bibli.begin());
  }
}

int Joueur::PhaseDeDesengagement()
{
  if (this->getBoard().empty())
  {
    cout << "Le joueur " << this->getNom() << " n'a pas de cartes sur le terrain" << endl;
    return 0;
  }
  else
  {
    for (Carte &carte : this->getBoard())
    {
      carte.setDesengage();
    }
  }
  return 1;
}

Carte &Joueur::ChoixCreature()
{

  int idCarteChoisie;
  cout << "Quelle carte voulez-vous jouer ? :) " << endl;
  // Afficher les cartes disponibles :
  for (auto &e : Hand)
  {
    e.print();
  }
  cout << " Veuillez renseignez le numero de la carte a poser ! Premiere carte afficher numero 1, etc..." << endl;
  cin >> idCarteChoisie;
  Carte &CarteChoisie = Hand[idCarteChoisie - 1];
  return CarteChoisie;
}

void Joueur::PhasePrincipale()
{
  // Stockage des terrains
  vector<Carte> nbLand;
  for (Carte &carte : this->getBoard())
  {
    if (carte.getID() == 1 && carte.getEtat() == false)
    {
      nbLand.push_back(carte);
    }
  }
  bool continuer = true;
  while (continuer)
  {
    Carte &CarteChoisie = this->ChoixCreature();                  // Creature choisie par le joueur.
    int cost = CarteChoisie.getCost();                            // Cout de la carte quelconque
    vector<string> cost_couleur = CarteChoisie.getCout_Couleur(); // cout couleur specifique
    int CoutCouleur = cost_couleur.size();
    int CoutTotale = CoutCouleur + cost;
    int nbTerrainTrouver = 0;

    for (Carte &c : nbLand)
    {
      for (auto s : cost_couleur) // On parcours les couleurs dont la carte a besoin
      {
        int i = 0; // Compteur qui va nous permettre de savoir si on a le bon nombre de carte de couleur.
        if (c.getCouleur() == s)
        { // Si c'est la bonne couleur alors
          if (CoutCouleur != i)
          {                     // Si le nombre de carte n'a pas deja été trouver alors
            c.setEngage();      // on engage la carte
            i++;                // On incremente i
            nbTerrainTrouver++; // On incremente le carte totale de terrain trouver
          }
          else // Si on a trouver toute les cartes de couleurs necessaire on doit verifier s'il reste des cartes de n'importe quelles couleurs qui satisfont le cost.
          {
            int cpt = 0;
            while (cpt <= (int)nbLand.size())
            {
              if (c.getEtat() == false)
              {
                c.setEngage();
                nbTerrainTrouver++;
                cpt++;
              }
              else
              {
                cpt++;
              }
            }
          }
        }
      }
    }
    if (nbTerrainTrouver == CoutTotale)
    {
      continuer = true;
    }
    else
    {
      for (Carte &c : nbLand)
      {
        c.setDesengage();
      }
      continuer = false;
    }
  }
}