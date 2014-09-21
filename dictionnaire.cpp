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
		for (uint32_t index = 0; getline (fichier,ligne); index++ )
		{
		  if(ligne.length() == taille_mot)
      {
        map_dictionnaire[index] = mot(ligne);
      }
		}
		fichier.close();
	}
	else cout << "Unable to open file";

	cout << map_dictionnaire.find(uint32_t(0))->second.value;


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
mot test = map_dictionnaire.find(indice_mot_cible)->second;
//for(size_t i = 0; i < test.size(); ++i)retour |= (test.at(i) == lettre);
return retour;
}

mot dictionnaire::mot_aleatoire()
{
  mt19937 rng;          // Crée un générateur de nombre aléatoires (standard C++11)
  rng.seed(uint32_t()); // Initialisation à l'aide d'une graine elle-même aléatoire (la scrap en mémoire)
  uniform_int_distribution<uint32_t> uint_dist(0,map_dictionnaire.size()); //Définit les limites du rng
  return map_dictionnaire.find(uint_dist(rng))->second; //Génère concrètement l'index aléatoire et retourne le mot associé
}

void dictionnaire::comparer(char)
{

}
