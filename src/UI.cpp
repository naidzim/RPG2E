#include "../include/UI.h"
#include <iostream>
#include <string>

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
