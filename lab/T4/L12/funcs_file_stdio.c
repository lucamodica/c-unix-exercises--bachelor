#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *f = fopen(argv[1],"w+");

    //Init check
    if(argc < 2){

        printf("Something went wrong. Here's the syntax in case you miss it:\n");
        printf("./program_name <filepath>\n\n");

    }
    else{

        //Test Read file
        for (int c = fgetc(f); c != EOF; c = fgetc(f)){
            printf("%c",c);
        }
        printf("\n");

        //Test write file
        char *text = " come stai? ";
        fwrite(text,strlen(text),1,f);
        printf("%d\n",strlen(text));
        fseek(f,0,0);
        for (int c = fgetc(f); c != EOF; c = fgetc(f)){
            printf("%c",c);
        }
        printf("\n");

        //Test positioning in a specific position of the file
        fseek(f,9,0);
        for (int c = fgetc(f); c != EOF; c = fgetc(f)){
            printf("%c",c);
        }
        printf("\n");
        
    }
    fclose(f);

    
}