#include <stdio.h>
#define MAX_LENGTH 80

void print_after(char str1[], char str2[]);

int main(){

    //Strings
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    //Inputs
    printf("Stringa s1: ");
    fgets(s1,sizeof(s1),stdin);
    s1[MAX_LENGTH-1] = '0';
    printf("Stringa s2: ");
    fgets(s2,sizeof(s2),stdin);
    s2[MAX_LENGTH-1] = '0';

    //Result
    printf("\nNice. Ecco ora il risultato della funzione print_after(s1,s2):\n");
    print_after(s1,s2);
    
}


void print_after(char str1[], char str2[]){

    int i=0,j=0;

    for(i=0;str1[i] != '\0';i++){
        
        if(str2[j+1] == '\0'){
            printf("%c",str1[i]);
        }
        else if(str1[i] != str2[j]){
            j = 0;
        }
        else{
            j++;
        }
        
    }
    
    
}
