#include <stdio.h>

#define MAX_LENGTH 80
#define NO_LETTERS ('Z'-'A'+ 1)

void count_char(char str[]);
void setup(int a[], int range, int st);
char tolowercase(char c);


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

    int i=0,wh=0;

    //Array where register records
    int chars[MAX_LENGTH];

    //Setting chars[] array
    setup(chars,NO_LETTERS,0);

    //Recording characters
    for(i=0; str[i] != '\0'; i++){
        
        //Checking for the character...
        //(notice that is case insensitive)
        char ch = tolowercase((char) str[i]);
        
        if(ch <= 'z' && ch >= 'a'){
            chars[ch - 'a']++;
        }
        else if(ch ==' '){
            wh++;
        }

    }
    chars[NO_LETTERS] = wh;

    //Printing the recordings as an histogram 
    for (i = 0; i <= NO_LETTERS; i++){
    
        if(chars[i] != 0){

            //First the character
            printf("%c: ",(i == NO_LETTERS) ? ' ' : 'a' + i);

            //Then the times
            for(int j = 0; j < chars[i]; j++){
                printf("*");
            }

            //To the next character found
            printf("\n");

        }    

    }
    
}

void setup(int a[], int range, int st){
    for (int i = 0; i < range; i++){ a[i] = st; }
}

char tolowercase(char c){
    return (c <= 'Z' && c >= 'A') ? c - 'A' + 'a' : c;
}
