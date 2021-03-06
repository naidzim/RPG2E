#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED

#include "../include/Joueur.h"
#include <unistd.h>


void affiche_UI(Joueur joueur_1,Joueur joueur_2,int nbTour,Attaque attaque);
void UI_attaque(Joueur joueur);
std::string convertEnergieToUI(int nbPointDenergie);
std::string convertPdvToUI(int nbPointDeVie);
void animation_debut();
std::string convertNbTourUI(int nbTour);

#endif // UI_H_INCLUDED
