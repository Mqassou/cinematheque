#ifndef date_H
#define date_H


typedef struct
{
int jour;
int mois;
int annee;
}Date;

void saisirDate(Date * d);
void afficherDate(const Date * d);
void compareDate(Date * d1,Date * d2);
void testDate();

#endif
