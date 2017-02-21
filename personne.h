#ifndef personne_H
#define personne_H
#include "date.h"

typedef struct
{
int status;
Date naissance;
char nom[64];
char prenom[64];
char nationalite[64];
}Personne;

Personne* saisirPersonne(Personne * p);
/*     -- saisirPersonne--

    1 - Permet d'insérer dans un tableau une personne
    2 - Paramètres : Pointeur de type personne
    3 - Elle retourne un pointeur de type personne
*/
void saisirPersonneFichier(FILE*f, const Personne *p);
/*     -- saisirPersonneFichier--

    1 - Permet d'insérer dans le fichier les personnes qui ont été ajoutées
    2 - Paramètres : pointeur de type FILE , pointeur de type personne
    3 - Elle ne renvoie rien
*/
void afficherPersonne(const Personne * p);
/*     -- afficherPersonne--

    1 - Permet d'afficher une personne stockée dans un tableau de personne
    2 - Paramètres : pointeur de type Personne constant car on ne le modifie pas puisque c'est une fonction d'affichage
    3 - Elle ne renvoie rien
*/
void testPersonne();
void recherchePersonne(Personne * p, int taille);
/*     -- recherchePersonne--

    1 - Permet chercher une personne dans un tableau de personne
    2 - Paramètres : pointeur de type Personne + un entier contenant la taille puisqu'il faut parcourir un tableau de personne pour trouver une personne spécifique
    3 - Elle ne renvoie rien
*/
void afficherToutePersonnes(Personne *aj, Personne *rj , const int utile_pers);
/*     -- afficherToutePersonnes--

    1 - Permet d'afficher toute les personnes stockée dans des tableaux (un tableau d'acteur et un tableau de realisateur ceci dans le cadre de la consigne).
    2 - Paramètres : 2 pointeurs de type Personne (un poutr acteur et un pour réalisateur) + en entier contenant la taille utile puisqu'il faut parcourir des tableaux de personnes et il est constant puisqu'on ne le modifie pas
    3 - Elle ne renvoie rien
*/
void extrairePersonneFichier(Personne *liste_act,Personne *liste_rea, FILE* f,int *utile_pers);
/*     -- extrairePersonneFichier--

    1 - Permet d'insérer dans le tableau acteur et réalisateur, les personnes
        contenues dans le fichier en fonction de leur status
    2 - Paramètres : pointeur de type FILE + tableau acteur + tableau réalisateur
        + taille utile personne
    3 - Elle ne renvoie rien
*/
#endif
