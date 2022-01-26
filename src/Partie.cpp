
#include "../Headers/Partie.hpp"
#include "../Headers/printAffichage.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

// -- -- -- Constructeur -- -- --
Partie::Partie(Joueur J1, Joueur J2, int tour)
{
    this->J1 = J1;
    this->J2 = J2;
    this->tour = tour;
}

// -- -- -- les gets -- -- --
Joueur *Partie::getJoueur1() { return &J1; }
Joueur *Partie::getJoueur2() { return &J2; }
int Partie::getTour() { return tour; }

// -- -- -- les sets -- -- --
void Partie::setTour(int t) { tour = t + 1; } // Voir si on garde
void Partie::setJoueur1(Joueur j) { J1 = j; }
void Partie::setJoueur2(Joueur p) { J2 = p; }

//  -- -- -- les methodes -- -- --
void Partie::PartieDeMagic(Joueur& J1, Joueur& J2)
{
    printAffichage p = printAffichage();
    string AllDeck = "";
    vector<string> AllDeckList = {};
    string path = "./";
     for (const auto & entry : fs::directory_iterator(path)){
          if(entry.path().extension() == ".json" && entry.path() != "./Cards.json" && entry.path() != "./CardsList.json"){
              AllDeck += entry.path().filename().stem().string() + "  ";
              AllDeckList.push_back(entry.path().filename().stem().string());
          }
     }
    bool DeckValide = false;
    string deckJ1 = "";
    string deckJ2 = "";
    cout << "Veuillez choisir un deck parmi cette liste : " << endl << endl << AllDeck << endl << endl;
    // Selection du deck J1
    while(DeckValide == false){
        for(string deck : AllDeckList){
            if(deckJ1 == deck){ 
                DeckValide = true;
            }
        }
        if(DeckValide == false){
            cout << J1.getNom() << ", veuillez choisir votre deck en rentrant son nom :" << endl;
            cin >> deckJ1;
        }
    }
    DeckValide = false;
    // Selection du deck J2
    while(DeckValide == false){
        for(string deck : AllDeckList){
            if(deckJ2 == deck){
                DeckValide = true;
            }
        }
        if(DeckValide == false){
            cout << J2.getNom() << ", veuillez choisir votre deck en rentrant son nom :" << endl;
            cin >> deckJ2;
        }
    }

    // -- Creation Deck --
    Deck d1 = Deck(deckJ1); // Creation du Deck. OK.
    Deck d2 = Deck(deckJ2);

    // Bibliotheques des deux joueurs. OK.
    J1.setBibli(d1);
    J2.setBibli(d2);

    // On melange au prealables les Bibliothèques des deux joueurs. OK.
    J1.MelangeBibli();
    J2.MelangeBibli();

    // Creation des mains avant le dubut du premier tour. OK.
    J1.setInitialHand();
    J2.setInitialHand();
    J1.NettoyageBibli();
    J2.NettoyageBibli();

    int n = rand() % 2;
    bool premiertour = true;

    while (J1.VerifMort() == false || J2.VerifMort() == false || J1.getMort() == false || J2.getMort() == false)
    {

        if (n % 2 == 0)
        {

            if (J1.VerifMort() == true)

            {
                cout << " HP de " << J1.getNom() << " = " << J1.getHP() << endl;
                p.printVictoire();
                cout << " Bravo à " << J2.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                return;
            }
            else
            {
                if (premiertour == false)
                {
                    p.printPioche();
                    J1.PhaseDePioche();
                    if (J1.getMort() == true)
                    {
                        cout << J1.getNom() << " : " << J1.getMort() << endl;
                        p.printVictoire();
                        cout << " Bravo à " << J2.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                        return;
                    }
                }

                p.printDesengagement();
                J1.PhaseDeDesengagement();
                J1.setPasPoserTerrain();

                p.printPrincipale();
                J1.PhasePrincipale();

                p.printCombat();
                PhaseDeCombat(J1, J2);
                J1.NettoyageHand();
                J2.NettoyageHand();
                J1.NettoyageGraveYard();
                J2.NettoyageGraveYard();
                /*
                cout << "Cimetiere de : " << J1.getNom() << endl;
                J1.printGraveYard();
                cout << "Cimetiere de : " << J2.getNom() << endl;
                J2.printGraveYard();
                cout << "HP de : " << J1.getNom() << " : " << J1.getHP() << endl;
                cout << "HP de : " << J2.getNom() << " : " << J2.getHP() << endl;

                cout << "Main de : " << J1.getNom() << endl;
                J1.printHand();
                cout << "Main de : " << J2.getNom() << endl;
                J2.printHand();
                */
                p.printPrincipale();
                J1.PhaseSecondaire();

                p.printFinDeTour();
                J1.FinDeTour();
                n += 1;
                premiertour = false;
            }
        }

        if (n % 2 == 1)
        {

            if (J2.VerifMort() == true)

            {
                cout << " HP de " << J2.getNom() << " = " << J2.getHP() << endl;
                p.printVictoire();
                cout << " Bravo à " << J1.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                return;
            }
            else
            {
                if (premiertour == false)
                {
                    p.printPioche();
                    J2.PhaseDePioche();
                    if (J2.getMort() == true)
                    {
                        cout << J2.getNom() << " : " << J2.getMort() << endl;
                        p.printVictoire();
                        cout << " Bravo à " << J1.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                        return;
                    }
                }

                p.printDesengagement();
                J2.PhaseDeDesengagement();
                J2.setPasPoserTerrain();

                p.printPrincipale();
                J2.PhasePrincipale();

                p.printCombat();
                PhaseDeCombat(J2, J1);
                J1.NettoyageHand();
                J2.NettoyageHand();
                J1.NettoyageGraveYard();
                J2.NettoyageGraveYard();
                /*
                cout << "Cimetiere de : " << J1.getNom() << endl;
                J1.printGraveYard();
                cout << "Cimetiere de : " << J2.getNom() << endl;
                J2.printGraveYard();

                cout << "HP de : " << J1.getNom() << " : " << J1.getHP() << endl;
                cout << "HP de : " << J2.getNom() << " : " << J2.getHP() << endl;

                cout << "Main de : " << J1.getNom() << endl;
                J1.printHand();
                cout << "Main de : " << J2.getNom() << endl;
                J2.printHand();
                */

                p.printPrincipale();
                J2.PhaseSecondaire();

                p.printFinDeTour();
                J2.FinDeTour();
                n += 1;
                premiertour = false;
            }
        }
    }
    return;
}

