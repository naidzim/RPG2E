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



int main()
{
    int choix;
    int nbTour=1;
    Attaque attaque;
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
        affiche_UI(joueur1,joueur2,0,Attaque());                        //affiche l'UI du jeux (tour 0)
        while(joueur1.getPersonnage().estVivant() && joueur2.getPersonnage().estVivant()){             //tant que j1 et j2 sont vivant (personne n'est mort)

            //debut de la partie

            if(joueur1.getPersonnage().estVivant() && joueur2.getPersonnage().estVivant()){
                //-----------------TOUR DE J1----------------------------------
                joueur1.getPersonnage().recevoirEenergie(25);
                choix = joueur1.jouer() - 1;                               // retourne le numero de l'attaque
                attaque = joueur1.getPersonnage().getAttaque()[choix];        // selectionne l'attaque a partir du choix
                joueur1.getPersonnage().attaquer(joueur2.getPersonnage(),attaque);
                joueur1.getPersonnage().perdreEenergie(attaque.getCoutEnergie());
                affiche_UI(joueur2,joueur1,nbTour,attaque);
            }


            if(joueur1.getPersonnage().estVivant() && joueur2.getPersonnage().estVivant()){
                //-----------------TOUR DE J2----------------------------------
                joueur2.getPersonnage().recevoirEenergie(15);
                choix = joueur2.jouer() - 1;                               //retourne le numero de l'attaque
                attaque = joueur2.getPersonnage().getAttaque()[choix];        // selectionne l'attaque a partir du choix
                joueur2.getPersonnage().attaquer(joueur1.getPersonnage(),attaque);
                joueur2.getPersonnage().perdreEenergie(attaque.getCoutEnergie());
                affiche_UI(joueur1,joueur2,nbTour,attaque);
            }
            nbTour++;
             joueur1.getPersonnage().recevoirEenergie(25);
             joueur2.getPersonnage().recevoirEenergie(15);
            affiche_UI(joueur1,joueur2,nbTour,attaque);


        }
    }
    return 0;
}
