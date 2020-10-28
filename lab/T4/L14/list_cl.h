#ifndef _LIST_CL_H
#define _LIST_CL_H

#include "client.h"

//Node type definition
typedef struct _node {
   unsigned int  id;
   client        person;
   struct _node *next;
} l_node;

//List type definition (am I really implementing a list without classes?? Goddamn)
typedef struct { 
   l_node *head;  // Head pointer
   l_node *tail;  // Tail pointer
} list_cl; 

//Empty list definition
#define EMPTY_LIST NULL

//List operation (prototype)
extern list_cl l_add_cl(list_cl, client);
extern client  l_rem_cl(list_cl *);
extern int     l_is_empty(list_cl);
extern list_cl l_clear(list_cl);
extern int     l_length(list_cl);

#endif
