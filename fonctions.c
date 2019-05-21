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
    SDL_Surface *cellules[NOMBRE_CELLULE_HAUTEUR][NOMBRE_CELLULE_LARGEUR] = {NULL};
    initAdv(cellules);

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

    int cellulesEtat[NOMBRE_CELLULE_HAUTEUR_TOTAL][NOMBRE_CELLULE_LARGEUR_TOTAL] = {MORTE};
    int cellulesEtatSuivant[NOMBRE_CELLULE_HAUTEUR_TOTAL][NOMBRE_CELLULE_LARGEUR_TOTAL] = {MORTE};


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

    initCelluleEtat(cellulesEtat);
    majAdv(ecran, cellules, cellulesEtat);
    while (continuer)
    {
        SDL_WaitEvent(&event);
        switch (event.type)
        {
            int clickX = 0;
            int clickY = 0;

            case SDL_QUIT:
                continuer = 0;
                break;

            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_SPACE:
                        break;
                }
                break;

            case SDL_MOUSEBUTTONUP:
                clickY = event.button.y;
                clickX = event.button.x;
                if (clickX >= POS_X_AIRE_DE_VIE && clickX <= POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE && clickY >= POS_Y_AIRE_DE_VIE && clickY <= POS_Y_AIRE_DE_VIE+HAUTEUR_AIRE_DE_VIE)
                {

                    int cellX = 0;
                    cellX = ((clickX-POS_X_AIRE_DE_VIE) - ((clickX-POS_X_AIRE_DE_VIE) % COTE_CELLULE_IDEAL)) / COTE_CELLULE_IDEAL;
                    int cellY = 0;
                    cellY = ((clickY-POS_Y_AIRE_DE_VIE) - ((clickY-POS_Y_AIRE_DE_VIE) % COTE_CELLULE_IDEAL)) / COTE_CELLULE_IDEAL;
                    if (cellulesEtat[cellY+50][cellX+50] == MORTE) 
                    {
                        cellulesEtat[cellY+50][cellX+50] = VIVANTE;
                    }
                    else  
                    {
                        cellulesEtat[cellY+50][cellX+50] = MORTE;
                    }
                }

                if (clickX >= POS_X_BOUTON_QUITTER && clickX <= POS_X_BOUTON_QUITTER + LARGEUR_BOUTON && clickY >= POS_Y_BOUTON_QUITTER && clickY <= POS_Y_BOUTON_QUITTER + HAUTEUR_BOUTON)
                {
                    continuer = 0;
                }

                if (clickX > POS_X_BOUTON_RESET && clickX < POS_X_BOUTON_RESET + LARGEUR_BOUTON && clickY > POS_Y_BOUTON_RESET && clickY < POS_Y_BOUTON_RESET + HAUTEUR_BOUTON)
                {
                    initCelluleEtat(cellulesEtat);
                }
                break;
        }
        majAdv(ecran, cellules, cellulesEtat);
        SDL_Flip(ecran);

    }


    TTF_CloseFont(police);
    TTF_CloseFont(policeTitre);
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
    SDL_FreeSurface(texteTitre);
    int i = 0;
    int j = 0;
    for (i = 0; i < NOMBRE_CELLULE_HAUTEUR; i++)
    {
        for (j = 0; j < NOMBRE_CELLULE_LARGEUR; j++)
        {
            SDL_FreeSurface(cellules[i][j]); // Libère une surface
        }
    }

}


void evolution (SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int cellulesEtatSuivant[][NOMBRE_CELLULE_LARGEUR_TOTAL],int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL])
{
    appliquerRegles (cellulesEtat, cellulesEtatSuivant);
    majAdv(ecran, cellules, cellulesEtat);
}

