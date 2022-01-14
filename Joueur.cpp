#include "Joueur.hpp"
#include "Carte.hpp"
#include "Terrain.hpp"

#include <algorithm>
#include <iostream>
#include <random> // std::default_random_engine

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

// Les gets
string Joueur::getNom() { return nom; }
int Joueur::getHP() { return HP; }
bool Joueur::getMort() { return mort; }
vector<Carte> Joueur::getBibli() { return Bibli; }
vector<Carte> Joueur::getBoard() { return Board; }
vector<Carte> Joueur::getGraveYard() { return GraveYard; }
vector<Carte> Joueur::getHand() { return Hand; }

// Les sets
void Joueur::setNom(string n) { nom = n; }
void Joueur::setHP(int s) { HP = s; }
vector<Carte> Joueur::setBibli(Deck v)
{
  Bibli = v.getDeck();
  return Bibli;
}

// Les Methodes
bool Joueur::VerifMort()
{
  if (this->getHP() <= 0 || mort == true)
  {
    cout << "Le joueur " << this->getNom() << " est mort ! C'est CIAO !!" << endl;
    return mort = true;
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

void Joueur::MelangeBibli(vector<Carte> v)
{
  random_device rd;
  default_random_engine rng(rd());
  shuffle(v.begin(), v.end(), rng);
  this->Bibli = v;
}

void Joueur::printBibli()
{
  for (auto e : Bibli)
  {
    e.print();
  }
}

int Joueur::PhaseDePioche()
{
  if (this->getBibli().empty())
  {
    mort = true;
    this->VerifMort();
    return 0;
  }
  else
  {
    this->getHand().push_back(this->getBibli().front());
    this->getBibli().erase(this->getBibli().begin());
    return 1;
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
}

Carte Joueur::ChoixCreature() {
  int id;
  cout << "Quelle carte voulez-vous jouer ? :) " << endl;
  this->getHand().print();
  cout << " Veuillez renseignez le numero de la carte à poser " << endl;
  getline(cin, id);
  Creature CarteChoisie = Carte(id);
  return CarteChoisie;
}

int Joueur::PhasePrincipale() {
    // Stockage des terrains 
    vector<Terrain> nbLand;
    for(Carte& carte : this->getBoard()) {
      if ( carte.getID() == 1 && carte.getEtat() = false) {
        nbLand.push_back(carte);
      }
    }

    bool FinChoix = true;
    while(FinChoix = false) {
      Creature CarteChoisie = this->ChoixCreature(); //Creature choisie par le joueur.
    }
  
   
    int cost = CarteChoisie.getCost();
    vector<string> cost_couleur = CarteChoisie.getCout_Couleur();
    int nb = cost_couleur.size();
  
    for(Terrain& c : nbLand) {
      int i = 0;
      for ( auto s : cost_couleur) {
        if ( c.getCouleur() = s ) {
          c.setEngage();
          if ( i = nb) {
            return 1;
          }
          nbLand.erase(c);
      }
    } 
    }
    

  }
}
