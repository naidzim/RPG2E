#ifndef JAMES_H_INCLUDED
#define JAMES_H_INCLUDED


#include "Personnage.h"
#include <iostream>
#include <string>

//Possibilité de personnaliser les personnages avec des attributs spéciaux
//genre des attaques ultimes
//des effets particuliers : intimidation (impossible d'attaquer au prochain tour),rage (buff en att/déf si en dessous d'un certain seuil de pv) etc...

using namespace std;

class James : public Personnage {

    public:
        James();
        //~James(); je sais pas si il le faut ou si il hérite

};





#endif // JAMES_H_INCLUDED
