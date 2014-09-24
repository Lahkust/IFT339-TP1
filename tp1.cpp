#include "librairie.h"
#include "jeu.h"


int main()
{

    jeu partie = jeu();
    char lettre = '0';

    while(1)
        {

            while(lettre != '#')
                {


                    //Démarrer la partie; demander au joueur le nom du fichier, nb de lettres, etc
                    partie.demarrer("ODS6.txt"); // Pour la correction auto du TP, ne pas demander le nom du fichier

                    cout<<partie.mot_aleatoire().tostring()<<endl;

                    cin >> lettre;



                }
                lettre= '0';
        }
    return 0;
}

