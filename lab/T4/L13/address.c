#include "address.h"

//Getter/Setter for street
char* getStreet(address addr){ return addr.street; }
void setStreet(address addr, char *value){ addr.street = value; }

//Getter/Setter for nciv
int getNciv(address addr){ return addr.nciv; }
void setNciv(address addr, int value){ addr.nciv = value; }

//Getter/Setter for cap
extern int getCap(address addr){ return addr.cap; }
extern void setCap(address addr, int value){ addr.cap = value; }

//Getter/Setter for loc
extern char* getLoc(address addr){ return addr.loc; }
extern void setLoc(address addr, country value){ addr.loc = value; }