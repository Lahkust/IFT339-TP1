#ifndef JEU_H
#define JEU_H

#include <iostream>

#include "dictionnaire.h"
#include "mot.h"


class jeu
{
  public:
    jeu();
    void rafraichir();  //Mettre � jour ce qui est affich� � l'�cran
    void demarrer(string);    //Ouvrir le dictionnaire





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    mot mot_aleatoire();
    void afficher_dictionnaire();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////






  private:
    dictionnaire le_dictionnaire;
};

#endif // JEU_H
