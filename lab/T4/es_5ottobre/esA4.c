#include <stdio.h>

float mid_num_string();

int main(){
    //Applying function
    printf("La media dei voti e': %G",mid_num_string());
}


float mid_num_string(){

    int sum = 0;
    int cont = 0;
    int n;
    
    printf("Inserire il numero di voti: ");
    scanf("%d",&cont);

    for(int i=0;i<cont;i++){
        printf("Voto %d: ", i+1);
        scanf("%d",&n);
        sum += n;
    }

    return (float) sum/cont;
}