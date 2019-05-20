#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "constantes.h"
#include "fonctions.h"

void editeur(SDL_Surface *ecran)
{
    TTF_Init();
    TTF_Font *police = TTF_OpenFont("Ubuntu-C.ttf",17);
    TTF_Font *policeTitre = TTF_OpenFont("Ubuntu-C.ttf",30);


    // surfaces
            // area of life
    SDL_Surface *aireDeVie = NULL;
            // button backgrounds
    SDL_Surface *boutonJouer = NULL;
    SDL_Surface *boutonStop = NULL;
    SDL_Surface *boutonQuitter = NULL;
    SDL_Surface *boutonReset = NULL;
            // button texts
    SDL_Surface *texteJouer = NULL;
    SDL_Surface *texteStop = NULL;
    SDL_Surface *texteReset = NULL;
    SDL_Surface *texteQuitter = NULL;
    SDL_Surface *texteTitre = NULL;

    SDL_Color couleurBlanche = {255, 255, 255};

    texteJouer = TTF_RenderText_Blended (police, "Jouer", couleurBlanche);
    texteStop = TTF_RenderText_Blended (police, "Stop", couleurBlanche);
    texteReset = TTF_RenderText_Blended (police, "Reinitialiser", couleurBlanche);
    texteQuitter = TTF_RenderText_Blended (police, "Quitter", couleurBlanche);
    texteTitre = TTF_RenderText_Blended (policeTitre, "Jeu de la Vie", couleurBlanche);

    // positions
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
    SDL_Rect posTexteStop;
    posTexteStop.x = POS_X_BOUTON_STOP + (LARGEUR_BOUTON-texteStop->w)/2;
    posTexteStop.y = POS_Y_BOUTON_STOP + (HAUTEUR_BOUTON-texteStop->h)/2;
    SDL_Rect posTexteJouer;
    posTexteJouer.x = POS_X_BOUTON_JOUER + (LARGEUR_BOUTON-texteJouer->w)/2;
    posTexteJouer.y = POS_Y_BOUTON_JOUER + (HAUTEUR_BOUTON-texteJouer->h)/2;
    SDL_Rect posTexteQuitter;
    posTexteQuitter.x = POS_X_BOUTON_QUITTER + (LARGEUR_BOUTON-texteQuitter->w)/2;
    posTexteQuitter.y = POS_Y_BOUTON_QUITTER + (HAUTEUR_BOUTON-texteQuitter->h)/2;
    SDL_Rect posTexteReset;
    posTexteReset.x = POS_X_BOUTON_RESET + (LARGEUR_BOUTON-texteReset->w)/2;
    posTexteReset.y = POS_Y_BOUTON_RESET + (HAUTEUR_BOUTON-texteReset->h)/2;
    SDL_Rect posTexteTitre;
    posTexteTitre.x = (LARGEUR_FENETRE-texteTitre->w)/2;
    posTexteTitre.y = POS_Y_TEXTE_TITRE;

    aireDeVie = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_AIRE_DE_VIE, HAUTEUR_AIRE_DE_VIE, 32, 0, 0, 0, 0);
    boutonJouer = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonStop = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonQuitter = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);
    boutonReset = SDL_CreateRGBSurface(SDL_HWSURFACE, LARGEUR_BOUTON, HAUTEUR_BOUTON, 32, 0, 0, 0, 0);

    SDL_FillRect(ecran, NULL, GRIS_FONCE);
    SDL_FillRect(aireDeVie, NULL, NOIR);
    SDL_FillRect(boutonStop, NULL, GRIS);
    SDL_FillRect(boutonJouer, NULL, GRIS);
    SDL_FillRect(boutonQuitter, NULL, GRIS);
    SDL_FillRect(boutonReset, NULL, GRIS);



    SDL_BlitSurface(aireDeVie, NULL, ecran, &posAireDeVie);
    SDL_BlitSurface(boutonJouer, NULL, ecran, &posBoutonJouer);
    SDL_BlitSurface(boutonStop, NULL, ecran, &posBoutonStop);
    SDL_BlitSurface(boutonQuitter, NULL, ecran, &posboutonQuitter);
    SDL_BlitSurface(boutonReset, NULL, ecran, &posboutonReset);
    SDL_BlitSurface(texteJouer, NULL, ecran, &posTexteJouer);
    SDL_BlitSurface(texteStop, NULL, ecran, &posTexteStop);
    SDL_BlitSurface(texteQuitter, NULL, ecran, &posTexteQuitter);
    SDL_BlitSurface(texteReset, NULL, ecran, &posTexteReset);
    SDL_BlitSurface(texteTitre, NULL, ecran, &posTexteTitre);
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


    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(boutonJouer);
    SDL_FreeSurface(boutonStop);
    SDL_FreeSurface(boutonQuitter);
    SDL_FreeSurface(boutonReset);
    SDL_FreeSurface(aireDeVie);
    SDL_FreeSurface(texteJouer);
    SDL_FreeSurface(texteQuitter);
    SDL_FreeSurface(texteStop);
    SDL_FreeSurface(texteReset);
}


