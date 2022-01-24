#ifndef MAGIC_COLOR_HPP
#define MAGIC_COLOR_HPP

#include <iostream>
#include "CouleurType.hpp"

class Color
{

public:
    Color(CouleurType t);
    ~Color();

    CouleurType getColorTexT() const;
    static Color CouleurChoisie(std::string type);

private:
    CouleurType colorTexT;
};

std::ostream &operator<<(std::ostream &flux, Color const &c);

#endif 