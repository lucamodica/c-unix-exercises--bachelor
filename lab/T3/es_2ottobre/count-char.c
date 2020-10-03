#include <stdio.h>
#define MAX_LENGTH 80

void count_char(char str[]);

struct counter
{
    int chars[MAX_LENGTH];
    int times[MAX_LENGTH];
};


int main(){

    //Strings
    char s[MAX_LENGTH];

    //Inputs
    printf("Stringa s: ");
    fgets(s,sizeof(s),stdin);

    //Result
    printf("\nNice. Ecco ora il risultato della funzione count_char(s):\n");
    count_char(s);
    
}


void count_char(char str[]){

    int i=0,j=0;

    //Struct where register records
    struct counter c;
    c.chars[0] = '\0';

    //Recording characters
    for(i=0;str[i] != '\0';i++){
        
        while (str[i] != c.chars[j] && c.chars[j] != '\0'){ j++; }
        
        //If is already registered, the times attr will be increased
        if(str[i] == c.chars[j]){
            c.times[j]++;
        }
        //If the char at that position is '\0',
        //it means that is a new character to be registered
        if(c.chars[j] == '\0'){
            c.chars[j+1] = c.chars[j];
            c.chars[j] = str[i];
            c.times[j] = 1;
        }
        j = 0;
        
    }

    //Printing the counter
    for(j=0;c.chars[j+1] != '\0';j++){

        printf("%d, %c \n", c.times[j], c.chars[j]);

    }

}
