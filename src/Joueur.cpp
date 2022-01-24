#include "../Headers/Joueur.hpp"
#include "../Headers/Carte.hpp"
#include "../Headers/Terrain.hpp"

#include <algorithm>
#include <iostream>
#include <random> // std::default_random_engine
#include <stdlib.h>
// ------------------------------------------------------------------------------
// ------------------------------ CONSTRUCTEURS ---------------------------------
// ------------------------------------------------------------------------------

Joueur::Joueur(string nom, int HP, int ID, vector<Carte *> Hand, vector<Carte *> Bibli, vector<Carte *> Board, vector<Carte *> GraveYard, bool APoserTerrain)
{
  this->nom = nom;
  this->HP = HP;
  this->ID = ID;
  this->Hand = Hand;
  this->Bibli = Bibli;
  this->Board = Board;
  this->GraveYard = GraveYard;
  this->APoserTerrain = false;
}

Joueur::Joueur(string nom, int HP, int ID)
{
  this->nom = nom;
  this->HP = HP;
  this->ID = ID;
  APoserTerrain = false;
}

Joueur::Joueur(){};
// ----------------------------------------------------------------------
// ------------------------------ LES GETS ------------------------------
// ----------------------------------------------------------------------

string Joueur::getNom() { return nom; }
int Joueur::getHP() { return HP; }
int Joueur::getId() { return ID; }
bool Joueur::getMort() { return mort; }
vector<Carte *> Joueur::getBibli() { return Bibli; }
vector<Carte *> Joueur::getBoard() { return Board; }
vector<Carte *> Joueur::getGraveYard() { return GraveYard; }
vector<Carte *> Joueur::getHand() { return Hand; }

// ----------------------------------------------------------------------
// ------------------------------ LES SETS ------------------------------
// ----------------------------------------------------------------------

void Joueur::setNom(string n) { nom = n; }
void Joueur::setHP(int s) { HP = s; }
void Joueur::setAPoserTerrain() { APoserTerrain = true; }
void Joueur::setPasPoserTerrain() { APoserTerrain = false; }
vector<Carte *> Joueur::setBoard(vector<Carte *> c)
{
  Board = c;
  return Board;
}
void Joueur::setBibli(Deck d) { this->Bibli = d.getDeck(); }

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
// ------------------------------------------------------------------------
// ------------------------------ LES PRINTS ------------------------------
// ------------------------------------------------------------------------

void Joueur::printHand()
{
  int i = 1;
  for (auto *e : Hand)
  {
    cout << " \t" << i++ << endl;
    e->printCouleur();
  }
}

void Joueur::printBibli()
{
  int i = 1;
  for (auto *e : Bibli)
  {
    cout << " \t" << i++ << endl;
    e->printCouleur();
  }
}

void Joueur::printGraveYard()
{
  int i = 1;
  for (auto &e : GraveYard)
  {
    cout << " \t" << i++ << endl;
    e->printCouleur();
  }
}

void Joueur::printBoard()
{
  int i = 1;
  for (auto &e : Board)
  {
    cout << " \t" << i++ << endl;
    e->printCouleur();
  }
}
// ------------------------------------------------------------------------------
// ------------------------------ LES ADDS ------------------------------
// ------------------------------------------------------------------------------

void Joueur::addToBibli(Carte *carte) { Bibli.push_back(carte); }
void Joueur::addToHand(Carte *carte) { Hand.push_back(carte); }
void Joueur::addToGraveYard(Carte *carte) { GraveYard.push_back(carte); }
void Joueur::addToBoard(Carte *carte) { Board.push_back(carte); }

// ------------------------------------------------------------------------------
// ------------------------------ LES NETYOYAGES ------------------------------
// ------------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------
// ------------------------------ METHODE UTILES  ------------------------------
// -----------------------------------------------------------------------------

int Joueur::VerifCin(int i)
{
  while (1)
  {
    if (cin.fail())
    {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      cout << "----------------------------------------------------------------" << endl;
      cout << " Entrer une valeur valide !" << endl;
      cout << "----------------------------------------------------------------" << endl;
      cout << "Numero : ";
      cin >> i;
    }
    if (!cin.fail())
      break;
  }
  return i;
}

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

