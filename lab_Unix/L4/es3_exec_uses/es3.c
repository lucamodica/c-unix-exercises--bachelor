#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <string.h>


int main (void) {
	pid_t my_pid, my_ppid, value;
	int status;

	char* args[] = {
    	"saluta_persona",
		"Clown",  
		"Felpa arancione",
		"Bell'uomo",
		"Giga Chad",
		"Roberto Tarantino (quello della coca)",
		NULL
	};

	

	switch (value = fork()){
		case -1:
			/* Handle error */
			fprintf(stderr,"Error #%03d: %s\n", errno, strerror(errno));
			break;

		case 0:
			//Child process
			printf("I'M THE CHILD.\n");
			printf("%s: My PID is %d and my parent's PID is %d\n",
	    	__FILE__, getpid(), getppid());

			//exexlp()
			printf("\nexeclp() INTENSIFIES\n");
			sleep(3);
			execlp("./saluta_persone","","Clown","Felpa arancione",
			"Giga Chad","Bell'uomo",NULL);

			//Don't need to check success. If here not success
			fprintf(stderr, "%s: %d. Error #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
			break;

		default:
			//Parent process
			printf("GIVE ME THE CHILD.\n");
			printf("%s: My PID is %d and my parent's PID is %d\n",
	         __FILE__, getpid(), getppid());

			//Waiting for child process
			pid_t terminatedPid=wait(&status);
			printf("\nTerminated child pid %d\n", terminatedPid);
		    
		    //execvp()
			printf("\nexecvp() INTENSIFIES\n");
			sleep(3);
			execvp("./saluta_persone",args);

			//Don't need to check success. If here not success
			fprintf(stderr, "%s: %d. Error #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));

		   break;
	}

	
	exit(EXIT_FAILURE);
}