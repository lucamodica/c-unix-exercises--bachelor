#ifndef _ADDRESS_H
#define _ADDRESS_H


//Enum and array for country
typedef enum { NA, IT, FR, DE, UK,  PT } country;
char *country_name[] = {"No country", "Italy", "France", "Germany", "Great Britain", "Portugal"};

//Address type
typedef struct{
    char *street;
    unsigned int nciv;
    unsigned int cap;
    country loc;
} address;

//List funcs (prototype)
extern char* getStreet(address);
extern void setStreet(address *, char *);
extern int getNciv(address);
extern void setNciv(address *, int);
extern int getCap(address);
extern void setCap(address *, int);
extern country getLoc(address);
extern void setLoc(address *, country);

#endif