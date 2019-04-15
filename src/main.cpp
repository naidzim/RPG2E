#include <iostream>
#include <string>
#include "../include/UI.h"
#include "../include/Gameplay.h"
#include "../include/Personnage.h"
#include "../include/Laffont.h"
#include "../include/James.h"
#include "../include/Joueur.h"
#include "../include/Client_sock.h"
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
        int point_acces;
        point_acces = create_socket();


        printPersonnage();
        //Choix des joueurs
        string choixj1;
        string choixj2 = comunicate_choix(point_acces,&choixj1);
        choixPersonnageAdv(joueur1,"james");           //permet au joueur de choisir le personnage
        //joueur1.getPersonnage().print_punch_line();
        choixPersonnageAdv(joueur2,choixj2);           //permet au joueur de choisir le personnage
        cout<<endl<<"L'adversaire a choisi : "<<joueur2.getPersonnage().getNom()<<" !"<<endl<<endl;

//debut de la partie

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
        cout << "Fin de la partie : vous avez gagné" << endl;
        fin_comm(point_acces);

    }

    return 0;
}
