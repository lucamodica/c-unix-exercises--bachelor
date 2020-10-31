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

int main(){

    //Pointer to the head node
    list l = (node *) malloc(sizeof(node));
    l->value = 0;
    l->next = NULL;

    //Generic node pointer
    node *c;

    //Creating the list
    c = l;
    for(int i = 1; i < 6; i++){
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
    printf("\n\n");

    //get_even func
    list even = get_even(l);
    printf("**Liste dopo la funzione get_even()**\n");

    //Printing odd list (the old modified one)
    printf("Dispari: ");
    c = l;
    while(c != NULL){
        printf("|| %d || ",c->value);
        c = c->next;
    }
    printf("\n");

    //Printing the new even list
    printf("Pari: ");
    c = even;
    while(c != NULL){
        printf("|| %d || ",c->value);
        c = c->next;
    }
    printf("\n");

}


list get_even(list l){

    //Result list
    list even = NULL;

    if(l != NULL){

        //Func pointer utilities
        node *prec = NULL;
        node *c = l;
        node *e;

        do{
            if(c->value%2 == 0){
                node *n = (node *) malloc(sizeof(node));
                n->value = c->value;
                n->next = NULL;
                //Point to the first even node
                if(even == NULL){
                    even = n;
                    e = even;
                }
                //Point to a new even node
                else{
                    e->next = n;
                    e = n;
                }

                //Deleting the first node from the original list
                n = c;
                if(prec == NULL){
                    c = c->next;
                    l = c;
                }
                //Deleting the current node from the original list
                else{
                    prec->next = c->next;
                    c = prec->next;
                }
                free(n);
                n = NULL;
            }
            else{
                prec = c;
                c = c->next;
            }
        }while(c != NULL);

        c = l;
        printf("Lista dispari (ma stampata nella funzione): ");
        while(c != NULL){
            printf("|| %d || ",c->value);
            c = c->next;
        }
        printf("\n\n");
        
    }

    return even; 
}