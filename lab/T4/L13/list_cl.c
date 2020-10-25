#include "list_cl.h"

//Adding an element to the list

list_cl l_add_cl(list_cl l, client c){
    if(l.head == NULL){
        l.head = (l_node *) malloc(sizeof(l_node));
        l.head->id = 0;
        l.head->person = c;
        
    }
    return;
}

/*
client l_rem_cl(list_cl l){
    return;
}


int l_is_empty(list_cl l){
    return;
}


list_cl l_clear(list_cl l){
    return;
}*/


int l_length(list_cl l){
    if(l.head == NULL){
        return 0;
    }
    return 0;
}