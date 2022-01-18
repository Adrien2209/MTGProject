#include "Joueur.hpp"
#include "Carte.hpp"
#include "Terrain.hpp"

#include <algorithm>
#include <iostream>
#include <random> // std::default_random_engine
#include <stdlib.h>

// Constructeur
Joueur::Joueur(string nom, int HP, int ID, vector<Carte *> Hand, vector<Carte *> Bibli, vector<Carte *> Board, vector<Carte *> GraveYard)
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
vector<Carte *> Joueur::getBibli() { return Bibli; }
vector<Carte *> Joueur::getBoard() { return Board; }
vector<Carte *> Joueur::getGraveYard() { return GraveYard; }
vector<Carte *> Joueur::getHand() { return Hand; }

// -- -- -- Les sets -- -- --
void Joueur::setNom(string n) { nom = n; }
void Joueur::setHP(int s) { HP = s; }
vector<Carte *> Joueur::setBoard(vector<Carte *> c)
{
  Board = c;
  return Board;
}
void Joueur::setBibli(Deck d)
{
  this->Bibli = d.getDeck();
}
void Joueur::setInitialHand()
{
  int i = 0;
  while (i < 7)
  {
    Hand.push_back(Bibli[i]);
    i++;
  }
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

void Joueur::MelangeBibli()
{
  random_device rd;
  default_random_engine rng(rd());
  shuffle(Bibli.begin(), Bibli.end(), rng);
  cout << " Melange de la bibliotheques de : " << nom << " en cours... FAIT " << endl;
}

void Joueur::printHand()
{
  for (auto *e : Hand)
  {
    e->print();
  }
}

void Joueur::printBibli()
{
  for (auto *e : Bibli)
  {
    e->print();
  }
}

void Joueur::printGraveYard()
{
  for (auto &e : GraveYard)
  {
    e->print();
  }
}

void Joueur::printBoard()
{
  for (auto &e : Board)
  {
    e->print();
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
    for (Carte *carte : this->getBoard())
    {
      carte->setDesengage();
    }
  }
  return 1;
}

vector<Carte *> Joueur::TerrainDispo()
{
  vector<Carte *> TerrainDispo;
  for (Carte *c : Board)
  {
    if (c->getEtat() == false)
    {
      TerrainDispo.push_back(c);
    }
  }
  return TerrainDispo;
}

vector<Carte *> Joueur::ChoixCreature()
{
  // Ici on demande au joeur quelle creture il veut poser :
  // Lorsqu'il a choisis ca carte on la recupere et
  // on verifie si le cout en mana est disponible sur le Board.
  int idCarteChoisie;
  vector<Carte *> ResCartePoser;

  while (idCarteChoisie != -1)
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << "                 Quelle CREATURE voulez-vous jouer ?               " << endl;
    cout << "----------------------------------------------------------------" << endl
         << endl;
    // Afficher les cartes disponibles :
    for (auto &e : Hand)
    {
      e->print();
    }

    cout << "----------------------------------------------------------------" << endl;
    cout << " Veuillez renseignez le numero de la carte a poser ! " << endl;
    cout << " Ecrire '-1' si vous ne voulez pas jouer de carte " << endl;
    cout << " Premiere carte afficher numero 1, etc..." << endl;
    cout << "----------------------------------------------------------------" << endl;

    cout << "Numero : ";
    cin >> idCarteChoisie;

    // On recupere la carte qu'il a choisis.

    Carte *CarteChoisie = Hand[idCarteChoisie - 1];
    cout << "----------------------------------------------------------------" << endl;
    cout << " Voici la carte que vous avez choisi : " << endl;
    cout << "----------------------------------------------------------------" << endl;

    CarteChoisie->print();

    // On verifie si le cout disponible sur le Board correspond a la carte chosie
    cout << "----------------------------------------------------------------" << endl;
    cout << " Possibilité de la poser. Chargement... " << endl;
    cout << "----------------------------------------------------------------" << endl;

    // Les cartes terrains disponible en jeu.
    int CoutCarteChoisie = CarteChoisie->getCost();
    map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); 
    map<string, int> coutDispo = this->CoutDisponibleEnJeu();
    std::map<std::string, int>::iterator it1, it2; // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element
    vector<Carte *> CarteEngageCeTour;

    // On parcours le CoutDispo pour voir si le cout totale de la carte est inferieur au cout dispo.
    // map<string, int>::iterator it;
    int res = this->CoutTotalDispoEnJeu();
    cout << " Le nb total de carte dispo est : " << res << endl;
    /* for (it = CoutDispo.begin(); it != CoutDispo.end(); ++it)
    {
      res += it->second;
    } */
    if (CarteChoisie->getID() == 1)
    {
      cout << " On rentre dans le if " << endl;
      this->PoserTerrain();
    }
    else
    {

      if (CarteChoisie->CoutTotale() <= res)
      {
        for (it1 = coutDispo.begin(); it1 != coutDispo.end(); ++it1)
        {
          for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); ++it2)
          {
            if (it1->first == it2->first) // Si la clé est la meme alors
            {
              if (it1->second < it2->second) // Si le coutDispo est < au cout demandé par la carte IMPOSSIBLE
              {
                cout << " Vous n'avez pas assez de carte Terrain : " << it1->first << " sur votre Board" << endl;
                cout << " Impossible de placer la carte que vous avez choisi !" << endl;
                cout << " Choisir une autre carte ! " << endl;
              }
              else if (it1->second >= it2->second) // Si le cout dispo >= le cout besoin de la carte ok
              {
                cout << " Vous avez assez de carte Terrain : " << it1->first << " sur votre Board" << endl;
                int cpt = 0;
                {
                  for (Carte *c : this->TerrainDispo()) // On engage le bon nombre de cartes de couleur necessaires
                  {
                    // Si le nombre de carte qui reste correspond au getCost() de la carte alors on engage sinon on engage pas on ne peut pas poser la carte.
                    if (c->getCouleur() == it1->first && cpt <= it2->second)
                    {
                      c->setEngage();
                      CarteEngageCeTour.push_back(c);
                    }
                    cpt++;
                  } // Une fois les cartes engagé on verifie qu'il
                }
              }
            }
          }
        }
        int cpt = 0;
        int cptCartePoser = 0;
        for (Carte *c : this->TerrainDispo())
        {
          if (CoutCarteChoisie <= (int)this->TerrainDispo().size() && cpt <= CoutCarteChoisie)
          {
            cout << " Vous avez assez de carte Terrain sur votre Board" << endl;
            cout << " Choisir une autre carte ! " << endl;
            c->setEngage();
            ResCartePoser.push_back(Hand[idCarteChoisie - 1]);
            cpt++;
            cptCartePoser++;
            cin >> idCarteChoisie;
          }
          else
          {
            for (Carte *c : CarteEngageCeTour)
            {
              c->setDesengage();
              ResCartePoser.erase(ResCartePoser.begin() + cptCartePoser);
            }
          }
        }
      }
      else
      {
        cout << " Vous avez assez de carte Terrain sur votre Board" << endl;
        cout << " Choisir une autre carte ! " << endl;
      }
    }
    return ResCartePoser;
  }
}

