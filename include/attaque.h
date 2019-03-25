#ifndef ATTAQUE_H_INCLUDED
#define ATTAQUE_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

//faire des classe filles pour pouvoir personnaliser les attaques ( effet d'endormissement, poison, buff en force, energie ,vie etc..)
//ajouter une description des attaques pour printPersonnage.
//ajouter les ultimes

class Attaque
{

public:
    Attaque(); //constructeurs
    Attaque(std::string nom, int degats,int m_cout_energie); //surcharge de constructeurs
    void afficher() const;
    int getDegats() const;
    Attaque& operator=(Attaque const& attaqueACopier);
    void afficherBis() const;

private:
    std::string m_nom;
    int m_degats;
    int m_cout_energie;
};

#endif // ATTAQUE_H_INCLUDED