// ------------------------------------------------------------------------------
// ------------------------------ POSER CARTES ------------------------------
// ------------------------------------------------------------------------------
void Joueur::PoserTerrain()
{
  int index;                                             // stockage de la valeur entrer dans le terminal
  vector<Carte *> TerrainEnMain = this->TerrainEnMain(); // Les terrains qui sont en mains
  if ((int)TerrainEnMain.size() == 0)                    // si PAS de terrains en mains
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << "Vous n'avez PAS de Terrain en main ! PETIT CHENAPAM ! PIOU PIOU 😮" << endl;
    cout << "----------------------------------------------------------------" << endl;
    APoserTerrain = false; // On set le bool qui gere le fait d'avoir poser un terrain a false
    return;                // On sort de la fonction.
  }
  else // sinon
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << "| Vous voulez donc poser un TERRAIN ! Très bien !              |" << endl;
    cout << "----------------------------------------------------------------" << endl;

    this->printHand(); // Print de la HAND pour que le joueur puisse choisir.

    cout << "----------------------------------------------------------------" << endl;
    cout << " Veuillez renseignez le numero de la carte a poser ! " << endl;
    cout << " Premiere carte afficher n° 1, etc..." << endl;
    cout << "----------------------------------------------------------------" << endl;

    cout << "Numero : ";
    cin >> index;
    index = this->VerifCin(index);

    // Evite les numero pas compris dans la hand
    bool valide = true;
    while (valide)
    {
      if (index > (int)Hand.size())
      {
        cout << "Valeur erronée ! Choisir une autre valeur" << endl;
        cout << "Numero : ";
        cin >> index;
        index = this->VerifCin(index);
      }
      else
      {
        valide = false;
      }
    }

    Carte *TerrainChoisie = Hand[index - 1];

    cout << "----------------------------------------------------------------" << endl;
    cout << " Voici la carte que vous avez choisi : " << endl;
    cout << "----------------------------------------------------------------" << endl;
    TerrainChoisie->printCouleur();
    cout << "----------------------------------------------------------------" << endl;
    cout << " Possibilité de la poser. Chargement... " << endl;
    cout << "----------------------------------------------------------------" << endl;

    if (TerrainChoisie->getID() == 1)
    {
      for (Carte *c : Hand)
      {
        if (c == TerrainChoisie) // surcharge su == si les cartes ont le mm numero unique
        {
          Board.push_back(Hand.at(index - 1));    // On ajoute la carte au board
          Hand.at(index - 1)->setLieu("Board");   //
          Hand.erase(Hand.begin() + (index - 1)); // On l'enleve de la mains
          APoserTerrain = true;                   // AposerTerrain = true
          cout << "----------------------------------------------------------------" << endl;
          cout << " Votre carte : " << TerrainChoisie->getNom() << " a ete poser ! " << endl;
          cout << "----------------------------------------------------------------" << endl;
          /*
          cout << "----------------------------------------------------------------" << endl;
          cout << " HAND APRES AVOIR POSER LE TERRAIN " << endl;
          cout << "----------------------------------------------------------------" << endl;
          this->printHand();
          cout << "----------------------------------------------------------------" << endl;
          cout << " BOARD APRES AVOIR POSER LE TERRAIN " << endl;
          cout << "----------------------------------------------------------------" << endl;
          this->printBoard();
          cout << "----------------------------------------------------------------" << endl;
          */
          return;
        }
      }
    }
    else
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << " Vous n'avez pas choisis un terrain ! Reesayer !" << endl;
      cout << "----------------------------------------------------------------" << endl;
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
  this->printHand();

  cout << "----------------------------------------------------------------" << endl;
  cout << " Veuillez renseignez le numero de la carte a poser ! " << endl;
  cout << " Premiere carte afficher n° 1, etc..." << endl;
  cout << "----------------------------------------------------------------" << endl;

  cout << "Numero : ";
  cin >> idCarteChoisie;
  idCarteChoisie = this->VerifCin(idCarteChoisie);

  vector<Carte *> TerrainDispo = this->TerrainDispo();
  // Evite les numeros pas compris dans la hand
  bool valide = true;
  while (valide)
  {
    if (idCarteChoisie > (int)Hand.size())
    {
      cout << "Valeur erronée ! Choisir une autre valeur" << endl;
      cout << "Numero : ";
      cin >> idCarteChoisie;
      idCarteChoisie = this->VerifCin(idCarteChoisie);
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
  if (CarteChoisie->getID() == 2) // si c'est bien une creature.
  {
    if (this->VerifCout(CarteChoisie)) // Si Verif cout renvoie true
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << " Votre carte peut etre poser ! (:)-<-< " << endl;
      cout << " Engagement des Terrains en cours..." << endl;
      cout << "----------------------------------------------------------------" << endl;

      this->EngageTerrainCouleur(CarteChoisie); // on lance l'engagement automatique des terrains

      this->EngageTerrainQuelconque(CarteChoisie); // on lance le choix de l'engagemenr des terrains pour le commonCost

      // Check des capacites de l'attaquant
      for (string capa : CarteChoisie->getCapacite()) // On parcours les capcites de la carte
      {
        if (capa == "Haste") // si elle a la capacite Haste
        {
          CarteChoisie->setPeutAttaquer(); // La carte peut attaquer des le premier tour
        }
      }

      Board.push_back(CarteChoisie); // on place la carte sur le board
      Hand.erase(Hand.begin() + id); // on l'enleve de la main
    }
    else
    {
      cout << " Impossible de poser votre carte ! [:o]-<-< " << endl;
    }
  }
  else
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Vous n'avez pas choisi de creature ! Reesayer !" << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
}

