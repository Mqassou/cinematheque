#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"
#include "date.h"

void testDate(){
Date date_1, date_2;
saisirDate(&date_1);
afficherDate(&date_1);
saisirDate(&date_2);
afficherDate(&date_2);
compareDate(&date_1, &date_2);
}
