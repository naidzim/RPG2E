#ifndef DEF_GAMEPLAY
#define DEF_GAMEPLAY

#include <string>
#include <stdio.h>
#include <locale>         // std::locale, std::tolower

#include "../include/James.h"
#include "../include/Laffont.h"
#include "../include/Joueur.h"

//personnage disponnible ( en globale c'est plus simple )


int sessionInit();
void printPersonnage(Joueur& joueur) ;
void choixPersonnage(Joueur& joueur);
std::string miniscule (std::string str);

#endif // DEF_GAMEPLAY
