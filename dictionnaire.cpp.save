#include <fstream>
#include <iostream>
#include <map>
#include <string>

#include "dictionnaire.h"

dictionnaire::dictionnaire()
{
  map_dictionnaire = map< uint32_t, mot >();
  map_associative = map< mot, set < mot > >();
}

dictionnaire::~dictionnaire()
{
  //dtor
}

void dictionnaire::ouvrir(string ods6, uint32_t taille_mot)
{

	string ligne;
	ifstream fichier(ods6);

	if (fichier.is_open())
	{
		for (uint32_t index; getline (fichier,ligne); ++index )
		{
		  if(ligne.length() == taille_mot)
      {
        map_dictionnaire.insert( std::pair<uint32_t,mot>(index,mot(ligne)) ;
      }
		}
		fichier.close();
	}
	else cout << "Unable to open file";

}


