#include <stdio.h>
#include <stdlib.h>
#include "list_cl.c"
#include "client.c"
#include "address.c"


int main(){

    //Initialize list
    list_cl *people = (list_cl *) malloc(sizeof(list_cl));
    people->head = EMPTY_LIST;
    people->tail = EMPTY_LIST;

    //Adding a person to the list
    client p = {12345, "luca", "modica", {"Via coso",37,14018,IT}};
    *people = l_add_cl(*people,p);
    setFirst_name(&p,"Andrea");
    *people = l_add_cl(*people,p);
    setLast_name(&p,"Babbo");
    *people = l_add_cl(*people,p);

    //Printing the list length
    printf("List length: %d\n\n",l_length(*people));
   
    //Printing info about the person on the head node
    if(l_is_empty(*people) == 0){
        client res = l_rem_cl(people);
        address addr = getAddress(res);
        country c = getLoc(addr);
        printf("**Top client info**\n");
        printf("CF: %d\n",getCf(res));
        printf("First name: %s\n",getFirst_name(res));
        printf("Last name: %s\n",getLast_name(res));
        printf("Street and civic number: %s, %d\n",getStreet(addr),getNciv(addr));
        printf("CAP: %d\n", getCap(addr));
        printf("Country: %s\n",country_name[c]);
    }
    else{
        printf("List is empty, can't retrieve the top client info. Maybe I can try to fill it...\n");
    }
    printf("List length: %d\n\n",l_length(*people));

    //Check if the list id empty
    printf("empty list check result: %s\n\n", (l_is_empty(*people) == 1) ? "empty" : "not empty");

    //Clear the list
    if(l_is_empty(*people) == 1){
        printf("Sorry dude, but the list is already empty.\n");
    }
    else{
        printf("Clearing list...\n");
        *people = l_clear(*people);
    }
    printf("List length: %d\n",l_length(*people));

}