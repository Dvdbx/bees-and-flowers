#include "listeAbeille.h"
#include "utilitaire.h"

// Allouer et initialiser une liste (vide) de abeilles
t_listeAbeille * creerListeAbeille(int maxabeilles)
{
    t_listeAbeille *nouv;
    int i;

    nouv=(t_listeAbeille *)malloc(1*sizeof(t_listeAbeille));

    nouv->max=maxabeilles;
    nouv->n=0;
    nouv->tab=(t_abeille **)malloc(maxabeilles*sizeof(t_abeille*));

    for (i=0; i<maxabeilles; i++)
        nouv->tab[i]=NULL;

    return nouv;
}

// Allouer et ajouter une abeille à la liste
// et retourner l'adresse de celui-ci
// ( mais il vaut mieux d'abord vérifier qu'il
//   y a de la place disponible avant d'appeler )
t_abeille * ajouterAbeille(t_listeAbeille *la)
{
    int i;
    t_abeille *abeille;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (la->n >= la->max)
        return NULL;

    // Allouer une abeille initialisée
    abeille=creerAbeille();

    // Chercher un emplacement libre
    i=0;
    while (la->tab[i]!=NULL && i<la->max)
        i++;

    // Si on a trouvé ...
    // (normalement oui car on a vérifié n<max)
    if (i<la->max)
    {
        // Accrocher le ennemi à l'emplacement trouvé
        la->tab[i]=abeille;
        la->n++;
    }
    // Sinon c'est qu'il y a un problème de cohérence
    else
        allegro_message("Anomalie gestion ajouterEnnemi : liste corrompue");

    return abeille;
}

// Gérer l'évolution de l'ensemble des abeilles
void actualiserListeAbeille(t_listeAbeille *la)
{
    int i;

    // actualiser chaque abeille
    for (i=0; i<la->max; i++)
        if (la->tab[i]!=NULL)
        {
            actualiserAbeille(la->tab[i]);
        }
}

// Dessiner sur une bitmap l'ensemble des abeilles
void dessinerListeAbeille(BITMAP *bmp,t_listeAbeille *la)
{
    int i;

    for (i=0; i<la->max; i++)
        if (la->tab[i]!=NULL)
            dessinerAbeille(bmp,la->tab[i]);

}
