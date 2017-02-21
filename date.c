#include <stdio.h>
#include <stdlib.h>
#include "date.h"

void saisirDate(Date * d)
{
    printf("Entrez votre jour de naissance \n");
    scanf("%d", &(d->jour));
    printf("Entrez votre mois de naissance \n");
    scanf("%d", &(d->mois));
    printf("Entrez votre annee de naissance \n");
    scanf("%d", &(d->annee));
}

void afficherDate(const Date * d)
{
    printf("Vous etes ne(e) le %d/%d/%d \n \n \n ", d->jour, d->mois, d->annee);
}

void compareDate(Date * d1, Date * d2)
{
    if ((d1->jour == d2->jour) && (d1->mois == d2->mois) && (d1->annee == d2->annee))
        printf("Les deux personnes sont nee le meme jour \n \n");
    else
        printf("Les deux dates sont differentes \n \n");
}
