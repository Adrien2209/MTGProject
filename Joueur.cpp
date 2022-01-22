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
    Bibli.front()->setLieu("Hand");
    Hand.push_back(Bibli.front());
    Bibli.erase(Bibli.begin());
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
    e->printCouleur();
  }
}

void Joueur::printBibli()
{
  for (auto *e : Bibli)
  {
    e->printCouleur();
  }
}

void Joueur::printGraveYard()
{
  for (auto &e : GraveYard)
  {
    e->printCouleur();
  }
}

void Joueur::printBoard()
{
  for (auto &e : Board)
  {
    e->printCouleur();
  }
}

void Joueur::addToBibli(Carte *carte)
{
  Bibli.push_back(carte);
}

void Joueur::addToHand(Carte *carte)
{
  Hand.push_back(carte);
}

void Joueur::addToGraveYard(Carte *carte)
{
  GraveYard.push_back(carte);
}

void Joueur::addToBoard(Carte *carte)
{
  Board.push_back(carte);
}

void Joueur::NettoyageBibli()
{
  int i = 0;
  for (auto *carte : this->Bibli)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      this->Bibli.erase(this->Bibli.begin() + i);
    }
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      this->Bibli.erase(this->Bibli.begin() + i);
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      this->Bibli.erase(this->Bibli.begin() + i);
    }
    else
    {
      i += 1;
    }
  }
}

void Joueur::NettoyageHand()
{
  int i = 0;
  for (auto *carte : this->Hand)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      // cout << "on va vouloir supprimer " << carte->getNom() << " a la position " << i << endl;
      this->Hand.erase(this->Hand.begin() + i);
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      this->Hand.erase(this->Hand.begin() + i);
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      this->Hand.erase(this->Hand.begin() + i);
    }
    else
    {
      i += 1;
    }
  }
}

void Joueur::NettoyageGraveYard()
{
  int i = 0;
  for (auto *carte : this->GraveYard)
  {
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      this->GraveYard.erase(this->GraveYard.begin() + i);
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      this->GraveYard.erase(this->GraveYard.begin() + i);
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      this->GraveYard.erase(this->GraveYard.begin() + i);
    }
    else
    {
      i += 1;
    }
  }
}

void Joueur::NettoyageBoard()
{
  int i = 0;
  for (auto *carte : this->Board)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      this->Board.erase(this->Board.begin() + i);
    }
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      this->Board.erase(this->Board.begin() + i);
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      this->Board.erase(this->Board.begin() + i);
    }
    else
    {
      i += 1;
    }
  }
}

void Joueur::PhaseDePioche()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::quelleCouleur("Magenta");

  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "      (  )        " << endl;
  cout << c << "       ||            [][][][]  []  [][][][] [][][][] []    []  [][][][]                                  " << endl;
  cout << c << "       ||            []    []  []  []    [] []       []    []  []                               " << endl;
  cout << c << "   ___|  |____       [][][][]  []  []    [] []       [][][][]  [][]             [][][] []  []                " << endl;
  cout << c << "  /__________/       []        []  []    [] []       []    []  []               []  [] [][]           " << endl;
  cout << c << "  /___________/      []        []  [][][][] [][][][] []    []  [][][][] [][][]  [][][] []  []         " << endl;
  cout << c << "  /___________/~~~  " << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

  if (this->getBibli().empty())
  {
    mort = true;
    this->VerifMort();
  }
  else
  {
    Bibli.front()->setLieu("Hand");
    Hand.push_back(Bibli.front());
    Bibli.erase(Bibli.begin());
  }
}

