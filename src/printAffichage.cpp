#include "../Headers/Color.hpp"
#include "../Headers/printAffichage.hpp"
#include <iostream>

using namespace std;

void printAffichage::printLogo()
{

    cout << "Lancement du jeu ... " << endl;
    cout << endl;

    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");
    Color c1 = Color::CouleurChoisie("Red");
    Color c2 = Color::CouleurChoisie("Green");
    Color c3 = Color::CouleurChoisie("Blue");
    cout << " \t" << couleurDefaut << "  [][][][]   []    [] " << c1 << "  []      [] [][][][] [][][][] [][][][] " << couleurDefaut << " [][][]      " << c2 << " [][][][] [][][]   [][][][]  [] [][][][] []     []     " << endl;
    cout << " \t" << couleurDefaut << "  []    []   []    [] " << c1 << "  []      [] []    [] []       []       " << couleurDefaut << " []  []      " << c2 << " []    [] []    [] []    []  [] []       [][]   []     " << endl;
    cout << " \t" << couleurDefaut << "  [][][][]   [][][][] " << c1 << "  []  []  [] [][][][] [][][][] [][][][] " << couleurDefaut << " [][][][] [] " << c2 << " [][][][] []    [] [][][][]  [] [][]     []  [] []        " << endl;
    cout << " \t" << couleurDefaut << "  []    []         [] " << c1 << "  []  []  [] []    []       []       [] " << couleurDefaut << " []    [][]  " << c2 << " []    [] []    [] []  []    [] []       []   [][]   " << endl;
    cout << " \t" << couleurDefaut << "  [][][][]   [][][][] " << c1 << "  [][][][][] []    [] [][][][] [][][][] " << couleurDefaut << " [][][][] [] " << c2 << " []    [] [][][]   []    []  [] [][][][] []     []      " << endl;
    cout << " \t" << couleurDefaut << endl;

    cout << c3 << "                       .:::a:::::..                 " << c1 << "                     ..:::::::::..                " << c2 << "                 ..:::;;;:::.. " << endl;
    cout << c3 << "                 ..:::::::d8::::::::::..            " << c1 << "                ..:::::?Y8888888b::::..           " << c2 << "             ..:::::d88888b::;;:::.. " << endl;
    cout << c3 << "              .::::::::::d88b:::::::::::::.         " << c1 << "             .:::::d8888P:::Y8888888b::::.        " << c2 << "          .:::d88bad8888888::88888b:::.  " << endl;
    cout << c3 << "            .:::::::::::d8888:::::::::::::::.       " << c1 << "          .:::::d88888b:::::Y88P::Y888b:::.       " << c2 << "        .::d88888888888:?88:888888888b::." << endl;
    cout << c3 << "          .::::::::::::d88888b::::::::::::::::.     " << c1 << "       .::::::d8P:::::::::::88::::88888b:::.      " << c2 << "      .::d8888888888888a:88888888888888b::.  " << endl;
    cout << c3 << "         :::::::::::::d8888888::::::::::::::::::    " << c1 << "      :::::::P:d:::::::::::d??ba:d8888888b:::     " << c2 << "     :::d8888888888888888888888888888888b:::    " << endl;
    cout << c3 << "         ::::::::::::d888888888b::::::::::::::::::  " << c1 << "     :::::::::?::::::::::::::::::::::Y8888b:Y:    " << c2 << "    ::::8888?88888888888888888888888888888b::  " << endl;
    cout << c3 << "       ::::::::::::d88888888888b::::::::::::::::::  " << c1 << "    ::::::::::::::::::::::::::::::::::Y8888b:Y:   " << c2 << "   :::ad8??:a888?8888:888888:888888888888888b:  " << endl;
    cout << c3 << "      .:::::::::::d88888888888888b::::::::::::::::. " << c1 << "   .::::::::::::::::::::::::::::::::b::88888:8:.  " << c2 << "  .:d8888a888888a:?88:88888?:8888888888888888:. " << endl;
    cout << c3 << "      :::::::::::d888888888888888888a:::::::::::::: " << c1 << "   :::::::::::::::::;;:::::::;;a:::::b::888888::  " << c2 << "  ::)8888888888888a88888888:a8888888888888888b: " << endl;
    cout << c3 << "      ::::::::::d888888888888888b:Y88b::::::::::::: " << c1 << "   :::::::::::::::d8888baaaaa88::::::)P:888888::  " << c2 << "  ::888888888888:???888888888??:::888888888888: " << endl;
    cout << c3 << "      :::::::::d88888888888888888b:888b:::::::::::: " << c1 << "   :::::::::::::d8888888888888P::::::d:d88888P::  " << c2 << "  ::Y888888888888sss:8888888aaa8888888888888P:: " << endl;
    cout << c3 << "      `::::::::8888888888888888888:Y888b::::::::::' " << c1 << "   `:::::::::::d88888888888P::::::::d8888888P::'  " << c2 << "  `::???::::::::::::888888888:::::::::::::::::' " << endl;
    cout << c3 << "       ::::::::8888888888888888888::Y888::::::::::  " << c1 << "    ::::::::::d88888888888P::::::d8888888P::;::   " << c2 << "   :::::::::::::::::888888888::::::::::::::::: " << endl;
    cout << c3 << "        :::::::Y888888888888888888?:d88P:::::::::   " << c1 << "    ::::::::d888888888888::::d88888888P?:dP::     " << c2 << "    ::::::::::::::::888888888::::::::::::::::   " << endl;
    cout << c3 << "         :::::::Y88888888888888888bd88P:::::::::    " << c1 << "     :::::::888888888888888888888888888bdP::      " << c2 << "     :::::::::::::::888888888:::::::::::::::  " << endl;
    cout << c3 << "          `:::::::Y88888888888888888P:::::::::'     " << c1 << "      `:::::888888888888888888888888888P::'       " << c2 << "      `:::::::::::::888888888:::::::::::::'   " << endl;
    cout << c3 << "           `::::::Y88888888888888P:::::::::'        " << c1 << "        `::::Y888888888888888888888P::::'         " << c2 << "         `:::::::::::888888888::::aa:::::'  " << endl;
    cout << c3 << "               `::::::Y8888888888P:::::::::'        " << c1 << "          `::::Y8888888888888888P:::::'           " << c2 << "           `::::ad8888888888888888P::::'   " << endl;
    cout << c3 << "                 ``::::::Y888P::::::::''            " << c1 << "             ``:::::Y8888888baaa;:''              " << c2 << "              ``::??Y888888888P??::'' " << endl;

    cout << " \t" << c << "                             ____________________________________________________________________________________________                                                  " << endl;
    cout << " \t" << c << "                            |                                                                                           |                                                  " << endl;
    cout << " \t" << c << "                            |      [][][][]   []   [][][][] []     [] []      [] [][][][] []    [] []    [] [][][][]    |                                                  " << endl;
    cout << " \t" << c << "                     _______|      []    []   []   []       [][]   []  []    []  []       [][]  [] []    [] []          | _______                                          " << endl;
    cout << " \t" << c << "                    |       |      [][][][]   []   [][]     []  [] []   []  []   [][]     [] [] [] []    [] [][]        |        |                                         " << endl;
    cout << " \t" << c << "                    |       |      []    []   []   []       []   [][]    [][]    []       []  [][] []    [] []          |        |                                         " << endl;
    cout << " \t" << c << "                    |       |      [][][][]   []   [][][][] []     []     []     [][][][] []    [] [][][][] [][][][]    |        |                                         " << endl;
    cout << " \t" << c << "                    |       |___________________________________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "                    |__________)                                                                                      (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printPioche()
{

    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");

    cout << couleurDefaut << endl;
    cout << " \t" << c << "                                                 _____________________________________________________________                                                   " << endl;
    cout << " \t" << c << "                                                 |                                                            |                                                  " << endl;
    cout << " \t" << c << "                                                 |      [][][][]  []  [][][][] [][][][] []    []  [][][][]    |                                                  " << endl;
    cout << " \t" << c << "                                          _______|      []    []  []  []    [] []       []    []  []          | _______                                          " << endl;
    cout << " \t" << c << "                                         |       |      [][][][]  []  []    [] []       [][][][]  [][]        |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |      []        []  []    [] []       []    []  []          |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |      []        []  [][][][] [][][][] []    []  [][][][]    |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |____________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "                                         |__________)                                                       (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printDesengagement()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");

    cout << couleurDefaut << endl;
    cout << " \t" << c << "                 __________________________________________________________________________________________________________________________________                                                 " << endl;
    cout << " \t" << c << "                |                                                                                                                                 |                                                  " << endl;
    cout << " \t" << c << "                |      [][][]   [][][][] [][][][] [][][][] []    []  [][][]   [][[]][]  [][][]   [][][][] []      [] [][][][] []    [] [][][][]   |                                                  " << endl;
    cout << " \t" << c << "         _______|      []    [] []       []       []       [][]  [] []        []    [] []        []       [][]  [][] []       [][]  []    []      | _______                                          " << endl;
    cout << " \t" << c << "        |       |      []    [] [][]     [][][][] [][][    [] [] [] []   [][] [][][][] []   [][] [][]     []  []  [] [][]     [] [] []    []      |        |                                         " << endl;
    cout << " \t" << c << "        |       |      []    [] []             [] []       []  [][] []     [] []    [] []     [] []       []      [] []       []  [][]    []      |        |                                         " << endl;
    cout << " \t" << c << "        |       |      [][][]   [][][][] [][][][] [][][][] []    []  [][][]   []    []  [][][]   [][][][] []      [] [][][][] []    []    []      |        |                                         " << endl;
    cout << " \t" << c << "        |       |_________________________________________________________________________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "        |__________)                                                                                                                            (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printPrincipale()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");

    cout << couleurDefaut << endl;
    cout << " \t" << c << "                      __________________________________________________________________________________________                                                 " << endl;
    cout << " \t" << c << "                     |                                                                                          |                                                  " << endl;
    cout << " \t" << c << "                     |      [][][][]  [][][][] [] []    [] [][][][] []  [][][][] [][][][] []       [][][][]     |                                                  " << endl;
    cout << " \t" << c << "              _______|      []    []  []    [] [] [][]  [] []       []  []    [] []    [] []       []           |________                                          " << endl;
    cout << " \t" << c << "             |       |      [][][][]  [][][][] [] [] [] [] []       []  [][][][] [][][][] []       [][]         |        |                                         " << endl;
    cout << " \t" << c << "             |       |      []        []  []   [] []  [][] []       []  []       []    [] []       []           |        |                                         " << endl;
    cout << " \t" << c << "             |       |      []        []   []  [] []    [] [][][][] []  []       []    [] [][][][] [][][][]     |        |                                         " << endl;
    cout << " \t" << c << "             |       |__________________________________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "             |__________)                                                                                     (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printSecondaire()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");

    cout << couleurDefaut << endl;
    cout << " \t" << c << "                      ______________________________________________________________________________________________                                                 " << endl;
    cout << " \t" << c << "                     |                                                                                              |                                                  " << endl;
    cout << " \t" << c << "                     |      [][][][]  [][][][] [][][][] [][][][] []    [] [][][]   [][][][] [] [][][][] [][][][]    |                                                  " << endl;
    cout << " \t" << c << "              _______|      []        []       []       []    [] [][]  [] []    [] []    [] [] []    [] []          |________                                          " << endl;
    cout << " \t" << c << "             |       |      [][][][]  [][]     []       []    [] [] [] [] []    [] [][][][] [] [][][][] [][]        |        |                                         " << endl;
    cout << " \t" << c << "             |       |            []  []       []       []    [] []  [][] []    [] []    [] [] [] []    []          |        |                                         " << endl;
    cout << " \t" << c << "             |       |      [][][][]  [][][][] [][][][] [][][][] []    [] [][][]   []    [] [] []   []  [][][][]    |        |                                         " << endl;
    cout << " \t" << c << "             |       |______________________________________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "             |__________)                                                                                         (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printFinDeTour()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");
    cout << couleurDefaut << endl;
    cout << " \t" << c << "                      _____________________________________________________________________________________________                                                " << endl;
    cout << " \t" << c << "                     |                                                                                             |                                                  " << endl;
    cout << " \t" << c << "                     |      [][][][] []  []    []    [][][]   [][][][]   [][][][] [][][][] []    [] [][][][]       |                                                  " << endl;
    cout << " \t" << c << "              _______|      []       []  [][]  []    []    [] []            []    []    [] []    [] []    []       |________                                          " << endl;
    cout << " \t" << c << "             |       |      [][]     []  [] [] []    []    [] [][]          []    []    [] []    [] [][][][]       |        |                                         " << endl;
    cout << " \t" << c << "             |       |      []       []  []  [][]    []    [] []            []    []    [] []    [] []  []         |        |                                         " << endl;
    cout << " \t" << c << "             |       |      []       []  []    []    [][][]   [][][][]      []    [][][][] [][][][] []    []       |        |                                         " << endl;
    cout << " \t" << c << "             |       |_____________________________________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "             |__________)                                                                                        (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printCombat()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Cyan");

    cout << couleurDefaut << endl;
    cout << " \t" << c << "                                                 ___________________________________________________________________                                                   " << endl;
    cout << " \t" << c << "                                                 |                                                                  |                                                  " << endl;
    cout << " \t" << c << "                                                 |      [][][][] [][][][]  []      [] [][][][] [][][][] [][][][]    |                                                  " << endl;
    cout << " \t" << c << "                                          _______|      []       []    []  [][]  [][] []    [] []    []    []       |________                                          " << endl;
    cout << " \t" << c << "                                         |       |      []       []    []  []  []  [] [][][][] [][][][]    []       |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |      []       []    []  []      [] []    [] []    []    []       |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |      [][][][] [][][][]  []      [] [][][][] []    []    []       |        |                                         " << endl;
    cout << " \t" << c << "                                         |       |__________________________________________________________________|        |                                         " << endl;
    cout << " \t" << c << "                                         |__________)                                                             (__________|                                         " << endl;
    cout << couleurDefaut << endl;
}

void printAffichage::printVictoire()
{
    Color couleurDefaut(FG_DEFAULT);
    Color c = Color::CouleurChoisie("Black");
    cout << c << endl;
    cout << couleurDefaut << endl;
    cout << c << "    .-=========-.";
    cout << c << "    \'-=======-'/";
    cout << c << "    _|   .=.   |_   ";
    cout << c << "   ((|  {{1}}  |))   ";
    cout << c << "     |   '|'   |   ";
    cout << c << "     |__ '`' __| ";
    cout << c << "       _`) (`_   ";
    cout << c << "     _|_______|_  ";
    cout << c << "    |___________|  ";
    cout << c << "    .-=========-.";
    cout << c << "    \'-=======-'/";
    cout << c << "    _|   .=.   |_   ";
    cout << c << "   ((|  {{1}}  |))   ";
    cout << c << "     |   '|'   |   ";
    cout << c << "     |__ '`' __| ";
    cout << c << "       _`) (`_   ";
    cout << c << "     _|_______|_  ";
    cout << c << "    |___________|  ";
    cout << c << "    .-=========-.";
    cout << c << "    \'-=======-'/";
    cout << c << "    _|   .=.   |_   ";
    cout << c << "   ((|  {{1}}  |))   ";
    cout << c << "     |   '|'   |   ";
    cout << c << "     |__ '`' __| ";
    cout << c << "       _`) (`_   ";
    cout << c << "     _|_______|_  ";
    cout << c << "    |___________|  " << endl;
    cout << couleurDefaut << endl;
}
