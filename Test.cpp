#include <vector>
#include <iostream>
using namespace std;

vector<Carte *> Joueur::ChoixCreature()
{
  // Ici on demande au joeur quelle creture il veut poser :
  // Lorsqu'il a choisis ca carte on la recupere et
  // on verifie si le cout en mana est disponible sur le Board.
  int idCarteChoisie;

  vector<Carte *> ResCartePoser;

  while (idCarteChoisie != 213 )
  {
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

    // Les cartes terrains disponible en jeu.
    int CoutCarteChoisie = CarteChoisie->getCost(); // Le cout de la carte choisie
    map<string, int> Cout_CouleurCarteChoisie = CarteChoisie->getCout_Couleur(); // Une map qui repertorie les couts en couleur de la carte en question.
    map<string, int> coutDispo = this->CoutDisponibleEnJeu(); // Une map qui repertorie le cout dispo en jeu.
    std::map<std::string, int>::iterator it1, it2; // Cree l'iterateur sur la map | it-> first : premier element | it -> second  : deuxieme element.
    vector<Carte *> CarteEngageCeTour; // Les cartes terrains engagees ce tour.

    // On parcours le CoutTotalDispo sur le BOARD pour voir si le cout totale de la carte est inferieur au cout dispo.
    int res = this->CoutTotalDispoEnJeu();

    if (CarteChoisie->getID() == 1)
    {
      this->PoserTerrain();
    }
    else
    {
      if (CarteChoisie->CoutTotale() <= res) // Si le cout de la carte est inferieur au cout total dispo en jeu
      {
        for (it1 = coutDispo.begin(); it1 != coutDispo.end(); ++it1) // On parcours le cout dispo en jeu 
        {
          for (it2 = Cout_CouleurCarteChoisie.begin(); it2 != Cout_CouleurCarteChoisie.end(); ++it2) // On parcours le cout couleur de la carte
          {
            if (it1->first == it2->first) // Si la clé est la meme alors
            {
              if (it1->second < it2->second) // Si le coutDispo est inferieur au cout demandé par la carte IMPOSSIBLE
              {
                cout << " Vous n'avez pas assez de carte Terrain : " << it1->first << " sur votre Board" << endl;
                cout << " Impossible de placer la carte que vous avez choisi !" << endl;
                cout << " Voulez vous poser une autre carte ? Si OUI ecrire le numero ecrire 213 ! " << endl;
                cin >> idCarteChoisie; // On lui demande s'il veut en poser une autre
              }
              else if (it1->second >= it2->second) // Si le cout dispo >= le cout besoin de la carte ok
              {
                cout << " Vous avez assez de carte Terrain sur votre Board" << endl;
                cout << " Voulez vous poser une autre carte ? Si OUI ecrire le numero sinon ecrire 213 ! " << endl;

                int cpt = 0;
                {
                  for (Carte *c : this->TerrainDispo()) // On engage le bon nombre de cartes de couleur necessaires
                  {
                    // Si le nombre de carte qui reste correspond au getCost() de la carte alors on engage sinon on engage pas on ne peut pas poser la carte.
                    if (c->getCouleur() == it1->first && cpt <= it2->second)
                    {
                      c->setEngage();
                      CarteEngageCeTour.push_back(c);
                      this->TerrainDispo().erase(CarteEngageCeTour.begin() + cpt);
                    }
                    cpt++;
                    res = this->CoutTotalDispoEnJeu();
                  } // Une fois les cartes engagé on verifie qu'il
                }
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
        cout << " Vous avez assez de carte Terrain sur votre Board" << endl;
        cout << "Voulez vous choisir une autre carte ? " << endl;
        cin >> idCarteChoisie;
      }
    }
  }
  return ResCartePoser;
}
