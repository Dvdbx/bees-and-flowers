#include "collision.h"
#include "utilitaire.h"

// G�rer collision (�ventuelle) entre une abeille et une fleur
void collision(t_fleur *fleur,t_abeille *abeille)
{
    int vx,vy,d2;

    // calcul du vecteur entre abeille et centre cible
    vx = abeille->x+abeille->tx/2 - (fleur->x+fleur->tx/2);
    vy = abeille->y+abeille->ty/2 - (fleur->y+fleur->ty/2);

    // calcul distance au carr� au centre de la cible (Pythagore)
    // (on reste sur le carr� pour �viter de calculer la racine)
    d2 = vx*vx + vy*vy;

    // si dans le disque alors
    if (( d2 < fleur->tx* fleur->tx )&&(rand()%19==0))
    {
        abeille->dx = 2*abeille->dx/3 ;
        abeille->dy = 2*abeille->dy/3 ;
    }
}

// G�rer les collisions entre les abeilles et une fleur
void collisionListe(t_listefleur*le,t_listeAbeille *la)
{
    int i;
    int j;
    // regarder pour chaque abeille...
    for (i=0; i<la->max; i++)
    {
        for(j=0; j<le->max; j++)
        {
            if ((la->tab[i]!=NULL)&&(le->tab[j]!=NULL))
                collision(le->tab[j],la->tab[i]);
        }
    }

}
