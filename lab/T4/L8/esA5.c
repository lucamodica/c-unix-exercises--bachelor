#include <stdio.h>

#define MAX_LENGTH 100

void count_char(char str[]);


int main(){

    //String
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

    //Arrays where register records
    char chars[MAX_LENGTH];
    int times[MAX_LENGTH];

    //Setting the first character in chars[]
    chars[0] = '\0';

    //Recording characters
    for(i=0;str[i] != '\0';i++){
        
        //Checking for the character...
        //(notice that is case insensitive)
        while ( str[i] != chars[j] && str[i]+32 != chars[j] && chars[j] != '\0'){ 
            j++; 
        }
        
        //If is already registered, the times attr will be increased
        if(str[i] == chars[j] || str[i]+32 == chars[j]){
            times[j]++;
        }
        //If the char at that position is '\0',
        //it means that is a new character to be registered
        if(chars[j] == '\0'){
            chars[j+1] = chars[j];
            if(str[i] >= 'A' && str[i] <= 'Z'){ chars[j] = str[i]+32; }
            else{ chars[j] = str[i]; }
            times[j] = 1;
        }
        j = 0;

        //if(str[i] >= 'A' && str[i] <= 'Z'){ printf("%c\n",str[i]+32); }

    }

    //Printing the recordings as an histogram 
    for (i = 0; chars[i+1] != '\0'; i++)
    {
        //First the character
        printf("%c: ",chars[i]);

        //Then the times
        for(j = 0; j < times[i]; j++){
            printf("*");
        }

        //To the next character found
        printf("\n");

    }
    

}
