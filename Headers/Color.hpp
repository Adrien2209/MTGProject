#ifndef MAGIC_COLOR_HPP
#define MAGIC_COLOR_HPP

#include <iostream>
#include "CouleurType.hpp"

class Color
{

public:
    Color(CouleurType t);
    ~Color();

    CouleurType getColorTexT() const; // Utile pour la surcharge de l'operateur <<
    static Color CouleurChoisie(std::string type); // Fonction qui permet grace a un string donner en entrer de retourner la couleur en question.
private:
    CouleurType colorTexT;
};

std::ostream &operator<<(std::ostream &flux, Color const &c); // surcharge operateur 

#endif 