int Joueur::PhaseDeDesengagement()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::quelleCouleur("Magenta");
  cout << c << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "     ______      " << endl;
  cout << c << "    |      |  [][][]     [][][][] [][][][] [][][][] []    []  [][][]   [][[]][]  [][][]   [][][][] []      [] [][][][] []    [] [][][][]                      " << endl;
  cout << c << "    |      |  []    []   []       []       []       [][]  [] []        []    [] []        []       [][]  [][] []       [][]  []    []                         " << endl;
  cout << c << "    | (o)(o)  []    []   [][]     [][][][] [][][    [] [] [] []   [][] [][][][] []   [][] [][]     []  []  [] [][]     [] [] []    []             [][][] [] []" << endl;
  cout << c << "    C      _) []    []   []             [] []       []  [][] []     [] []    [] []     [] []       []      [] []       []  [][]    []             []  [] [][] " << endl;
  cout << c << "    | ,___|   [][][]     [][][][] [][][][] [][][][] []    []  [][][]   []    []  [][][]   [][][][] []      [] [][][][] []    []    []   [] [] []  [][][] [] []" << endl;
  cout << c << "    |   /" << endl;
  cout << couleurDefaut<< " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
 

  if (this->getBoard().empty())
  {
    cout <<"--------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    cout <<  " LE JOUEUR " << this->getNom() << " N'A PAS DE TERRAINS SUR LE BOARD ! " << endl;
    cout <<  "--------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
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
    if (c->getID() == 1)
    {
      if (c->getEtat() == false)
      {
        TerrainDispo.push_back(c);
      }
    }
  }
  return TerrainDispo;
}

vector<Carte *> Joueur::MAJTerrainDispo()
{
  int cpt = 0;

  for (Carte *c : this->TerrainDispo())
  {
    if (c->getEtat() == true)
    {
      this->TerrainDispo().erase(this->TerrainDispo().begin() + cpt);
    }
    cpt++;
  }
  return this->TerrainDispo();
}

vector<Carte *> Joueur::TerrainEnMain()
{
  vector<Carte *> TerrainEnMain;
  for (Carte *c : Hand)
  {
    if (c->getID() == 1)
    {
      TerrainEnMain.push_back(c);
    }
  }
  return TerrainEnMain;
}

vector<Carte *> Joueur::CreatureEnMain()
{
  vector<Carte *> CreatureEnMain;
  for (Carte *c : Hand)
  {
    if (c->getID() == 2)
    {
      CreatureEnMain.push_back(c);
    }
  }
  return CreatureEnMain;
}

