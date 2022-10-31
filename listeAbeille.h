#ifndef LISTEABEILLE_H_INCLUDED
#define LISTEABEILLE_H_INCLUDED

#include "abeilles.h"

// Une collection de abeilles
typedef struct listeAbeille
{
    // nombre maxi d'éléments
    // =taille du tableau de pointeurs
    int max;

    // nombre effectif de pointeurs utilisés
    // (les autres sont à NULL)
    int n;

    // le tableau de pointeurs (alloué dynamiquement)
    t_abeille **tab;

} t_listeAbeille;



/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser une liste (vide) de abeilles
t_listeAbeille * creerListeAbeille(int maxabeilles);

// Allouer et ajouter un ennemi à la liste
// et retourner l'adresse de ce nouveau ennemi
// retourne NULL en cas de problème
t_abeille * ajouterAbeille(t_listeAbeille *la);

// Gérer l'évolution de l'ensemble des abeilles
void actualiserListeAbeille(t_listeAbeille *la);

// Dessiner sur une bitmap l'ensemble des abeilles
void dessinerListeAbeille(BITMAP *bmp,t_listeAbeille *la);


#endif // LISTEABEILLE_H_INCLUDED
