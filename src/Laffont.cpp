
#include "../include/Laffont.h"

Laffont::Laffont(){
    //Plus stratégique que James, peut se buff en défense, pas beaucoup de dégat
    this->m_nom="Laffont";
    this->punch_line="Je vous meprise !";
    this->m_vie=100;
    this->nrjMax=75;
    this->m_energie=75;  //energie de base
    this->liste_attaque[0]=Attaque("explication confuse",15,45);    // L'adversaire a 1 chance sur 2 de rater son attaque au prochain tour
    this->liste_attaque[1]=Attaque("c'est lamentable !",10,60);     //Laffont se régénère de 30 point de vie et prendra 10 point de dégat en moins au prochain tour
    this->liste_attaque[2]=Attaque("preparation de TP",35,75);      //attaque basique
    this->liste_attaque[3]=Attaque("Ne rien faire",0,0);
    //liste_attaque[3].afficherBis();
}


