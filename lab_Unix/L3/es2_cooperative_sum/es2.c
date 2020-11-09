#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>

#define NUM_KIDS 10

int main(){
	pid_t pid, ppid, value, childPid;
	int status, sum = 0, i = 0;

	for (i = 0; i < NUM_KIDS; i++){
		
		switch (value = fork()){

			case -1:
				/* Handle error */
				fprintf(stderr,"Error #%03d: %s\n", errno, strerror(errno));
				break;

			case 0:
				
				//pid infos
				pid = getpid();
				ppid = getppid();

				//Random number generator
				srand(getpid());
				int rands = rand()%6+1;

				printf("pid: %d, ppid: %d, random value: %d\n",pid,ppid,rands);

				exit(rands);
				break;
			
			default:
				break;
		}

	}

	while ((childPid = waitpid(0, &status, 0))!= -1) {
      if (childPid == 0) {
        printf("No child terminated\n");
      } 
	  else {
		sum += WEXITSTATUS(status);
        printf("PARENT:  PID=%d terminated (the child) with status %d\n", childPid, WEXITSTATUS(status));
      }

      sleep(1);
    }

	printf("Sum: %d\n",sum);
	
	



}