void Joueur::PoserEnchantement()
{

  int idCarteChoisie; // Variable qui stock l'ID de la carte choisie

  cout << "----------------------------------------------------------------" << endl;
  cout << "                 Quelle Enchantement voulez-vous jouer ?               " << endl;
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
  idCarteChoisie = this->VerifCin(idCarteChoisie);

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
      idCarteChoisie = this->VerifCin(idCarteChoisie);
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
  if (CarteChoisie->getID() == 3)
  {
    if (this->VerifCout(CarteChoisie))
    {
      cout << "----------------------------------------------------------------" << endl;
      cout << " Votre carte peut etre poser ! (:)-<-< " << endl;
      cout << " Engagement des Terrains en cours..." << endl;
      cout << "----------------------------------------------------------------" << endl;
      this->EngageTerrainCouleur(CarteChoisie);
      this->EngageTerrainQuelconque(CarteChoisie);

      if (CarteChoisie->getTarget() == "All")
      {
        for (Carte *carte : Board)
        {
          carte->setEndurance(carte->getEndurance() + CarteChoisie->getEnduranceBonus());
          carte->setBaseEndurance(carte->getBaseEndurance() + CarteChoisie->getEnduranceBonus());
          carte->setForce(carte->getForce() + CarteChoisie->getForceBonus());
        }
      }
      else
      {
        for (Carte *carte : Board)
        {
          if (carte->getType() == CarteChoisie->getTarget())
          {
            carte->setEndurance(carte->getEndurance() + CarteChoisie->getEnduranceBonus());
            carte->setBaseEndurance(carte->getBaseEndurance() + CarteChoisie->getEnduranceBonus());
            carte->setForce(carte->getForce() + CarteChoisie->getForceBonus());
          }
        }
      }

      GraveYard.push_back(CarteChoisie);
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
    cout << " Vous n'avez pas choisi un enchantement ! Reesayer !" << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
}

// --------------------------------------------------------------------
// ------------------------------ PHASES ------------------------------
// --------------------------------------------------------------------

void Joueur::PhaseDePioche()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::CouleurChoisie("Magenta");

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
  Color c = Color::CouleurChoisie("Magenta");
  cout << c << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "     ______      " << endl;
  cout << c << "    |      |  [][][]     [][][][] [][][][] [][][][] []    []  [][][]   [][[]][]  [][][]   [][][][] []      [] [][][][] []    [] [][][][]                      " << endl;
  cout << c << "    |      |  []    []   []       []       []       [][]  [] []        []    [] []        []       [][]  [][] []       [][]  []    []                         " << endl;
  cout << c << "    | (o)(o)  []    []   [][]     [][][][] [][][    [] [] [] []   [][] [][][][] []   [][] [][]     []  []  [] [][]     [] [] []    []             [][][] [] []" << endl;
  cout << c << "    C      _) []    []   []             [] []       []  [][] []     [] []    [] []     [] []       []      [] []       []  [][]    []             []  [] [][] " << endl;
  cout << c << "    | ,___|   [][][]     [][][][] [][][][] [][][][] []    []  [][][]   []    []  [][][]   [][][][] []      [] [][][][] []    []    []   [] [] []  [][][] [] []" << endl;
  cout << c << "    |   /" << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

  if (this->getBoard().empty())
  {
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    cout << " LE JOUEUR " << this->getNom() << " N'A PAS DE TERRAINS SUR LE BOARD ! " << endl;
    cout << "--------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
    return 0;
  }
  else
  {
    for (Carte *carte : Board)
    {
      carte->setDesengage();
    }
  }
  return 1;
}

void Joueur::PhasePrincipale()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::CouleurChoisie("Magenta");
  cout << c << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "   ____________                                                                                                                                                              " << endl;
  cout << c << "  |    _|_     |  [][][][] [][][][] [][][][] [][][][] [][][][]   []      [] [][][][] [][][][]    [][][][] [][][][] [][][][] [][][][]  [][][][] [][][][]                                                                                                                                       " << endl;
  cout << c << "  |   |_|_|    |  []    [] []    [] []       []       []    []    []    []  []    [] []          []       []    [] []    []    []     []       []                                                                                               " << endl;
  cout << c << "  |   |   |    |  [][][][] []    [] [][][][] [][]     [][][][]     []  []   []    [] [][][][]    []       [][][][] [][][][]    []     [][]     [][][][]                                                                                                                      " << endl;
  cout << c << "  |   |___|    |  []       []    []       [] []       []  []        [][]    []    []       []    []       []    [] []  []      []     []             []                                                                                " << endl;
  cout << c << "  |____________|  []       [][][][] [][][][] [][][][] []   []        []     [][][][] [][][][]    [][][][] []    [] []    []    []     [][][][] [][][][] [][][]                                                                                                                       " << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

  bool continu = true;
  while (continu)
  {

    Color c1 = Color::CouleurChoisie("Red");
    cout << "----------------------------------------------------------------" << endl;
    cout << c1 << this->getNom() << couleurDefaut << " Voulez-vous poser un TERRAIN [1], une CREATURE [2], un Enchantement [3] ou rien [4]" << endl;
    cout << " Entrer " << c1 << " [1] , [2] , [3] ou [4] " << couleurDefaut << endl;
    cout << "----------------------------------------------------------------" << endl;

    int index;
    cin >> index;
    index = this->VerifCin(index);

    if (index == 1)
    {
      if (APoserTerrain == false)
      {
        this->PoserTerrain();
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
      continu = true;
    }
    else if (index == 3)
    {
      this->PoserEnchantement();
      this->TerrainDispo();
      continu = true;
    }
    else if (index == 4)
    {
      continu = false;
    }
    else
    {
      cout << " Entrer un nombre compris entre [1] et [4] ! MERCI (':-|) " << endl;
    }
  }
}

void Joueur::PhaseSecondaire()
{
  this->PhasePrincipale();
}

void Joueur::FinDeTour()
{
  Color couleurDefaut(FG_DEFAULT);
  Color c = Color::CouleurChoisie("Magenta");
  cout << c << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;
  cout << c << "                                                                                                                                                                " << endl;
  cout << c << "   [][][][] []  []    []    [][][]   [][][][]   [][][][] [][][][] []    [] [][][][]                        " << endl;
  cout << c << "   []       []  [][]  []    []    [] []            []    []    [] []    [] []    []                                                                                                              " << endl;
  cout << c << "   [][]     []  [] [] []    []    [] [][]          []    []    [] []    [] [][][][]     " << endl;
  cout << c << "   []       []  []  [][]    []    [] []            []    []    [] []    [] []  []                                                                                                         " << endl;
  cout << c << "   []       []  []    []    [][][]   [][][][]      []    [][][][] [][][][] []    []         " << endl;
  cout << couleurDefaut << " --------------------------------------------------------------------------------------------------------------------------------------------------------------- " << endl;

  APoserTerrain = false;
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
    while (1)
    {
      if (cin.fail())
      {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << " Veuillez entrer une valeur valide " << endl;
        cin >> id;
      }
      if (!cin.fail())
        break;
    }

    if (id > (int)Hand.size())
    {
      cout << "Veuiller rentrer un numero valide " << endl;
      cin >> id;
      // ICIIIII
    }
    else
    {
      GraveYard.push_back(Hand[id - 1]);
      Hand.erase(Hand.begin() + (id - 1));
    }
  }

  for (Carte *c : Board)
  {
    c->setPeutAttaquer();
    c->setEndurance(c->getBaseEndurance());
  }
}

