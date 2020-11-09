#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/sysinfo.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>

int main(int argc, char *argv[]) {

	printf("%s: My PID is %d and my parent's PID is %d\n",
	       __FILE__, getpid(), getppid());

	if (argc > 0) {
		for (int i = 1; i < argc; i++){
			fprintf(stdout,"Ehi chown %d, %s\n",i,argv[i]);
		}
	} 
	else {
		printf("Sono richiesti argomenti. Ne sono stati inseriti %d\n",argc-1);
	}
}
