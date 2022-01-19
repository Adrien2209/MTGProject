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
  vector<int> ListeADelete = {};
  for (auto *carte : this->Bibli)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      i += 1;
    }
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      ListeADelete.push_back(i);
      cout << "on va vouloir supprimer " << carte->getNom() << " a la position " << i << endl;
      this->Bibli.erase(this->Bibli.begin() + i);
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      i += 1;
    }
    else
    {
      i += 1;
    }
  }
  for (int ite : ListeADelete)
  {
    this->Bibli.erase(this->Bibli.begin() + ite);
  }
}

void Joueur::NettoyageHand()
{
  int i = 0;
  vector<int> ListeADelete = {};
  for (auto *carte : this->Hand)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      cout << "on va vouloir supprimer " << carte->getNom() << " a la position " << i << endl;
      this->Hand.erase(this->Hand.begin() + i);
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      ListeADelete.push_back(i);
      i += 1;
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      ListeADelete.push_back(i);
      i += 1;
    }
    else
    {
      i += 1;
    }
  }
  cout << "Ici ca marche AVANT le for, taille : " << ListeADelete.size() << endl;
  /*
  for(int ite : ListeADelete){
    cout << "Ici ca marche dans le for " << this->Hand.at(ite)->getNom() << " et l'indice est " <<  ListeADelete.at(ite) << endl;
    this->Hand.erase(this->Hand.begin()+ite);
    cout << "EFFACE" << endl;
  }
  */
}

void Joueur::NettoyageGraveYard()
{
  int i = 0;
  vector<int> ListeADelete = {};
  for (auto *carte : this->GraveYard)
  {
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      i += 1;
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      i += 1;
    }
    if (carte->getLieu() == "Board")
    {
      addToBoard(carte);
      i += 1;
    }
    else
    {
      i += 1;
    }
  }
  for (int ite : ListeADelete)
  {
    this->GraveYard.erase(this->GraveYard.begin() + ite);
  }
}

