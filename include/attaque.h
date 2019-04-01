#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED

#include <iostream>
#include <string>



//faire des classe filles pour pouvoir personnaliser les attaques ( effet d'endormissement, poison, buff en force, energie ,vie etc..)
//ajouter une description des attaques pour printPersonnage.
//ajouter les ultimes

class Attaque
{

public:
    Attaque(); //constructeurs
    Attaque(std::string nom, int degats,int m_cout_energie); //surcharge de constructeurs

    void afficher() const; // affiche infos completes sur attaque
    void afficherBis() const;

    std::string getNom() const;
    int getDegats() const;
    int getEnergie() const;

    Attaque& operator=(Attaque const& attaqueACopier);

private:
    std::string m_nom;
    int m_degats;
    int m_cout_energie;
};

#endif // ATTAQUE_H_INCLUDED