void appliquerRegles(int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL], int cellulesEtatSuivant[][NOMBRE_CELLULE_LARGEUR_TOTAL])
{
    int i = 0;
    int j = 0;

    for (i = 1; i < NOMBRE_CELLULE_HAUTEUR_TOTAL - 1; i++)      // j'enlève les valeurs extremes pour ne pas gérer l'absence de cellules
    {
        for (j = 1; j < NOMBRE_CELLULE_LARGEUR_TOTAL - 1; j++)
        {
            int compteurVoisineVivante = 0;

            if (cellulesEtat[i - 1][j - 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i - 1][j] == VIVANTE)
                {                
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i - 1][j + 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i][j - 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i][j + 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i + 1][j - 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i + 1][j] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }
            if (cellulesEtat[i + 1][j + 1] == VIVANTE)
                {
                    compteurVoisineVivante += 1;
                }

            if (compteurVoisineVivante < 2 || compteurVoisineVivante > 3)
                {
                    cellulesEtatSuivant[i][j] = MORTE;
                }
            if (compteurVoisineVivante == 3)
                {
                    cellulesEtatSuivant[i][j] = VIVANTE;
                }
            if (compteurVoisineVivante == 2)
                {
                     cellulesEtatSuivant[i][j] = cellulesEtat[i][j];
                }

           // if (cellulesEtat[i][j] == cellulesEtatSuivant[i][j])    // Pour gérer la fin de l'évolution (stable)
           //     compteurFinEvolution++;
           cellulesEtat[i][j] = cellulesEtatSuivant[i][j];
        }
    }

    for (i = 1; i < NOMBRE_CELLULE_HAUTEUR_TOTAL - 1; i++)      // j'enlève les valeurs extremes pour ne pas gérer l'absence de cellules
    {
        for (j = 1; j < NOMBRE_CELLULE_LARGEUR_TOTAL - 1; j++)
        {
           cellulesEtat[i][j] = cellulesEtatSuivant[i][j];
        }
    } 
}

void initCelluleEtat(int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < NOMBRE_CELLULE_HAUTEUR_TOTAL; i++)
    {
        for (j = 0; j < NOMBRE_CELLULE_LARGEUR_TOTAL; j++)
        {
            cellulesEtat[i][j] = MORTE;
        }
    }
}

void majAdv(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < NOMBRE_CELLULE_HAUTEUR; i++)
    {
        for (j = 0; j < NOMBRE_CELLULE_LARGEUR; j++) // -1 car on laisse les cellules externes mortes.
        {
            if (cellulesEtat[i+50][j+50] == VIVANTE)
            {
                animerCellule(ecran, cellules, i, j);
            }
            if (cellulesEtat[i+50][j+50] == MORTE)
            {
                tuerCellule(ecran, cellules, i, j);
            }
        }
    }
}

void animerCellule(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int a, int b)
{
    SDL_Rect positionCellule;
    SDL_FillRect(cellules[a][b], NULL, COULEUR_CELLULE_VIVANTE);

    positionCellule.x = POS_X_AIRE_DE_VIE + TAILLE_MEMBRANE + (COTE_CELLULE + TAILLE_MEMBRANE) * b;
    positionCellule.y = POS_Y_AIRE_DE_VIE + TAILLE_MEMBRANE + (COTE_CELLULE + TAILLE_MEMBRANE) * a;

    SDL_BlitSurface(cellules[a][b], NULL, ecran, &positionCellule);
}

void tuerCellule(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int a, int b)
{
    SDL_Rect positionCellule;
    SDL_FillRect(cellules[a][b], NULL, COULEUR_CELLULE_MORTE);

    positionCellule.x = POS_X_AIRE_DE_VIE + TAILLE_MEMBRANE + (COTE_CELLULE + TAILLE_MEMBRANE) * b;
    positionCellule.y = POS_Y_AIRE_DE_VIE + TAILLE_MEMBRANE + (COTE_CELLULE + TAILLE_MEMBRANE) * a;

    SDL_BlitSurface(cellules[a][b], NULL, ecran, &positionCellule);
}

void initAdv(SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR])
{
    int i = 0;
    int j = 0;
    for (i = 0; i < NOMBRE_CELLULE_HAUTEUR; i++)
    {
        for (j = 0; j < NOMBRE_CELLULE_LARGEUR; j++)
        {
            cellules[i][j] = SDL_CreateRGBSurface(SDL_HWSURFACE, COTE_CELLULE, COTE_CELLULE, 32, 0, 0, 0, 0); // Crée une surface
        }
    }
}
