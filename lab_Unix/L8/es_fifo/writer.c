#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE    1000


int main(int argc, char * argv[]){
  int fifo_fd, str_len;
  char my_msg[BUF_SIZE];
  ssize_t num_bytes;

  int data_processed;

  //The 3 messages
  char *msgs[] = { "well cum", "getting cock", "dozzzer" };

  // Open FIFO in write mode
  fifo_fd = open(argv[1], O_WRONLY);

  //Writing the 3 messages
  for (int i = 0; i < 3; i++){
	// Assemble the message
	str_len = sprintf(my_msg,"%s\n",msgs[i]);
	// Write message to FIFO
	data_processed=write(fifo_fd, my_msg, str_len);
	printf("Wrote %d bytes\n",data_processed);
  }
  
  close(fifo_fd);

  return(0);
}
