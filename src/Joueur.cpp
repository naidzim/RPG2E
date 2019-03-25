#include "../include/Personnage.h"
#include <iostream>
#include <string>
#include "../include/Joueur.h"

Joueur::Joueur(){

}

Joueur::~Joueur()
{

}

void Joueur::affiche(){
    cout<<"mes couilles"<<this->m_perso_joueur.getNom()<<endl;
}

Joueur::Joueur(Personnage  perso_joueur){
    this->m_perso_joueur=perso_joueur;
}


Personnage Joueur::getPersonnage(){
    return (this->m_perso_joueur);
}

void Joueur::jouer(){
    /*se déclenche a chaque tour*/
    /*choisi une ou plusieurs attaques en fonction de son energie */
}



void Joueur::choisir_personnage(){
    /*se déclenche au debut*/
    /*choisi un perso a tour de rôle*/
}

