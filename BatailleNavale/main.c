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
    int x,y,k = 0;
    printf("\n");
    printf("    ");
    for(k = 0; k < 8; k++){
        printf("  %d    ", k);
    }
    printf("\n");
    printf("\n");
    for(y = 0 ; y < 8; y++) {
        printf(" %d ", y);
        for(x = 0 ; x < 8; x++){
            switch (tableau[y][x]) {
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

/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
//La fonction renvoie 1 si il y a un bateau sur la case
int verifieCase (int tbJoueur[8][8], int posXBateau, int posYBateau)
{
    if(tbJoueur[posYBateau][posXBateau] != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// Retourne 1 si il y a un bateau dans le champs de placement du bateau
int verifieBateau(int tbJoueur[8][8], int posXBateau, int posYBateau, int sensbateau, int tailleBateau)
{
    int i;
    int outvar = 0;// si outvar 1 -- > Il y a quelque chose
    switch (sensbateau)
    {
       case 1:
           for(i=posYBateau; i <= posXBateau + tailleBateau; i++)
           {
               if (verifieCase(tbJoueur, posXBateau, i)==1)
               {
                   outvar = 1;
                   break;
               }
               else
               {
                   outvar = 0;
               }
           }
           break;
           
       case 2:
           for(i=posYBateau; i <= posYBateau+tailleBateau; i++)
           {
               if (verifieCase(tbJoueur, i, posXBateau) ==1)
               {
                   outvar = 1;
                   break;
               }
               else
               {
                   outvar = 0;
               }
           }
           break;
    }
    return outvar;
}
/*-----------------------------------------------------------------------*/

// MAIN
int main(int argc, const char * argv[]) {
    
    // Initialiser les variables du jeu
    int choix = 1;
    int nbTours = 1;
    int nbToursMax = 30;
    int tbJoueur1[8][8] = {0};
    int tbJoueur2[8][8] = {0};
    
    // Creer les tableaux pour les deux joueurs
    
    // Menu principal
    do {
        printf("<<<<<<            BATAILLE NAVALE             >>>>>>");
        printf("\n1. Commencer");
        printf("\n2. Charger une partie"); //Ne fait rien
        printf("\n3. Modifier le nombre de tours maximum");
        printf("\n0. Quitter");
        printf("\n");
        printf("\nNombre de tours maximum : %d", nbToursMax);
        printf("\n");
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

