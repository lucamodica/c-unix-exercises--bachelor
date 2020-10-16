//Prototipi funcs
int slength(char s[]);
char *scut_last_word(char s[]);
int string_is_empty(char s[]);
int string_is_palindrome(char s[]);
int string_compare(char s1[],char s2[]);
void string_wipe_whitespaces(char s[]);
int string_how_many(char c,char s[]);


int slength(char s[]){
    int i;
    for(i=0; (*(s + i) != '\0') && (*(s + i) != '\n'); i++){  }
    return i;
}

char *scut_last_word(char s[]){
    int i;
    for (i = slength(s); i > 0 && s[i] != ' '; i--){}
    s[i] = '\0';
    return s;
}

int string_is_empty(char s[]){
    return *s == '\n' || *s == '\0';
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