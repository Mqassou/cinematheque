#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "personne.h"
#include "film.h"
#include "date.h"
#define TAILLE_MAX 30

void test1()
{
    int utile_pers=8;
    int utile_film=6;
    int testStatut=0;
    int selection=0;
    char saisieTest1[255];

    Personne acteur[TAILLE_MAX];
    Personne realisateur[TAILLE_MAX];
    Film film[TAILLE_MAX];

    strcpy(acteur[0].nom,"cruise");
    strcpy(acteur[0].prenom,"tom");
    strcpy(acteur[0].nationalite,"americain");
    acteur[0].naissance.jour=12;
    acteur[0].naissance.mois=2;
    acteur[0].naissance.annee=1980;
    acteur[0].status=1;

    strcpy(acteur[1].nom,"depp");
    strcpy(acteur[1].prenom,"johny");
    strcpy(acteur[1].nationalite,"americain");
    acteur[1].naissance.jour=1;
    acteur[1].naissance.mois=7;
    acteur[1].naissance.annee=1985;
    acteur[1].status=1;

    strcpy(acteur[2].nom,"Bale");
    strcpy(acteur[2].prenom,"Christian");
    strcpy(acteur[2].nationalite,"US");
    acteur[2].naissance.jour=30;
    acteur[2].naissance.mois=01;
    acteur[2].naissance.annee=1974;
    acteur[2].status=1;

    strcpy(acteur[3].nom,"DiCaprio");
    strcpy(acteur[3].prenom,"Leonardo");
    strcpy(acteur[3].nationalite,"US");
    acteur[3].naissance.jour=11;
    acteur[3].naissance.mois=11;
    acteur[3].naissance.annee=1974;
    acteur[3].status=1;

    strcpy(acteur[4].nom,"Norton");
    strcpy(acteur[4].prenom,"Edward");
    strcpy(acteur[4].nationalite,"US");
    acteur[4].naissance.jour=18;
    acteur[4].naissance.mois=8;
    acteur[4].naissance.annee=1969;
    acteur[4].status=1;


    strcpy(realisateur[0].nom,"fincher");
    strcpy(realisateur[0].prenom,"david");
    strcpy(realisateur[0].nationalite,"americain");
    realisateur[0].naissance.jour=14;
    realisateur[0].naissance.mois=9;
    realisateur[0].naissance.annee=1950;
    realisateur[0].status=0;

    strcpy(realisateur[1].nom,"spielberg");
    strcpy(realisateur[1].prenom,"steven");
    strcpy(realisateur[1].nationalite,"americain");
    realisateur[1].naissance.jour=24;
    realisateur[1].naissance.mois=4;
    realisateur[1].naissance.annee=1930;
    realisateur[1].status=0;

    strcpy(realisateur[2].nom,"Nolan");
    strcpy(realisateur[2].prenom,"Christopher");
    strcpy(realisateur[2].nationalite,"US");
    realisateur[2].naissance.jour=30;
    realisateur[2].naissance.mois=07;
    realisateur[2].naissance.annee=1970;
    realisateur[2].status=0;



    strcpy(film[0].titre,"Titanic");
    film[0].realisateur=realisateur[0];
    film[0].acteur[0]=acteur[0];
    film[0].acteur[1]=acteur[3];
    film[0].annee=1994;
    film[0].duree=120;
    film[0].genre=DRAME;

    strcpy(film[1].titre,"edge of tomorrow");
    film[1].realisateur=realisateur[0];
    film[1].acteur[0]=acteur[0];
    film[1].acteur[1]=acteur[1];
    film[1].annee=2004;
    film[1].duree=140;
    film[1].genre=SCIENCE_FICTION;

    strcpy(film[2].titre,"Batman");
    film[2].realisateur=realisateur[0];
    film[2].acteur[0]=acteur[0];
    film[2].acteur[1]=acteur[1];
    film[2].annee=2005;
    film[2].duree=140;
    film[2].genre=SCIENCE_FICTION;

    strcpy(film[3].titre,"Fight Club");
    film[3].realisateur=realisateur[0];
    film[3].acteur[0]=acteur[0];
    film[3].acteur[1]=acteur[4];
    film[3].annee=1999;
    film[3].duree=140;
    film[3].genre=ACTION;

    strcpy(film[4].titre,"Inception");
    film[4].realisateur=realisateur[0];
    film[4].acteur[0]=acteur[0];
    film[4].acteur[1]=acteur[4];
    film[4].annee=1999;
    film[4].duree=140;
    film[4].genre=SCIENCE_FICTION;

    strcpy(film[5].titre,"Interstellar");
    film[5].realisateur=realisateur[0];
    film[5].acteur[0]=acteur[0];
    film[5].acteur[1]=acteur[4];
    film[5].annee=1999;
    film[5].duree=140;
    film[5].genre=SCIENCE_FICTION;

 do{
    printf("=== Menu TEST 1 ===\n\n");
    printf("0. Quitter le menu \n");
    printf("1. Afficher une filmographie\n");
    printf("2. Afficher tous les films\n");
    printf("3. Rechercher un film selon son titre \n");
    printf("4. Rechercher un film selon son annee de sortie \n");
    printf("5. Rechercher tous les films anterieurs a une annee \n");
    printf("6. Rechercher tous les films appartenant à un genre \n");
    printf("7. Rechercher un film selon plusieurs criteres \n");
    printf("8. Modifier un film \n");
    printf("9. Rechercher une personne \n\n");
    printf("Que souhaitez-vous faire ? \n \n");


     while(1)
    {
        fgets(saisieTest1, 255, stdin);
        if(sscanf(saisieTest1, "%d", &selection) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    switch(selection)
    {
        case 0:
        printf("\n \nVous souhaitez donc quitter le test 1\n \n");
        break;
        case 1:
            afficherToutePersonnes(acteur,realisateur,utile_pers);
            filmographie(film,utile_film);
            break;

        case 2:
            afficherTousLesFilms(film, utile_film);
            break;
    case 3:
            rechercheFilmTitre(film, utile_film);
            break;

    case 4:
            rechercheFilmAnnee(film, utile_film);
            break;
    case 5:
            rechercheFilmAnneeInf(film, utile_film);
            break;
    case 6:
            rechercheFilmGenre(film, utile_film);
            break;
    case 7:
        rechercheMultiple(film, utile_film);
        break;
    case 8:
        modifierFilm(film,utile_pers, utile_film);
        break;

    case 9:
        printf("Allez vous chercher un realisateur ou un acteurs ? (0 pour realisateur et 1 pour acteur) \n");
            fgets(saisieTest1, 255, stdin);
            sscanf(saisieTest1, "%d", &testStatut);
             while((testStatut!=0) && (testStatut!=1))
                    {
                        printf("Vous devez uniquement choisir 0 (realisateur) ou 1 (acteur)\n");
                        fgets(saisieTest1, 255, stdin);
                        sscanf(saisieTest1, "%d", &testStatut);
                    }
         if(testStatut==1)
            {
                    recherchePersonne(acteur, utile_pers);
            }
            else
            {

                    recherchePersonne(realisateur, utile_pers);
            }
            break;

    default:
        printf("\n \n Mauvaise saisie \n \n");
        break;
    }
    }while(selection!=0);

    return;
}

