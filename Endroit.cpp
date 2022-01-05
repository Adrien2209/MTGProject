#include "Endroit.hpp"


Endroit::Endroit(bool est_engage, bool est_morte, bool est_main, bool est_bibliotheque, bool est_board) { 
    this -> est_engage  = true;
    this -> est_morte = false ;
    this -> est_main = false ;
    this -> est_bibliotheque = true;
    this -> est_board = false;
}

bool Endroit::getEst_Engage() {
    return est_engage;
}

pair<bool,bool> Endroit::getEst_Morte() {
    return {est_morte,est_engage};
}

pair<bool,bool> Endroit::getEst_Main() {
    return {est_main,est_engage};
}

pair<bool,bool> Endroit::getEst_Bibliotheque() {
    return {est_bibliotheque,est_engage};
}

pair<bool,bool> Endroit::getEst_Board() {
    return {est_board,est_engage};
}


void Endroit::setEst_Engage() {
    est_engage = true;
}

void Endroit::setEst_Morte() {
    est_engage = true;
    est_morte = true; 
    est_main = false;
    est_bibliotheque = false;
    est_board = false;
}

void Endroit::setEst_Main() {
    est_engage = true;
    est_morte = false; 
    est_main = true;
    est_bibliotheque = false;
    est_board = false;
}

void Endroit::setEst_Bibliotheque() {
    est_engage = true;
    est_morte = false; 
    est_main = false;
    est_bibliotheque = true;
    est_board = false;
}

void Endroit::setEst_Board() {
    est_engage = false;
    est_morte = false; 
    est_main = false;
    est_bibliotheque = true;
    est_board = true;
}




