#include "client.h"
#include <string.h>

//Getter/Setter for cf
unsigned int getCf(client c){ return c.cf; }
void setCf(client *c, unsigned int value){ c->cf = value; }

//Getter/Setter for first_name
char* getFirst_name(client c){ return c.first_name; }
void setFirst_name(client *c, char *value){ c->first_name = value; }

//Getter/Setter for last_name
char* getLast_name(client c){ return c.last_name; }
void setLast_name(client *c, char *value){ c->last_name = value; }

//Getter/Setter for address
address getAddress(client c){ return c.addr; }
void setAddress(client *c, address value){ c->addr = value; }