// ------------------------------------------------------------------------------
// ------------------------------ GESTION DE COUT  ------------------------------
// ------------------------------------------------------------------------------
bool Joueur::VerifCout(Carte *CarteChoisie)
{
  map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
  map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // map qui repertorie le cout dispo en jeu
  map<std::string, int>::iterator it, it2;                                     // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.

  int coutTotal = CarteChoisie->CoutTotale(); // Le cout total de la carte choisie
  int res = this->CoutTotalDispoEnJeu();      // Une map qui repertorie le cout total dispo en jeu.

  /*for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); it2++)
  {
    cout << it2->first << " : " << it2->second << endl;
  }
  */

  /*
    Pour placer la carte il faut :
      - Que le nb de carte terrain dispo sur le board soit superieur au nb totale de carte terrain besoin
      - Si cette condition est remplie alors on verifie que le cout en couleur est respecter
      s'il ne l'ai pas on ne peut pas placer la carte.
      - et comme on a vu que le nb totale de carte dispo est >= au nb de carte besoin et que le nb de carte
      de couleur est verifier on peut poser la carte et donner le choix au joueur d'engager les terrains qu'il reste.

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

// ----------------------------------------------------------------------------------
// ------------------------------ ENGAGEMENT TERRAINS  ------------------------------
// ----------------------------------------------------------------------------------

vector<string> Joueur::TerrainAEngager(Carte *CarteChoisie)
{
  map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
  map<string, int> coutDispo = this->CoutDisponibleEnJeu();                    // map qui repertorie le cout dispo en jeu
  map<std::string, int>::iterator it1, it2;                                    // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.

  int coutTotal = CarteChoisie->CoutTotale(); // Le cout total de la carte choisie
  int res = this->CoutTotalDispoEnJeu();      // le cout total dispo en jeu.

  map<string, int>::iterator it;
  vector<string> CarteAEngage;
  if (res >= coutTotal) // si le cout total dispo en jeu >= cout total de la carte choisie
  {
    for (it = Cout_CouleurCarteChoisie.begin(); it != Cout_CouleurCarteChoisie.end(); it++) // On parcours la map qui repertorie les couts en couleur de la carte en question.
    {
      int i = 0;
      if (it->first == "White" && coutDispo["White"] >= it->second) // si == White et que Le cout dispo >= cout couleur besoin, alors on ajoute au resultat sinon pas la peine.
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
  vector<string> Terrains = this->TerrainAEngager(c); // recupere la liste des terrains à engager.
  vector<Carte *> res;                                // valeur que l'on va renvoyer

  for (auto s : Terrains) // On parcours les terrains a engager.
  {
    int cpt = 0;
    for (auto c : this->TerrainDispo()) // on parcours les terrains dispos.
    {
      if (s == c->getCouleur() && cpt < 1)
      {
        res.push_back(c); // et on les ajoute dns les terrains a engager.
        cpt++;
      }
    }
  }
  return res;
}

void Joueur::EngageTerrainCouleur(Carte *CarteChoisie)
{
  vector<Carte *> Terrains = this->TerrainCouleurAEngage(CarteChoisie); // Listes des terrains couleur a engager
  vector<Carte *> TerrainsDispo = this->TerrainDispo();                 // Listes des terrains dispos.

  cout << "----------------------------------------------------------------" << endl;
  cout << " Voici vos terrains disponibles " << endl;
  cout << "----------------------------------------------------------------" << endl;
  cout << "----------------------------------------------------------------" << endl;
  int i = 1;
  // On affiche les terrains dispos
  for (Carte *c : TerrainsDispo)
  {
    cout << " \t" << i++ << endl;
    c->printCouleur();
  }

  cout << "----------------------------------------------------------------" << endl;
  cout << " Le(s) terrain(s) suivant vont être engagee (;-o) : " << endl;
  cout << "----------------------------------------------------------------" << endl;
  // On affiche les terrains qui vont automatiquement etre engager.
  for (auto c : Terrains)
  {
    c->printCouleur();
  }
  cout << endl;

  for (Carte *c : TerrainsDispo) // Parcours les terraisn dispos
  {
    for (Carte *t : Terrains) // Parcours les terrains a engager
    {
      if (c == t) // grace a la surcharge sur Numero on engage seulement s'ils sont egales.
      {
        c->setEngage();
      }
    }
  }
  TerrainsDispo = this->MAJTerrainDispo(); // met a jours les terrains dispos.
  cout << "----------------------------------------------------------------" << endl;
  cout << " Vos terrains ont bien ete engager voici la liste de vos terrains encore disponibles " << endl;
  cout << "----------------------------------------------------------------" << endl;
  int k = 1;
  for (auto c : TerrainsDispo)
  {
    cout << " \t" << k++ << endl;
    c->printCouleur();
  }
  return;
}

void Joueur::EngageTerrainQuelconque(Carte *CarteChoisie)
{
  int index;
  int nb = CarteChoisie->getCost();
  vector<Carte *> TerrainsDispo = this->TerrainDispo();
  int i = 0;

  if (nb == 0) // si le commonCost = 0, pas besoin d'engager de terrains supplementaires.
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Pas besoin de terrains supplementaires " << endl;
    cout << "----------------------------------------------------------------" << endl;
  }
  else // sinon
  {
    cout << "----------------------------------------------------------------" << endl;
    cout << " Vous devez engager encore : " << nb << " terrains ! " << endl;
    cout << "----------------------------------------------------------------" << endl;

    while (i < nb) // tant qu'on a pas engager le bon nombre de terrains
    {
      Color couleurDefaut(FG_DEFAULT);
      cout << " Entrer le n° du " << c1 << "Terrain" << couleurDefaut << " que vous voulez engager : ";
      cin >> index;
      index = VerifCin(index);

      cout << endl;
      cout << "----------------------------------------------------------------" << endl;

      Carte *TerrainChoisie = this->TerrainDispo()[index - 1]; // On recup la carte choisie.

      for (Carte *t : TerrainsDispo) // On parcours les terrains dispo.
      {
        if (TerrainChoisie == t) // grace a la surcharge si mm Numero alors :
        {
          TerrainChoisie->setEngage(); // On engage le terrain.
        }
      }

      TerrainsDispo = this->MAJTerrainDispo(); // On met a jour les terrains dispos.
      cout << "----------------------------------------------------------------" << endl;
      cout << " Votre terrain a bien ete engager ! Voici les terrains qu'il vous reste " << endl;
      cout << "----------------------------------------------------------------" << endl;
      int j = 1;
      for (auto c : TerrainsDispo)
      {
        cout << " \t" << j++ << endl;
        c->printCouleur();
      }
      i++;
    }
  }
  return;
}
