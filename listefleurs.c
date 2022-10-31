#include "listefleurs.h"
#include "utilitaire.h"

// Allouer et initialiser une liste (vide) de fleurs
t_listefleur * creerListefleur(int maxfleurs)
{
    t_listefleur *nouv;
    int i;

    nouv=(t_listefleur *)malloc(1*sizeof(t_listefleur));

    nouv->max=maxfleurs;
    nouv->n=0;
    nouv->tab=(t_fleur **)malloc(maxfleurs*sizeof(t_fleur*));

    for (i=0; i<maxfleurs; i++)
        nouv->tab[i]=NULL;

    return nouv;
}

// Allouer et ajouter une fleur � la liste
// et retourner l'adresse de celui-ci
// ( mais il vaut mieux d'abord v�rifier qu'il
//   y a de la place disponible avant d'appeler )
t_fleur * ajouterfleur(t_listefleur *la)
{
    int i;
    t_fleur *fleur;

    // Liste pleine, on alloue rien et on retourne NULL...
    if (la->n >= la->max)
        return NULL;

    // Allouer une fleur initialis�e
    fleur=creerfleur();

    // Chercher un emplacement libre
    i=0;
    while (la->tab[i]!=NULL && i<la->max)
        i++;

    // Si on a trouv� ...
    // (normalement oui car on a v�rifi� n<max)
    if (i<la->max)
    {
        // Accrocher le ennemi � l'emplacement trouv�
        la->tab[i]=fleur;
        la->n++;
    }
    // Sinon c'est qu'il y a un probl�me de coh�rence
    else
        allegro_message("Anomalie gestion ajouterEnnemi : liste corrompue");

    return fleur;
}

// Dessiner sur une bitmap l'ensemble des fleurs
void dessinerListefleur(BITMAP *bmp,t_listefleur *la)
{
    int i;

    for (i=0; i<la->max; i++)
        if (la->tab[i]!=NULL)
            dessinerfleur(bmp,la->tab[i]);

}
