#include <iostream>
#include <string>
#include "../include/UI.h"
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

//personnage disponnible ( en globale c'est plus simple )
Laffont laffont;
James james;

void printPersonnage(){

    laffont.sePresenter();
    james.sePresenter();

}

void choixPersonnage(Joueur * joueur){
    //joueur est entré/sortie => pointeur
    string choix;
    bool choix_ok =false;
    while(!choix_ok){
        cout<<"Quelle est votre choix ? : ";
        cin>>choix;
        switch(choix[0]){
            case 'j':
                *joueur=Joueur(james);
                choix_ok=true;
                break;
            case 'l':
                *joueur=Joueur(laffont);
                choix_ok=true;
                break;
            default:
                cout<<"Choisis un personnage disponnible gros con !"<<endl;
        }
    }
}


int main()
{

    printPersonnage();                  //affiche les personnages disponnible
    Joueur joueur;                      // un joueur (il en faudrait 2 du coup)
    choixPersonnage(&joueur);           //permet au joueur de choisir le personnage
    Joueur joueur2 = Joueur(laffont);       //à remplacer par le vrai deuxième joueur plus tard
    cout<<endl<<"Vous avez choisi "<<joueur.getPersonnage().getNom()<<" !"<<endl<<endl;
    joueur.getPersonnage().print_punch_line();
    animation_debut();
    affiche_UI(joueur,joueur2,0);           //affiche l'UI du jeux
    cout<<endl<<endl<<"Action de jeux a afficher ...";
    cout<<endl<<endl;
    return 0;
}
