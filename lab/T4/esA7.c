#include <stdio.h>

#define MAX_LENGTH 80

int slength(char s[]);
int string_is_palindrome(char s[]);
int string_compare(char s1[],char s2[]);
void string_wipe_whitespaces(char s[]);
int string_how_many(char c,char s[]);


int main(){

    char str1[MAX_LENGTH];
    char str2[MAX_LENGTH];
    char test_c = 'c';

    printf("Inserisci stringa1: ");
    gets(str1);
    printf("Inserisci stringa2: ");
    gets(str2);

    //Results
    printf("\n1) Esito verifica della stringa1 palindroma: %d",string_is_palindrome(str1));
    printf("\n2) Esito confronto stringa1 e stringa2: %d",string_compare(str1,str2));
    string_wipe_whitespaces(str1);
    printf("\n3) Stringa1 senza spazi: %s",str1);
    printf("\n4) Occorrenze di %c nella stringa2: %d",test_c,string_how_many(test_c,str2));
}


int slength(char s[]){
    int i;
    for(i=0; (*(s + i) != '\0') && (*(s + i) != '\n'); i++){  }
    return i;
}

int string_is_palindrome(char s[]){

    for (int i = 0; i < slength(s)/2; i++){
        if(s[i] != s[slength(s) - 1 - i]){
            return 0;
        }
    }
    return 1;

}

int string_compare(char s1[],char s2[]){

    //Comparing character
    for(int i = 0; i < slength(s1) && i < slength(s2); i++){
        if(s1[i] < s2[i]){ return 1; }
        if(s1[i] > s2[i]){ return -1; }
    }
    
    //Comparing length (shorter words have priority)
    if(slength(s1) < slength(s2)){ return 1; }
    if(slength(s1) > slength(s2)){ return -1; }

    //Strings are lexicographical equal
    return 0;

}

void string_wipe_whitespaces(char s[]){

    for(int i = 0; i < slength(s); i++){

        if(s[i] == ' '){
            for (int j = i; s[j] = ' ' && j+1 < slength(s); j++){
                s[j] = s[j+1];
            }
        }

    }

}

int string_how_many(char c,char s[]){

    int count = 0;
    for (int i = 0; i < slength(s); i++){
        count = (s[i] == c)? ++count : count;
    }
    return count;

}
