#include <stdio.h>

#define MAX_LENGTH 80

void read_line(char *s);

int main(){

    char str[MAX_LENGTH];

    while(str[0] != '\n' && str[0] != '\0'){

        //Input line
        printf("Inserisci una linea: \n");
        printf("> ");
        fgets(str,MAX_LENGTH,stdin);

        //Print dimension of each string in the line
        if(str[0] != '\n' && str[0] != '\0'){
            printf("Le dimensioni delle parole inserite e': \n");
            printf("> ");
            read_line(str);
        }
        printf("\n");

    }
    
    printf("Programma terminato!\n");
}

void read_line(char s[]){

    int count = 0;
    for (int i=0; s[i] != '\n' && s[i] != '\0'; i++){
        count = (s[i] >= '!' && s[i] <= '~')? ++count : count;
        if ( (s[i] == ' ' || s[i+1] == '\n' || s[i+1] == '\0' ) && count > 0){
            printf("%d  ",count);
            count = 0;
        }
    }
    
}
