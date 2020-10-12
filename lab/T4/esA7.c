#include <stdio.h>

#define MAX_LENGTH 256

int slength(char s[]);
char *scut_last_word(char s[]);
int string_is_empty(char s[]);


int main(){

    char str[MAX_LENGTH];

    printf("Inserisci Stringa: ");
    scanf('%s',&str);

    //Results
    printf("\n1) Lunghezza della stringa: %d",slength(str));
    printf("sfhdsihvidhdi");
}


int slength(char s[]){
    int cont = 0;
    for(char *c = s; *c != '\0'; c++){
        cont++;
    }
    return cont;
}

char *scut_last_word(char s[]){

}

int string_is_empty(char s[]){
    
}



