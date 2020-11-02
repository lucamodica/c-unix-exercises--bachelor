#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    int value;
    struct _node *next;
} node;

typedef node *list; //Punta al nodo "testa" della lista

/* Fornire una definizione per la funzione:
 * 
 * list l_cut_at(list l, int cut_value)
 * 
 * la quale elimini e deallochi gli elementi della lista l a partire
 * dalla prima occorrenza di un elemento con campo "value" uguale a "cut_value".
 * La funzione restituisce il puntatore alla lista così modificata.
 */


list l_cut_at(list, int);
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
    l = l_cut_at(l,6);
    c = l;
    printf("Lista dopo il taglio: ");
    while(c != NULL){
        printf("|| %d || ",c->value);
        c = c->next;
    }
    printf("\n");

}


list l_cut_at(list l, int cut_value){

    if(l != NULL){
        node *e = l;
        node *p = NULL;

        do{
            if(e->value == cut_value){
                if(p == NULL){
                    l = NULL;
                }
                else{
                    p->next = NULL;
                }
                l_free(e);
                e = NULL;
            }
            else{
                p = e;
                e = e->next;
            }
        }while(e != NULL);

    }

    return l;
}

void l_free(list l){
    
    do{
        node *e = l;
        l = l->next;
        free(e);
    } while (l != NULL);
    
}