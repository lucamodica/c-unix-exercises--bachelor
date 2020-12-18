
//Custom library for semaphore-based exercises

#ifndef SEM_LIB
#define SEM_LIB
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/sem.h>


#define KEY 12345 //Key for creating a semaphore set
#define INIT_SAMPLE_VALUE 5 //An init semaphore value

//A classic error-checking macro
#define TEST_ERROR    if (errno) {fprintf(stderr, \
					   "%s:%d: PID=%5d: Error %d (%s)\n",\
					   __FILE__,\
					   __LINE__,\
					   getpid(),\
					   errno,\
					   strerror(errno));}


//Init semaphore func
int semInit(int nsems);

//Setting semaphore value func
int setSemValue(int sem_id, int nsem, int value);

//Getting semaphore value func
int getSemValue(int sem_id, int nsem);

//Reserve semaphore func
int semReserve(int sem_id, int nsem);

//Relase semaphore func
int semRelease(int sem_id, int nsem);

//Remove semaphore func
int semRemove(int sem_id);


#endif