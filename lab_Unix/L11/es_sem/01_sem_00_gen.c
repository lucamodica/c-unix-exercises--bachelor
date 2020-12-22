#include "sem_lib.h"

//Testing creating and setting a semaphore to 0

int main(void){
    
    //Creating semaphore and setting it
    int sem_id = semInit(2);
    setSemValue(sem_id,0,0);
    TEST_ERROR;

    //Print init sem info
    printf("Creating a first semaphore set with id = %d, and first semaphore with value = %d.\n",sem_id,getSemValue(sem_id,0));

}

