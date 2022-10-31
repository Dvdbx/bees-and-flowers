#include <stdio.h>
#include "abeilles.h"
#include "utilitaire.h"

// Allouer et initialiser un abeille
t_abeille * creerAbeille()
{
    t_abeille *nouv;

    // Pour charger la séquence
    int i;
    char nomfichier[256];
    // Allouer
    nouv=(t_abeille *)malloc(1*sizeof(t_abeille));

    // charger les images de la séquence d'animation en fonction des vagues
    for (i=0; i<NIMAGE; i++)
    {
        sprintf(nomfichier,"abeille%d.bmp",i);
        nouv->img[i] = load_bitmap_check(nomfichier);
    }

        // pour la taille on se base sur la 1ère image de la séquence
    nouv->tx = nouv->img[0]->w;
    nouv->ty = nouv->img[0]->h;

    nouv->x = rand()%(SCREEN_W-2*nouv->tx+1)+nouv->tx;
    nouv->y = rand()%(SCREEN_H-2*nouv->ty+1)+nouv->ty;
    nouv->dx=0;
    nouv->dy=0;

    nouv->imgcourante=0;
    nouv->cptimg=0;
    nouv->tmpimg=2;

    // Retourner ce nouvel abeille tout frais
    return nouv;
}

// Actualiser un abeille (bouger, sortie écran ...)
void actualiserAbeille(t_abeille *abeille)
{
// proba de changement de déplacement : une chance sur 20
    if ( rand()%19==0 )
    {
        // Nouveau vecteur déplacement
        abeille->dx = rand()%(11)-5;
        abeille->dy = rand()%(11)-5;
    }

    // contrôle des bords : ici on décide de rebondir sur les bords
    if  (  ( abeille->x < 0 && abeille->dx < 0 ) || ( abeille->x + abeille->tx > SCREEN_W && abeille->dx > 0) )
        abeille->dx = -abeille->dx;

    if  (  ( abeille->y < 0 && abeille->dy < 0 ) || ( abeille->y + abeille->ty > SCREEN_H && abeille->dy > 0) )
        abeille->dy = -abeille->dy;

    // calculer nouvelle position
    // nouvelle position = position actuelle + deplacement
    abeille->x = abeille->x + abeille->dx;
    abeille->y = abeille->y + abeille->dy;


    abeille->cptimg++;
    if (abeille->cptimg>=abeille->tmpimg)
    {
        abeille->cptimg=0;

        abeille->imgcourante++;

        // quand l'indice de l'image courante arrive à NIMAGE
        // on recommence la séquence à partir de 0
        if (abeille->imgcourante>=NIMAGE)
            abeille->imgcourante=0;
    }
}

// Dessiner abeille sur la bitmap bmp
void dessinerAbeille(BITMAP *bmp,t_abeille*abeille)
{
    draw_sprite(bmp,abeille->img[abeille->imgcourante],abeille->x,abeille->y);
}
