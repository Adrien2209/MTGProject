//
// Created by Wassim on 18/01/2022.
//

#include "../Headers/Color.hpp"

Color::Color(CouleurType t) : couleurTexte(t)
{
}

Color::~Color()
{
}

CouleurType Color::getCouleurTexte() const
{
    return couleurTexte;
}

Color Color::quelleCouleur(std::string type)
{
    if (type == "Red")
        return ((FG_RED));
    else if (type == "Blue")
        return ((FG_BLUE));
    else if (type == "White")
        return (FG_DEFAULT);
    else if (type == "Multicolor")
        return (FG_MAGENTA);
    else if (type == "Black")
        return (FG_YELLOW);
    else if (type == "Green")
        return (FG_GREEN);
    else if (type == "Cyan")
        return (FG_CYAN);
    else if (type == "Magenta")
        return (FG_MAGENTA);
    else
        return (FG_DEFAULT);
}

std::ostream &operator<<(std::ostream &flux, Color const &c)
{
    return flux << "\033[" << c.getCouleurTexte() << "m";
}