#include "../include/Gameplay.h"

void ajoutPerso(vector<Personnage> &persoDispo)
{
    persoDispo.push_back(James());
    persoDispo.push_back(Laffont());
}
int sessionInit()
{
    int choix;
    bool bonChoix = false;
    cout<<"              -----------------------------------------------------------------------------------"<<endl;
    cout << "                                           BIENVENUE SUR RP2GE                              "<<endl;
    cout<<"              -----------------------------------------------------------------------------------"<<endl;
    cout <<"\n\n";
    cout << "****Ce jeu se joue en PLEIN ECRAN ****"<< endl;
    cout << "Appuyer sur Entrer !" << endl;
    getchar();
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

void printPersonnage()
{
    vector<Personnage> persoDispo;
    ajoutPerso(persoDispo);
    cout<<endl<<endl<<"Choisissez un personnage parmi les suivants :"<<endl<<endl;
    for (int i =0; i< persoDispo.size() ;i++)

        persoDispo[i].sePresenter();

}

void choixPersonnage(Joueur& joueur){

    string choix, str;
    bool choix_ok =false;
    while(!choix_ok){
        cout<<"Quelle est votre choix ? : ";
        cin>> str;

        choix = miniscule(str);

        if (choix == "james")
        {
            joueur.m_perso = James();
            choix_ok=true;

        }
        else if (choix == "laffont")
        {

            joueur.m_perso = Laffont();
            choix_ok=true;
        }
        else
            cout<<"Choisis un personnage disponnible gros con !"<<endl;
        }

}

string miniscule (string str)
{
    string mot;
    locale loc;
    for (std::string::size_type i=0; i<str.length(); ++i)
    mot += tolower(str[i],loc);
    return mot;
}
