#include <stdio.h>
#include <stdlib.h>
#include "personne.h"
#include "film.h"
#include <string.h>

Personne* saisirPersonne(Personne * p)
{
    char saisiePersonne[255];

    printf("Entrez votre nom \n");
    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%s", p->nom) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    printf("Entrez votre prenom \n");
    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%s", p->prenom) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    printf("Entrez votre nationalite \n");
    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%s", p->nationalite) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    printf("Entrez votre jour de naissance \n");
    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%d", &(p->naissance.jour)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    while(p->naissance.jour<1 || p->naissance.jour>31)
    {
        printf("Vous devez choisir un nombre compris entre 1 et 31 \n");
        while(1)
        {
            fgets(saisiePersonne, 255, stdin);
            if(sscanf(saisiePersonne, "%d", &(p->naissance.jour)) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
    }
    printf("Entrez votre mois de naissance \n");

    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%d", &(p->naissance.mois)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    while(p->naissance.mois<1 || p->naissance.mois>12)
    {
        printf("Vous devez choisir un nombre compris entre 1 et 12 \n");
        while(1)
        {
            fgets(saisiePersonne, 255, stdin);
            if(sscanf(saisiePersonne, "%d", &(p->naissance.mois)) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
    }
    printf("Entrez votre annee de naissance \n");
    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%d", &(p->naissance.annee)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    while(p->naissance.annee<1)
    {
        printf("Vous devez choisir un nombre superieur a 0 \n");
        while(1)
        {
            fgets(saisiePersonne, 255, stdin);
            if(sscanf(saisiePersonne, "%d", &(p->naissance.annee)) == 1) break;
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
    }
    printf("Entrez votre statut (0 pour realisateur et 1 pour acteur )");

    while(1)
    {
        fgets(saisiePersonne, 255, stdin);
        if(sscanf(saisiePersonne, "%d", &(p->status)) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }

    while((p->status != 0) && (p->status != 1))
    {
        printf("Vous devez choisir entre 0 pour realisateur et 1 pour acteur\n");
        while(1)
        {
            fgets(saisiePersonne, 255, stdin);
            sscanf(saisiePersonne, "%d", &(p->status));
            printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
        }
    }
    return p;
}

void afficherPersonne(const Personne * p)
{
    printf("La personne s'appelle %s %s. \nElle est de nationalite %s \nCette personne est nee le %d/%d/%d \nCette personne exerce en tant ", p->nom, p->prenom, p->nationalite, p->naissance.jour, p->naissance.mois, p->naissance.annee);
    if(p->status == 0)
    {
        printf("que realisateur \n");
    }
    else
    {
        printf("qu'acteur. \n");
    }
}

void afficherToutePersonnes(Personne *aj, Personne *rj , const int utile_pers)
{
    int i=0;
    for(i=0; i<utile_pers; i++)
    {


        if(rj[i].status == 0 && strcmp(rj[i].nom,"")!=0) //vérifie si le status correspond à un réal et que le nom existe
        {
            printf("\n\nREALISATEUR \n");
            printf("//////////////////////// \n");
            printf("Nom : %s \n", rj[i].nom);
            printf("Prenom : %s \n", rj[i].prenom);
            printf("Date de naissance: %d/%d/%d \n",  rj[i].naissance.jour, rj[i].naissance.mois, rj[i].naissance.annee);
            printf("Nationnalite : %s \n", rj[i].nationalite);
        }
    }



    for(i=0; i<utile_pers; i++)
    {
        if (aj[i].status == 1 && strcmp(aj[i].nom,"")!=0) //vérifie si le status correspond à un acteur et que le nom existe
        {
            printf("\n\nACTEUR \n");
            printf("//////////////////////// \n");
            printf("Nom : %s \n", aj[i].nom);
            printf("Prenom : %s \n", aj[i].prenom);
            printf("Date de naissance: %d/%d/%d \n",  aj[i].naissance.jour, aj[i].naissance.mois, aj[i].naissance.annee);
            printf("Nationnalite : %s \n", aj[i].nationalite);
        }

    }
    printf("//////////////////////// \n\n");

}

void recherchePersonne(Personne * p, int taille)
{
    int i;
    char nomChercher[64];
    char tab[64];
    char saisieRecherchePers[255];
    int drapeau = 1;
    printf("Entrez le nom de la personne que vous recherchez \n");

    while(1)
    {
        fgets(saisieRecherchePers, 255, stdin);
        if(sscanf(saisieRecherchePers, "%s", nomChercher) == 1) break;
        printf("Erreur votre saisie est incorrecte, veuillez recommencer\n");
    }
    maj(nomChercher);

    for(i = 0; i<taille; i++)
    {
        strcpy(tab,p[i].nom);
        maj(tab);

        if(strcmp(tab, nomChercher)== 0) // Vérifie l'existence de la personne dans chaque cases du tableau
        {
            drapeau = 0;
            break;
        }
    }


    if(drapeau == 0) //On affiche ses infos si elle existe
    {
        printf("Fiche : ");
        if(p[i].status == 0)
        {
            printf("REALISATEUR \n");
        }
        else
        {
            printf("ACTEUR \n");
        }
        printf("Nom : %s \n", p[i].nom);
        printf("Prenom : %s \n", p[i].prenom);
        printf("Date de naissance: %d/%d/%d \n",  p[i].naissance.jour, p[i].naissance.mois, p[i].naissance.annee);
        printf("Nationnalite : %s \n", p[i].nationalite);
    }
    else if(drapeau == 1)
    {
        printf("Aucune personne portant ce nom ! \n");
    }
}

void extrairePersonneFichier(Personne *liste_act,Personne *liste_rea, FILE* f,int *utile_pers)
{
    fseek(f,0,SEEK_SET);
    char tab[100];
    char caractere='a';


    while(caractere!=EOF)
    {
        fscanf(f,"%s",tab);
        caractere=fgetc(f);

        // parcours le contenu du fichier


        if(strcmp(tab,"PersonneRea")==0)
        {
            // Detection de la ligne realisateur
            // affectation des éléments réalisateur du fichier dans le tableau réalisateur
            fscanf(f,"%s",tab);

            strcpy(liste_rea[*utile_pers].nom,tab);

            fscanf(f,"%s",tab);
            strcpy(liste_rea[*utile_pers].prenom,tab);



            fscanf(f,"%d",&(liste_rea[*utile_pers].naissance.jour));
            fscanf(f,"%d",&(liste_rea[*utile_pers].naissance.mois));
            fscanf(f,"%d",&(liste_rea[*utile_pers].naissance.annee));

            fscanf(f,"%s",tab);
            strcpy(liste_rea[*utile_pers].nationalite,tab);

            fscanf(f,"%d",&(liste_rea[*utile_pers].status));

            *utile_pers=*utile_pers+1;
        }

        else if(strcmp(tab,"PersonneAct")==0)
        {
            // Detection de la ligne acteur
            // affectation des éléments acteur du fichier dans le tableau acteur

            fscanf(f,"%s",tab);

            strcpy(liste_act[*utile_pers].nom,tab);

            fscanf(f,"%s",tab);
            strcpy(liste_act[*utile_pers].prenom,tab);



            fscanf(f,"%d",&(liste_act[*utile_pers].naissance.jour));
            fscanf(f,"%d",&(liste_act[*utile_pers].naissance.mois));
            fscanf(f,"%d",&(liste_act[*utile_pers].naissance.annee));

            fscanf(f,"%s",tab);
            strcpy(liste_act[*utile_pers].nationalite,tab);

            fscanf(f,"%d",&(liste_act[*utile_pers].status));

            *utile_pers=*utile_pers+1;

        }
    }
    return;


}

void saisirPersonneFichier(FILE*f, const Personne *p)
{
    f=fopen("test_fichier.txt","a");

//insère un acteur dans le fichier
    if(strcmp(p->nom,"") && p->status==1 )
    {
        fprintf(f,"\nPersonneAct %s %s %d %d %d %s %d",p->nom,p->prenom,p->naissance.jour,p->naissance.mois,p->naissance.annee,p->nationalite,p->status);
    }
//insère un realisateur dans le fichier
    else if(strcmp(p->nom,"") && p->status==0 )
    {
        fprintf(f,"\nPersonneRea %s %s %d %d %d %s %d",p->nom,p->prenom,p->naissance.jour,p->naissance.mois,p->naissance.annee,p->nationalite,p->status);
    }

    return;
}
