//
//  main.c
//  BatailleNavale
//
//  Created by Shan Abasse on 18/03/2021.
//

#include <stdio.h>

// FONCTIONS DU JEU

/*-----------------------------------------------------------------------*/
// Cette fonction permet d'afficher un tableau
// Arguments : tableau d'entiers
void afficheTableau (int tableau[8][8]) {
    int i,j,k = 0;
    printf("\n");
    printf("    ");
    for(k = 0; k < 8; k++){
        printf("  %d    ", k);
    }
    printf("\n");
    printf("\n");
    for(i = 0 ; i < 8; i++) {
        printf(" %d ", i);
        for(j = 0 ; j < 8; j++){
            switch (tableau[i][j]) {
                case 0: printf(" [ - ] "); break;
                // TODO: Differents cas dans le tableau
                default:
                    break;
            }
            
        }
        printf("\n");
        printf("\n");
    }
    printf("\n");
}
/*-----------------------------------------------------------------------*/


// MAIN
int main(int argc, const char * argv[]) {
    
    // Initialiser les variables du jeu
    int choix = 1;
    int nbTours = 1;
    int tbJoueur1[8][8] = {0};
    int tbJoueur2[8][8] = {0};
    
    // Creer les tableaux pour les deux joueurs
    
    // Menu principal
    do {
        printf("<<<<<<            BATAILLE NAVALE             >>>>>>");
        printf("\n1. Commencer / Continuer ");
        printf("\n2. Charger une partie"); //Ne fait rien
        printf("\n3. Sauvegarder la partie"); //Ne fait rien
        printf("\n0. Quitter");
        printf("\nVotre choix : ");
        scanf("%d",&choix );
        printf("\n");
        switch (choix) {
            case 1:
                afficheTableau(tbJoueur1);
                choix = 0;
                break;
                
            default:
                printf("Choix non actif, ou invalide");
                break;
        }
    }while (choix != 0);
    
    return 0;
}

