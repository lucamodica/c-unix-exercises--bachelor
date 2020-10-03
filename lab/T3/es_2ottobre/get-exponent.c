#include <stdio.h>
#include <string.h>

int get_exponent(double num);


int main(){

    //Double value
    double n;

    //Inputs
    printf("Inserisci un valore double: ");
    scanf("%lf",&n);

    //Result
    printf("\nNice. Ecco il suo esponente secondo lo standard IEEE 754-1985: %d\n",get_exponent(n));

}


int get_exponent(double num){

    int i=0;
    unsigned long int u;
    unsigned long int d;
    memcpy(&u,&num,sizeof(num));
    

    //Extracting the double exponent
    
    for (int i = 0; i < 12; i++)
    {
        
    }
    

    return u << 52;

}
