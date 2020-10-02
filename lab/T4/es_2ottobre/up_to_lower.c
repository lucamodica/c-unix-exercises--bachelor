#include <stdio.h>

char *p = NULL;
char *s = "Hello WoRLd! Today's temperature is 34C";

int up_to_lower(char *);

int main(){

    p = s;
    printf("In questo programma, verra' stampata la stringa \n\"%s\"", s);
    //printf("%s",s);
    printf("\nsolo con lettere minuscole.\n");

    //Applying function
    printf("\n\nEsito operazione: \n (%d)", up_to_lower(p));
}


int up_to_lower(char *str){

    int check = -1;
    int i = 0;
    if(str != NULL){
        while (*(str+i) != '\0'){
            char cr = *(str+i);
            if(cr > 64 && cr < 91){
                cr += 32;
            }
            printf("%c",cr);
            i++;
        }
        check = 0;
    }
    return check;
    
}
