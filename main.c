#include <allegro.h>
#include <time.h>

#include "abeilles.h"
#include "listeAbeille.h"
#include "fleurs.h"
#include "listefleurs.h"
#include "collision.h"

int main()
{
    // Buffer
    BITMAP *page;

    // Image de fond
    BITMAP *decor;

    // initialise liste des abeilles
    t_listeAbeille*abeille=NULL;

    //initialise les fleurs
    t_listefleur*fleur=NULL;

    // Il y aura du hasard
    srand(time(NULL));

    // Lancer allegro et le mode graphique
    allegro_init();
    install_keyboard();

    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,800,600,0,0)!=0)
    {
        allegro_message("prb gfx mode");
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    // buffer
    page=create_bitmap(SCREEN_W,SCREEN_H);

    // charger image de fond
    decor=load_bitmap("decor.bmp",NULL);
    if (!decor)
    {
        allegro_message("pas pu trouver decor.bmp");
        exit(EXIT_FAILURE);
    }

    // créer l'abeille
    abeille=creerListeAbeille(8);
    fleur=creerListefleur(15);

    // BOUCLE DE JEU
    while (!key[KEY_ESC])
    {
        // effacer buffer en appliquant décor  (pas de clear_bitmap)
        blit(decor,page,0,0,0,0,SCREEN_W,SCREEN_H);

        ajouterAbeille(abeille);
        ajouterfleur(fleur);

        // bouger tout le monde
        actualiserListeAbeille(abeille);

        // afficher tout le monde
        dessinerListefleur(page,fleur);
        dessinerListeAbeille(page,abeille);

        //collision
        collisionListe(fleur,abeille);

        // afficher tout ça à l'écran
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);

        // petite temporisation
        rest(10);
    }

    return 0;
}
END_OF_MAIN();
