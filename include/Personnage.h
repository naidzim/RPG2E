
#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "attaque.h"


using namespace std;

class Personnage
{

public:
    //constructeurs
    Personnage();
    //constructeur de copie
    Personnage(Personnage const& personnageACopier);

    //destructeurs
    ~Personnage();

    //methodes
    void sePresenter();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible,Attaque attaque);
    bool estVivant() const;
    void afficherEtat() const;
    Personnage& operator=(Personnage const& personnageACopier);
    void print_punch_line();
    string getNom();

protected:
    Attaque liste_attaque[3];
    int m_vie;
    int m_energie;
    string punch_line;
    string m_nom;

};


#endif // DEF_PERSONNAGE
