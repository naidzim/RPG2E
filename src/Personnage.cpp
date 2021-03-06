#include "../include/Personnage.h"


using namespace std;



Personnage::Personnage()
{

}



Personnage::Personnage(Personnage const& personnageACopier):
    m_vie(personnageACopier.m_vie), m_energie(personnageACopier.m_energie),
    m_nom(personnageACopier.m_nom),punch_line(personnageACopier.punch_line),nrjMax(personnageACopier.nrjMax)
{
    liste_attaque[0]=  Attaque(personnageACopier.liste_attaque[0]);
    liste_attaque[1]=  Attaque(personnageACopier.liste_attaque[1]);
    liste_attaque[2]=  Attaque(personnageACopier.liste_attaque[2]);
    liste_attaque[3]=  Attaque(personnageACopier.liste_attaque[3]);
}



string Personnage::getNom() const{
    return this->m_nom;
 }

void Personnage::print_punch_line() const{
    cout<<"\""<<punch_line<<"\""<<endl;
}

void Personnage::sePresenter() const{

    cout<<"--------------------"<<m_nom<<"--------------------"<<endl<<endl;
    cout<<" * point de vie : "<<m_vie<<endl;
    cout<<" * point de d'energie : "<<m_energie<<endl;
    cout<<" * attaque disponnible : "<<endl;
    for(int i =0;i<4;i++){
        liste_attaque[i].afficher();
    }
    cout<<endl;
}

void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;

    if (m_vie < 0)
    {
        m_vie = 0;
    }

}


void Personnage::perdreEenergie(int nbEnergie)
{
    m_energie -= nbEnergie;

    if (m_energie <0) m_energie = 0;
}

void Personnage::recevoirEenergie(int nbEnergie)
{
    if (m_energie >= nrjMax)
    {
        m_energie = nrjMax;
    }
    else
        m_energie += nbEnergie;

}


int Personnage::attaquer(Personnage &cible,Attaque const attaque)
{
    cible.recevoirDegats(attaque.getDegats());
    return 0;
}



bool Personnage::estVivant() const
{
    return m_vie > 0; //Renvoie true si m_vie > 0 et false sinon.

}

Personnage& Personnage::operator=(Personnage const& personnageACopier)
{
    if( this != &personnageACopier )
    //on verifie que l'objet n'est pas le meme que celui qu'on veut copier
    {
        punch_line = personnageACopier.punch_line;
        m_nom=personnageACopier.m_nom;
        m_vie = personnageACopier.m_vie;
        m_energie= personnageACopier.m_energie;
        nrjMax=personnageACopier.nrjMax;
        this->liste_attaque[0]=personnageACopier.liste_attaque[0];
        this->liste_attaque[1]=personnageACopier.liste_attaque[1];
        this->liste_attaque[2]=personnageACopier.liste_attaque[2];
        this->liste_attaque[3]=personnageACopier.liste_attaque[3];
    }
    return *this; //on renvoie l'objet lui meme
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "energie : " << m_energie << endl;

}
int Personnage::getVie() const
{
    return m_vie;
}
int Personnage::getEnergie() const
{
    return m_energie;
}

Attaque* Personnage::getAttaque()
{
    return this->liste_attaque;
}
string Personnage::getNomAttaque(int i) const
{
    return liste_attaque[i].getNom();
}
