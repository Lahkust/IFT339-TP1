#include "librairie.h"
#include "mot.h"

int main()
{
	vector<string> vec_mots;								//Vecteur contenant les mots du scrabble
	vector<int> vec_choix_correspondant;					//Vecteur contenant les mots correspondants au nombre de lettre desir�
	vector<int> vec_lettre_correpondant;					//Vecteur contenant les essaie correspondants aux lettre du mot cible
	map<mot,list<mot>> dictionnaire;						//Map contenant les objets de type mot et leur liste correspondante
	int int_nb_lettre;										//Variable contenant le nombre de lettre d�sir� par l'utilisateur
	int int_indice_mot_choisit;								//Variable contenant le mot choisi correspondant au crit�re
	string str_mot_cible;									//Le mot cibl� par le programme
	string str_lettre_disponible("ABCDEFGHIJKLMNOPQRVWXYZ");//Lettres disponibles
	string str_lettre_utilise;								//Lettres utilis�es
	string str_solution;									//Solution en cours (lettres trouv�es de str_mot_choisit)
	char c_essaie;											//Le caract�re choisit par l'utilisateur

	//R�cup�ration de la liste de mot
	vec_mots = lireFichier("ODS6.txt"); 

	//Saisie du nombre de lettre du mot � rechercher
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
		str_solution.push_back('-');

	do
	{
		system("cls");
		cout<<"--- Bonne chance ! ---"<<"\n\n";
		cout<<"Les lettres disponibles : "<<str_lettre_disponible<<endl;
		cout<<"Les lettres utilisees : "<<str_lettre_utilise<<endl;
		cout<<"Le mot cache : "<<str_solution<<endl;
		cout<<"Le mot cache : "<<str_mot_cible<<endl;

		//Saise de la lettre 
		cout<<"Essaie : "; cin>>c_essaie;
		c_essaie = (toupper(c_essaie));

		//Mise � jour des lettres utilis�es
		if(str_lettre_utilise.find(c_essaie) > str_lettre_utilise.size())
			str_lettre_utilise.push_back(c_essaie);
		//Mise � jour des lettres disponibles
		if(str_lettre_disponible.find(c_essaie) <= str_lettre_disponible.size())
		  str_lettre_disponible.erase(str_lettre_disponible.find(c_essaie),1);

		//Recherche des pr�sences de l'essaie dans le mot cible
		vec_lettre_correpondant.clear();
		for(int i=0; i<str_mot_cible.size();i++)
		  if(str_mot_cible[i] == c_essaie)
		    vec_lettre_correpondant.push_back(i);

	}while(c_essaie != '#');
	
	system("pause");
	return 0;
}

