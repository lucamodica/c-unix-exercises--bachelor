#include <stdio.h>
#include <math.h>

int get_exponent(double num);


int main(){

    //Double value
    double n;

    //Inputs
    printf("Inserisci un valore double: ");
    scanf("%ld",&n);

    //Result
    int e;
    double m = frexp(n,&e);
    printf("\nNice. Ecco il suo esponente secondo lo standard IEEE 754-1985: %d\n",get_exponent(n));

}


int get_exponent(double num){

    int exp;
    double mantissa;
    //memcpy(data, &num, sizeof(data));

    mantissa = frexp(num,&exp);

    return exp;

}
