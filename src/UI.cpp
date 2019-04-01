#include "../include/UI.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string convertNbTourUI(int nbTour){
    //convertit le nombre de tour en élément affichable
    // ex : 1 => PREMIER 2=> DEUXIEME etc..
    //si quelqu'un a la fois il peut en rajouter au cas ou

    string numTour;
    switch(nbTour){
        case 0 :
            numTour = "PREMIER";
            break;
        case 1 :
            numTour = "PREMIER";
            break;
        case 2 :
            numTour = "DEUXIEME";
            break;
        case 3 :
            numTour = "TROISIEME";
            break;
        case 4 :
            numTour = "QUATRIEME";
            break;
        case 5 :
            numTour = "CINQUIEME";
            break;
        case 6 :
            numTour = "SIXIEME";
            break;
        case 7 :
            numTour = "SEPTIEME";
            break;
        case 8 :
            numTour = "HUITIEME";
            break;
        case 9 :
            numTour = "NEUVIEME";
            break;
        case 10 :
            numTour = "DIXIEME";
            break;
        default :
            numTour = "N'IEME";
            break;
    }

    return numTour;
}

string convertAttaqueToAction(Joueur attaquant,Joueur cible,Attaque attaque){
    //transforme une attaque en action de jeux (ex: machin attaque bidule avec coup de boule...)
    ostringstream temp;
    temp<<attaque.getDegats();
    string attaqueS = temp.str();
    string action = "   * "+attaquant.getPersonnage().getNom()+" a utilise "+ attaque.getNom()+" ! ";
    action += "      => "+cible.getPersonnage().getNom()+ " a perdu "+ attaqueS + " point de vie \n\n";
    return action;
}

void affiche_UI(Joueur joueur_1,Joueur joueur_2,int nbTour, Attaque attaque){


    //fonction à appeler à chaque fin de tour précédé de 'std::system ( "CLS" )'
    //pour redéssinner l'UI
    //cmpt compte le nombre d'action ce tour ci pour l'instant limité à 1 action par perso => 2 max/tour
    //actionUI affiche les actions a la suite pour le même tour même si on redéssine l'UI
    //déclaré en static pour persistence

    static string actionUI;
    static int cmpt=2;
    string action;
    system ( "CLS" );      //on vide le contenu de la console pour afficher le nouvel UI du jeux
    Personnage perso_J1 = joueur_1.getPersonnage();
    Personnage perso_J2 = joueur_2.getPersonnage();
    string numTour = convertNbTourUI(nbTour);
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout << "                                                                            "<<numTour<<"  TOUR                              "<<endl;
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
    if(nbTour == 0){      //debut du jeux pas encore d'action à afficher
        actionUI = "";
    }
    else{
        action = convertAttaqueToAction(joueur_2,joueur_1,attaque);
        if(cmpt==2){
            actionUI=action;
            cmpt=1;
        }
        else{
            actionUI+=action;
            cmpt+=1;
        }
    }
    cout<<endl<<" ------------------------------------------------ACTION DE JEUX----------------------------------------------- ";
    cout<<endl<<endl;
    cout<<actionUI<<endl;
    cout<<" -------------------------------------------------------------------------------------------------------------  "<<endl<<endl;

}

void UI_attaque(Joueur joueur){
    cout<<" ____________________________________________________________________________________________________________ ";
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

void animation_debut()
{
    cout<<"Debut du jeux ";
    Sleep(500);
    cout<<".";
    Sleep(500);                //attend 3 secondes pour temporiser
    cout<<".";
    Sleep(500);
    cout<<"."<<endl;
    Sleep(300);
    system ( "CLS" );      //on vide le contenu de la console pour afficher l'UI du jeux

}
