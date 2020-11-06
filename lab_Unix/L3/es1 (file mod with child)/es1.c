#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
  pid_t my_pid, my_ppid, value;
  int status;
  FILE *f = fopen(argv[1],"w+"); //File to be modified

  //Init check
  if(argc < 2){

      printf("Something went wrong. Here's the syntax in case you miss it:\n");
      printf("./program_name <filepath>\n\n");

  }
  //File menagement by a father and a child
  else{
	switch (value = fork()) {
		case -1:
			/* Handle error */
			fprintf(stderr,"Error #%03d: %s\n", errno, strerror(errno));
			break;

		case 0:
			/* Perform actions specific to child */
			my_pid = getpid();
			my_ppid = getppid();
			printf("CHILD:  PID=%d, PPID=%d, fork_value=%d\n", my_pid, my_ppid, value);

			//Write file
			char *text = " come stai? ";
			printf("Now I'm writing a file appending \"%s\"...\n",text);
			fwrite(text,strlen(text),1,f);
			fseek(f,10,0);
			for (int c = fgetc(f); c != EOF; c = fgetc(f)){
				printf("%c",c);
			}
			printf("\n");

			sleep(5);
			printf("CHILD: exit...\n");
			exit(69);

		default:
			/* Perform actions specific to parent */
			my_pid = getpid();
			my_ppid = getppid();
			printf("PARENT: PID=%d, PPID=%d, fork_value=%d\n", my_pid, my_ppid, value);

			printf("Waiting for child process %d termination (writing file)...\n",value);

			sleep(30);

			pid_t terminatedPid=wait(&status);
			printf("Terminated pid %d\n", terminatedPid);

			printf("Child terminated with status %d\n",WEXITSTATUS(status));

			//Reading modified file
			printf("Now that my child isn't here, let's read his file!\n\n");
			fseek(f,0,0);
			for (int c = fgetc(f); c != EOF; c = fgetc(f)){
				printf("%c",c);
			}
			printf("\n");
			

			break;
  	}
  }



}
