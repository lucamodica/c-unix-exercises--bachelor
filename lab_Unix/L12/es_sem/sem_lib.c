
//List of function for semaphore-based exercise

#include "sem_lib.h"

//Init semaphore func
int semInit(int nsems){
    return semget(IPC_PRIVATE,nsems,IPC_CREAT | 0600);
}

//Setting semaphore value func
int setSemValue(int sem_id, int nsem, int value){
    return semctl(sem_id,nsem,SETVAL,value);
}

//Getting semaphore value func
int getSemValue(int sem_id, int nsem){
    return semctl(sem_id,nsem,GETVAL);
}

//Reserve semaphore func
int semReserve(int sem_id, int nsem){
    struct sembuf sop;

    sop.sem_num = nsem;
    sop.sem_op = -1;
    sop.sem_flg = 0;

    return semop(sem_id, &sop, 1);
}

//Relase semaphore func
int semRelease(int sem_id, int nsem){
    struct sembuf sop;

    sop.sem_num = nsem;
    sop.sem_op = 1;
    sop.sem_flg = 0;

    return semop(sem_id, &sop, 1);
}

//Remove semaphore func
int semRemove(int sem_id){
    return semctl(sem_id,0,IPC_RMID);
}