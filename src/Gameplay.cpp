#include "../include/Gameplay.h"

using namespace std;

int sessionInit()
{
    int choix;
    bool bonChoix = false;
    cout<<"              -----------------------------------------------------------------------------------"<<endl;
    cout << "                                           BIENVENUE SUR RP2GE                              "<<endl;
    cout<<"              -----------------------------------------------------------------------------------"<<endl;
    cout <<"\n\n";
    do {
        cout << "1. Commencer une nouvelle partie"<< endl;
        cout << "2. Afficher les regles du jeu" << endl;
        cout << "0. Quitter la partie" << endl;
        cout << "Votre choix : ";
        cin >> choix;
        switch ( choix ){
            case 0:
                cout << "A bientot !!" << endl;
                bonChoix = 1;
                return 0;
            case 1:
                cout << "\n\nAttente de connexion...." << endl;
                cout << "Connexion reussie" << endl;
                cout << "----------------------------------------------" << endl;
                cout << "          Phase de preparation" << endl;
                cout << "----------------------------------------------" << endl;
                bonChoix = 1;
                return 1;
            case 2:
                cout << "En cours de developpement... Reessayer plutard\n" << endl;
                break;

            default:
                cout << "\n\nChoix impossible !!" << endl;
                cout << "Reessayer\n\n" << endl;
                break;
        }
    } while (!bonChoix);

}

void printPersonnage(Joueur& joueur){

    joueur.getPersonnage().sePresenter();

}

void choixPersonnage(Joueur& joueur){
    //joueur est entré/sortie => pointeur
    cout<<endl<<endl<<"Choisissez un personnage parmi les suivants :"<<endl<<endl;
    //printPersonnage();                  //affiche les personnages disponnible
    string choix;
    bool choix_ok =false;
    while(!choix_ok){
        cout<<"Quelle est votre choix ? : ";
        cin>>choix;
        if (choix == "James")
        {
            joueur.m_perso = James();
            choix_ok=true;

        }
        else if (choix == "Laffont")
        {

            joueur.m_perso = Laffont();
            choix_ok=true;
        }
        else
            cout<<"Choisis un personnage disponnible gros con !"<<endl;
        }

}
