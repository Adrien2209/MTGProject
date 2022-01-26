#ifndef MAGIC_COULEURTYPE_HPP
#define MAGIC_COULEURTYPE_HPP

#include <string>

enum CouleurType {
    FG_RED      = 31 ,
    FG_GREEN    = 32,
    FG_BLUE     = 34,
    FG_DEFAULT  = 39,
    FG_CYAN     = 36, 
    FG_MAGENTA = 35, 
    FG_YELLOW  = 33  //33 represente en realite le jaune mais pour tester dans une console noire, on commence avec le jaune
};



#endif