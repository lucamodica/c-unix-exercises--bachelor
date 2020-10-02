#include <stdio.h>

#define MAX_LENGTH 80

int print_after(char*,char*);

int main(){
    
    //Strings
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];

    //Useful counters
    int i = 0;

    //Strings inputs
    printf("Inserire la prima stringa: \n");
    fgets(s1,sizeof(s1),stdin);
    printf("s1 = %s",s1);

    printf("Inserire la seconda stringa: \n");
    fgets(s2,sizeof(s2),stdin);
    printf("s2 = %s",s2);


    printf("\nStringa dopo la funzione print_after(s1,s2): \n%s", print_after(s1,s2));
}

char print_after(char *str1, char *str2){
    
}