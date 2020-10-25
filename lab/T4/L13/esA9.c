#include <stdio.h>
#include <stdlib.h>
#include "list_cl.h"
#include "list_cl.c"
#include "client.h"
#include "client.c"


int main(){

    //Initialize list
    list_cl *class = (list_cl *) malloc(sizeof(list_cl));

    //Adding a person to the list
    client p = {12345, "luca", "modica", {"Via coso",37,14018,IT}};
    *class = l_add_cl(*class,p);



    //Printing the list length
    printf("Lunghezza lista: %d\n",l_length(*class));

}