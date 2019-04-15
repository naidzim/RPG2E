#ifndef DEF_GAMEPLAY
#define DEF_GAMEPLAY

#include <string>
#include <vector>
#include <stdio.h>
#include <locale>         // std::locale, std::tolower

#include "../include/James.h"
#include "../include/Laffont.h"
#include "../include/Joueur.h"


void ajoutPerso(vector<Personnage> &persoDispo);
int sessionInit();
void printPersonnage();
void choixPersonnage(Joueur& joueur);
int choixPersonnageAdv(Joueur& joueur,std::string choix);
std::string miniscule (std::string str);

#endif // DEF_GAMEPLAY