void Joueur::NettoyageBoard()
{
  int i = 0;
  vector<int> ListeADelete = {};
  for (auto *carte : this->Board)
  {
    if (carte->getLieu() == "GraveYard")
    {
      addToGraveYard(carte);
      i += 1;
    }
    if (carte->getLieu() == "Hand")
    {
      addToHand(carte);
      i += 1;
    }
    if (carte->getLieu() == "Bibli")
    {
      addToBibli(carte);
      i += 1;
    }
    else
    {
      i += 1;
    }
  }
  for (int ite : ListeADelete)
  {
    this->Board.erase(this->Board.begin() + ite);
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
    Bibli.front()->setLieu("Hand");
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
  // vector<Carte*> res;
  for (Carte *c : this->TerrainDispo())
  {
    if (c->getEtat() == true)
    {
      this->TerrainDispo().erase(this->TerrainDispo().begin() + cpt);
    }
    else
    {
    }
    cpt++;
  }
  return this->TerrainDispo();
}

/*
vector<Carte *> Joueur::PoserCreature()
{
  // Ici on demande au joeur quelle creture il veut poser :
  // Lorsqu'il a choisis ca carte on la recupere et
  // on verifie si le cout en mana est disponible sur le Board.

  int idCarteChoisie;
  vector<Carte *> ResCartePoser;

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
  cout << " Ecrire '-1' si vous ne voulez pas jouer de carte " << endl;
  cout << " Premiere carte afficher numero 1, etc..." << endl;
  cout << "----------------------------------------------------------------" << endl;

  cout << "Numero : ";
  cin >> idCarteChoisie;

  string arret;
  bool FinDeChoix = true;
  while (FinDeChoix)
  {
    // Evite les numero pas compris dans la hand
    bool valide = true;
    while (valide)
    {
      if (idCarteChoisie > (int)Hand.size())
      {
        cout << " Valeur erronée ! Choisir une autre valeur" << endl;
        cin >> idCarteChoisie;
      }
      else
      {
        valide = false;
      }
    }

    // On recupere la carte qu'il a choisis.

    Carte *CarteChoisie = Hand[idCarteChoisie - 1];
    cout << "----------------------------------------------------------------" << endl;
    cout << " Voici la carte que vous avez choisi : " << endl;
    cout << "----------------------------------------------------------------" << endl;

    CarteChoisie->printCouleur();

    // On verifie si le cout disponible sur le Board correspond a la carte chosie
    cout << "----------------------------------------------------------------" << endl;
    cout << " Possibilité de la poser. Chargement... " << endl;
    cout << "----------------------------------------------------------------" << endl;

    vector<Carte *> TerrainDispo = this->TerrainDispo();
    int CoutCarteChoisie = CarteChoisie->getCost();
    int coutTotal = CarteChoisie->CoutTotale();                                  // Le cout de la carte choisie
    map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
    map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // Une map qui repertorie le cout dispo en jeu.
    std::map<std::string, int>::iterator it1, it2;                               // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.
    vector<Carte *> CarteEngageCeTour;                                           // Les cartes terrains engagees ce tour.
    int coutTotalEnJeu = this->CoutTotalDispoEnJeu();

    // On parcours le CoutTotalDispo sur le BOARD pour voir si le cout totale de la carte est inferieur au cout dispo.

    if (coutTotal <= coutTotalEnJeu) // Si le cout de la carte est inferieur au cout total dispo en jeu
    {
      for (it1 = coutDispo.begin(); it1 != coutDispo.end(); ++it1) // On parcours le cout dispo en jeu
      {
        for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); ++it2) // On parcours le cout couleur de la carte
        {
          if (it1->first == it2->first) // Si la clé est la meme alors
          {
            if (it1->second < it2->second) // Si le coutDispo est inferieur au cout demandé par la carte IMPOSSIBLE
            {
              cout << " PAS ASSEZ DE TERRAIN DISPO " << it1->first << " sur votre Board" << endl;
              cout << " Impossible de placer la carte que vous avez choisi !" << endl;
              cout << " Voulez vous poser une autre carte ? Si OUI ecrire le numero ecrire 213 ! " << endl;
              cin >> idCarteChoisie; // On lui demande s'il veut en poser une autre
            }
            else if (it1->second >= it2->second) // Si le cout dispo >= le cout besoin de la carte ok
            {
              int cpt = 0;
              for (Carte *c : this->TerrainDispo()) // On engage le bon nombre de cartes de couleur necessaires
              {
                // Si le nombre de carte qui reste correspond au getCost() de la carte alors on engage sinon on engage pas on ne peut pas poser la carte.
                if (c->getCouleur() == it1->first && cpt <= it2->second)
                {
                  c->setEngage();
                  CarteEngageCeTour.push_back(c);
                }
                TerrainDispo = this->TerrainDispo();
                cpt++;
                res = this->CoutTotalDispoEnJeu();

              } // Une fois les cartes engagé on verifie qu'il
              cout << " Vous avez assez de carte Terrain sur votre Board" << endl;

              cout << " Voulez vous poser une AUTRE CARTE ? Si OUI ecrire le numero sinon ecrire 213 ! " << endl;
              cin >> idCarteChoisie; // On lui demande s'il veut poser une autre carte.
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
          c->setEngage();
          ResCartePoser.push_back(Hand[idCarteChoisie - 1]);
          cpt++;
          cptCartePoser++;
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
      cout << " [1] Vous n'avez pas assez de carte terrain sur votre Board" << endl;
      cout << " [2] Voulez vous choisir une autre carte ? " << endl;
      cin >> idCarteChoisie;
    }
  }
  return ResCartePoser;
}
*/
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

  vector<Carte *> TerrainDispo = this->MAJTerrainDispo();
  // Evite les numero pas compris dans la hand
  bool valide = true;
  while (valide)
  {
    if (idCarteChoisie > (int)Hand.size())
    {
      cout << " Valeur erronée ! Choisir une autre valeur" << endl;
      cin >> idCarteChoisie;
    }
    else
    {
      valide = false;
    }
  }

  // On recupere la carte qu'il a choisis.
  Carte *CarteChoisie = Hand[idCarteChoisie - 1];

  cout << "----------------------------------------------------------------" << endl;
  cout << " Voici la carte que vous avez choisi : " << endl;
  cout << "----------------------------------------------------------------" << endl;

  CarteChoisie->printCouleur();

  // On verifie si le cout disponible sur le Board correspond a la carte chosie
  cout << "----------------------------------------------------------------" << endl;
  cout << " Possibilité de la poser. Chargement... " << endl;
  cout << "----------------------------------------------------------------" << endl;

  map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
  map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // map qui repertorie le cout dispo en jeu
  std::map<std::string, int>::iterator it1, it2;                               // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.

  int CoutCarteChoisie = CarteChoisie->getCost(); // Le cout de la carte choisie
  int coutTotal = CarteChoisie->CoutTotale();     // Le cout total de la carte choisie
  int res = this->CoutTotalDispoEnJeu();          // Une map qui repertorie le cout total dispo en jeu.

  vector<Carte *> CarteEngageCeTour; // Les cartes terrains engagees ce tour.

  if (coutTotal <= res) // Si le cout de la carte est inferieur au cout total dispo en jeu
                        // Alors on fait les verifications necessaires.
  {
    for (it1 = coutDispo.begin(); it1 != coutDispo.end(); ++it1) // On parcours le cout dispo en jeu
    {
      for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); ++it2) // On parcours le cout couleur de la carte
      {
        if (it1->first == it2->first) // Si la clé est la meme alors
        {
          if (it1->second < it2->second) // Si le coutDispo est inferieur au cout demandé par la carte IMPOSSIBLE
          {
            cout << " PAS ASSEZ DE TERRAIN DISPO " << it1->first << " sur votre Board" << endl;
            cout << " Impossible de placer la carte que vous avez choisi !" << endl;
            return;
          }
          else if (it1->second >= it2->second) // Si le cout dispo >= le cout besoin de la carte ok
          {
            int cpt = 0;
            for (Carte *c : TerrainDispo) // On engage le bon nombre de cartes de couleur necessaires
            {
              if (c->getCouleur() == it1->first && cpt <= it2->second)
              {
                c->setEngage();
                CarteEngageCeTour.push_back(c);
                cpt++;
              }
            }
            cout << " Vous avez assez de Terrain de couleur sur votre Board " << endl;
            cout << " Verifions s'il vous reste des cartes pour le CommonCost " << endl;
          }
        }
      }
    }
    // On a engager des cartes de couleur, il faut mtn verifier si on peut combler le CommonCost sinon il faut les desengagees les terrains engagees
    TerrainDispo = this->MAJTerrainDispo();

    if (CoutCarteChoisie <= (int)TerrainDispo.size())
    {
      for (Carte *c : TerrainDispo)
      {
        c->setEngage();
        CarteEngageCeTour.push_back(c);
      }
      Board.push_back(CarteChoisie);
      Hand.erase(Hand.begin() + (idCarteChoisie - 1));
      return;
    }
    else
    {
      for (Carte *c : CarteEngageCeTour)
      {
        c->setDesengage();
      }
      return;
    }
  }
  else
  {
    cout << " [**] Vous n'avez pas assez de carte terrain sur votre Board" << endl;
    cout << " [**] Pensez à choisir une autre CREATURE ? " << endl;
    return;
  }
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
//vector<Carte *> MAJ

