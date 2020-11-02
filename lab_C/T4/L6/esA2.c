#include <stdio.h>

float mid_num_string();

int main(){
    //Applying function
    printf("La media e': %G",mid_num_string());
}


float mid_num_string(){

    int sum = 0;
    int cont = 0;
    int n;
    
    printf("Inserire la stringa di cifre: ");

    while(scanf("%d",&n) && n>0){
        sum += n;
        cont++;
    }

    return (float) sum/cont;
}