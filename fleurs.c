#include <stdio.h>
#include "fleurs.h"
#include "utilitaire.h"
#define NIMAGE 15


// Allouer et initialiser une fleur
t_fleur * creerfleur()
{
    t_fleur *nouv;

    int n;

    // Pour charger la séquence
    char nomfichier[256];

    // Allouer
    nouv=(t_fleur *)malloc(1*sizeof(t_fleur));

    n=rand()%15;

    sprintf(nomfichier,"fleur%d.bmp",n);
    nouv->img= load_bitmap_check(nomfichier);

        // pour la taille on se base sur la 1ère image de la séquence
    nouv->tx = nouv->img->w;
    nouv->ty = nouv->img->h;

    nouv->x = rand()%((SCREEN_W - nouv->tx) - nouv->tx +1)+ nouv->tx;
    nouv->y = rand()%((SCREEN_H - nouv->ty) - nouv->ty +1)+ nouv->ty;

    // Retourner ce nouvel fleur tout frais
    return nouv;
}

// Dessiner fleur sur la bitmap bmp
void dessinerfleur(BITMAP *bmp,t_fleur*fleur)
{
    draw_sprite(bmp,fleur->img,fleur->x,fleur->y);
}