void Joueur::PoserTerrain()
{
  string index;
  int i = 0;

  cout << "----------------------------------------------------------------" << endl;
  cout << " Vous voulez donc poser un TERRAIN ! Très bien ! " << endl;
  cout << "----------------------------------------------------------------" << endl;

  vector<Carte *> TerrainEnMain = this->TerrainEnMain();

  for (Carte *c : TerrainEnMain)
  {
    c->printCouleur();
  }

  if ((int)TerrainEnMain.size() == 0)
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << "Vous n'avez PAS de Terrain en main ! PETIT CHENAPAM ! PIOU PIOU :o" << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
  else
  {
    cout << " Entrer le nom du TERRAIN " << endl;
    cin >> index;

    while (i <= (int)Hand.size())
    {
      if (Hand.at(i)->getNom() == index)
      {
        Board.push_back(Hand.at(i));
        Hand.at(i)->setLieu("Board");
        Hand.erase(Hand.begin() + i);
        return;
      }
      i++;
    }
  }
  return;
}
// COUT DISPONIBLE SUR LE TERRAIN POUR VOIR SI LA CREATURE PEUT ETRE POSER
map<string, int> Joueur::CoutDisponibleEnJeu()
{
  map<string, int> res = {{"White", 0}, {"Blue", 0}, {"Black", 0}, {"Red", 0}, {"Green", 0}};
  int nbWhite = 0;
  int nbBlue = 0;
  int nbBlack = 0;
  int nbRed = 0;
  int nbGreen = 0;

  if (Board.empty())
  {
    return res;
  }
  else
  {
    for (Carte *t : this->MAJTerrainDispo())
    {
      if (t->getCouleur() == "White")
      {
        nbWhite = nbWhite + 1;
        res[t->getCouleur()] = nbWhite;
      }
      else if (t->getCouleur() == "Blue")
      {
        nbBlue = nbBlue + 1;
        res[t->getCouleur()] = nbBlue;
      }
      else if (t->getCouleur() == "Black")
      {
        nbBlack = nbBlack + 1;
        res[t->getCouleur()] = nbBlack;
      }
      else if (t->getCouleur() == "Red")
      {
        nbRed = nbRed + 1;
        res[t->getCouleur()] = nbRed;
      }
      else if (t->getCouleur() == "Green")
      {
        nbGreen = nbGreen + 1;
        res[t->getCouleur()] = nbGreen;
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

  int res = 0;
  for (it = A.begin(); it != A.end(); ++it)
  {
    cout << " Sur le Board vous avez : " << it->first << " au(x) nombre(s) de " << it->second << endl;
    cout << "----------------------------------------------------------------" << endl;
    res += it->second;
  }

  return res;
}

void Joueur::PhasePrincipale()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::quelleCouleur("Magenta");
  cout << c << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "   ____________                                                                                                                                                              " << endl;
  cout << c << "  |    _|_     |  [][][][] [][][][] []  []    [] [][][][] []  [][][][] [][][][] []       []       [][][][]                                                                                                                                   " << endl;
  cout << c << "  |   |_|_|    |  []    [] []    [] []  [][]  [] []       []  []    [] []    [] []       []       []                                                                                                                " << endl;
  cout << c << "  |   |   |    |  [][][][] [][][][] []  [] [] [] []       []  [][][][] [][][][] []       []       [][]                                                                                                                      " << endl;
  cout << c << "  |   |___|    |  []       [] []    []  []  [][] []       []  []       []    [] []       []       []                                                                                                         " << endl;
  cout << c << "  |____________|  []       []   []  []  []    [] [][][][] []  []       []    [] [][][][] [][][][] [][][][]  [][][]                                                                                                                      " << endl;
  cout << couleurDefaut<< " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

  bool APoserTerrain = false;
  bool continu = true;
  while (continu)
  {

    Color c1 = Color::quelleCouleur("Red");
    cout << "----------------------------------------------------------------" << endl;
    cout << c1 << this->getNom() << couleurDefaut << " Voulez-vous poser un TERRAIN [1], une CREATURE [2] ou rien [3] " << endl;
    cout <<  " Entrer " << c1 << " [1] , [2] ou [3] " << couleurDefaut << endl;
    cout << "----------------------------------------------------------------" << endl;

    int index;
    cin >> index;

    if (index == 1)
    {
      if (APoserTerrain == false)
      {
        this->PoserTerrain();
        APoserTerrain = true;
      }
      else
      {
        cout << "----------------------------------------------------------------" << endl;
        cout << " Vous avez deja poser un TERRAIN malheuresement ! " << endl;
        cout << " Vous ne pouvez plus jouer de " << c1 << " TERRAIN " << couleurDefaut << " CE TOUR CI ! " << endl;
        cout << "----------------------------------------------------------------" << endl;
      }
      continu = true;
    }
    else if (index == 2)
    {
      this->PoserCreature();
      this->TerrainDispo();
      this->NettoyageHand();
      continu = true;
    }
    else if (index == 3)
    {
      continu = false;
    }
    else
    {
      cout << " Veuiller entrer un nombre correct ! MERCI LES AMIS ! UhO" << endl;
      continu = true;
    }
  }
}

void Joueur::PoserCreature()
{

  int idCarteChoisie; // Variable qui stock l'ID de la carte choisie

  cout << "----------------------------------------------------------------" << endl;
  cout << "                 Quelle CREATURE voulez-vous jouer ?               " << endl;
  cout << "----------------------------------------------------------------" << endl
       << endl;

  // Afficher les cartes disponibles :
  for (Carte *e : Hand)
  {
    e->printCouleur();
  }

  cout << "----------------------------------------------------------------" << endl;
  cout << " Veuillez renseignez le numero de la carte a poser ! " << endl;
  cout << " Premiere carte afficher n° 1, etc..." << endl;
  cout << "----------------------------------------------------------------" << endl;

  cout << "Numero : ";
  cin >> idCarteChoisie;

  vector<Carte *> TerrainDispo = this->TerrainDispo();
  // Evite les numero pas compris dans la hand
  bool valide = true;
  while (valide)
  {
    if (idCarteChoisie > (int)Hand.size())
    {
      cout << " Valeur erronée ! Choisir une autre valeur" << endl;
      cout << " Numero : ";
      cin >> idCarteChoisie;
    }
    else
    {
      valide = false;
    }
  }

  // On recupere la carte qu'il a choisis.
  Carte *CarteChoisie = Hand[idCarteChoisie - 1];
  int id = idCarteChoisie - 1;

  cout << "----------------------------------------------------------------" << endl;
  cout << " Voici la carte que vous avez choisi : " << endl;
  cout << "----------------------------------------------------------------" << endl;

  CarteChoisie->printCouleur();

  // On verifie si le cout disponible sur le Board correspond a la carte chosie
  cout << "----------------------------------------------------------------" << endl;
  cout << " Possibilité de la poser. Chargement... " << endl;
  cout << "----------------------------------------------------------------" << endl;
  if (CarteChoisie->getID() == 2)
  {
    if (this->VerifCout(CarteChoisie))
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << " Votre carte peut etre poser ! (:)-<-< " << endl;
      cout << " Engagement des Terrains en cours..." << endl;
      cout << "----------------------------------------------------------------" << endl;
      this->EngageTerrainCouleur(CarteChoisie);
      this->EngageTerrainQuelconque(CarteChoisie);
      Board.push_back(CarteChoisie);
      Hand.erase(Hand.begin() + id);
      for (auto c : Hand)
      {
        c->printCouleur();
      }
    }
    else
    {
      cout << " Impossible de poser votre carte ! [:o]-<-< " << endl;
    }
  }
  else
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Vous avez choisis un terrain et non pas une creature ! Reesayer !" << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
}

bool Joueur::VerifCout(Carte *CarteChoisie)
{
  map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
  map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // map qui repertorie le cout dispo en jeu
  map<std::string, int>::iterator it, it2;                                     // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.

  int coutTotal = CarteChoisie->CoutTotale(); // Le cout total de la carte choisie
  int res = this->CoutTotalDispoEnJeu();      // Une map qui repertorie le cout total dispo en jeu.

  for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); it2++)
  {
    cout << it2->first << " : " << it2->second << endl;
  }
  /*
    Pour placer la carte il faut :
      - Que le nb de carte terrain sur le board soit superieur au nb totale de carte terrain besoin
      - Si cette condition est remplie alors on verifie que le cout en couleur est respecter
      s'il ne l'ai pas on ne peut pas placer la carte.
      - et comme on a vu que le nb totale de carte dispo est >= au nb de carte besoin et que le nb de carte
      de couleur est verifier on peut poser la carte et donner le choix au joueur d'engager c terrain.

  */

  if (res >= coutTotal)
  {
    for (it = Cout_CouleurCarteChoisie.begin(); it != Cout_CouleurCarteChoisie.end(); it++)
    {
      if (it->first == "White")
      {

        if (coutDispo["White"] < it->second)
        {
          return false;
        }
      }
      else if (it->first == "Black")
      {
        if (coutDispo["Black"] < it->second)
        {
          return false;
        }
      }
      if (it->first == "Blue")
      {
        if (coutDispo["Blue"] < it->second)
        {
          return false;
        }
      }
      if (it->first == "Red")
      {
        if (coutDispo["Red"] < it->second)
        {
          return false;
        }
      }
      if (it->first == "Green")
      {
        if (coutDispo["Green"] < it->second)
        {
          return false;
        }
      }
    }
    return true;
  }
  else
  {
    return false;
  }
}

