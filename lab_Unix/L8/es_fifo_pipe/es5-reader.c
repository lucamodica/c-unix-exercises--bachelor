#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>


#define BUF_SIZE 100


int main(int argc, char * argv[]){
	
  int fifo_fd;
  FILE *log=NULL;
  char readbuf[BUF_SIZE];
  int num_bytes;

  //Create the FIFO if it does not exist
  mkfifo(argv[1], S_IRUSR | S_IWUSR);

  //Open the log file
  log = fopen(argv[2], "w");

  //Keep reading until the reader will be killed
  fifo_fd = open(argv[1], O_RDONLY);
  while (num_bytes = read(fifo_fd, readbuf, BUF_SIZE)) {
    printf("Received a message of %d bytes: %s\n",num_bytes,readbuf);
    fprintf(log,"%s",readbuf);
	  memset(readbuf,'\0',sizeof(readbuf));
  }

  close(fifo_fd);
  unlink(argv[1]);
}
