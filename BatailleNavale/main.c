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
                case 0: printf(" [   ] "); break;
                // TODO: Differents cas dans le tableau
                case 1: printf(" [ B ] "); break;
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
int verifieCase (int tbJoueur[8][8], int posYBateau, int posXBateau)
{
    if(tbJoueur[posYBateau][posXBateau] == 1)
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
           for(i=posYBateau; i <= posYBateau + tailleBateau; i++)
           {
               if (verifieCase(tbJoueur, i, posXBateau) == 1)
               {
                   outvar = 1;
               }
           }
           break;
           
       case 2:
           for(i=posYBateau; i <= posYBateau+tailleBateau; i++)
           {
               if (verifieCase(tbJoueur, posYBateau, i) == 1)
               {
                   outvar = 1;
               }
           }
           break;
    }
    return outvar;
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
//Cette fonction permet de placer les bateaux sur le tableau en fonction des données inscrit sur initbateau
void placeBateauprocess(int posYBateau, int posXBateau, int tableauDeJeu[8][8], int tailleBateau, int sensBateau)
{
    int i;
    if(sensBateau == 1)
    {
        for(i=posYBateau; i<(posYBateau+tailleBateau); i++)
        {
            tableauDeJeu[i][posXBateau] = 1;
        }
    }
    else if(sensBateau ==2)
    {
        for(i=posXBateau; i<((posXBateau)+tailleBateau); i++)
        {
            tableauDeJeu[posYBateau][i] = 1;
        }
    }
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
//Cette fonction permet au joueur d'entrer les coordonnées des bateaux ainsi que leurs sens
//Verifie si la valeur entrée est libre : avec VerifPointUnique
void initBateau(int tbJoueur[8][8],  int tailleBateau)
{
    int posYBateau;
    int posXBateau;
    int sensBateau;
    int vrai = 0;
    
    // Choix du sens du bateau
    do{
        printf("\n");
        printf("Entrer le sens du Bateau : \n");
        printf("1. Bas \n");
        printf("2. Droite \n");
        printf("\n");
        printf("Votre choix : ");
        scanf("%d", &sensBateau);
        if(sensBateau != 1 && sensBateau != 2 ){
            printf(" \n Mauvais choix !  Reessayez \n");
        }
    }while(sensBateau != 1 && sensBateau != 2);

    
    do{
        printf("\n");
        printf("\nEntrer la ligne du bateau(entre 0 et 7 compris): ");
        scanf("%d", &posYBateau);
        printf("\nEntrer la colonne du bateau(entre 0 et 7 compris): ");
        scanf("%d", &posXBateau);
        printf("\n");
        
        if(posYBateau >= 0 && posYBateau < 8)
        {
            if (posXBateau >= 0 && posXBateau < 8)
            {
                if (verifieBateau(tbJoueur, posYBateau, posXBateau, sensBateau, tailleBateau) == 0)
                {
                    placeBateauprocess(posYBateau, posXBateau, tbJoueur, tailleBateau, sensBateau);
                    vrai = 0;
                }
                else
                {
                    printf("Coordonnées non utilisable ! \n");
                    vrai = 1;
                }
            }
            else
            {
                printf("Entrez une colonne entre 0 et 7\n");
                vrai = 1;
            }
        }
        else
        {
            printf("Entrez une ligne entre 0 et 7\n");
            vrai = 1;
        }

    }while(vrai != 0);
}

/*-----------------------------------------------------------------------*/
void debutdepartie(int tbJoueur[8][8])
{
    for(int i=2; i <5; i++)
    {
        printf("\nPlacez vos bateaux \n");
        int numBateau = i - 1;
        printf("Bateau numéro : %d \n", numBateau);
        initBateau(tbJoueur, i);
        afficheTableau(tbJoueur);
    }
}
/*-----------------------------------------------------------------------*/
/*-----------------------------------------------------------------------*/
// MAIN
int main(int argc, const char * argv[]) {
    
    // Initialiser les variables du jeu
    int choix = 1;
    int nbTours = 0;
    int nbToursMax = 30;
    int tbJoueur1[8][8] = {0};
    int tbJoueur2[8][8] = {0};
    int nbBateauJ1 = 3;
    int nbBateauJ2 = 3;
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
                if(nbTours == 0)
                {
                    // LES DEUX JOUEURS PLACENT LES 3 BATEAUX
                    printf("\n------- JOUEUR 1 ------- \n");
                    debutdepartie(tbJoueur1);
                    afficheTableau(tbJoueur1);

                    printf("\n------- JOUEUR 2 ------- \n");
                    debutdepartie(tbJoueur2);
                    afficheTableau(tbJoueur2);
                    nbTours ++;
                    choix = 0;
                }
                else if(nbTours % 2 == 0)
                {
                    //Tour du joueur 1
                    printf("\n------- JOUEUR 1 -------\n");
                    //Implementer les tirs
                    afficheTableau(tbJoueur2);
                    nbTours ++;
                    choix = 0;
                }
                else
                {
                    //Tour du joueur 2
                    printf("\n------- JOUEUR 1 -------\n");
                    nbTours ++;
                    choix = 0;
                }
                break;
                
            default:
                printf("\nChoix non actif, ou invalide\n");
                break;
        }
    }while (choix != 0 || nbTours == 30);
    printf("\nJeu terminer !");
    return 0;
}

