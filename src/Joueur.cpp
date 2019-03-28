#include <iostream>
#include <string>
#include "../include/Joueur.h"
#include "../include/Personnage.h"

using namespace std;

Joueur::Joueur(){

}



Joueur::Joueur(Personnage  perso_joueur){
    this->m_perso=perso_joueur;
}


Personnage& Joueur::getPersonnage(){
    return m_perso;
}

int Joueur::jouer(){
    /*se déclenche a chaque tour*/
    int action;
    cout << "Choisir une attaque :"<< endl;
    cin >> action;

    switch (action){
        case 1:
            cout << "Vous avez choisi " << m_perso.getNomAttaque(0)<<endl;
            return 1;
        case 2:
            cout << "Vous avez choisi " << m_perso.getNomAttaque(2)<<endl;
            return 2;
        case 3:
            cout << "Vous avez choisi " << m_perso.getNomAttaque(2)<<endl;
            return 3;
    }
}
