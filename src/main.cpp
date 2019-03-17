#include <iostream>
#include <string>
#include "../include/Personnage.h"
#include "../include/Laffont.h"
#include "../include/James.h"
#include "../include/Joueur.h"

using namespace std;

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

    cout<<"              -----------------------------------------------------------------------------------"<<endl;
    cout << "                                           BIENVENUE SUR RPG2E                              "<<endl;
    cout<<"              -----------------------------------------------------------------------------------"<<endl;


    cout<<endl<<endl<<"Choisissez un personnage parmi les suivants :"<<endl<<endl;
    printPersonnage();                  //affiche les personnages disponnible
    Joueur joueur;                      // un joueur (il en faudrait 2 du coup)
    choixPersonnage(&joueur);           //permet au joueur de choisir le personnage
    cout<<endl<<"Vous avez choisi "<<joueur.getPersonnage().getNom()<<" !"<<endl<<endl;
    joueur.getPersonnage().print_punch_line();
    return 0;
}
