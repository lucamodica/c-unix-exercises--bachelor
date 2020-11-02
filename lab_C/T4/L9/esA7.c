#include <stdio.h>
#include "string_utilities.h"

#define MAX_LENGTH 80


int main(){

    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char test_c = 'c';

    printf("Inserisci stringa1: ");
    fgets(str1,MAX_LENGTH,stdin);
    printf("Inserisci stringa2: ");
    fgets(str2,MAX_LENGTH,stdin);

    //Results
    printf("\n1) Esito verifica della stringa1 palindroma: %d",string_is_palindrome(str1));
    printf("\n2) Esito confronto stringa1 e stringa2: %d",string_compare(str1,str2));
    string_wipe_whitespaces(str1);
    printf("\n3) Stringa1 senza spazi: %s",str1);
    printf("\n4) Occorrenze di %c nella stringa2: %d\n",test_c,string_how_many(test_c,str2));
}

