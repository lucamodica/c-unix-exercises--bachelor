#include <stdio.h>

int main(int argc, char *argv[]){

    FILE *f = fopen(argv[1],"a+");

    //Init check
    if(argc < 2){
        printf("Something went wrong. Here's the syntax in case you miss it:\n");
        printf("./program_name <filepath>\n\n");
    }


}