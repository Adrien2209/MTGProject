//
// Created by Wassim on 18/01/2022
//

#ifndef MAGIC_COLOR_HPP
#define MAGIC_COLOR_HPP

#include <iostream>
#include "CouleurType.hpp"


class Color {

public :
    Color(CouleurType t);
    ~Color();

    CouleurType getCouleurTexte() const;
    static Color quelleCouleur(std::string type);
private:
     CouleurType couleurTexte;
};

std::ostream& operator << (std::ostream& flux, Color const& c);

#endif //MAGIC_COLOR_H