vector<string> Joueur::TerrainAEngager(Carte *CarteChoisie)
{
  map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
  map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // map qui repertorie le cout dispo en jeu
  map<std::string, int>::iterator it1, it2;                                    // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.

  int coutTotal = CarteChoisie->CoutTotale(); // Le cout total de la carte choisie
  int res = this->CoutTotalDispoEnJeu();      // Une map qui repertorie le cout total dispo en jeu.

  map<string, int>::iterator it;
  vector<string> CarteAEngage;
  if (res >= coutTotal)
  {
    for (it = Cout_CouleurCarteChoisie.begin(); it != Cout_CouleurCarteChoisie.end(); it++)
    {
      int i = 0;
      if (it->first == "White" && coutDispo["White"] >= it->second)
      {
        while (i < it->second)
        {
          CarteAEngage.push_back("White");
          i++;
        }
      }
      else if (it->first == "Black" && coutDispo["Black"] >= it->second)
      {
        while (i < it->second)
        {
          CarteAEngage.push_back("Black");
          i++;
        }
      }
      else if (it->first == "Blue" && coutDispo["Blue"] >= it->second)
      {
        while (i < it->second)
        {
          CarteAEngage.push_back("Blue");
          i++;
        }
      }
      else if (it->first == "Red" && coutDispo["Red"] >= it->second)
      {
        while (i < it->second)
        {
          CarteAEngage.push_back("Red");
          i++;
        }
      }
      else if (it->first == "Green" && coutDispo["Green"] >= it->second)
      {
        while (i < it->second)
        {
          CarteAEngage.push_back("Green");
          i++;
        }
      }
    }
    return CarteAEngage;
  }
  return CarteAEngage;
}

