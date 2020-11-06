#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>

int i;

/* Keep CPU busy for a time proportional to loops, Hard to be
   optimized by compilers */
void busy_cpu(unsigned long loops) {
	int i;    /* Different than global variable */
	double my_var=0.25;

	for(i=0; i<loops; i++){
		my_var += 0.5;
		my_var = my_var > 1 ? my_var-1 : my_var;
	}
}

void do_stuff() {

	printf("Hi, I'm son number %d, my PID is %d and I'm running a lot of stuff\n",
	       i,
	       getpid());
	srand(time(0));
	//  busy_cpu(rand() % 100000);
	//busy_cpu(10000000);
	busy_cpu(rand() % 10000000000);
}

int main (void) {
	long num_cores, num_proc;
	pid_t child_pid;
	int status;

	printf("My PID is %d, number of processors is %li, of which %li are on-line \n",
	       getpid(),
	       num_cores = sysconf(_SC_NPROCESSORS_CONF),
	       sysconf(_SC_NPROCESSORS_ONLN));

	//  num_proc = 2*num_cores;   /* MAGIC NUMBER, don't ask me */
	num_proc =8;

	for (i=0; i<num_proc; i++) {
		switch (child_pid = fork()) {
		case -1:
			/* Handle error */

		case 0:
			/* Perform actions specific to child */
			do_stuff();
			//      exit(EXIT_SUCCESS);
			printf("Done! (PID=%d - PPID=%d)\n",getpid(),getppid());
			exit(i);
			printf("Hi, my PID is %d and you should never see this message\n", getpid());
			break;

		default:
			/* Perform actions specific to parent */
			printf("I'm the proud parent of a child with PID %d\n", child_pid);
			break;
		}
	}

	//sleep(90);
	/* Now let's wait that all kids do the stuff */
	while ((child_pid = wait(&status)) != -1) {
		printf("PARENT: PID=%d. Got info of child with PID=%d, status=0x%04X\n", getpid(), child_pid, status);
		//printf("PARENT: PID=%d. Got info of child with PID=%d, status=%d\n", getpid(), child_pid, WEXITSTATUS(status));
	}
	if (errno == ECHILD) {
		printf("In PID=%6d, no more child processes\n", getpid());
		exit(EXIT_SUCCESS);
	} else {
		fprintf(stderr, "Error #%d: %s\n", errno, strerror(errno));
		exit(EXIT_FAILURE);
	}
}
