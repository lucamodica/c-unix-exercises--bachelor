#include <stdio.h>
#include "operation.h"

//Testing the 2 modules

int main(){
    int a = 2, b = 4;

    printf("%d + %d = %d\n",a,b,sum(a,b));  
    printf("%d * %d = %d\n",a,b,mult(a,b));       
}