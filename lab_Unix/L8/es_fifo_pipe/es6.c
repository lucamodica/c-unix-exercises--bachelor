#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>

//General info
#define NUM_MAX 10
#define NUM_KIDS 4

//Variable indicating when a child has to stop the number generating
int end = 0; 

//Handling error func
void error(char* details){
	fprintf(stderr,"%s: %d. %s #%03d: %s",__FILE__,__LINE__,details,errno,strerror(errno));
	exit(EXIT_FAILURE);
}

//Handling signal func
void signalHandler(int sig){
	switch (sig){
		case SIGINT:
			printf("CHILD %d - Received: SIGINT\n",getpid());
			end = 1;
			break;

		case SIGUSR1:
			printf("CHILD %d - Received: SIGUSR1\n",getpid());
			break;
	
		default:
			break;
	}
	printf("CHILD %d - ok\n",getpid());
}


int main(){

	int pipe_op[2];  //[0] --> read - [1] --> write
	pid_t forkk; //Fork result
	pid_t pidd;

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
					pidd = getpid();
					printf("CHILD %5d - Hi there!\n",pidd);
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
					sigaddset(&m_INT_USR1, SIGINT);
					sigaddset(&m_INT_USR1, SIGUSR1);

					//setting sigaction
					sa.sa_handler = signalHandler;
					sa.sa_mask = m_empty;
					sa.sa_flags = 0;
					sigaction(SIGINT, &sa, NULL);
         			sigaction(SIGUSR1, &sa, NULL);

					//Init random number generator and buffer
					srand(pidd);
					char *buf = malloc(sizeof(int)+sizeof(pid_t));

					//Masking INT and USR1 signal while child operates
					sigprocmask(SIG_SETMASK,&m_INT_USR1,NULL);

					//Operates until a INT signal is riceived (until end = 1)
					while (!end){
						//Generates number
						int n = rand() % NUM_MAX + 1;

						//Saving random num and child pid
						memcpy(buf,&pidd,sizeof(pid_t));
						memcpy(buf+sizeof(pid_t),&n,sizeof(int));

						//Writing buffer content in pipe
						printf("CHILD %5d - writing %d\n",pidd,n);
						int wr_res = write(pipe_op[1],buf,sizeof(pid_t)+sizeof(int));
						if (wr_res == -1){ error("Error in writing pipe"); }
						
						//Suspend child in waiting a signal
						sigsuspend(&m_empty);
					}
					
					//Closing writing flux
					close(pipe_op[1]);

					//Closing process
					printf("CHILD %d - exit\n",getpid());
					exit(EXIT_SUCCESS);
					break;
				
				default:
					break;
			}

		}

		//Init parent and closing writing flux (parent is the reader)
		printf("PRETE %5d - I'm a boring reader teaching my sons what a number is\n",getpid());
		close(pipe_op[1]);
		int remainingChildren = NUM_KIDS; //Children to be waited


		//Extracting each number children inserted into the pipe, evaluating the min
		while (remainingChildren > 0){
			
			int min_val = INT_MAX; //Start min value
			pid_t min_pid = -1; //Pid of the process with minium value
			pid_t pid_list[remainingChildren];

			//Start for loop to read all of the number of the remaining processes
			printf("Start reading generated number from my beautiful kids...\n");
			for (int i = 0; i < remainingChildren; i++){
				
				pid_t cPid; //PID read
				int val; //Value written by the process
				int rd_res; //Reading result

				//Reading PID
				rd_res = read(pipe_op[0],&cPid,sizeof(pid_t));
				if (rd_res == -1){ error("Error in reading pid from pipe"); }
				pid_list[i] = cPid;

				//Reading process value
				rd_res = read(pipe_op[0],&val,sizeof(int));
				if (rd_res == -1){ error("Error in reading number generated by process from pipe"); }

				printf("PRETE - (%d) From %d - Value %d\n",i,cPid,val);

				//Check if the value extracted is minus than the previous one
				if(val<min_val){
					min_val = val;
					min_pid = cPid;
				}
				
			}

			printf("********\nPARENT - Min value %d from %d\n********\n",min_val,min_pid);

			//Kill the process with pid = min_pid with SIGINT
			//The others will receive the SIGUSR1
			for (int i = 0; i < remainingChildren; i++){
				if(pid_list[i] == min_pid){
					kill(pid_list[i],SIGINT);
				}
				else{
					kill(pid_list[i],SIGUSR1);
				}
			}
			
			remainingChildren--;
			printf("------------------------------------------\n\n");
		}

		//Closing reading flux
		close(pipe_op[0]);

		//Closing process
		printf("PARENT %d - exit\n",getpid());
		exit(EXIT_SUCCESS);

	}
	//Print error attempting pipe creation
	else{
		error("Error in pipe creation");
	}
	

}