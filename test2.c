#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "personne.h"
#include "film.h"
#include "date.h"
#define TAILLE_MAX 2

void test2()
{
    Personne * listePersonneAct=(Personne *)malloc(TAILLE_MAX * sizeof(Personne));
    Personne * listePersonneRea=(Personne *)malloc(TAILLE_MAX * sizeof(Personne));
    Film * listeFilm=(Film *)malloc(TAILLE_MAX * sizeof(Film));
    int utile_pers=0;
    int utile_film=0;
    int testStatut=0;
    int selection=0;
    char saisieTest2[255];



    //system("cls");
    do{
    printf("=== Menu TEST 2 ===\n\n");
    printf("0. Quitter le menu \n");
    printf("1. Ajouter des personnes\n");
    printf("2. Ajouter des films \n");
    printf("3. Afficher une filmographie\n");
    printf("4. Afficher tous les films\n");
    printf("5. Rechercher un film selon son titre \n");
    printf("6. Rechercher un film selon son annee de sortie \n");
    printf("7. Rechercher tous les films anterieurs a une annee \n");
    printf("8. Rechercher tous les films appartenant à un genre \n");
    printf("9. Rechercher un film selon plusieurs criteres \n");
    printf("10. Modifier un film \n");
    printf("11. Supprimer un film \n");
    printf("12. Rechercher une personne \n\n");
    printf("Que souhaitez-vous faire ? \n \n");



     while(1)
    {
        fgets(saisieTest2, 255, stdin);
        if(sscanf(saisieTest2, "%d", &selection) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    switch(selection)
    {
        case 0:
        printf("\n \nVous souhaitez donc quitter le programme\n \n");
        break;
        case 1:
            printf("Allez vous saisir des realisateurs ou des acteurs ? (0 pour realisateur et 1 pour acteur) \n");
                     while(1)
                                {
                                    fgets(saisieTest2, 255, stdin);
                                    if(sscanf(saisieTest2, "%d", &testStatut) == 1) break;
                                    printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                                }
                    while((testStatut!=0) && (testStatut!=1))
                    {
                        printf("Vous devez uniquement choisir 1 (acteur) ou 0 (realisateur)\n");
                    }

            if(testStatut==1)
            {
                    saisirPersonne(listePersonneAct+utile_pers);
                    afficherPersonne(listePersonneAct+utile_pers);
            }
            else
            {

                    saisirPersonne(listePersonneRea+utile_pers);
                    afficherPersonne(listePersonneRea+utile_pers);
            }
              utile_pers=utile_pers+1;

               if(utile_pers+1>=TAILLE_MAX){
                listePersonneAct=(Personne *)realloc(listePersonneAct,utile_pers+1 * sizeof(Personne));
                listePersonneRea=(Personne *)realloc(listePersonneRea,utile_pers+1 * sizeof(Personne));
                }
            break;

        case 2:
            /*
            printf("Combien de film voulez-vous saisir? \n");
                do
                    {
                        scanf("%d", &utile_film);
                    }
                    while(utile_film <= 0);

                for(i=0; i<utile_film; i++)
                    {*/


                       saisirFilm(listeFilm,listePersonneAct,listePersonneRea,&utile_film, &utile_pers);
                        afficherFilm(listeFilm+utile_film-1);

                        if(utile_film+1>=TAILLE_MAX){
                            listeFilm=(Film *)realloc(listeFilm,utile_film+1 * sizeof(Film));
                            }
                    //}

            break;
    case 3:
        afficherToutePersonnes(listePersonneAct,listePersonneRea,utile_pers);
        filmographie(listeFilm,utile_film);
        break;

    case 4:
        afficherTousLesFilms(listeFilm, utile_film);
        break;
    case 5:
        rechercheFilmTitre(listeFilm, utile_film);
        break;
    case 6:
        rechercheFilmAnnee(listeFilm, utile_film);
        break;
    case 7:
        rechercheFilmAnneeInf(listeFilm, utile_film);
        break;
    case 8:
        rechercheFilmGenre(listeFilm, utile_film);
        break;
    case 9:
        rechercheMultiple(listeFilm, utile_film);
        break;
    case 10:
        modifierFilm(listeFilm,utile_pers, utile_film);
        break;
    case 11:
        supprimerFilm(listeFilm, &utile_film);
        break;
    case 12:

        printf("Allez vous chercher un realisateur ou un acteurs ? (0 pour realisateur et 1 pour acteur) \n");
                        fgets(saisieTest2, 255, stdin);
                        sscanf(saisieTest2, "%d", &testStatut);
             while((testStatut!=0) && (testStatut!=1))
                    {
                        printf("Vous devez uniquement choisir 0 (realisateur) ou 1 (acteur)\n");
                        fgets(saisieTest2, 255, stdin);
                        sscanf(saisieTest2, "%d", &testStatut);
                    }
         if(testStatut==1)
            {
                    recherchePersonne(listePersonneAct, utile_pers);
            }
            else
            {

                    recherchePersonne(listePersonneRea, utile_pers);
            }
            break;

    default:
        printf("\n \nMauvaise saisie\n \n");
        break;
    }
    }while(selection!=0);

free(listePersonneAct);
free(listePersonneRea);
free(listeFilm);
    return;
}
