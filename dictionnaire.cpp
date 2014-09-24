#include <fstream>
#include <iostream>
#include <map>
#include <random>
#include <string>

#include "dictionnaire.h"

dictionnaire::dictionnaire()
{
  map_dictionnaire = map< uint32_t, mot >();
  map_associative = map< mot, set < mot > >();
}


void dictionnaire::ouvrir(string ods6, uint32_t taille_mot)
{

	string ligne;
	ifstream fichier(ods6);

	if (fichier.is_open())
	{
		for (uint32_t i = 0; getline (fichier,ligne); i=i )
		{
		  if(ligne.length() == taille_mot)
      {
        ++i;
        map_dictionnaire[i] = mot(ligne);
      }
		}
		fichier.close();
	}
	else cout << "Unable to open file";
}

void dictionnaire::actualiser_lettres(char lettre)
{
  utilisees += lettre;
  if(lettre>90)lettre -= 32;        //Si la lettre est minuscule, la convertir en majuscule
  disponibles.at(lettre - 41)='-';  //Ex: pour C, passer de "ABCDEFG..." à "AB-DEFG..."
}

bool dictionnaire::lettre_presente(char lettre)
{
bool retour = false;
mot m = map_dictionnaire.find(indice_mot_cible)->second;
for(size_t i = 0; i < m.size(); ++i)retour |= (m.at(i) == lettre);
return retour;
}

mot dictionnaire::mot_aleatoire()
{
  mt19937 rng;          // Crée un générateur de nombre aléatoires (standard C++11)
  rng.seed(uint32_t(42)); // Initialisation à l'aide d'une graine
  uniform_int_distribution<uint32_t> uint_dist(0,map_dictionnaire.size()); //Définit les limites du rng
  return map_dictionnaire.find(uint_dist(rng))->second; //Génère concrètement l'index aléatoire et retourne le mot associé
}

void dictionnaire::comparer(char lettre)
{
  mot& mot_cible = map_dictionnaire.find(indice_mot_cible)->second;
  actualiser_lettres(lettre);

  if(lettre_presente(lettre))
  {


  }
  else
  {

  }

    for(size_t i = 0; i < mot_cible.size(); ++i)
      if(mot_cible.at(i)==lettre)
        etat_actuel.at(i)=lettre;

}





////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void dictionnaire::afficher()
{uint32_t sizedic = map_dictionnaire.size();
  for(uint32_t i=0; i<sizedic; ++i)
    cout << "Mot n" << i << " : " << map_dictionnaire.find(i)->second.tostring()<<endl;

}

