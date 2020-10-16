#include <stdio.h>
#include "string_utilities.h"

#define MAX_LENGTH 80


int main(){

    char str[MAX_LENGTH];

    printf("Inserisci Stringa: ");
    fgets(str,sizeof(str),stdin);

    //Results
    printf("\n1) Lunghezza della stringa: %d",slength(str));
    printf("\n2) Stringa senza ultima parola: %s",scut_last_word(str));
    printf("\n3) Esito stringa vuota: %d\n",string_is_empty(str));
}



