#include "librairie.h"
#include "mot.h"

int main()
{
	vector<string> vec_mots;								//Vecteur contenant les mots du scrabble
	vector<int> vec_choix_correspondant;					//Vecteur contenant les choix correspondants au nombre de lettre desir�
	map<mot,list<mot>> dictionnaire;						//Map contenant les objets de type mot et leur liste correspondante
	int int_nb_lettre;										//Variable contenant le nombre de lettre d�sir� par l'utilisateur
	int int_indice_mot_choisit;								//Variable contenant le mot choisi correspondant au crit�re
	string str_mot_cible;									//Le mot cibl� par le programme
	string str_lettre_disponible("ABCDEFGHIJKLMNOPQRVWXYZ");//Lettres disponibles au d�marrage 
	string str_lettre_utilisee;								//Lettres utilis�e par l'utilisateur
	string str_mot_cache;									//Le mot cach� dans sont �tat actuel du jeu ( lettre d�vcouvertes et non d�couvertes)

	vec_mots = lireFichier("ODS6.txt"); //R�cup�ration de la liste de mot

	cout << "Nombre de lettres : "; cin>>int_nb_lettre;

	//Cr�ation d'un vecteur contant l'indice des mots correspondants � la taille demand�
	for(int i=0; i<vec_mots.size(); i++)	
	{
		if(vec_mots[i].size() == int_nb_lettre)
			vec_choix_correspondant.push_back(vec_mots[i].size());
	}

	//Initialisation de la source al�atoire
    srand (time(NULL));
	//S�lection au hasard de l'indice d'un mot de la liste correspondante � la taille demand�
	int_indice_mot_choisit = rand() % vec_choix_correspondant.size();

	//R�cup�ration du mot cibl� par le programme
	str_mot_cible = vec_mots[int_indice_mot_choisit];

	//Initialisation du mot cach�
	for(int i=0; i<str_mot_cible.size(); i++)
		str_mot_cache.push_back('-');

	system("cls");
	cout<<"--- Bonne chance ! ---"<<"\n\n";
	cout<<"Les lettres disponibles : "<<str_lettre_disponible<<endl;
	cout<<"Les lettres utilisees : "<<str_lettre_utilisee<<endl;

	cout<<"Le mot cache : "<<str_mot_cache<<endl;

	system("pause");
	return 0;
}

