#include "../include/Personnage.h"


using namespace std;



Personnage::Personnage()
{

}



Personnage::Personnage(Personnage const& personnageACopier): m_vie(personnageACopier.m_vie), m_energie(personnageACopier.m_energie),
    m_nom(personnageACopier.m_nom),punch_line(personnageACopier.punch_line)
{
    liste_attaque[0]=  Attaque(personnageACopier.liste_attaque[0]);
    liste_attaque[1]=  Attaque(personnageACopier.liste_attaque[1]);
    liste_attaque[2]=  Attaque(personnageACopier.liste_attaque[2]);
}


Personnage::~Personnage()
{

}

 string Personnage::getNom(){
    return this->m_nom;
 }

void Personnage::print_punch_line(){
    cout<<"\""<<this->punch_line<<"\""<<endl;
}

void Personnage::sePresenter(){
    char lettre_choix = tolower(this->m_nom[0]);
    cout<<"--------------------"<<this->m_nom<<" (appuyez sur "<<lettre_choix<<")"<<"--------------------"<<endl<<endl;
    cout<<" * point de vie : "<<this->m_vie<<endl;
    cout<<" * point de d'energie : "<<this->m_energie<<endl;
    cout<<" * attaque disponnible : "<<endl;
    for(int i =0;i<3;i++){
        this->liste_attaque[i].afficher();
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

void Personnage::attaquer(Personnage &cible,Attaque attaque)
{
    cible.recevoirDegats(attaque.getDegats());
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
        this->liste_attaque[0]=personnageACopier.liste_attaque[0];
        this->liste_attaque[1]=personnageACopier.liste_attaque[1];
        this->liste_attaque[2]=personnageACopier.liste_attaque[2];
    }
    return *this; //on renvoie l'objet lui meme
}

void Personnage::afficherEtat() const
{
    cout << "Vie : " << m_vie << endl;
    cout << "energie : " << m_energie << endl;

}
