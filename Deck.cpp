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
        DeckRetour.push_back(new Creature(title, color, lieu, etat, id, capacity, colorcost, commoncost, force, endurance, peutAttaquer));
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
        DeckRetour.push_back(new Enchantement(title, color, lieu, etat, id, colorcost, commoncost, ForceBonus, EnduranceBonus, Target));
        i += 1;
    }

    return DeckRetour;
}

void Deck::printDeck() {
    for ( auto e : this->deck) {
        e->print();
    }
}
