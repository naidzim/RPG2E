#ifndef DEF_PERSONNAGE
#define DEF_PERSONNAGE

#include <iostream>
#include <string>
#include "attaque.h"


class Personnage
{

public:

    Personnage();
    Personnage(Personnage const& personnageACopier);//constructeur de copie
    Personnage& operator=(Personnage const& personnageACopier);


    void sePresenter() const; //affiche le nom, stats et attaques
    void print_punch_line() const;
    void afficherEtat() const; // affiche vie et energie actuelles (combat)

    std::string getNom() const ;
    std::string getNomAttaque(int i) const;
    int getVie() const;
    int getEnergie() const;
    Attaque* getAttaque();

    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible,Attaque attaque);
    bool estVivant() const;

protected:
    std::string m_nom;
    std::string punch_line;
    int m_vie;
    int m_energie;
    Attaque liste_attaque[3]; // 2 attaques +1 ultime

};


#endif // DEF_PERSONNAGE
