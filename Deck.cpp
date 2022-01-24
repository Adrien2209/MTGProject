#include "Deck.hpp"
#include <fstream>
#include <iostream>

Deck::Deck(string nom) { 
    this -> nom = nom;
    this -> deck = Deck::getDeckFromFile(nom);
}
Deck::Deck(string nom, vector<Carte*> deck) { 
    this -> nom = nom;
    this -> deck = deck;
}

string Deck::getNom() {
    return nom;
}

vector<Carte*> Deck::getDeck() {
    return deck;
}

// Ajouter ça dans le main pour test Deck d1 = Deck("DeckTest2");
// d1.CreateDeck("CreateTest");

void Deck::CreateDeck(string name){
    //Importation de la CardsList
    vector<Carte *> CardList = getDeckFromFile("Cards");
    string choixcouleur= "";
    string choixtype = "";
    string choixCarte = "";
    bool Menu = false;
    bool FirstTime = true;
    bool FirstTimeMenu = true;
    std::ifstream ifs("CardsList.json");
    json TriCardList;
    ifs >> TriCardList;
    json Deck;
    int i = 0;
    Deck[name]["Terrain"] = json::array({});
    Deck[name]["Creature"] = json::array({});
    Deck[name]["Enchantement"] = json::array({});
    while(i<30){
        Menu = false;
        FirstTime = true;
        if(FirstTimeMenu == true){
            cout << "Vous voulez une carte de quelle couleur ?" << endl;
            cout << "White ; Blue ; Black ; Red ; Green ; Multicolor" << endl;
            cin >> choixcouleur;
        }

        //Carte blanches
        while(choixcouleur == "White" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }
            
            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "White" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["White"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;
                    cout << endl << i << " cartes sur 30" << endl;   
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "White" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["White"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;
                    cout << endl << i << " cartes sur 30" << endl;     
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "White" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["White"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;  
                    cout << endl << i << " cartes sur 30" << endl;   
                }   
            }
            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }
        

        //Cartes bleues
        while(choixcouleur == "Blue" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }

            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Blue" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["Blue"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Blue" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["Blue"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Blue" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["Blue"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;  
                    cout << endl << i << " cartes sur 30" << endl;   
                }   
            }

            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }

        //Cartes noires
        while(choixcouleur == "Black" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }

            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Black" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["Black"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;  
                    cout << endl << i << " cartes sur 30" << endl;   
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Black" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["Black"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Black" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["Black"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }   
            }

            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }

        //Cartes Rouge
        while(choixcouleur == "Red" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }

            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Red" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["Red"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Red" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["Red"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Red" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["Red"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }   
            }

            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }

        //Cartes Vertes
        while(choixcouleur == "Green" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }

            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Green" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["Green"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Green" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["Green"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Green" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["Green"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }   
            }

            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }

        //Cartes Multicolor
        while(choixcouleur == "Multicolor" && Menu == false && i < 30){
            if(FirstTime == true){
                cout << "Tres bien, quel type de carte ?" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
            }

            while(choixtype == "Terrain" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Multicolor" && carte->getID() == 1){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Terrain"].push_back(TriCardList["Cards"]["Multicolor"]["Terrain"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;  
                    cout << endl << i << " cartes sur 30" << endl;   
                }           
            }

            while(choixtype == "Creature" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Multicolor" && carte->getID() == 2){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Creature"].push_back(TriCardList["Cards"]["Multicolor"]["Creature"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }    
            }

            while(choixtype == "Enchantement" && Menu == false && i < 30){
                for(Carte* carte : CardList){
                    if(carte->getCouleur() == "Multicolor" && carte->getID() == 3){
                        carte->printCouleur();
                    }
                }
                cout << "Quelle carte voulez vous ? Tapez son numero. Tapez Back pour revenir en arriere" << endl;
                cin >> choixCarte;
                if(choixCarte == "Back"){
                    choixtype = "Back";
                }
                else {
                    Deck[name]["Enchantement"].push_back(TriCardList["Cards"]["Multicolor"]["Enchantement"][stoi(choixCarte) - 1]);
                    choixCarte = "";
                    i += 1;   
                    cout << endl << i << " cartes sur 30" << endl;  
                }   
            }

            while(choixtype == "Back" && Menu == false && i < 30){
                FirstTime = false;
                cout << "Tres bien, quel type de carte ? Tapez Back pour revenir en arriere" << endl;
                cout << "Terrain ; Enchantement ; Creature" << endl;
                cin >> choixtype;
                if(choixtype == "Back"){
                    Menu = true;
                }
            }
        }

        while(choixcouleur == "Back"){
            FirstTimeMenu = false;
            cout << "Vous voulez une carte de quelle couleur ?" << endl;
            cout << "White ; Blue ; Black ; Red ; Green ; Multicolor" << endl;
            cin >> choixcouleur;
        }

        if(choixcouleur != "Red" && choixcouleur != "Blue" && choixcouleur != "Black" && choixcouleur != "White" && choixcouleur != "Green" && choixcouleur != "Multicolor" && choixcouleur != "Back"){
            cout << "Je n'ai pas bien compris, veuillez réessayer" << endl;
        }
    }
    int n = 0;
    for(const auto &creature : Deck[name]["Creature"].items()){
        creature.value()["ID"] = n;
        n +=1;
    }
    for(const auto &creature : Deck[name]["Enchantement"].items()){
        creature.value()["ID"] = n;
        n +=1;
    }
    for(const auto &creature : Deck[name]["Terrain"].items()){
        creature.value()["ID"] = n;
        n +=1;
    }
    std::ofstream file(name + ".json");
    file << Deck;
}

