#include <stdio.h>

#define MAX_LENGTH 256

int slength(char s[]);
//char *scut_last_word(char s[]);
//int string_is_empty(char s[]);


int main(){

    char str[MAX_LENGTH];

    printf("Inserisci Stringa: ");
    fgets(str,sizeof(str),stdin);
    printf("%s",str);

    //Results
    printf("\n1) Lunghezza della stringa: %d",slength(str));
    //printf("\n2) Stringa senza ultima parola: %s",scut_last_word(str));
    //printf("\n3) Esito stringa vuota: %d\n",string_is_empty(str));
}


int slength(char s[]){
    int cont = 0;
    for(char *c = s; *c != '\n' || *c != '\0'; c++){
        cont++;
    }
    return cont;
}

/*
char *scut_last_word(char s[]){
    int i;
    printf("\n%d",slength(s));
    for (int i = slength(s); i > 0 && s[i] != ' '; i--){
        //printf("\n%d",i);
    }
    s[i] = '\0';
    return s;
}

int string_is_empty(char s[]){
    return *s == '\n' || *s == '\0';
}
*/






