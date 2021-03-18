//
//  main.c
//  BatailleNavale
//
//  Created by Shan Abasse on 18/03/2021.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    // Initialiser les variables du jeu
    int choix = 1;
    int nbTours = 1;
    int tbJoueur1[8][8];
    int tbJoueur2[8][8];
    
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
                <#statements#>
                break;
                
            default:
                printf("Choix non actif, ou invalide");
                break;
        }
    }while (choix != 0);
    
    return 0;
}



