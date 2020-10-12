#include <stdio.h>

#define MAX_LENGTH 80

int slength(char s[]);
char *scut_last_word(char s[]);
int string_is_empty(char s[]);


int main(){

    char str[MAX_LENGTH];

    printf("Inserisci Stringa: ");
    fgets(str,sizeof(str),stdin);

    //Results
    printf("\n1) Lunghezza della stringa: %d",slength(str));
    printf("\n2) Stringa senza ultima parola: %s",scut_last_word(str));
    printf("\n3) Esito stringa vuota: %d\n",string_is_empty(str));
}


int slength(char s[]){
    int i;
    for(i=0; (*(s + i) != '\0') && (*(s + i) != '\n'); i++){  }
    return i;
}

char *scut_last_word(char s[]){
    int i;
    for (i = slength(s); i > 0 && s[i] != ' '; i--){}
    s[i] = '\0';
    return s;
}

int string_is_empty(char s[]){
    return *s == '\n' || *s == '\0';
}






