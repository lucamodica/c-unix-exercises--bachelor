#include <stdio.h>

void to_bin(int num);


int main(){

    //Input
    unsigned n;
    printf("Intero n: ");
    scanf("%d",&n);

    //Result
    printf("Nice. Stampa della conversione in bianrio %d: ",n);
    to_bin(n);
    
}


void to_bin(int num){

    for(unsigned i = 1 << 31; i > 0; i >>= 1){

        printf("%s",(num & i) ? "1" : "0");
       

    }
    printf("\n");

}