#include "../include/attaque.h"

using namespace std;


Attaque::Attaque(string nom, int degats,int cout_energie)
{
    this->m_nom=nom;
    this->m_degats=degats;
    this->m_cout_energie=cout_energie;
}

Attaque::Attaque()
{

}


void Attaque::afficher() const
{
    cout << "     - " << m_nom << " (Degats : " << m_degats <<", Energie : "<< m_cout_energie<<")" << endl;
}

void Attaque::afficherBis() const
{
    cout << m_nom << " (Degats : " << m_degats <<", Energie : "<< m_cout_energie<<")";
}

int Attaque::getDegats() const
{
    return m_degats;
}

Attaque& Attaque::operator=(Attaque const& attaqueACopier)
{
    if( this != &attaqueACopier )
    //on verifie que l'objet n'est pas le meme que celui qu'on veut copier
    {
        m_nom = attaqueACopier.m_nom;
        m_degats= attaqueACopier.m_degats;
        m_cout_energie= attaqueACopier.m_cout_energie;
    }
    return *this; //on renvoie l'objet lui meme
}
