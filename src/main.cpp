#include <iostream>
#include <string>
#include "../include/UI.h"
#include "../include/Gameplay.h"
#include "../include/Personnage.h"
#include "../include/Laffont.h"
#include "../include/James.h"
#include "../include/Joueur.h"
#include "windows.h"
#include <cstdlib>

using namespace std;

/*---------------------------------------------------------------------------------------------------*/
/*                                     SE JOUE PLEINE ECRAN                                          */
/*---------------------------------------------------------------------------------------------------*/



int main()
{
    int choix;
    choix = sessionInit();
    Joueur joueur,joueur2;

    if (choix == 1)
    {
        //Choix du joueur 1
        choixPersonnage(joueur);           //permet au joueur de choisir le personnage
        cout<<endl<<"Vous avez choisi "<<joueur.getPersonnage().getNom()<<" !"<<endl<<endl;
        joueur.getPersonnage().print_punch_line();

        //choix du joueur 2

        choixPersonnage(joueur2);           //permet au joueur de choisir le personnage
        cout<<endl<<"Vous avez choisi "<<joueur2.getPersonnage().getNom()<<" !"<<endl<<endl;
        joueur2.getPersonnage().print_punch_line();
    }
    ///#####################################################################################
    animation_debut();
    affiche_UI(joueur,joueur2,0);           //affiche l'UI du jeux
    cout<<endl<<endl<<"Action de jeux a afficher ...";
    cout<<endl<<endl;
    return 0;
}
