#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <errno.h>

#define READ_BUF_SIZE 100

//Error check macro
#define TEST_ERROR    if (errno) {fprintf(stderr, \
					   "%s:%d: PID=%5d: Error %d (%s)\n",\
					   __FILE__,\
					   __LINE__,\
					   getpid(),\
					   errno,\
					   strerror(errno));}

int main() {

	//Variables
	int pipez[2]; // [0] --> read - [1] --> write
	const char some_data[] = "Bro no pressure really, you're a master at work."; //Data to be passed through pipe
	pid_t fork_res; //fork() variable
	char *mode = "R";

	//Setting for opening pipe and errors
	pipe(pipez);
	TEST_ERROR;
	
	//Creating 2 brothers and handling them
	for(int i = 0; i < 2; i++){

		//Change mode if It's the second child
		if(i==1){ mode="W"; }

		switch (fork_res = fork()){
			
			//Handle error 
			case -1:
				TEST_ERROR;
				exit(EXIT_FAILURE);
				break;


			//Handle brothers (children)
			case 0:
				//Writing brother
				if(strcmp(mode,"W")){
					//Init
					close(pipez[0]);
					printf("\nSneak here, the writing brother is ready! (PID=%d)\n",getpid());

					//Writing some data
					write(pipez[1],some_data,strlen(some_data));
					printf("I just wrote a %ld bytes message, hoping my brother reciving it.\n\n",strlen(some_data));

					//Closing writing flux
					close(pipez[1]);
				}
				//Reading brother
				else{
					//Init
					close(pipez[1]);
					printf("\nYoooo, reading brother here! (PID=%d)\n",getpid());

					//Reading some data if available
					char buffer[BUFSIZ + 1]; //Buffer array
					memset(buffer, '\0', sizeof(buffer));
					int data_processed = read(pipez[0],buffer,READ_BUF_SIZE);
					printf("Alright alright alright, let's see what we've got!\n");
					printf("A message of %d bytes from my writing brother, here what it is: '%s'\n\n", data_processed, buffer);

					//Closing reading flux
					close(pipez[0]);
				}

				//Brothers' exit
				exit(EXIT_SUCCESS);
				break;

			
			//Handle parent
			default:
				printf("Parent (PID=%d) of 2 awesome child.\n",getpid());

		}

	}

	printf("Parent ended.\n\n");
	exit(EXIT_SUCCESS);

}