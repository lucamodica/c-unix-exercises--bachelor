#include <stdio.h>

char locate_char();

int main(){
    //Applying function
    locate_char();
}


char locate_char(){

    char c;
    char *answer = NULL;
    
    printf("Inserire il carattere: ");
    scanf("%c",&c);

    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')){
        answer = "una lettera dell'alfabeto";
    }
    else if (c >= '0' && c <= '9'){
        answer = "un numero";
    }
    else{
        answer = "non alfanumerico";
    }

    printf("Il carattere che hai inserito e' %s.", answer);
}