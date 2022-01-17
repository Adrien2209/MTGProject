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

    // Ajout des creatures dans le deck
    const auto &creature = deck["DeckTest"]["Creature"];
    for (const auto &liste_creature : creature.items())
    {
        string title = liste_creature.value()["Title"];
        int commoncost = liste_creature.value()["CommonCost"];
<<<<<<< Updated upstream
        vector<string> colorcost = liste_creature.value()["ColorCost"];
        /*
=======
>>>>>>> Stashed changes
        vector<string> color_cost_string = liste_creature.value()["ColorCost"];
        // Conversion du vector de string en map
        map<string, int> colorcost = {{"White", 0}, {"Blue", 0}, {"Black", 0}, {"Red", 0}, {"Green", 0}};
        int nbWhite, nbBlue, nbBlack, nbRed, nbGreen = 0;
        for (string t : color_cost_string)
        {
            if (t == "White")
            {
                colorcost[t] = nbWhite++;
            }
            else if (t == "Blue")
            {
                colorcost[t] = nbBlue++;
            }
            else if (t == "Black")
            {
                colorcost[t] = nbBlack++;
            }
            else if (t == "Red")
            {
                colorcost[t] = nbRed++;
            }
            else if (t == "Green")
            {
                colorcost[t] = nbGreen++;
            }
        }
<<<<<<< Updated upstream
        */
=======
>>>>>>> Stashed changes
        string color = liste_creature.value()["Color"];
        string type = liste_creature.value()["Type"];
        int force = liste_creature.value()["Force"];
        int endurance = liste_creature.value()["Endurance"];
        vector<string> capacity = liste_creature.value()["Capacity"];
        int id = liste_creature.value()["ID"];
        string lieu = "Bibli";
        bool etat = false;
        DeckRetour.push_back(new Creature(title, color, lieu, etat, id, capacity, colorcost, commoncost, force, endurance));
    }

    // Ajout des terrains dans le deck
    const auto &terrain = deck["DeckTest"]["Terrain"];
    for (const auto &liste_terrain : terrain.items())
    {
        string title = liste_terrain.value()["Title"];
        string color = liste_terrain.value()["Color"];
        int id = liste_terrain.value()["ID"];
        string lieu = "Bibli";
        bool etat = false;
        DeckRetour.push_back(new Terrain(title, color, lieu, etat, id));
    }

    return DeckRetour;
}

void Deck::printDeck() {
    for ( auto e : this->deck) {
        e->print();
    }
}
