#include "sem_lib.h"

//Testing removing the semaphore

int main(void){
    
    //Creating semaphore and setting it
    int sem_id = semInit(2);
    TEST_ERROR;

    //Print init sem info
    printf("Creating a first semaphore set with id = %d.\n",sem_id);
    printf("Sem 0 value = %d\n",getSemValue(sem_id,0));
    printf("Sem 1 value = %d\n\n",getSemValue(sem_id,1));

    //Removing the semaphore
    sleep(5);
    semRemove(sem_id);
    printf("But now, the #%d semaphore was removed with success.\n\n",sem_id);


}