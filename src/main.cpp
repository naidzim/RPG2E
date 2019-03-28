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

//personnage disponnible ( en globale c'est plus simple )



int main()
{
    int choix;
    Attaque atak;

    choix = sessionInit();
    Joueur joueur1,joueur2;

    if (choix == 1)
    {
        printPersonnage();
        //Choix du joueur 1
        cout << "Joueur 1 ";
        choixPersonnage(joueur1);           //permet au joueur de choisir le personnage
        cout<<endl<<"Vous avez choisi "<<joueur1.getPersonnage().getNom()<<" !"<<endl<<endl;
        joueur1.getPersonnage().print_punch_line();

        //choix du joueur 2
        cout << "Joueur2 ";
        choixPersonnage(joueur2);           //permet au joueur de choisir le personnage
        cout<<endl<<"Vous avez choisi "<<joueur2.getPersonnage().getNom()<<" !"<<endl<<endl;
        joueur2.getPersonnage().print_punch_line();

        animation_debut();
        //debut de la partie
        affiche_UI(joueur1,joueur2,0);           //affiche l'UI du jeux
        cout<<endl<<endl<<"Action de jeux a afficher ...";
        choix = joueur1.jouer() - 1; //retourn le numero de l'attaque
        atak = joueur1.getPersonnage().getAttaque()[choix];
        atak.afficher();
        joueur1.getPersonnage().attaquer(joueur2.getPersonnage(),atak);
        affiche_UI(joueur1,joueur2,0);
        choix = joueur2.jouer() - 1; //retourn le numero de l'attaque


    }
    return 0;
}
