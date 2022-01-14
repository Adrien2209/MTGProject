#ifndef CARTE_H
#define CARTE_H

#include <string>
using namespace std;

class Carte {
    private : 
    string nom, couleur, lieu;
    bool etat;
    int numero;
    

    public :
    Carte(int numero);
    Carte(string  nom, string couleur, string lieu, bool etat, int numero); // Constructeur
    ~Carte() {}; // Destructeur

    void virtual print();
    int virtual getID();
    
    // Les gets

    string getCouleur();
    string getNom();
    string getLieu();
    int getNumero();
    
    // Les sets
    void setLieu(string l);
    void setEngage();
    void setDesengage();
    // Les methodes
    
    bool getEtat();

    void Death();

};

#endif