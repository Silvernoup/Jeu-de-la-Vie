#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>

#include "constantes.h"


int main ( int argc, char** argv )
{
    TTF_Init();
    SDL_Surface *ecran = NULL;
    SDL_Surface *texte = NULL;
    TTF_Font *police = NULL;

    // initialize SDL video
if (SDL_Init(SDL_INIT_VIDEO) == -1) // Démarrage de la SDL. Si erreur :
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError()); // Écriture de l'ejrreur
        exit(EXIT_FAILURE);                                                          // On quitte le programme
    }

    putenv("SDL_VIDEO_WINDOW_POS=center"); //pour centrer la fenêtre
    ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (ecran == NULL)
    {
        fprintf(stderr, "Erreur dans le chargement du mode video : %s\n", SDL_GetError()); // Écriture de l'erreur
        exit(EXIT_FAILURE);                                                                // On quitte le programme
    }

    police = TTF_OpenFont("Ubuntu-C.ttf",40);
    SDL_Color couleurNoire = {0, 0, 0};
    texte = TTF_RenderText_Blended(police, "Jeu de la Vie", couleurNoire);
    
    SDL_Rect pos;
    pos.x = (ecran->w)/2 - (texte->w)/2;
    pos.y = (ecran->h)/2 - (texte->h)/2;
    SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));
    SDL_BlitSurface(texte, NULL, ecran, &pos);

    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
            case SDL_QUIT:
                done = true;
                break;

                // check for keypresses
            case SDL_KEYDOWN:
                {
                    // exit if ESCAPE is pressed
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        done = true;
                    break;
                }
            } // end switch
        } // end of message processing

        // DRAWING ENDS HERE

        // finally, update the screen :)
        SDL_Flip(ecran);
    } // end main loop

    
    TTF_CloseFont(police);
    TTF_Quit();

    SDL_FreeSurface(texte);
    SDL_Quit(); // Fermeture de la SDL
     
    return EXIT_SUCCESS;
}
