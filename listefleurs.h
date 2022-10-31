#ifndef LISTEFLEURS_H_INCLUDED
#define LISTEFLEURS_H_INCLUDED

#include "fleurs.h"

// Une collection de fleurs
typedef struct listefleur
{
    // nombre maxi d'�l�ments
    // =taille du tableau de pointeurs
    int max;

    // nombre effectif de pointeurs utilis�s
    // (les autres sont � NULL)
    int n;

    // le tableau de pointeurs (allou� dynamiquement)
    t_fleur **tab;

} t_listefleur;



/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser une liste (vide) de fleurs
t_listefleur * creerListefleur(int maxfleurs);

// Allouer et ajouter un ennemi � la liste
// et retourner l'adresse de cette nouvelle fleur
// retourne NULL en cas de probl�me
t_fleur * ajouterfleur(t_listefleur *la);


// Dessiner sur une bitmap l'ensemble des fleurs
void dessinerListefleur(BITMAP *bmp,t_listefleur *la);


#endif // LISTEFLEURS_H_INCLUDED
