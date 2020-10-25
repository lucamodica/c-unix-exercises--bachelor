#include "list_cl.h"

//Check if the list is empty
int l_is_empty(list_cl l){
    return (l.head == EMPTY_LIST) ? 1 : 0;
}

//Counting elements in the list
int l_length(list_cl l){
    l_node *n = l.head;
    int count = 0;

    while(n!=NULL){
        count++;
        n = n->next;
    }
    
    return count;
}

//Adding an element to the list
list_cl l_add_cl(list_cl l, client c){
    if(l_is_empty(l)){
        l.head = (l_node *) malloc(sizeof(l_node));
        l.tail = (l_node *) malloc(sizeof(l_node));
        l.head->id = 0;
        l.head->person = c;
        l.head->next = NULL;
        l.tail = l.head;
    }
    else{
        //Create new node
        l_node *n = (l_node *) malloc(sizeof(l_node));
        n->id = l_length(l);
        n->person = c;
        n->next = NULL;

        //Inserting as first tail
        if(l.tail == l.head){
            l.tail = n;
            l.head->next = l.tail;
        }
        //Inserting an element as new tail
        else{
            l.tail->next = n;
            l.tail = n;
        }
    }
    return l;
}

//Return the client info saved on head node
client l_rem_cl(list_cl l){
    return l.head->person;
}

//Removing all the elements of the list
list_cl l_clear(list_cl l){
    l_node *n = NULL;
    l_node *d = l.head;

    while(d != NULL){
        n = d;
        printf("id %d (%s %s), deleted.\n",n->id,n->person.first_name,n->person.last_name);
        d = d->next;
        free(n);
    }
    l.head = EMPTY_LIST;
    l.tail = EMPTY_LIST;

    return l;
}


