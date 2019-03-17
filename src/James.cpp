
#include "../include/James.h"

James::James(){
    //frappe fort et beaucoup de vie mais a peu d'energie et n'en reprend pas beaucoup chaque tour
    // en gros c'est un tank
    this->m_nom="James";
    this->punch_line="Vous allez moucher rouge !";
    this->m_vie=150;
    this->m_energie=50;     //energie de base
    this->liste_attaque[0]=Attaque("caressage de cote",50,50);
    this->liste_attaque[1]=Attaque("Frappe du grizzly",35,35);
    this->liste_attaque[2]=Attaque("echauffement du poignet",0,25); // la prochaine attaque fera 10% de dégat en plus
}