void Joueur::PoserTerrain()
{
  string index;
  int i = 0;
  vector<Carte *> ListeTerrainChoisi;
  cout << " Vous voulez donc poser un TERRAIN ! Très bien ! " << endl;

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
        if (ListeTerrainChoisi.size() < 1)
        {
          cout << "Raille" << ListeTerrainChoisi.size() << endl;
          Board.push_back(Hand.at(i));
          Hand.erase(Hand.begin() + i);
          ListeTerrainChoisi.push_back(Hand.at(i));
          return;
        }
        else
        {
          cout << " Vous avez deja poser un TERRAIN malheuresement ! " << endl;
          cout << " Vous ne pouvez plus jouer de TERRAIN CE TOUR CI ! " << endl;
          return;
        }
      }
      i++;
    }
  }
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
    res += it->second;
  }
  return res;
}

void Joueur::PhasePrincipale()
{
  bool continu = true;
  while (continu)
  {
    int index;
    cout << " Voulez-vous poser un TERRAIN [1] ou une CREATURE [2] " << endl;
    cout << " Entrer [1] ou [2] " << endl;
    cout << " Entrer [3] si vous ne voulez pas posez de cartes " << endl;
    cin >> index;

    if (index == 1)
    {
      this->PoserTerrain();
      continu = true;
    }
    else if (index == 2)
    {
      this->PoserCreature();
      continu = true;
    }
    else
    {
      continu = false;
    }
  }
}
