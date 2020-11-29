#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>

#define NUM_MAX 20000
#define NUM_KIDS 4

void error(char* details){
	fprintf(stderr,"%s: %d. %s #%03d: %s",__FILE__,__LINE__,details,errno,strerror(errno));
	exit(EXIT_FAILURE);
}



int main(){

	int pipe_op[2];  //[0] --> read - [1] --> write
	pid_t forkk; //Fork result

	//Opening pipe and check
	if(pipe(pipe_op) == 0){
		//Generating kids
		for (int i = 0; i < NUM_KIDS; i++){
			
			//Fork
			switch (forkk = fork()){
				case -1:
					error("Error in creating child");
					break;

				case 0:
					pid_t pid = getpid();
					printf("CHILD %5d - Hi there!\n",pid);
					close(pipe_op[0]); //closing read flux

					//Sigaction struct to hanfling signals
					struct sigaction sa;

					//Mask for signal SIGUSR1 and SIGINT
					sigset_t m_INT_USR1;
					//Mask for unmasking any signal in sigaction
					sigset_t m_empty;

					//Setting m_empty
					sigemptyset(&m_empty);

					//Setting m_INT_USR1
					sigemptyset(&m_INT_USR1);
					ai


					break;
				
				default:
					break;
			}

		}
	}
	//Print error attempting pipe creation
	else{
		error("Error in pipe creation");
	}
	

}