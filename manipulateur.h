#ifndef MANIPULATEUR_H
#define MANIPULATEUR_H

#include <string>

#include "mot.h"

using namespace std;
class manipulateur
{
public:
    manipulateur();
    ~manipulateur();

    void actualiser_lettres(char); // Retire la lettre des lettres disponibles et ajoute la lettre aux lettrres utilis�es
    bool lettre_presente(char);    // V�rifie si le char est pr�sent dans le mot cible


private:

    string disponibles;         //lettres disponibles
    string utilisees;           //lettres utilis�es
    string etat_actuel;         //mot tel qu'affich�, tel que trouv� actuellement
    uint32_t indice_mot_cible;
    mot mot_aleatoire();        // G�n�re un indice al�atoire et en retourne le mot associ�
    void comparer(char);        // Compare le char avec le mot cible, v�rifie si la lettre est
    // pr�sente, met � jour l'affichage des lettres, etc

};


#endif // MANIPULATEUR_H
