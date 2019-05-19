#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>

#include "constantes.h"
#include "fonctions.h"

void editeur(SDL_Surface *ecran)
{
    SDL_Surface *aireDeVie = NULL;
    SDL_Surface *boutonJouer = NULL;
    SDL_Surface *boutonStop = NULL;
    SDL_Surface *boutonQuitter = NULL;
    SDL_Surface *boutonReset = NULL;
    SDL_Rect posAireDeVie;
    posAireDeVie.x = POS_X_AIRE_DE_VIE;
    posAireDeVie.y = POS_Y_AIRE_DE_VIE;
    SDL_Rect posBoutonStop;
    posBoutonStop.x = POS_X_BOUTON_STOP;
    posBoutonStop.y = POS_Y_BOUTON_STOP;
    SDL_Rect posBoutonJouer;
    posBoutonJouer.x = POS_X_BOUTON_JOUER;
    posBoutonJouer.y = POS_Y_BOUTON_JOUER;
    SDL_Rect posboutonQuitter;
    posboutonQuitter.x = POS_X_BOUTON_QUITTER;
    posboutonQuitter.y = POS_Y_BOUTON_QUITTER;
    SDL_Rect posboutonReset;
    posboutonReset.x = POS_X_BOUTON_RESET;
    posboutonReset.y = POS_Y_BOUTON_RESET;

    aireDeVie = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_AIRE_DE_VIE, HAUTEUR_AIRE_DE_VIE, 32, 0, 0, 0, 0);
    boutonJouer = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonStop = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonQuitter = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonReset = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);

    SDL_FillRect(ecran, NULL, GRIS_FONCE);
    SDL_FillRect(aireDeVie, NULL, BLANC);
    SDL_FillRect(boutonStop, NULL, GRIS);
    SDL_FillRect(boutonJouer, NULL, GRIS);
    SDL_FillRect(boutonQuitter, NULL, GRIS);
    SDL_FillRect(boutonReset, NULL, GRIS);

    SDL_BlitSurface(aireDeVie, NULL, ecran, &posAireDeVie);
    SDL_BlitSurface(boutonJouer, NULL, ecran, &posBoutonJouer);
    SDL_BlitSurface(boutonStop, NULL, ecran, &posBoutonStop);
    SDL_BlitSurface(boutonQuitter, NULL, ecran, &posboutonQuitter);
    SDL_BlitSurface(boutonReset, NULL, ecran, &posboutonReset);

    SDL_Event event;
    int continuer = 1;

    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                }
                break;
        }
        SDL_Flip(ecran);

    }


    SDL_FreeSurface(boutonJouer);
    SDL_FreeSurface(boutonStop);
    SDL_FreeSurface(boutonQuitter);
    SDL_FreeSurface(boutonReset);
    SDL_FreeSurface(aireDeVie);
}


