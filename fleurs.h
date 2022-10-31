#ifndef FLEURS_H_INCLUDED
#define FLEURS_H_INCLUDED

#include <allegro.h>

// chaque fleur
typedef struct fleur
{
    // coordonnée (du coin sup. gauche)
    float x, y;

    // Bitmap
    BITMAP *img;

    //taille des bitmaps
    int tx, ty;

} t_fleur;

/*********************/
/*     PROTOTYPES    */
/*********************/

// Allouer et initialiser une fleur
//   ( à adapter selon besoins )
t_fleur * creerfleur();

// Dessiner une abeille sur la bitmap bmp
void dessinerfleur(BITMAP *bmp,t_fleur *fleur);


#endif // FLEURS_H_INCLUDED
