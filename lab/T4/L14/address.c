#include "address.h"

//Getter/Setter for street
char* getStreet(address addr){ return addr.street; }
void setStreet(address *addr, char *value){ addr->street = value; }

//Getter/Setter for nciv
int getNciv(address addr){ return addr.nciv; }
void setNciv(address *addr, int value){ addr->nciv = value; }

//Getter/Setter for cap
int getCap(address addr){ return addr.cap; }
void setCap(address *addr, int value){ addr->cap = value; }

//Getter/Setter for loc
country getLoc(address addr){ return addr.loc; }
void setLoc(address *addr, country value){ addr->loc = value; }