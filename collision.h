#ifndef COLLISION_H_INCLUDED
#define COLLISION_H_INCLUDED

#include "listeAbeille.h"

#include "listefleurs.h"

// G�rer collision (�ventuelle) entre un abeille (un tir) et un fleur
void collision(t_fleur *fleur,t_abeille *abeille);

// G�rer les collisions entre les abeilles (tous les tirs) et un fleur
void collisionListe(t_listefleur *fleur,t_listeAbeille *la);


#endif // COLLISION_H_INCLUDED