vector<Carte *> Deck::getDeckFromFile(string nomDeck)
{
    std::vector<Carte *> DeckRetour = {};
    std::ifstream ifs(nomDeck + ".json");
    json deck;
    ifs >> deck;
    int i = 1;

    // Ajout des creatures dans le deck
    const auto &creature = deck["DeckTest"]["Creature"];
    for (const auto &liste_creature : creature.items())
    {
        string title = liste_creature.value()["Title"];
        int commoncost = liste_creature.value()["CommonCost"];
        vector<string> color_cost_string = liste_creature.value()["ColorCost"];
        // Conversion du vector de string en map
        map<string, int> colorcost = {{"White", 0}, {"Blue", 0}, {"Black", 0}, {"Red", 0}, {"Green", 0}};
        int nbWhite = 0, nbBlue = 0, nbBlack = 0, nbRed = 0, nbGreen = 0;
        for (string t : color_cost_string)
        {
            if (t == "White")
            {
                nbWhite++;
                colorcost[t] = nbWhite;
            }
            else if (t == "Blue")
            {
                nbBlue++;
                colorcost[t] = nbBlue;
            }
            else if (t == "Black")
            {
                nbBlack++;
                colorcost[t] = nbBlack;
            }
            else if (t == "Red")
            {
                nbRed++;
                colorcost[t] = nbRed;
            }
            else if (t == "Green")
            {
                nbGreen++;
                colorcost[t] = nbGreen;
            }
        }
        string color = liste_creature.value()["Color"];
        string type = liste_creature.value()["Type"];
        int force = liste_creature.value()["Force"];
        int endurance = liste_creature.value()["Endurance"];
        vector<string> capacity = liste_creature.value()["Capacity"];
        string lieu = "Bibli";
        int id = i;
        bool etat = false;
        bool peutAttaquer = false;
        DeckRetour.push_back(new Creature(title, color, lieu, etat, id, capacity, colorcost, commoncost, force, endurance, peutAttaquer, type, color_cost_string));
        i += 1;
    }

    // Ajout des terrains dans le deck
    const auto &terrain = deck["DeckTest"]["Terrain"];
    for (const auto &liste_terrain : terrain.items())
    {
        string title = liste_terrain.value()["Title"];
        string color = liste_terrain.value()["Color"];
        string lieu = "Bibli";
        int id = i;
        bool etat = false;
        DeckRetour.push_back(new Terrain(title, color, lieu, etat, id));
        i += 1;
    }

    // Ajout des enchantements dans le deck
    const auto &enchantement = deck["DeckTest"]["Enchantement"];
    for (const auto &liste_enchantement : enchantement.items())
    {
        string title = liste_enchantement.value()["Title"];
        string color = liste_enchantement.value()["Color"];
        int commoncost = liste_enchantement.value()["CommonCost"];
        vector<string> color_cost_string = liste_enchantement.value()["ColorCost"];
        // Conversion du vector de string en map
        map<string, int> colorcost = {{"White", 0}, {"Blue", 0}, {"Black", 0}, {"Red", 0}, {"Green", 0}};
        int nbWhite = 0, nbBlue = 0, nbBlack = 0, nbRed = 0, nbGreen = 0;
        for (string t : color_cost_string)
        {
            if (t == "White")
            {
                nbWhite++;
                colorcost[t] = nbWhite;
            }
            else if (t == "Blue")
            {
                nbBlue++;
                colorcost[t] = nbBlue;
            }
            else if (t == "Black")
            {
                nbBlack++;
                colorcost[t] = nbBlack;
            }
            else if (t == "Red")
            {
                nbRed++;
                colorcost[t] = nbRed;
            }
            else if (t == "Green")
            {
                nbGreen++;
                colorcost[t] = nbGreen;
            }
        }
        int ForceBonus = liste_enchantement.value()["ForceBonus"];
        int EnduranceBonus = liste_enchantement.value()["EnduranceBonus"];
        string Target = liste_enchantement.value()["Target"];
        string lieu = "Bibli";
        bool etat = false;
        int id = i;
        DeckRetour.push_back(new Enchantement(title, color, lieu, etat, id, colorcost, commoncost, ForceBonus, EnduranceBonus, Target, color_cost_string));
        i += 1;
    }

    return DeckRetour;
}

void Deck::printDeck() {
    for ( auto e : this->deck) {
        e->print();
    }
}