void Partie::PartieDeMagicCombatTest(Joueur& J1, Joueur& J2)
{
    printAffichage p = printAffichage();
    string deckJ1 = "CreateTest";
    string deckJ2 = "CreateTest";
    // -- Creation Deck --
    Deck d1 = Deck(deckJ1); // Creation du Deck. OK.
    Deck d2 = Deck(deckJ2);

    // Bibliotheques des deux joueurs. OK.
    J1.setBibli(d1);
    J2.setBibli(d2);

    // On melange au prealables les Bibliothèques des deux joueurs. OK.
    J1.MelangeBibli();
    J2.MelangeBibli();

    // Creation des mains avant le dubut du premier tour. OK.
    J1.setInitialHand();
    J2.setInitialHand();
    J1.NettoyageBibli();
    J2.NettoyageBibli();

    int n = rand() % 2;
    bool premiertour = true;

    while (J1.VerifMort() == false || J2.VerifMort() == false || J1.getMort() == false || J2.getMort() == false)
    {

        if (n % 2 == 0)
        {

            if (J1.VerifMort() == true)

            {
                cout << " HP de " << J1.getNom() << " = " << J1.getHP() << endl;
                p.printVictoire();
                cout << " Bravo à " << J2.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                return;
            }
            else
            {
                if (premiertour == false)
                {
                    p.printPioche();
                    J1.PhaseDePioche();
                    if (J1.getMort() == true)
                    {
                        cout << J1.getNom() << " : " << J1.getMort() << endl;
                        p.printVictoire();
                        cout << " Bravo à " << J2.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                        return;
                    }
                }

                p.printDesengagement();
                J1.PhaseDeDesengagement();

                p.printCombat();
                PhaseDeCombatTest(J1, J2);

                J1.NettoyageHand();
                J2.NettoyageHand();

                cout << "Cimetiere de : " << J1.getNom() << endl;
                J1.printGraveYard();
                cout << "Cimetiere de : " << J2.getNom() << endl;
                J2.printGraveYard();
                cout << "HP de : " << J1.getNom() << " : " << J1.getHP() << endl;
                cout << "HP de : " << J2.getNom() << " : " << J2.getHP() << endl;

                cout << "Main de : " << J1.getNom() << endl;
                J1.printHand();
                cout << "Main de : " << J2.getNom() << endl;
                J2.printHand();

                p.printFinDeTour();
                J1.FinDeTour();
                n += 1;
                premiertour = false;
            }
        }

        if (n % 2 == 1)
        {

            if (J2.VerifMort() == true)

            {
                cout << " HP de " << J2.getNom() << " = " << J2.getHP() << endl;
                p.printVictoire();
                cout << " Bravo à " << J1.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                return;
            }
            else
            {
                if (premiertour == false)
                {
                    p.printPioche();
                    J2.PhaseDePioche();
                    if (J2.getMort() == true)
                    {
                        cout << J2.getNom() << " : " << J2.getMort() << endl;
                        p.printVictoire();
                        cout << " Bravo à " << J1.getNom() << " pour la victoire ! Bravo mon champion ! " << endl;
                        return;
                    }
                }

                p.printDesengagement();
                J2.PhaseDeDesengagement();

                p.printCombat();
                PhaseDeCombatTest(J2, J1);
                
                J1.NettoyageHand();
                J2.NettoyageHand();
                cout << "Cimetiere de : " << J1.getNom() << endl;
                J1.printGraveYard();
                cout << "Cimetiere de : " << J2.getNom() << endl;
                J2.printGraveYard();

                cout << "HP de : " << J1.getNom() << " : " << J1.getHP() << endl;
                cout << "HP de : " << J2.getNom() << " : " << J2.getHP() << endl;

                cout << "Main de : " << J1.getNom() << endl;
                J1.printHand();
                cout << "Main de : " << J2.getNom() << endl;
                J2.printHand();

                p.printFinDeTour();
                J2.FinDeTour();
                n += 1;
                premiertour = false;
            }
        }
    }
    return;
}

