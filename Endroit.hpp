#ifndef ENDROIT_H
#define ENDROIT_H

#include <string>
using namespace std;

class Endroit {
    private :
    bool est_engage, est_morte, est_main, est_bibliotheque, est_board; 

    public :
    Endroit(bool,bool,bool,bool, bool);
    ~Endroit() {};

    bool getEst_Engage();
    pair<bool,bool> getEst_Morte() ;
    pair<bool,bool> getEst_Main();
    pair<bool,bool> getEst_Bibliotheque() ;
    pair<bool,bool> getEst_Board() ;


    void setEst_Engage();
    void setEst_Morte() ;
    void setEst_Main();
    void setEst_Bibliotheque() ;
    void setEst_Board() ;

};

#endif