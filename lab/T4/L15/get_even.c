#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
} node;

typedef node *list; //Punta al nodo "testa" della lista

/* Fornire una definizione per la funzione:
 * 
 * list l_get_at(list l, int cut_value)
 * 
 * la quale estrae dalla lista l i nodi con "value" pari e li riorganizzi
 * a formare una nuova lista.
 * La funzione restituisce il puntatore alla lista così modificata.
 * 
 * se l->(1,2,4,7,9,0) allora dopo la chiamata l_get_even(l) la lista sarà l->(1,7,9)
 * e la funzione restituirà la lista (2,4,0).
 */

list get_even(list);
void l_free(list);

int main(){

    //Pointer to the head node
    list l = (node *) malloc(sizeof(node));
    l->value = 0;
    l->next = NULL;

    //Creating the list
    node *c = l;
    for(int i = 1; i < 10; i++){
        node *n = (node *) malloc(sizeof(node));
        n->value = i;
        n->next = NULL;
        c->next = n;
        c = n;
    }

    //Printing test
    c = l;
    printf("Lista: ");
    while(c != NULL){
        printf("|| %d || ",c->value);
        c = c->next;
    }
    printf("\n");

    //l_cut_at func
    l = l_cut_at(l,4);
    c = l;
    printf("Lista dopo il taglio: ");
    while(c != NULL){
        printf("|| %d || ",c->value);
        c = c->next;
    }
    printf("\n");

}