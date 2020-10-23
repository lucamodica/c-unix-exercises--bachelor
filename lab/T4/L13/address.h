#ifndef _ADDRESS_H
#define _ADDRESS_H


typedef enum { NA, IT, FR, DE, UK,  PT } country;

char *country_name[] = "";

typedef struct{
    char *street;
    unsigned int nciv
    unsigned int cap;
    country loc;
}

#endif