void Partie::PhaseDeCombat(Joueur& J1, Joueur& J2)
{

    Color cJ = Color::CouleurChoisie("Red");

    Color couleurDefaut(FG_DEFAULT);

    // -- -- -- -- -- Partie choix de l'attaquant -- -- -- -- --

    vector<Carte *> liste_Attaque = {}; // Liste qui donne toutes les cartes avec lesquelles l'attaque est possible

    // Ajouter && J1.getHand()[i]->getPeutAttaquer() == true au IF
    for (unsigned int i = 0; i < J1.getBoard().size(); i++)
    {
        if (J1.getBoard()[i]->getID() == 2 && J1.getBoard()[i]->getEtat() == false && J1.getBoard()[i]->getPeutAttaquer() == true)
        {
            liste_Attaque.push_back(J1.getBoard()[i]);
        }
    }

    if (liste_Attaque.empty())
    {
        cout << "----------------------------------------------------------------" << endl;
        cout << "Joueur " << cJ << J1.getNom() << couleurDefaut << " ne peut pas attaquer ce tour ci" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }

    else
    {
        cout << "----------------------------------------------------------------" << endl;
        cout << "Joueur " << cJ << J1.getNom() << couleurDefaut << endl;
        cout << "----------------------------------------------------------------" << endl;
        int compteur = 0;
        for (Carte *carte : liste_Attaque)
        { // J'affiche les cartes avec lesquelles l'attaque est possible
            carte->printCouleur();
            compteur += 1;
        }

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer ? Quand tu as fini, rentre " << cJ << "OK" << couleurDefaut << ", ET EN MAJUSCULE !! :" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        string safeword = "";                 // Mot cle defini a OK qui permet a l'utilisateur de terminer son action
        vector<int> choix_attaquant = {};     // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite attaquer
        vector<Carte *> Attacking_Cards = {}; // Vecteur de carte qui contient les cartes qui vont attaquer

        while (safeword != "OK")
        { // Tant que l'utilisateur n'a pas ecrit ok, il rentre les cartes avec lesquelles il compte attaquer
            cin >> safeword;

            if (safeword != "OK")
            {
                if(stoi(safeword) > compteur || stoi(safeword) <= 0){
                    cout << "Veuillez entrer un numero valide" << endl;
                }
                else{
                choix_attaquant.push_back(stoi(safeword));
                safeword = "";
                }
            }
        }
        for (int i : choix_attaquant)
        { // Ajout des cartes dans le vecteur de carte qui contient les cartes qui vont attaquer
            Attacking_Cards.push_back(liste_Attaque[i - 1]);
        }

        cout << "----------------------------------------------------------------" << endl;
        cout << " Tu as donc selectionne les cartes suivantes " << endl;
        cout << "----------------------------------------------------------------" << endl;

        for (Carte *carte : Attacking_Cards)
        { // Affichage des cartes selectionne par le joueur
            carte->printCouleur();
        }

        // -- -- -- -- -- Partie choix du defenseur -- -- -- -- --

        cout << "----------------------------------------------------------------" << endl;
        cout << "Maintenant ! Joueur " << cJ << J2.getNom() << couleurDefaut << endl;
        cout << "----------------------------------------------------------------" << endl;

        vector<Carte *> liste_Defense = {}; // Liste qui donne toutes les cartes avec lesquelles la defense est possible

        safeword = "";
        for (unsigned int i = 0; i < J2.getBoard().size(); i++)
        {
            if (J2.getBoard()[i]->getID() == 2 && J2.getBoard()[i]->getEtat() == false)
            {
                liste_Defense.push_back(J2.getBoard()[i]);
            }
        }

        if (liste_Defense.empty())
        {
            cout << "----------------------------------------------------------------" << endl;
            cout << "Joueur " << cJ << J2.getNom() << couleurDefaut << " ne peut pas defendre ce tour ci" << endl;
            cout << "----------------------------------------------------------------" << endl;
            for (Carte *carte : Attacking_Cards)
            {
                bool AtLifeLink = false;
                carte->setEngage();

                // Check des capacites de l'attaquant
                for (string capa : carte->getCapacite())
                {
                    if (capa == "LifeLink")
                    {
                        AtLifeLink = true;
                    }
                }
                cout << "-----------------------------------------------------" << endl;
                cout << "Ok, celle-ci va te percuter de plein fouet ! " << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "avant attaque : " << J2.getHP() << endl;
                J2.setHP((J2.getHP()) - (carte->getForce()));
                cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "apres attaque : " << cJ << J2.getHP() << endl;

                // Check de la capacité lifelink
                if (AtLifeLink == true)
                {
                    J1.setHP((J1.getHP()) + (carte->getForce()));
                }
                safeword = "";
            }
        }

        else
        {
            for (Carte *carte : Attacking_Cards)
            {
                bool AtFly = false;
                bool AtLifeLink = false;
                bool AtDeathTouch = false;
                bool ADeathRattle = false;
                carte->setEngage();

                // Check des capacites de l'attaquant
                for (string capa : carte->getCapacite())
                {
                    if (capa == "LifeLink")
                    {
                        AtLifeLink = true;
                    }
                    if (capa == "DeathTouch")
                    {
                        AtDeathTouch = true;
                    }
                    if (capa == "Flying")
                    {
                        AtFly = true;
                    }
                    if (capa == "DeathRattle")
                    {
                        ADeathRattle = true;
                    }
                }
                cout << "----------------------------------------------------------------" << endl;
                cout << " Quelle carte va te defendre face a cette carte ! " << endl;
                cout << "----------------------------------------------------------------" << endl;
                carte->printCouleur();
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "Veux tu defendre sur cette carte ? Ci dessous les cartes avec lesquelles tu peux defendre ! " << endl;
                cout << "Entrer " << cJ << "OUI " << couleurDefaut << "si tu veux defendre, " << cJ << "NON" << couleurDefaut << " sinon !" << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                for (Carte *carte_def : liste_Defense)
                {
                    carte_def->printCouleur();
                }

                cin >> safeword;

                if (safeword == "NON")
                {
                    cout << "-----------------------------------------------------" << endl;
                    cout << "Ok, celle-ci va te percuter de plein fouet ! " << endl;
                    cout << "-----------------------------------------------------" << endl;
                    cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "avant attaque : " << J2.getHP() << endl;
                    J2.setHP((J2.getHP()) - (carte->getForce()));
                    cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "apres attaque : " << cJ << J2.getHP() << endl;

                    // Check de la capacité lifelink
                    if (AtLifeLink == true)
                    {
                        J1.setHP((J1.getHP()) + (carte->getForce()));
                    }
                    safeword = "";
                }

                if (safeword == "OUI")
                {
                    bool stop = false;

                    cout << "----------------------------------------------------------------------------------" << endl;
                    cout << " Tres bien, avec quelle carte compte tu defendre ? Rentre " << cJ << "OK " << couleurDefaut << "quand tu as fini" << endl;
                    cout << "----------------------------------------------------------------------------------" << endl;
                    safeword = "";

                    for (Carte *carte_def : liste_Defense)
                    {
                        carte_def->printCouleur();
                    }

                    cin >> safeword;

                    if (safeword == "OK")
                    {
                        stop = true;
                    }

                    while (stop == false)
                    {
                        cout << "-----------------------------------------------------" << endl;
                        cout << " Tu as choisi cette carte ! " << endl;
                        cout << "-----------------------------------------------------" << endl;
                        liste_Defense[stoi(safeword) - 1]->printCouleur();

                        bool DefFly = false;
                        bool DefReach = false;
                        bool DefLifeLink = false;
                        bool DefDeathTouch = false;
                        bool DefDeathRattle = false;

                        // Check des capacites du defenseur
                        for (string capa : liste_Defense[stoi(safeword) - 1]->getCapacite())
                        {
                            if (capa == "LifeLink")
                            {
                                DefLifeLink = true;
                            }
                            if (capa == "Reach")
                            {
                                DefReach = true;
                            }
                            if (capa == "DeathTouch")
                            {
                                DefDeathTouch = true;
                            }
                            if (capa == "Flying")
                            {
                                DefFly = true;
                            }
                            if (capa == "DeathRattle")
                            {
                                DefDeathRattle = true;
                            }
                        }

                        // Check de la capacite Flying pour l'attaquant et si le defenseur n'a ni flying ni reach
                        if (AtFly == true && DefReach == false && DefFly == false)
                        {
                            cout << "------------------------------------------------------------------------------" << endl;
                            cout << "La carte que tu as choisi ne peut pas defendre sur la carte qui t'attaque ! " << endl;
                            cout << "------------------------------------------------------------------------------" << endl;
                        }

                        else
                        {

                            // Actualisation des points de vie
                            liste_Defense[stoi(safeword) - 1]->minusEndurance(carte->getForce());
                            carte->minusEndurance(liste_Defense[stoi(safeword) - 1]->getForce());

                            // Check de la capacite DeathTouch pour l'attaquant
                            if (AtDeathTouch == true)
                            {
                                cout << "L'attaquant a death touch" << endl;
                                liste_Defense[stoi(safeword) - 1]->setEndurance(0);
                            }

                            // Check de la capacite DeathTouch pour le défenseur
                            if (DefDeathTouch == true)
                            {
                                cout << "Le defenseur a death touch" << endl;
                                carte->setEndurance(0);
                            }

                            // Check de la capacite lifelink pour l'attaquant
                            if (AtLifeLink == true)
                            {
                                J1.setHP((J1.getHP()) + (carte->getForce()));
                            }

                            // Check de la capacite lifelink pour le défenseur
                            if (DefLifeLink == true)
                            {
                                J2.setHP((J2.getHP()) + (liste_Defense[stoi(safeword) - 1]->getForce()));
                            }

                            if (liste_Defense[stoi(safeword) - 1]->getEndurance() <= 0)
                            {
                                liste_Defense[stoi(safeword) - 1]->setLieu("GraveYard");
                                if (DefDeathRattle == true)
                                {
                                    for (Carte *card : J2.getBoard())
                                    {
                                        if (card->getType() == liste_Defense[stoi(safeword) - 1]->getType() && card->getLieu() != "GraveYard")
                                        {
                                            card->setEndurance(card->getEndurance()+1);
                                            card->setForce(card->getForce()+1);
                                        }
                                    }
                                }
                            }
                            if (carte->getEndurance() <= 0)
                            {
                                carte->setLieu("GraveYard");
                                if (ADeathRattle == true)
                                {
                                    for (Carte *card : J1.getBoard())
                                    {
                                        if (card->getType() == liste_Defense[stoi(safeword) - 1]->getType() && card->getLieu() != "GraveYard")
                                        {
                                            card->setEndurance(card->getEndurance()+1);
                                            card->setForce(card->getForce()+1);
                                        }
                                    }
                                }
                            }
                        }
                        liste_Defense.erase(liste_Defense.begin() + stoi(safeword) - 1);

                        if (liste_Defense.empty())
                        {
                            cout << "----------------------------------------------------------------------------------" << endl;
                            cout << "Tu n'as plus de cartes pour defendre" << endl;
                            cout << "----------------------------------------------------------------------------------" << endl;
                            stop = true;
                            safeword = "";
                        }

                        if (carte->getEndurance() <= 0)
                        {
                            cout << "----------------------------------------------------------------------------------" << endl;
                            cout << "La carte qui attaque est morte tu n'as plus besoin de defendre" << endl;
                            cout << "----------------------------------------------------------------------------------" << endl;
                            stop = true;
                            safeword = "";
                        }

                        else
                        {
                            cout << "----------------------------------------------------------------------------------" << endl;
                            cout << "Tres bien, avec quelle carte compte tu defendre ? Rentre " << cJ << "OK " << couleurDefaut << "quand tu as fini" << endl;
                            cout << "----------------------------------------------------------------------------------" << endl;
                            safeword = "";

                            for (Carte *carte_def : liste_Defense)
                            {
                                carte_def->printCouleur();
                            }

                            cin >> safeword;

                            if (safeword == "OK")
                            {
                                stop = true;
                            }
                        }
                    }
                }
                safeword = "";
            }
        }
    }
    cout << "------------------------------------------" << endl;
    cout << cJ << "Fin de la phase d'attaque (*^▽^*)" << couleurDefaut << endl;
    cout << "------------------------------------------" << endl;
}