vector<Carte *> Joueur::TerrainCouleurAEngage(Carte *c)
{
  vector<string> Terrains = this->TerrainAEngager(c);
  vector<Carte *> res;

  for (auto s : Terrains)
  {
    int cpt = 0;
    for (auto c : this->TerrainDispo())
    {
      if (s == c->getCouleur() && cpt < 1)
      {
        res.push_back(c);
        cpt++;
      }
    }
  }
  return res;
}

void Joueur::EngageTerrainCouleur(Carte *CarteChoisie)
{
  vector<Carte *> Terrains = this->TerrainCouleurAEngage(CarteChoisie);
  vector<Carte *> TerrainsDispo = this->TerrainDispo();

  cout << "----------------------------------------------------------------" << endl;
  cout << " Voici vos terrains disponibles " << endl;
  cout << "----------------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (Carte *c : TerrainsDispo)
  {
    c->printCouleur();
  }
  cout << "----------------------------------------------------------------" << endl;
  cout << " Le(s) terrain(s) suivant vont être engagee (;-o) : " << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (auto c : Terrains)
  {
    c->printCouleur();
  }
  cout << endl;
  /*
    if (taille == 0)
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << "Vous avez engager tous vos terrains ! MERCI !" << endl;
      cout << "----------------------------------------------------------------" << endl;
    }
    else
    { */
  for (Carte *c : TerrainsDispo)
  {
    for (Carte *t : Terrains)
    {
      if (c == t)
      {
        c->setEngage();
      }
    }
  }
  TerrainsDispo = this->MAJTerrainDispo();
  cout << "----------------------------------------------------------------" << endl;
  cout << " Vos Terrains ont bien ete engager voici la liste de vos terrains encore disponible " << endl;
  cout << "----------------------------------------------------------------" << endl;
  for (auto c : TerrainsDispo)
  {
    c->printCouleur();
  }
  return;
}

void Joueur::EngageTerrainQuelconque(Carte *CarteChoisie)
{
  string index;
  int nb = CarteChoisie->getCost();
  vector<Carte *> TerrainsDispo = this->TerrainDispo();
  int i = 0;

  if (nb == 0)
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Pas besoin de terrains supplementaires " << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
  else
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Vous devez engager encore : " << nb << " terrains ! " << endl;
    cout << "----------------------------------------------------------------" << endl;

    while (i < nb)
    {
      Color couleurDefaut(FG_DEFAULT);
      
      cout << " Entrer le nom du " << c1 << "Terrain" << couleurDefaut << "que vous voulez engager : ";
      cin >> index;
      cout << endl;
      cout << "----------------------------------------------------------------" << endl;
      for (Carte *c : TerrainsDispo)
      {
        if (index == c->getNom())
        {
          c->setEngage();
        }
      }

      TerrainsDispo = this->MAJTerrainDispo();
      cout << "----------------------------------------------------------------" << endl;
      cout << " Votre terrain a bien ete engager ! Voici les terrains qu'il vous reste " << endl;
      cout << "----------------------------------------------------------------" << endl;
      for (auto c : TerrainsDispo)
      {
        c->printCouleur();
      }
      i++;
    }
  }
  return;
}

void Joueur::PhaseSecondaire()
{
  this->PhasePrincipale();
}

void Joueur::FinDeTour()
{
  int id;
  while (Hand.size() > 7)
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Vous devez defausser une carte parmi : " << endl;
    cout << "----------------------------------------------------------------" << endl;
    cout << " Entrer le numero de la carte a envoyer au cimetiere : " << endl;
    cout << "----------------------------------------------------------------" << endl;
    this->printHand();

    cin >> id;

    if (id > (int)Hand.size())
    {
      cout << "Veuiller rentrer un numero valide " << endl;
      cin >> id;
    }
    else
    {
      GraveYard.push_back(Hand[id - 1]);
      Hand.erase(Hand.begin() + (id - 1));
    }
  }
}