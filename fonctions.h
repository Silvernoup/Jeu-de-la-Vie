#ifndef DEF_FONCTIONS
#define DEF_FONCTIONS



void editeur(SDL_Surface *ecran);
void appliquerRegles(int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL], int cellulesEtatSuivant[][NOMBRE_CELLULE_LARGEUR_TOTAL]);
void initCelluleEtat(int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL]);
void animerCellule(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int a, int b);
void tuerCellule(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int a, int b);
void majAdv(SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL]);
void evolution (SDL_Surface *ecran, SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR], int cellulesEtatSuivant[][NOMBRE_CELLULE_LARGEUR_TOTAL],int cellulesEtat[][NOMBRE_CELLULE_LARGEUR_TOTAL]);
void initAdv(SDL_Surface *cellules[][NOMBRE_CELLULE_LARGEUR]);


#endif