void Joueur::PoserTerrain()
{
  string index;
  int i = 0;
  // bool possible = true; // Possible de poser un terrain
  cout << " Voulez-vous poser un terrain ? " << endl;
  cin >> index;

  while (i <= (int)Hand.size())
  {
    if (this->getHand().at(i)->getNom() == index)
    {
      Board.push_back(Hand.at(i));
      Hand.erase(Hand.begin() + i);
      // possible = false;
      return;
    }
    i++;
  }

  cout << " Vous n'avez pas ce terrain : " << index << endl;
}

// COUT DISPONIBLE SUR LE TERRAIN POUR VOIR SI LA CREATURE PEUT ETRE POSER
map<string, int> Joueur::CoutDisponibleEnJeu()
{
  map<string, int> res = {{"White", 0}, {"Blue", 0}, {"Black", 0}, {"Red", 0}, {"Green", 0}};
  int nbWhite, nbBlue, nbBlack, nbRed, nbGreen = 0;

  if (Board.empty())
  {
    return res;
  }
  else
  {
    for (Carte *t : this->TerrainDispo())
    {
      if (t->getCouleur() == "White")
      {
        res[t->getCouleur()] = nbWhite++;
      }
      else if (t->getCouleur() == "Blue")
      {
        res[t->getCouleur()] = nbBlue++;
      }
      else if (t->getCouleur() == "Black")
      {
        res[t->getCouleur()] = nbBlack++;
      }
      else if (t->getCouleur() == "Red")
      {
        res[t->getCouleur()] = nbRed++;
      }
      else if (t->getCouleur() == "Green")
      {
        res[t->getCouleur()] = nbGreen++;
      }
    }
  }
  return res;
}

// Cout total dispo en jeu

int Joueur::CoutTotalDispoEnJeu()
{
  map<string, int> A = this->CoutDisponibleEnJeu();
  map<string, int>::iterator it;
  int res;
  for (it = A.begin(); it != A.end(); ++it)
  {
    res += it->second;
    cout << res << endl;

  }
  return res;
}

/*void Joueur::PhasePrincipale()
{
  // On lui demande quelle carte il veut poser ? Un Terrain ou une Creature ?
  // On verifie que la carte qu'il veut posser est dans sa main !
  // Si elle ne l'est pas, il rechoisit une autre.
  // S'il a poser un Terrain, on garde cette info ! car s'il en repose un pas le droit !
  // S'il pose une creature, on regarde si le cout disponible sur le Board est suffisant puis on la pose.
  // Sinon on ne pose pas la carte, et on passe a la phase suivante.

  // Stockage des terrains
  vector<Carte *> nbLand;
  for (Carte *carte : this->getBoard())
  {
    if (carte->getID() == 1 && carte->getEtat() == false)
    {
      nbLand.push_back(carte);
    }
  }
  bool continuer = true;
  while (continuer)
  {
    Carte *CarteChoisie = this->ChoixCreature();                   // Creature choisie par le joueur.
    int cost = CarteChoisie->getCost();                            // Cout de la carte quelconque
    vector<string> cost_couleur = CarteChoisie->getCout_Couleur(); // cout couleur specifique
    int CoutCouleur = cost_couleur.size();
    int CoutTotale = CoutCouleur + cost;
    int nbTerrainTrouver = 0;

    for (Carte *c : nbLand)
    {
      for (auto s : cost_couleur) // On parcours les couleurs dont la carte a besoin
      {
        int i = 0; // Compteur qui va nous permettre de savoir si on a le bon nombre de carte de couleur.
        if (c->getCouleur() == s)
        { // Si c'est la bonne couleur alors
          if (CoutCouleur != i)
          {                     // Si le nombre de carte n'a pas deja été trouver alors
            c->setEngage();     // on engage la carte
            i++;                // On incremente i
            nbTerrainTrouver++; // On incremente le carte totale de terrain trouver
          }
          else // Si on a trouver toute les cartes de couleurs necessaire on doit verifier s'il reste des cartes de n'importe quelles couleurs qui satisfont le cost.
          {
            int cpt = 0;
            while (cpt <= (int)nbLand.size())
            {
              if (c->getEtat() == false)
              {
                c->setEngage();
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
      for (Carte *c : nbLand)
      {
        c->setDesengage();
      }
      continuer = false;
    }
  }
}
*/