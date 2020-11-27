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

/*
 * NUM_PROC processes are printing NUM_ITER strings to stdout. At most
 * SEM_INIT_VAL processes are allowed to print concurrently. The time
 * taken from the beginning until the termination of the last process
 * is also printed
 *
 * Try to:
 * - redirect the output to /dev/null
 * - investigate the relationship between SEM_INIT_VAL and the time
 *   taken to complete
 */


#define NUM_PROC      8
#define NUM_ITER      100
#define SEM_INIT_VAL  5
#define TEST_ERROR    if (errno) {fprintf(stderr, \
					   "%s:%d: PID=%5d: Error %d (%s)\n",\
					   __FILE__,\
					   __LINE__,\
					   getpid(),\
					   errno,\
					   strerror(errno));}




int main (void)
{
	pid_t child_pid;
	int i, j, status;
	int s_id;
	time_t time_start, time_end;
	struct sembuf sops;

	// Create a semaphore and initializes to SEM_INIT_VAL
	s_id = semget(IPC_PRIVATE, 1, 0600);
	TEST_ERROR;
	semctl(s_id, 0, SETVAL, SEM_INIT_VAL);
	TEST_ERROR;

	// Init the data structure of a semaphore operation
	sops.sem_num = 0;
	sops.sem_flg = 0;

	// Read time at the beginning
	time_start = time(NULL);

	// Create NUM_PROC processes
	for (i=0; i<NUM_PROC; i++) {
		switch (fork()) {
		case -1:
			/* Handle error */
			TEST_ERROR;
			exit(EXIT_FAILURE);
		case 0:

			for (j=0; j<NUM_ITER; j++) {
				// Access the resource
				sops.sem_op = -1;
				semop(s_id, &sops, 1);
				TEST_ERROR;

				printf("CHILD PID %5d: j=%2d\n", getpid(), j);
				sleep(1);

				// Release the resource
				sops.sem_op = 1;
				semop(s_id, &sops, 1);
				TEST_ERROR;
			}

			exit(0);
			break;

		default:
			break;
		}
	}

	/* Now let's wait for the termination of all kids */
	while ((child_pid = wait(&status)) != -1) {
		printf("PARENT: PID=%d. Got info of child with PID=%d, status=0x%04X\n", getpid(), child_pid,status);
	}

	time_end = time(NULL);
	fprintf(stderr,"Total time: %ld (sec)\n", time_end-time_start);

	// Deallocate the semaphore
	semctl(s_id, 0, IPC_RMID);

	exit(EXIT_SUCCESS);
}
