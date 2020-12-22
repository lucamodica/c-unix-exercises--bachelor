#include "sem_lib.h"

//Testing releasing value of a semaphore set 5 times 

int main(void){
    
    //Creating semaphore and setting it
    int sem_id = semInit(2);
    setSemValue(sem_id,1,0);
    TEST_ERROR;

    //Print init sem info
    printf("Setting semaphore set with id = %d.\n",sem_id);
    printf("Sem 0 value = %d\n",getSemValue(sem_id,0));
    printf("Sem 1 value = %d\n\n",getSemValue(sem_id,1));

    //Releasing the second semaphore 5 times
    for(int i = 0; i < INIT_SAMPLE_VALUE; i++){
        semRelease(sem_id,1);
    }

    //Print sem info after release
    printf("Semaphore set with id = %d info, after some release.\n",sem_id);
    printf("Sem 0 value = %d\n",getSemValue(sem_id,0));
    printf("Sem 1 value = %d\n\n",getSemValue(sem_id,1));


}