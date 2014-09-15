#ifndef DICTIONNAIRE_H
#define DICTIONNAIRE_H

#include <map>
#include <set>

#include "mot.h"

class dictionnaire
{
  public:

    //Manipulateur: impl�ment� par le dictionnaire

  void ouvrir(string,uint32_t);  //Ouvrir le fichier indiqu� par le string et r�cup�rer les mots de longueur uint32_t

    dictionnaire();
    ~dictionnaire();

  private:

  map< uint32_t, mot > map_dictionnaire;      // ensemble des mots tir�s du fichier ODS6
  map< mot, set < mot > > map_associative;    // ensemble des mots utilis�s lors de la triche

};

#endif // DICTIONNAIRE_H
