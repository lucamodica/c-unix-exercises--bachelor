#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#define READ_BUF_SIZE 100

int main() {
  int data_processed;
  int file_pipes[2]; // [0] --> read - [1] --> write
  const char some_data[] = "Fede è gay";
  char buffer[BUFSIZ + 1];
  pid_t fork_result;

  memset(buffer, '\0', sizeof(buffer));

  printf("La dimensione del buffer della pipe è di %d bytes\n", PIPE_BUF);

  if (pipe(file_pipes) == 0) {
    fork_result = fork();
    switch (fork_result) {
      case -1:
        fprintf(stderr, "Fork failure");
        exit(EXIT_FAILURE);
      case 0:
        close(file_pipes[1]);

		//Reading 10 numbers
		int data;
		while (data_processed = read(file_pipes[0], &data, sizeof(int))) {
			printf("Reading number: %d\n",data);
			printf("Waiting...\n\n");
  		}

		printf("Child exit.\n");
        exit(EXIT_SUCCESS);
      default:
        close(file_pipes[0]);

		//Writing 10 numbers
		for (int i = 0; i < 10; i++){
			write(file_pipes[1],&i,sizeof(int));
			printf("Writing number: %d\n",i);
			sleep(1);
		}
        
		printf("\nParent exit.\n");
        exit(EXIT_SUCCESS);
    }
  }

  //Closing parent write flux 
  close(file_pipes[1]);



}