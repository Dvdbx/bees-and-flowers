#ifndef LISTEABEILLE_H_INCLUDED
#define LISTEABEILLE_H_INCLUDED

#include "abeilles.h"

// Une collection de abeilles
typedef struct listeAbeille
{
    // nombre maxi d'�l�ments
    // =taille du tableau de pointeurs
    int max;

    // nombre effectif de pointeurs utilis�s
    // (les autres sont � NULL)
    int n;

    // le tableau de pointeurs (allou� dynamiquement)
    t_abeille **tab;

} t_listeAbeille;



/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser une liste (vide) de abeilles
t_listeAbeille * creerListeAbeille(int maxabeilles);

// Allouer et ajouter un ennemi � la liste
// et retourner l'adresse de ce nouveau ennemi
// retourne NULL en cas de probl�me
t_abeille * ajouterAbeille(t_listeAbeille *la);

// G�rer l'�volution de l'ensemble des abeilles
void actualiserListeAbeille(t_listeAbeille *la);

// Dessiner sur une bitmap l'ensemble des abeilles
void dessinerListeAbeille(BITMAP *bmp,t_listeAbeille *la);


#endif // LISTEABEILLE_H_INCLUDED
