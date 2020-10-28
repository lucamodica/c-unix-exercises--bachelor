#ifndef _CLIENT_H
#define _CLIENT_H
#define EMPTY_CLIENT {0,"","",{"",0,0,NA}}

#include "address.h"

//Client type
typedef struct{
    unsigned int cf;
    char *first_name;
    char *last_name;
    address addr;
} client;

//List funcs (prototype)
extern unsigned int getCf(client);
extern void setCf(client *, unsigned int);
extern char* getFirst_name(client);
extern void setFirst_name(client *, char *);
extern char* getLast_name(client);
extern void setLast_name(client *, char *);
extern address getAddress(client);
extern void setAddress(client *, address);

#endif