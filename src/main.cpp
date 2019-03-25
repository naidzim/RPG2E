#include <iostream>
#include <string>
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

string convertPdvToUI(int nbPointDeVie){

/*convertit le nombre de point de vie d'un personnage en
en nombre de de tiret par exemple ou autre
Elle sera modifié avec le nombre de point de vie passé en paramètre
au fur et a mesure que la partie avance*/

    string fragment = "==";
    string barre_de_vie ="*";
    for(int i=0;i<nbPointDeVie/10;i++) {
        barre_de_vie = barre_de_vie + fragment;
    }
    barre_de_vie = barre_de_vie + "*"+"     ";
    return barre_de_vie;
}

string convertEnergieToUI(int nbPointDenergie){

/*convertit le nombre de point d' energie d'un personnage en
en nombre de de tiret par exemple ou autre
Elle sera modifié avec le nombre de point d'nergie passé en paramètre
au fur et a mesure que la partie avance*/

    string fragment = "--";
    string barre_denergie ="*";
    for(int i=0;i<nbPointDenergie/10;i++) {
        barre_denergie = barre_denergie + fragment;
    }
    barre_denergie = barre_denergie + "*"+"     ";
    return barre_denergie;
}

void UI_attaque(Joueur joueur){
    cout<<" _____________________________________________________________________________________________________________ ";
    cout<<endl<<endl;
    cout<<"   1) ";
    joueur.getPersonnage().getAttaque()[0].afficherBis();
    cout<<"         2) ";
    joueur.getPersonnage().getAttaque()[1].afficherBis();
    cout<<"   ";
    cout<<endl<<endl<<"   3) ";
    joueur.getPersonnage().getAttaque()[2].afficherBis();
    cout<<endl<<endl;
    cout<<" _____________________________________________________________________________________________________________ "<<endl;

}

void affiche_UI(Joueur joueur_1,Joueur joueur_2,int nbTour){

    //Le paramètre nbTour servira à afficher le nombre de tour passé au lieu de "PREMIER TOUR"
    //Il sera récupéré via la futur boucle while qui fera tourner le programme et qui l'incrementera
    /*fonction à appeler à chaque fin de tour précédé de 'std::system ( "CLS" )'
    pour redéssinner l'UI*/

    Personnage perso_J1 = joueur_1.getPersonnage();
    Personnage perso_J2 = joueur_2.getPersonnage();
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "                                                                                PREMIER TOUR                              "<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl<<endl<<endl<<endl<<"          "<<perso_J1.getNom()<<endl;
    cout<<convertPdvToUI(perso_J1.getVie())<<perso_J1.getVie()<<" point de vie  "<<endl;
    cout<<convertEnergieToUI(perso_J1.getEnergie())<<perso_J1.getEnergie()<<" point d'energie   "<<endl;
    cout<<"                                                                                                                     "<<perso_J2.getNom()<<endl;
    cout<<"                                                                                                             "<<convertPdvToUI(perso_J2.getVie())<<perso_J2.getVie()<<" point de vie  "<<endl;
    cout<<"                                                                                                             "<<convertEnergieToUI(perso_J2.getEnergie())<<perso_J2.getEnergie()<<" point d'energie  "<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    cout<<endl<<endl<<endl<<endl<<endl;
    UI_attaque(joueur_1);
    cout<<endl<<endl;
}

int main()
{

    cout<<"                                              -----------------------------------------------------------------------------------"<<endl;
    cout << "                                                                             BIENVENUE SUR RP2GE                              "<<endl;
    cout<<"                                              -----------------------------------------------------------------------------------"<<endl;


    cout<<endl<<endl<<"Choisissez un personnage parmi les suivants :"<<endl<<endl;
    printPersonnage();                  //affiche les personnages disponnible
    Joueur joueur;                      // un joueur (il en faudrait 2 du coup)
    choixPersonnage(&joueur);           //permet au joueur de choisir le personnage
    Joueur joueur2 = Joueur(laffont);       //à remplacer par le vrai deuxième joueur plus tard
    cout<<endl<<"Vous avez choisi "<<joueur.getPersonnage().getNom()<<" !"<<endl<<endl;
    joueur.getPersonnage().print_punch_line();
    cout<<"Debut du jeux ..."<<endl;
    Sleep(3000);                //attend 3 secondes pour temporiser
    std::system ( "CLS" );      //on vide le contenu de la console pour afficher l'UI du jeux
    affiche_UI(joueur,joueur2,0);           //affcihe l'UI du jeux
    cout<<endl<<endl<<"Action de jeux a afficher ...";
    cout<<endl<<endl<<
    return 0;
}
