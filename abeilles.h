#ifndef ABEILLES_H_INCLUDED
#define ABEILLES_H_INCLUDED
#define NIMAGE 21
#include <allegro.h>

// chaque abeilles qui se déplace
typedef struct abeille
{
    // coordonnée (du coin sup. gauche)
    float x, y;

    // vecteur deplacement
    float dx, dy;

    // Gestion de l'enchainement des images de la séquence
    // indice de l'image courante
    int imgcourante;
    // on passe à l'image suivante une fois tous les tmpimg
    int cptimg, tmpimg;

    // Séquence d'animation
    BITMAP *img[NIMAGE];

    //taille des bitmaps
    int tx, ty;

} t_abeille;

/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser une abeille
//   ( à adapter selon besoins )
t_abeille * creerAbeille();

// Actualiser une abeille (bouger ...)
void actualiserAbeille(t_abeille *abeille);

// Dessiner une abeille sur la bitmap bmp
void dessinerAbeille(BITMAP *bmp,t_abeille *abeille);

#endif // ABEILLES_H_INCLUDED
