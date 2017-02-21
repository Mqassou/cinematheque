#ifndef film_H
#define film_H
#include "personne.h"



typedef enum genre
{
AUCUN,
ACTION,
HORREUR,
COMEDIE,
DOCUMENTAIRE,
POLICIER,
DRAME,
ANIMATION,
SCIENCE_FICTION
}Genre;

typedef struct film
{
    int duree;
    int genre;
    int annee;
    char titre[64];
    Personne realisateur;
    Personne acteur[4];


}Film;

//FONCTION POUR LA SAISIE
void saisirFilm(Film *p, Personne *pers_act,Personne *pers_rea, int *utile_film, int *utile_pers);
/*     -- saisirFilm--

    1 - Permet de saisir un film dans le tableau film
    2 - Paramètres : tableau de film + taille utile film + taille utile personne
                    + tableau acteur + tableau realisateur
    3 - Elle ne renvoie rien
*/
int existePersonne(Personne * p, char *c,int utile_pers);
/*     -- existePersonne--

    1 - Permet de  savoir si une personne a été déjà enregistrée
    2 - Paramètres : pointeur de type personne + chaine de caractère+ taille utile personne

    3 - Elle renvoie 0 si la personne est déjà enregistrée et 1 dans le cas
        contraire
*/
void genre(const int g);
/*     -- genre--

    1 - Permet d'afficher le genre du film
    2 - Paramètres : une variable de type int
    3 - Elle ne renvoie rien
*/
void maj(char *p);

/*     -- maj--

    1 - Permet  de mettre en majuscule, la chaine de caractère passée en paramètre
    2 - Paramètres : chaine de caractère
    3 - Elle ne renvoie rien
*/
int detectActeur(Film * f, char * nom, int taille);
/*     -- detectActeur--

    1 - Permet de savoir si un acteur n'est pas enregistrée dans plus de 10 films
    2 - Paramètres :pointeur de type film, taille utile film
    3 - Elle renvoie 1 si l'acteur a plus de 10 films et 0 si il a moins de 10films
*/
int detectReal(Film * f, char * nom, int taille);
/*     -- detectReal--

    1 - Permet de savoir si un realisateur n'est pas enregistrée dans plus de 5 films
    2 - Paramètres :pointeur de type film, taille utile film
    3 - Elle renvoie 1 si le realisateur a plus de 5 films et 0 si il a moins de 5 films
*/

//FONCTION DE RECHERCHE

Film* rechercheFilmTitre( Film *p,int utile);


/*     -- rechercheFilmTitre--

    1 - Permet de rechercher un film par son titre
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle renvoie l'adresse du film qui a été trouvé, pour le fonctionnement
        de la fonction modifierFilm
*/
void rechercheFilmAnnee(const Film *p,int utile);
/*     -- rechercheFilmAnnee--

    1 - Permet de rechercher un film par son année
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle ne renvoie rien
*/
void rechercheFilmAnneeInf(const Film *p,int utile);
/*     -- rechercheFilmAnneeInf--

    1 - Permet de rechercher les films dont l'année est inférieur à une année donnée
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle ne renvoie rien
*/
void rechercheFilmGenre(const Film *p,int utile);
/*     -- rechercheFilmGenre--

    1 - Permet de rechercher un film par son genre
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle ne renvoie rien
*/
void rechercheMultiple(const Film *p, int utile);
/*     -- rechercheMultiple--

    1 - Permet de rechercher un film en fonctions de plusieurs critères
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle ne renvoie rien
*/


//FONCTION D'AFFICHAGE
void afficherTousLesFilms(const Film *p, const int utile_film);

/*     -- afficherTousLesFilms--

    1 - Permet  d'afficher tous les films stocké dansle tableau de film
    2 - Paramètres : tableau de film + taille utile du tableau film
    3 - Elle ne renvoie rien
*/
void afficherFilm(const Film *p);

/*     -- afficherFilm--

    1 - Permet  d'afficher un film en particulier
    2 - Paramètre : tableau de film
    3 - Elle ne renvoie rien
*/
void filmographie(Film * f, int taille);

/*     -- filmographie--

    1 - Permet  d'afficher la filmographie d'un acteur
    2 - Paramètre : tableau de film + entier contenant la taille du tableau de film à parcourir
    3 - Elle ne renvoie rien
*/

//FONCTION QUI MODIFIE UN FILM

void  modifierFilm(Film *p, const int utile_pers, const int utile_film);

/*     -- modifierFilm--

    1 - Permet de modifier les différents champs d'un film
    2 - Paramètres : tableau de film + taille utile  personne + taille utile film
    3 - Elle ne renvoie rien
*/


//FONCTION POUR LES FICHIERS

void supprimerFilm(Film * f, int * tailleFilm);

/*     -- supprimerFilm--

    1 - Permet de supprimer un film dans un tableau de film
    2 - Paramètres : tableau de film + taille utile film de type pointeur puisque la taille sera modifiée après la suppression d'un film
    3 - Elle ne renvoie rien
*/

void saisirFilmFichier(FILE* f, const Film *p,int utile_pers);
/*     -- saisirFilmFichier--

    1 - Permet de saisir un film dans un fichier
    2 - Paramètres : pointeur de type FILE + tableau de film + taille utile  personne
    3 - Elle ne renvoie rien
*/
void majFichier(FILE* f, int utile_film, int utile_pers, Personne *liste_acteur, Personne *liste_realisateur, Film *liste_film);
/*     -- majFichier--

    1 - Permet  mettre à jour toutes les modifications dans le fichier.
    2 - Paramètres : pointeur de type FILE + taille utile personne + taille utile film
                    + tableau acteur + tableau réalisateur + tableau film
    3 - Elle ne renvoie rien
*/
void extraireFilmFichier(Film *f, FILE* p,int *utile_film);
/*     -- extraireFilmFichier--

    1 - Permet d'insérer dans le tableau film, les films qui sont dans le fichier
    2 - Paramètres : pointeur de type FILE + tableau de film + taille utile film
    3 - Elle ne renvoie rien
*/

#endif

