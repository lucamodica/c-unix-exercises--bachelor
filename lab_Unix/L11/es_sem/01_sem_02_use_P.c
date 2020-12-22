#include "sem_lib.h"

//Testing reserving value of a semaphore set 3 times 

int main(void){
    
    //Creating semaphore and setting it
    int sem_id = semInit(2);
    setSemValue(sem_id,1,INIT_SAMPLE_VALUE);
    setSemValue(sem_id,0,INIT_SAMPLE_VALUE);
    TEST_ERROR;

    //Print init sem info
    printf("Creating a first semaphore set with id = %d.\n",sem_id);
    printf("Sem 0 value = %d\n\n",getSemValue(sem_id,0));

    //Reserving the semaphore 3 times
    for(int i = 0; i < 3; i++){
        semReserve(sem_id,0);
    }

    //Print sem info after release
    printf("Semaphore set with id = %d info, after some reserve.\n",sem_id);
    printf("Sem 0 value = %d\n",getSemValue(sem_id,0));


}