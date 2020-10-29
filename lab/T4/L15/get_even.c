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