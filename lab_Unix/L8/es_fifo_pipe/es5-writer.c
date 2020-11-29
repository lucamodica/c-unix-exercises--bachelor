#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE    1000


int main(int argc, char * argv[]){
  int fifo_fd;
  char my_msg[BUF_SIZE];
  ssize_t num_bytes;

  int data_processed;

  //The 3 messages
  char *msgs[] = { "well cum", "getting cock", "dozzzer" };

  // Open FIFO in write mode
  while ((fifo_fd = open(argv[1], O_WRONLY)) == -1){
	  fprintf(stderr,"%s: %d. Error in open() #%03d: %s",__FILE__,__LINE__,errno,strerror(errno));
  }
  

  //Writing the 3 messages
  for (int i = 0; i < 3; i++){
	//Saving message on buffer
	sprintf(my_msg,"%s\n",msgs[i]);
	//Write message to FIFO
	data_processed = write(fifo_fd, my_msg, strlen(my_msg));
	//Print the result written
	printf("Wrote %d bytes\n",data_processed);
  }

  //Closing the fifo
  close(fifo_fd);

  return(0);
}
