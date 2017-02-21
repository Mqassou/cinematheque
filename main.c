#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "date.h"
#include "personne.h"



int main()
{
    int choixMenu = 0;
    char saisieMenu[255];
    do
    {
        printf("=== Menu ACCUEIL ===\n\n");
        printf("0. Quitter le menu \n \n");
        printf("1. TEST 1 \n \n");
        printf("2. TEST 2 \n \n");
        printf("3. TEST 3 \n \n");
        printf(" \n \nChoisissez le test que vous souhaitez realiser ? \n \n");

     while(1)
    {
        fgets(saisieMenu, 255, stdin);
        if(sscanf(saisieMenu, "%d", &choixMenu) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

        switch(choixMenu)
        {
        case 0:
            printf("\n \n Vous souhaitez donc quitter le programme\n \n");
            break;
        case 1:
            test1();
            break;
        case 2:
            test2();
            break;
        case 3:
            test3();
            break;
        default:
            printf(" \n \n Mauvaise saisie \n \n");
            break;
        }


    }while(choixMenu!=0);

       return 0;
}
