#include "sem_lib.h"

//Test synchronization parent-child with semaphores

int main(void){

    int sem_id; //Semaphore id
    pid_t child; //Var for fork() func

    //Init semaphore and setting it
    printf("***Starting semaphore program***\n");
    sem_id = semInit(1);
    TEST_ERROR;
    setSemValue(sem_id,0,0);
    TEST_ERROR;
    printf("A semaphore with #%d and value=%d was created.\n\n\n",sem_id,getSemValue(sem_id,0));

    //Fork with parent-child synchronization
    switch (child = fork()){
        
        //Fork failed code
        case -1:
            printf("Fork failed.\n");
            TEST_ERROR;
            break;

        //Child code
        case 0:

            //Init child
            printf("Child #%d - Hi! The semaphore is mine riiiight now.\n",getpid());
            printf("Child #%d - I'll hold it for 5 seconds!\n",getpid());
            sleep(5);

            //Releasing the semaphore
            semRelease(sem_id,0);
            printf("Child #%d - Semaphore released! Bye folks.\n\n",getpid());

            exit(EXIT_SUCCESS);
            break;
        
        //Father code
        default:

            //Trying to reserve the semaphore
            printf("Parent #%d - Trying to reserve the semaphore. (sem_value = %d).\n\n",getpid(),getSemValue(sem_id,0));
            semReserve(sem_id,0);
            TEST_ERROR;
            
            //Keeping it for 2 seconds
            printf("Parent #%d - Semaphore reserved!\n",getpid());
            printf("Parent #%d - I'll hold it for 2 seconds.\n",getpid());
            sleep(2);

            //Deallocating the semaphore
            semRemove(sem_id);
            TEST_ERROR;
            printf("Parent #%d - Now, we're deallocating the semaphore with id = #%d\n",getpid(),sem_id);

            exit(EXIT_SUCCESS);
            break;
    }
}