void Partie::PhaseDeCombatTest(Joueur& J1, Joueur& J2)
{

    Color cJ = Color::CouleurChoisie("Red");
    Color couleurDefaut(FG_DEFAULT);

    // -- -- -- -- -- Partie choix de l'attaquant -- -- -- -- --

    vector<Carte *> liste_Attaque = {}; // Liste qui donne toutes les cartes avec lesquelles l'attaque est possible

    // Ajouter && J1.getHand()[i]->getPeutAttaquer() == true au IF
    for (unsigned int i = 0; i < J1.getHand().size(); i++)
    {
        if (J1.getHand()[i]->getID() == 2 && J1.getHand()[i]->getEtat() == false)
        {
            liste_Attaque.push_back(J1.getHand()[i]);
        }
    }

    if (liste_Attaque.empty())
    {
        cout << "----------------------------------------------------------------" << endl;
        cout << "Joueur " << cJ << J1.getNom() << couleurDefaut << " ne peut pas attaquer ce tour ci" << endl;
        cout << "----------------------------------------------------------------" << endl;
    }

    else
    {
        cout << "----------------------------------------------------------------" << endl;
        cout << "Joueur " << cJ << J1.getNom() << couleurDefaut << endl;
        cout << "----------------------------------------------------------------" << endl;

        for (Carte *carte : liste_Attaque)
        { // J'affiche les cartes avec lesquelles l'attaque est possible
            carte->printCouleur();
        }

        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Parmis ces creatures, avec lesquelles decides-tu d'attaquer. Quand tu as fini, rentre " << cJ << "OK" << couleurDefaut << ", ET EN MAJUSCULE !! :" << endl;
        cout << "-----------------------------------------------------------------------------------------------------------------" << endl;

        string safeword = "";                 // Mot cle defini a OK qui permet a l'utilisateur de terminer son action
        vector<int> choix_attaquant = {};     // Un vecteur d'entier correspondant aux positions des cartes de son board avec lesquelles il souhaite attaquer
        vector<Carte *> Attacking_Cards = {}; // Vecteur de carte qui contient les cartes qui vont attaquer

        while (safeword != "OK")
        { // Tant que l'utilisateur n'a pas ecrit ok, il rentre les cartes avec lesquelles il compte attaquer
            cin >> safeword;
            if (safeword != "OK")
            {
                choix_attaquant.push_back(stoi(safeword));
                safeword = "";
            }
        }
        for (int i : choix_attaquant)
        { // Ajout des cartes dans le vecteur de carte qui contient les cartes qui vont attaquer
            Attacking_Cards.push_back(liste_Attaque[i - 1]);
        }

        cout << "----------------------------------------------------------------" << endl;
        cout << " Tu as donc selectionne les cartes suivantes " << endl;
        cout << "----------------------------------------------------------------" << endl;

        for (Carte *carte : Attacking_Cards)
        { // Affichage des cartes selectionne par le joueur
            carte->printCouleur();
        }

        // -- -- -- -- -- Partie choix du defenseur -- -- -- -- --

        cout << "----------------------------------------------------------------" << endl;
        cout << "Maintenant ! Joueur " << cJ << J2.getNom() << couleurDefaut << endl;
        cout << "----------------------------------------------------------------" << endl;

        vector<Carte *> liste_Defense = {}; // Liste qui donne toutes les cartes avec lesquelles la defense est possible

        safeword = "";
        for (unsigned int i = 0; i < J2.getHand().size(); i++)
        {
            if (J2.getHand()[i]->getID() == 2 && J2.getHand()[i]->getEtat() == false)
            {
                liste_Defense.push_back(J2.getHand()[i]);
            }
        }

        for (Carte *carte : Attacking_Cards)
        {
            bool AtFly = false;
            bool AtLifeLink = false;
            bool AtDeathTouch = false;
            bool ADeathRattle = false;

            // Check des capacites de l'attaquant
            for (string capa : carte->getCapacite())
            {
                if (capa == "LifeLink")
                {
                    AtLifeLink = true;
                }
                if (capa == "DeathTouch")
                {
                    AtDeathTouch = true;
                }
                if (capa == "Flying")
                {
                    AtFly = true;
                }
                if (capa == "DeathRattle")
                {
                    ADeathRattle = true;
                }
            }
            cout << "----------------------------------------------------------------" << endl;
            cout << " Quelle carte va te defendre face a cette carte ! " << endl;
            cout << "----------------------------------------------------------------" << endl;
            carte->printCouleur();
            cout << "------------------------------------------------------------------------------------------------" << endl;
            cout << "Veux tu defendre sur cette carte ? Ci dessous les cartes avec lesquelles tu peux defendre ! " << endl;
            cout << "Entrer " << cJ << "OUI " << couleurDefaut << "si tu veux defendre, " << cJ << "NON" << couleurDefaut << " sinon !" << endl;
            cout << "------------------------------------------------------------------------------------------------" << endl;

            for (Carte *carte_def : liste_Defense)
            {
                carte_def->printCouleur();
            }

            cin >> safeword;

            if (safeword == "NON")
            {
                cout << "-----------------------------------------------------" << endl;
                cout << "Ok, celle-ci va te percuter de plein fouet ! " << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "avant attaque : " << J2.getHP() << endl;
                J2.setHP((J2.getHP()) - (carte->getForce()));
                cout << "HP de " << cJ << J2.getNom() << couleurDefaut << "apres attaque : " << cJ << J2.getHP() << endl;

                // Check de la capacité lifelink
                if (AtLifeLink == true)
                {
                    J1.setHP((J1.getHP()) + (carte->getForce()));
                }
                safeword = "";
            }

            if (safeword == "OUI")
            {
                bool stop = false;

                cout << "----------------------------------------------------------------------------------" << endl;
                cout << " Tres bien, avec quelle carte compte tu defendre ? Rentre " << cJ << "OK " << couleurDefaut << "quand tu as fini" << endl;
                cout << "----------------------------------------------------------------------------------" << endl;
                safeword = "";

                for (Carte *carte_def : liste_Defense)
                {
                    carte_def->printCouleur();
                }

                cin >> safeword;

                if (safeword == "OK")
                {
                    stop = true;
                }

                while (stop == false)
                {
                    cout << "-----------------------------------------------------" << endl;
                    cout << " Tu as choisi cette carte ! " << endl;
                    cout << "-----------------------------------------------------" << endl;
                    liste_Defense[stoi(safeword) - 1]->printCouleur();

                    bool DefFly = false;
                    bool DefReach = false;
                    bool DefLifeLink = false;
                    bool DefDeathTouch = false;
                    bool DefDeathRattle = false;

                    // Check des capacites du defenseur
                    for (string capa : liste_Defense[stoi(safeword) - 1]->getCapacite())
                    {
                        if (capa == "LifeLink")
                        {
                            DefLifeLink = true;
                        }
                        if (capa == "Reach")
                        {
                            DefReach = true;
                        }
                        if (capa == "DeathTouch")
                        {
                            DefDeathTouch = true;
                        }
                        if (capa == "Flying")
                        {
                            DefFly = true;
                        }
                        if (capa == "DeathRattle")
                        {
                            DefDeathRattle = true;
                        }
                    }

                    // Check de la capacite Flying pour l'attaquant et si le defenseur n'a ni flying ni reach
                    if (AtFly == true && DefReach == false && DefFly == false)
                    {
                        cout << "------------------------------------------------------------------------------" << endl;
                        cout << "La carte que tu as choisi ne peut pas defendre sur la carte qui t'attaque ! " << endl;
                        cout << "------------------------------------------------------------------------------" << endl;
                    }

                    else
                    {

                        // Actualisation des points de vie
                        liste_Defense[stoi(safeword) - 1]->minusEndurance(carte->getForce());
                        carte->minusEndurance(liste_Defense[stoi(safeword) - 1]->getForce());

                        // Check de la capacite DeathTouch pour l'attaquant
                        if (AtDeathTouch == true)
                        {
                            cout << "L'attaquant a death touch" << endl;
                            liste_Defense[stoi(safeword) - 1]->setEndurance(0);
                        }

                        // Check de la capacite DeathTouch pour le défenseur
                        if (DefDeathTouch == true)
                        {
                            cout << "Le defenseur a death touch" << endl;
                            carte->setEndurance(0);
                        }

                        // Check de la capacite lifelink pour l'attaquant
                        if (AtLifeLink == true)
                        {
                            J1.setHP((J1.getHP()) + (carte->getForce()));
                        }

                        // Check de la capacite lifelink pour le défenseur
                        if (DefLifeLink == true)
                        {
                            J2.setHP((J2.getHP()) + (liste_Defense[stoi(safeword) - 1]->getForce()));
                        }

                        if (liste_Defense[stoi(safeword) - 1]->getEndurance() <= 0)
                        {
                            liste_Defense[stoi(safeword) - 1]->setLieu("GraveYard");
                            if (DefDeathRattle == true)
                            {

                                for (Carte *card : J2.getHand())
                                {
                                    if (card->getType() == liste_Defense[stoi(safeword) - 1]->getType() && card->getLieu() != "GraveYard")
                                    {
                                        card->setEndurance(card->getEndurance()+1);
                                        card->setForce(card->getForce()+1);
                                    }
                                }

                            }
                        }

                        if (carte->getEndurance() <= 0)
                        {
                            carte->setLieu("GraveYard");
                            if (ADeathRattle == true)
                            {
                                for (Carte *card : J1.getHand())
                                {
                                    if (card->getType() == carte->getType() && card->getLieu() != "GraveYard")
                                    {
                                        card->setEndurance(card->getEndurance()+1);
                                        card->setForce(card->getForce()+1);
                                    }
                                }
                            }
                        }
                    }
                    liste_Defense.erase(liste_Defense.begin() + stoi(safeword) - 1);

                    if (liste_Defense.empty())
                    {
                        cout << "----------------------------------------------------------------------------------" << endl;
                        cout << "Tu n'as plus de cartes pour defendre" << endl;
                        cout << "----------------------------------------------------------------------------------" << endl;
                        stop = true;
                        safeword = "";
                    }

                    if (carte->getEndurance() <= 0)
                    {
                        cout << "----------------------------------------------------------------------------------" << endl;
                        cout << "La carte qui attaque est morte tu n'as plus besoin de defendre" << endl;
                        cout << "----------------------------------------------------------------------------------" << endl;
                        stop = true;
                        safeword = "";
                    }

                    else
                    {
                        cout << "----------------------------------------------------------------------------------" << endl;
                        cout << "Tres bien, avec quelle carte compte tu defendre ? Rentre " << cJ << "OK " << couleurDefaut << "quand tu as fini" << endl;
                        cout << "----------------------------------------------------------------------------------" << endl;
                        safeword = "";

                        for (Carte *carte_def : liste_Defense)
                        {
                            carte_def->printCouleur();
                        }

                        cin >> safeword;

                        if (safeword == "OK")
                        {
                            stop = true;
                        }
                    }
                }
            }
            safeword = "";
        }
    }
    cout << "------------------------------------------" << endl;
    cout << cJ << "Fin de la phase d'attaque (*^▽^*)" << couleurDefaut << endl;
    cout << "------------------------------------------" << endl;
}
