#ifndef JOUEUR_H_INCLUDED
#define JOUEUR_H_INCLUDED

#include "Personnage.h"
#include <iostream>
#include <string>

using namespace std;

class Joueur {
    public:
        Joueur();
        ~Joueur();
        Joueur(Personnage perso_joueur);
        void jouer();                       //il y en aura surement besoin
        void choisir_personnage();          //il y en aura surement besoin
        void affiche();                     //pour debug
        Personnage getPersonnage();
    private:
        Personnage m_perso_joueur;
};


#endif // JOUEUR_H_INCLUDED
