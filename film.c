#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "film.h"



//Fonction qui nous affiche le genre du film
void genre(const int g)
{
    switch(g)
    {
    case AUCUN :
        printf("Genre du film : Aucun\n");
        break;
    case ACTION :
        printf("Genre du film : Action\n");
        break;
    case HORREUR :
        printf("Genre du film : Horreur\n");
        break;
    case COMEDIE :
        printf("Genre du film : Comedie\n");
        break;
    case DOCUMENTAIRE :
        printf("Genre du film : Documentaire\n");
        break;
    case POLICIER :
        printf("Genre du film : Policier\n");
        break;
    case DRAME:
        printf("Genre du film : Drame\n");
        break;
    case ANIMATION :
        printf("Genre du film : Animation\n");
        break;
    case SCIENCE_FICTION :
        printf("Genre du film : Science_fiction\n");
        break;

    default:
        printf("Genre du film : pas de genre defini\n");
        break;
    }
}

void saisirFilm(Film *p, Personne *pers_act,Personne *pers_rea, int *utile_film, int *utile_pers)
{

    int i=0;
    int nombre=0;
    char saisieFilm[255];
    printf("Veuillez saisir le titre du film: ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%s", p[*utile_film].titre) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("\nVeuillez saisir l'annee du film: ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%d", &(p[*utile_film].annee)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("\nVeuillez saisir le nom du realisateur: ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%s", p[*utile_film].realisateur.nom) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    // Test pour savoir si le realisateurn a plus de 5 films
    if(detectReal(p,p[*utile_film].realisateur.nom,*utile_film))
    {
        printf("Vous ne pouvez ajouter davantage de film (max 5) pour %s",p[*utile_film].realisateur.nom);
        return;
    }
    // Test pour savoir si le realisateur est enregistre dans notre base de données
    else if (existePersonne(pers_rea,p[*utile_film].realisateur.nom,*utile_pers))
    {
        printf("La personne saisi n'a pas ete enregistree \n");
        printf("Nous allons proceder a son enregistrement : \n");
        saisirPersonne(pers_rea);
        *utile_pers=*utile_pers+1;

    }

    printf("\nVeuillez saisir la duree en minutes du film : ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%d", &(p[*utile_film].duree)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("\nCombien d'acteur voulez-vous saisir? : ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%d", &nombre) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    while(nombre<=0 || nombre>4)
    {
        if(nombre<=0 || nombre>4)
        {
            printf("Vous devez saisir un nombre compris entre 0 et 5 \n : ");
        }
        while(1)
        {
            fgets(saisieFilm, 255, stdin);
            if(sscanf(saisieFilm, "%d", &nombre) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }

    }

    for(i=0; i<nombre; i++)
    {
        printf("\nVeuillez saisir saisir le nom de l'acteur: ");
        while(1)
        {
            fgets(saisieFilm, 255, stdin);
            if(sscanf(saisieFilm, "%s", p[*utile_film].acteur[i].nom) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }

        // Test pour savoir si l'acteur a plus de 10 films
        if(detectActeur(p,p[*utile_film].acteur[i].nom,*utile_film))
        {
            printf("Vous ne pouvez ajouter davantage de film (max 10) pour %s",p[*utile_film].acteur[i].nom);
            return;
        }
        // Test pour savoir si l'acteur est enregistre dans notre base de données
        else if (existePersonne(pers_act,p[*utile_film].acteur[i].nom,*utile_pers))
        {
            printf("La personne saisi n'a pas ete enregistree \n");
            printf("Nous allons proceder a son enregistrement : \n");
            saisirPersonne(pers_act);
            *utile_pers=*utile_pers+1;

        }
    }

    printf("\nVeuillez saisir le numero correspondant au genre du film: ");
    printf("\n0-AUCUN\n1-ACTION\n2-HORREUR\n3-COMEDIE\n4-DOCUMENTAIRE\n5-POLICIER\n6-DRAME\n7-ANIMATION\n8-SCIENCE_FICTION\n: ");
    while(1)
    {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%d", &(p[*utile_film].genre)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    while(p[*utile_film].genre<0 || p[*utile_film].genre>8)
   {
         printf("Vous devez choisir les gens qui vous sont proposees\n");
        while(1)
            {
        fgets(saisieFilm, 255, stdin);
        if(sscanf(saisieFilm, "%d", &(p[*utile_film].genre)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }

    }
    *utile_film=*utile_film+1;

    return;
}



int existePersonne(Personne * p,char *c,int utile_pers)
{
    int i;
    char tab[64];
    char tab2[64];
    strcpy(tab,c);
    maj(tab);

    for(i = 0; i<utile_pers; i++)
    {
        strcpy(tab2,p[i].nom);
        maj(tab2);
        if(strcmp(tab2, tab) == 0)
        {
            return 0;
        }
    }
    return 1;
}



void afficherFilm(const Film *p)
{
    int i=0;
    printf("//////////////////////// \n");
    printf("Realisateur du film : %s \n\n",p->realisateur.nom);
    for(i=0; i<4; i++)
    {
        if(strcmp(p->acteur[i].nom,""))
        {
            printf("Acteur du film : %s \n\n",p->acteur[i].nom);
        }

    }

    printf("Titre du film : %s \n\n",p->titre);
    printf("Annee du film : %d \n\n",p->annee);
    printf("Duree du film : %d minutes\n\n",p->duree);
    genre(p->genre);
    printf("//////////////////////// \n\n");

}

void afficherTousLesFilms(const Film *p, const int utile_film)
{
    int i=0,j=0;

    if(utile_film==0)
    {
        printf("Il n'y a aucun film  dans la base de donnees \n\n");
    }
    for(j=0; j<utile_film ; j++)
    {

        printf("//////////////////////// \n");
        printf("Realisateur du film : %s \n\n",p[j].realisateur.nom);

        for(i=0; i<4 ; i++)
        {
            if(strcmp(p[j].acteur[i].nom,""))
            {
                printf("Acteur du film : %s\n\n",p[j].acteur[i].nom);
            }

        }

        printf("Titre du film : %s \n\n",p[j].titre);
        printf("Annee du film : %d \n\n",p[j].annee);
        printf("Duree du film : %d minutes\n\n",p[j].duree);
        genre(p[j].genre);
        printf("//////////////////////// \n\n");
    }
}

Film* rechercheFilmTitre( Film *p,int utile)
{
    char film_titre[64];
    char titre[64];
    char saisieRechFilmTitre[255];
    printf("Quel est le titre du film que vous recherchez?\n");
    while(1)
    {
        fgets(saisieRechFilmTitre, 255, stdin);
        if(sscanf(saisieRechFilmTitre, "%s", film_titre) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    maj(film_titre);// Le titre en parametre est mis en majuscule

    int i=0;
    for(i=0; i<utile; i++)
    {
        strcpy(titre,(p+i)->titre);// copie du titre dans un tableau dont la portée est locale
        maj(titre);// le tableau titre[64] est mis en majuscule
        if(strcmp(titre,film_titre)==0)
        {
            afficherFilm(p+i);
            return (p+i);
        }
    }
    printf("Le film ne figure pas dans notre base de donnees\n\n");

    return NULL;
}

void rechercheFilmAnnee(const Film *p,int utile)
{
    int annee=0;
    char saisieRechFilmAnnee[255];
    printf("A quel annee souhaitez-vous trouver votre film?\n");
    while(1)
    {
        fgets(saisieRechFilmAnnee, 255, stdin);
        if(sscanf(saisieRechFilmAnnee, "%d", &annee) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    int i=0;
    int drapeau=0;
    for(i=0; i<utile; i++)
    {
        if((p+i)->annee==annee)
        {
            afficherFilm(p+i);
            drapeau=1;
        }
    }

    if(drapeau==0)
    {
        printf("Aucun film correspondant a l'annee donne \n\n");
    }
    return;

}

void rechercheFilmAnneeInf(const Film *p,int utile)
{
    int anneeInf=0;
    char saisieRechFilmAnneeInf[255];
    printf("A quel annee souhaitez-vous afficher les films anterieur a l'annee donnee?\n");
    while(1)
    {
        fgets(saisieRechFilmAnneeInf, 255, stdin);
        if(sscanf(saisieRechFilmAnneeInf, "%d", &anneeInf) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    int i=0;
    int drapeau=0;
    for(i=0; i<utile; i++)
    {
        if((p+i)->annee<anneeInf)
        {
            afficherFilm(p+i);
            drapeau=1;
        }
    }

    if(drapeau==0)
    {
        printf("Aucun film anterieur a l'annee donne\n\n");
    }
    return;
}

void rechercheFilmGenre(const Film *p,int utile)
{
    int _genre=0;
    char saisieRechFilmGenre[255];
    printf("Quel genre de film souhaitez-vous afficher ?\n");
    printf("\n0-AUCUN\n1-ACTION\n2-HORREUR\n3-COMEDIE\n4-DOCUMENTAIRE\n5-POLICIER\n6-DRAME\n7-ANIMATION\n8-SCIENCE_FICTION\n: ");
    while(1)
        {
            fgets(saisieRechFilmGenre, 255, stdin);
            if(sscanf(saisieRechFilmGenre, "%d", &_genre) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }

   while(_genre<0 || _genre>8)
   {
         printf("Vous devez choisir les gens qui vous sont proposees\n");
        while(1)
        {
            fgets(saisieRechFilmGenre, 255, stdin);
            if(sscanf(saisieRechFilmGenre, "%d", &_genre) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
    }
    int i=0;
    int drapeau=0;
    for(i=0; i<utile; i++)
    {
        if(((p+i)->genre)==_genre)
        {
            afficherFilm(p+i);
            drapeau=1;
        }
    }
    if(drapeau==0)
    {
        printf("Aucun film  correspondant au genre donne\n\n");
    }

    return;

}


void rechercheMultiple(const Film *p, int utile)
{
    char realisateur[64];
    char realisateur_copie[64];
    char saisieRechMultiple[255];
    int annee_bas=0;
    int annee_haut=0;
    int duree=0;
    int drapeau =0;
    printf("Recherche multiple>>\n");
    printf("Tous les films de : ");
    while(1)
    {
        fgets(saisieRechMultiple, 255, stdin);
        if(sscanf(saisieRechMultiple, "%s", realisateur) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("Dont la duree en heure est superieur a : ");
    while(1)
    {
        fgets(saisieRechMultiple, 255, stdin);
        if(sscanf(saisieRechMultiple, "%d", &duree) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("Sortis entre : ");
    while(1)
    {
        fgets(saisieRechMultiple, 255, stdin);
        if(sscanf(saisieRechMultiple, "%d", &annee_bas) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    printf("et : ");
    while(1)
    {
        fgets(saisieRechMultiple, 255, stdin);
        if(sscanf(saisieRechMultiple, "%d", &annee_haut) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    printf("Tous les films de %s sortis entre %d et %d durant plus de %d heure: ------------------- \n\n",realisateur, annee_bas,annee_haut,duree);
    int i=0;

    for(i=0; i<utile; i++)
    {

        strcpy(realisateur_copie,(p+i)->realisateur.nom);
        maj(realisateur_copie);
        maj(realisateur);
        if(strcmp(realisateur_copie,realisateur)==0 && ((p+i)->annee)>=annee_bas && ((p+i)->annee)<=annee_haut && ((p+i)->duree)/60>duree)
        {
            afficherFilm(p+i);
            drapeau=1;
        }
    }

    if (drapeau==0)
    {
        printf("Pas de film correspondant aux criteres donnes\n\n");
    }
    return;


}

void filmographie(Film * f, int taille)
{
    char saisieFilmo[255];
    int i, j, l,m;
    int k,n;
    int drapeau = 1;
    int act = 1;
    int real = 1;
    int test_arret1 = 0;
    int test_arret2 = 0;
    char nomFilmo[20];
    char copieFilmo[64];
    printf("Entrez le nom de la personne dont vous souhaitez le filmographie \n");
    while(1)
    {
        fgets(saisieFilmo, 255, stdin);
        if(sscanf(saisieFilmo, "%s", nomFilmo) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    maj(nomFilmo);


    //Test de l'existence d'un acteur portant ce nom
    for(i = 0; i<taille; i++)
    {
        for(k = 0; k<4; k++)
        {
            strcpy(copieFilmo,(f+i)->acteur[k].nom);
            maj(copieFilmo);
            if(strcmp(copieFilmo, nomFilmo) == 0)
            {
                printf("Resultat : %s \n",(f+i)->acteur[k].nom);
                drapeau = 0;
                act = 0;
                break;
            }
        }
        if(drapeau == 0)
            break;
    }

    //Test de l'existence d'un realisateur portant ce nom si il n'y a pas d'acteur portnt ce nom
    if(act == 1)
        for(l = 0; l<taille; l++)
        {
            strcpy(copieFilmo,(f+l)->realisateur.nom);
            maj(copieFilmo);
            if(strcmp(copieFilmo, nomFilmo) == 0)
            {
                printf("Resultat : %s \n",(f+l)->realisateur.nom);
                drapeau = 0;
                real = 0;
                break;
            }
        }


    if(drapeau == 1)
    {
        printf(" \nAucun realisateur ou acteur portant ce nom \n \n");
        return;
    }


    //Recherche de tout les film de l'acteur portant ce nom si il existe
    if((drapeau == 0)&&(act==0))
    {
        for(j = 0; j<taille; j++)
        {
            for(n = 0; n<4; n++)
            {
                strcpy(copieFilmo,(f+j)->acteur[n].nom);
                maj(copieFilmo);
                if(strcmp(copieFilmo, nomFilmo) == 0)
                {
                    printf("%s (%d) \n",(f+j)->titre, (f+j)->annee);
                    test_arret1++;
                    /*tabRea[k] = f[j];
                    k++;*/
                }
                if (test_arret1 == 10)
                    break;
            }
        }
    }

    //Recherche de tout les film du realisateur portant ce nom si il existe
    if((drapeau == 0)&&(real==0))
    {
        for(m = 0; m<taille; m++)
        {
            strcpy(copieFilmo,(f+m)->realisateur.nom);
            maj(copieFilmo);
            if(strcmp(copieFilmo, nomFilmo) == 0)
            {
                printf("%s (%d) \n",(f+m)->titre, (f+m)->annee);
                test_arret2++;
            }
            if (test_arret2 == 5)
                break;
        }
    }

    return;

}



int detectReal(Film * f, char * nom, int taille)
{
    int cptr=0; //représente le nombre de film détecter pour un realisateur
    int i;
    char tab[64];
    char tab2[64];
    strcpy(tab,nom);
    maj(tab);

    // parcours l'ensemble des films

    for(i=0; i<taille ; i++)
    {
        strcpy(tab2,(f+i)->realisateur.nom);
        maj(tab2);
        if(strcmp(tab2,tab) == 0)
        {
            cptr++;
        }
    }
    if(cptr > 5)//si le nombre de film est supérieur à 5
    {
        return 1;

    }
    else
    {
        return 0;
    }

}

int detectActeur(Film * f, char * nom, int taille)
{
    int cptr=0;//représente le nombre de film détecter pour un realisateur
    int i=0;
    int k=0;
    char tab[64];
    char tab2[64];
    strcpy(tab,nom);
    maj(tab);

    // parcours l'ensemble des films
    for(i = 0; i<taille; i++)
    {
        // parcours l'ensemble des  acteurs dans un film ( maximum 4)
        for(k = 0; k<4; k++)
        {
            strcpy(tab2,(f+i)->acteur[k].nom);
            maj(tab2);
            if(strcmp(tab2,tab) == 0)
            {
                cptr++;
            }
        }
    }
    if(cptr >=10) //si le nombre de film est supérieur à 10
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void maj(char *p)
{
    int i=0;
    // boucle qui met en majuscule chaque caractère
    while(p[i])
    {
        p[i]=toupper(p[i]);
        i++;
    }
}

void modifierFilm(Film *p, const int utile_pers, const int utile_film)
{
    int choix=0,i=0;
    char saisieModifierFilm[255];
    Film *p2=NULL;
    printf("Modification d'un film : \n\n");
    // p2 récupère l'adresse  du film qui correspond au titre que la personne aura cherché
    p2=rechercheFilmTitre(p,utile_film);

    if(p2==NULL)
    {
        return ;
    }

    printf("Voici le contenu du film que vous souhaitez modifier\n\n");
    afficherFilm(p2);
    while(1)
    {
        printf("Choisissez le numero du champ que vous souhaitez modifier?\n\n");
        printf("0 - Aucun \n1 - Realisateur \n2 - Acteur \n3 - Titre \n4 - Annee \n5 - Duree \n6 - Genre\n\nnumero saisi:");
        while(1)
        {
            fgets(saisieModifierFilm, 255, stdin);
            if(sscanf(saisieModifierFilm, "%d", &choix) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
        if(choix==0)
        {
            return;
        }

        else
        {
            while(choix>6 || choix<0)
            {
                printf("Votre choix doit etre compris entre 0 et 6 inclus\n");
                while(1)
                {
                    fgets(saisieModifierFilm, 255, stdin);
                    if(sscanf(saisieModifierFilm, "%d", &choix) == 1) break;
                    printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                }
            }

             // choix des champs à modifier

            printf("\n\n");
            switch(choix)
            {
            case 1:
                printf("nom du realisateur : \n");
                while(1)
                {
                    fgets(saisieModifierFilm, 255, stdin);
                    if(sscanf(saisieModifierFilm, "%s", p2->realisateur.nom) == 1) break;
                    printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                }
                break;
            case 2:
                for(i=0; i<utile_pers ; i++)
                {
                    if(strcmp(p2->acteur[i].nom,""))
                    {
                        printf("Acteur du film : %s \n\n",p2->acteur[i].nom);
                        printf("Souhaitez-vous le modifier ? 1 pour oui et 0 pour pour non\n:");
                        while(1)
                        {
                            fgets(saisieModifierFilm, 255, stdin);
                            if(sscanf(saisieModifierFilm, "%d",&choix) == 1) break;
                            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                        }
                        while(choix!=0 && choix!=1)
                        {
                            printf("Votre choix doit etre soit de 1 ou de 0 \n");
                            while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%d",&choix) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                        }
                        if(choix==0)
                        {
                            ;
                        }
                        else
                        {
                            printf("nom de l'acteur : \n");
                            while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%s",p2->acteur[0].nom) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                            printf("\n\n");
                        }
                    }

                }
                break;
            case 3:
                printf("Titre du film : \n");
                while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%s",p2->titre) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                break;
            case 4:
                printf("Annee du film : \n");
                while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%d",&(p2->annee)) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                break;
            case 5:
                printf("Duree du film  en minutes : \n");
                while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%d",&(p2->duree)) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                break;
            case 6:
                printf("Choisissez le numero correspondant au genre du film  : \n\n");
                printf("\n0-AUCUN\n1-ACTION\n2-HORREUR\n3-COMEDIE\n4-DOCUMENTAIRE\n5-POLICIER\n6-DRAME\n7-ANIMATION\n8-SCIENCE_FICTION\n: ");
                while(1)
                            {
                                fgets(saisieModifierFilm, 255, stdin);
                                if(sscanf(saisieModifierFilm, "%d",&(p2->genre)) == 1) break;
                                printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
                            }
                break;

            default:
                printf(" Vous n'avez pas selectionne un champ valide\n\n");
                break;
            }
        }
    }

}


void extraireFilmFichier(Film *f, FILE* p,int *utile_film)
{
    fseek(p,0,SEEK_SET);

    char tab[100];
    char caractere='a';
    int i=0;


    while(caractere!=EOF)
    {
        fscanf(p,"%s",tab);
        caractere=fgetc(p);
    // Parcours du fichier


        if(strcmp(tab,"Film")==0)
        { // détection de la chaine "Film", on commence à entrer les données dans le tableau film
            fscanf(p,"%s",tab);
            strcpy(f[*utile_film].realisateur.nom,tab);
            fscanf(p,"%s",tab);

            if(strcmp(tab,"Acteur")==0)
            {
                i=0;
                while(strcmp(tab,"FinActeur")!=0)
                {
                    fscanf(p,"%s",tab);
                    if(strcmp(tab,"FinActeur")!=0)
                    {
                        strcpy(f[*utile_film].acteur[i].nom,tab);
                    }

                    i++;
                }

            }


            fscanf(p,"%s",tab);
            strcpy(f[*utile_film].titre,tab);

            fscanf(p,"%d",&(f[*utile_film].annee));
            fscanf(p,"%d",&(f[*utile_film].duree));
            fscanf(p,"%d",&(f[*utile_film].genre));
            *utile_film=*utile_film+1;
        }



    }



    return;

}

void saisirFilmFichier(FILE *f, const Film *p,int utile_pers)
{
    int i=0;
    f=fopen("test_fichier.txt","a");

    fprintf(f,"\nFilm %s Acteur",p->realisateur.nom);
    //insère un film dans le fichier

    for(i=0; i<utile_pers; i++)
    {  //insère l'ensemble des acteurs si ils existent
        if(strcmp(p->acteur[i].nom,""))
        {
            fprintf(f," %s",p->acteur[i].nom);
        }

    }
    fprintf(f," FinActeur %s %d %d %d",p->titre,p->annee,p->duree,p->genre);




    return;

}

void supprimerFilm(Film * f, int * tailleFilm  )
{
    int i,j;
    int pos;
    int drapeau = 1; //Drapeau afin de vérifier l'existence du film a supprimer
    char nomSupp[64];
    char copieNomSupp[64];
    char saisieSupprFilm[255];
    printf("Entrez le nom du film que vous souhaitez supprimer \n");
    while(1)
    {
        fgets(saisieSupprFilm, 255, stdin);
        if(sscanf(saisieSupprFilm, "%s", nomSupp) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    maj(nomSupp);

    for(i=0; i < * tailleFilm; i++)
    {
        strcpy(copieNomSupp,((f+i)->titre));
        maj(copieNomSupp);
        if(strcmp(copieNomSupp, nomSupp) == 0)
        {
            pos = i;
            drapeau = 0;
            break;
        }
    }
    if(drapeau == 0)
    {
        for(j = pos; j< * tailleFilm; j++)
        {
            f[j] = f[j+1]; //On décale les éléments du tableau vers la gauche jusqu'a l'élément à supprimer, ceci afin de l'ecraser
        }
        *tailleFilm = *tailleFilm - 1; //On décrémente la taille utile d'une unité car suite au décalage des valeurs il va rester une derniere case vide
        printf("Le film a bien ete supprime \n\n");
        return;
    }
    else if(drapeau == 1)
    {
        printf("Il n'y a pas de film portant ce nom \n\n");
        return;
    }
    return;
}


void majFichier(FILE* f, int utile_film, int utile_pers,Personne *liste_acteur, Personne *liste_realisateur, Film *liste_film)
{

    f=fopen("test_fichier.txt","w");
    fprintf(f," ");
    int i=0;

      //insère tous les films dans le fichier
    for(i=0; i<utile_film; i++)
    {
        saisirFilmFichier(f,liste_film+i,utile_film);
    }
    i=0;
    //insère  tous les acteurs dans le fichier
    for(i=0; i<utile_pers; i++)
    {
        saisirPersonneFichier(f, liste_acteur+i);
    }
    i=0;

     //insère  tous les réalisateurs dans le fichier

    for(i=0; i<utile_pers; i++)
    {
        saisirPersonneFichier(f,liste_realisateur+i);
    }


    return;
}
