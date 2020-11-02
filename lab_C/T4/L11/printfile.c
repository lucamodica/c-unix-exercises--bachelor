#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 2048


int main(int argc, char *argv[]){
    int fd = 0;
    if(argc == 1){
        printf("Usage: printfile <pathname>\n");
    }
    else{
        fd = open(argv[1], O_RDONLY);

        if(fd == -1){
            perror(NULL);
        }
        else{
            int n;
            char text[BUFFER_SIZE];

            //Lettura e stampa contenuto del file
            do{
                n = read(fd,text,BUFFER_SIZE);
                /*
                for(int i=0; i<n; i++){
                    putchar(text[i]);
                }*/
                for(int i=0; i<n; i++){
                    putchar(text[i]);
                }
            }while (n!=0 && n!=-1);
            
            close(fd);
            fd = 0;

        }
        
    }

    return fd;
}