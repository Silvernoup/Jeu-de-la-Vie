#ifndef DEF_CONSTANTES
#define DEF_CONSTANTES

#define LARGEUR_FENETRE 1200    // Largeur de la  fenetre principale 
#define HAUTEUR_FENETRE 600     // Hauteur de la fenetre principale

#define LARGEUR_AIRE_DE_VIE 900     // Largeur de l'aire de vie
#define HAUTEUR_AIRE_DE_VIE 450     // Hauteur de l'aire de vie

#define POS_X_AIRE_DE_VIE 50   // Position en x de l'aire de vie
#define POS_Y_AIRE_DE_VIE 100     // Position en y de l'aire de vie

#define LARGEUR_BOUTON (LARGEUR_FENETRE-LARGEUR_AIRE_DE_VIE)/2   // Largeur des boutons
#define HAUTEUR_BOUTON HAUTEUR_FENETRE/20   // Hauteur des boutons

#define POS_X_BOUTON_JOUER POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE+(LARGEUR_FENETRE-(POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE)-LARGEUR_BOUTON)/2 // Position en x du bouton joeur
#define POS_Y_BOUTON_JOUER 0.45*HAUTEUR_AIRE_DE_VIE+POS_Y_AIRE_DE_VIE  // Position en y du bouton jouer
#define POS_X_BOUTON_STOP POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE+(LARGEUR_FENETRE-(POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE)-LARGEUR_BOUTON)/2  // Position en x du bouton stop
#define POS_Y_BOUTON_STOP 0.55*HAUTEUR_AIRE_DE_VIE+POS_Y_AIRE_DE_VIE   // Position en y du bouton stop
#define POS_X_BOUTON_QUITTER POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE+(LARGEUR_FENETRE-(POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE)-LARGEUR_BOUTON)/2  // Position en x du bouton quitter
#define POS_Y_BOUTON_QUITTER 0.8*HAUTEUR_AIRE_DE_VIE+POS_Y_AIRE_DE_VIE     // Position en y du bouton quitter
#define POS_X_BOUTON_RESET POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE+(LARGEUR_FENETRE-(POS_X_AIRE_DE_VIE+LARGEUR_AIRE_DE_VIE)-LARGEUR_BOUTON)/2  // Position en x du bouton reset
#define POS_Y_BOUTON_RESET 0.2*HAUTEUR_AIRE_DE_VIE+POS_Y_AIRE_DE_VIE     // Position en y du bouton reset

#define BLANC SDL_MapRGB(ecran->format, 255, 255, 255)
#define NOIR SDL_MapRGB(ecran->format, 0, 0, 0)
#define BLEU SDL_MapRGB(ecran->format, 30, 70, 127)
#define GRIS_FONCE SDL_MapRGB(ecran->format, 39,40,34)
#define GRIS SDL_MapRGB(ecran->format, 66, 66, 66)


#endif