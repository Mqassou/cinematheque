#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "personne.h"
#include "film.h"
#include "date.h"
#define TAILLE_MAX 30

/*
Personne Depp = {"Depp","Johny","US",09,06,1963,1};
Personne Nolan = {"Nolan","Christopher","US",30,07,1970,0};
Personne Bale = {"Bale","Christian","US",30,01,1974,1};
Personne Fincher = {"Fincher","David","US",28,08,1962,0};
*/

//1 TABLEAU
/*
void testPersonne(){
Personne Depp, Nolan, Bale, Fincher;
Personne listStat[TAILLE_MAX]={Depp,Nolan,Bale,Fincher};
Personne * listePersonne;
listePersonne = (Film *)malloc(30 * sizeof(Film));
listePersonne = listStat;

//Informations de James Cameron
strcpy(listePersonne[0].nom,"Depp");
strcpy(listePersonne[0].prenom,"Johny");
strcpy(listePersonne[0].nationalite,"US");
listePersonne[0].naissance.jour=9;
listePersonne[0].naissance.mois=06;
listePersonne[0].naissance.annee=1963;
listePersonne[0].status=1;
//Informations de Fincher
strcpy(listePersonne[1].nom,"Nolan");
strcpy(listePersonne[1].prenom,"Christopher");
strcpy(listePersonne[1].nationalite,"US");
listePersonne[1].naissance.jour=30;
listePersonne[1].naissance.mois=07;
listePersonne[1].naissance.annee=1970;
listePersonne[1].status=0;

//Informations de James Cameron
strcpy(listePersonne[2].nom,"Bale");
strcpy(listePersonne[2].prenom,"Christian");
strcpy(listePersonne[2].nationalite,"US");
listePersonne[2].naissance.jour=30;
listePersonne[2].naissance.mois=01;
listePersonne[2].naissance.annee=1974;
listePersonne[2].status=1;
//Informations de Fincher
strcpy(listePersonne[3].nom,"Fincher");
strcpy(listePersonne[3].prenom,"David");
strcpy(listePersonne[3].nationalite,"US");
listePersonne[3].naissance.jour=28;
listePersonne[3].naissance.mois=8;
listePersonne[3].naissance.annee=1962;
listePersonne[3].status=0;
afficherPersonne(listePersonne);
recherchePersonne(listePersonne,TAILLE_MAX);
*/

//2 TABLEAU
void testPersonne(){
Personne Depp, Nolan, Bale, Fincher;
Personne listStatAct[TAILLE_MAX]={Depp,Bale};
Personne listStatRea[TAILLE_MAX]={Nolan,Fincher};
Personne * listePersonneAct;
Personne * listePersonneRea;
listePersonneAct = (Personne *)malloc(30 * sizeof(Personne));
listePersonneRea = (Personne *)malloc(30 * sizeof(Personne));
listePersonneAct = listStatAct;
listePersonneRea = listStatRea;

//Informations de James Cameron
strcpy(listePersonneAct[0].nom,"Depp");
strcpy(listePersonneAct[0].prenom,"Johny");
strcpy(listePersonneAct[0].nationalite,"US");
listePersonneAct[0].naissance.jour=9;
listePersonneAct[0].naissance.mois=06;
listePersonneAct[0].naissance.annee=1963;
listePersonneAct[0].status=1;
//Informations de Leonardo Dicaprio
strcpy(listePersonneRea[0].nom,"Nolan");
strcpy(listePersonneRea[0].prenom,"Christopher");
strcpy(listePersonneRea[0].nationalite,"US");
listePersonneRea[0].naissance.jour=30;
listePersonneRea[0].naissance.mois=07;
listePersonneRea[0].naissance.annee=1970;
listePersonneRea[0].status=0;

//Informations de James Cameron
strcpy(listePersonneAct[1].nom,"Bale");
strcpy(listePersonneAct[1].prenom,"Christian");
strcpy(listePersonneAct[1].nationalite,"US");
listePersonneAct[1].naissance.jour=30;
listePersonneAct[1].naissance.mois=01;
listePersonneAct[1].naissance.annee=1974;
listePersonneAct[1].status=1;
//Informations de Leonardo Dicaprio
strcpy(listePersonneRea[1].nom,"Fincher");
strcpy(listePersonneRea[1].prenom,"David");
strcpy(listePersonneRea[1].nationalite,"US");
listePersonneRea[1].naissance.jour=28;
listePersonneRea[1].naissance.mois=8;
listePersonneRea[1].naissance.annee=1962;
listePersonneRea[1].status=0;

recherchePersonne(listePersonneAct,TAILLE_MAX); //Test pour acteur
recherchePersonne(listePersonneRea,TAILLE_MAX); //Test pour realisateur

}
