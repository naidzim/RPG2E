#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Personnage.h"
#include <iostream>
#include <string>


class Joueur {

public:
    Joueur();
    Joueur(Personnage perso_joueur);

    int jouer();                       // permet de choisir une action
    Personnage getPersonnage();

//private:
    Personnage m_perso;
};


#endif // JOUEUR_H_INCLUDED
