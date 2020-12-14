#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <errno.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//Maxium message size
#define MSG_MAX_SIZE  128
//Maxium time number generable
#define TYPE_MAX 10

//Func to check for errors
#define TEST_ERROR    if (errno) {dprintf(STDERR_FILENO, \
					   "%s:%d: PID=%5d: Error %d (%s)\n",\
					   __FILE__,\
					   __LINE__,\''
					   getpid(),\
					   errno,\
					   strerror(errno));}

//Struct of a message
struct msgbuf {
  long mtype;                       /* type of message */
  char mtext[MSG_MAX_SIZE];         /* user-define message */
};

//Print queue status with useful informations
void print_info_stats(int q_id);

int main() {

  int q_id; //Message queue key
  key_t key=IPC_PRIVATE; //Unique key for msg_queue creation
  struct msgbuf msg; //msg variable
  int num_bytes; 
  int ret_val;

  //Init ctime
  time_t curtime;
  time(&curtime);

  srand(getpid()); //Starting random seed
  
  //Creating message queue
  q_id = msgget(key, IPC_CREAT | 0600);
  TEST_ERROR;
  printf("Created message queue identifier: %d\n\n",q_id);

  //Print initial info about the just created queue
  print_info_stats(q_id);

  //Test sending a message to the created queue
  num_bytes = sprintf(msg.mtext,"HELLOOOOO");
  num_bytes++;
  msg.mtype = (rand() % 10) + 1;
  msgsnd(q_id, &msg, num_bytes, 0);
  printf("A message of %d bytes is sent to the %d queue: %s \nTime: %s\n",num_bytes,q_id,msg.mtext,ctime(&curtime));

  //Print info after sending a message
  print_info_stats(q_id);

  //Deallocating the queue
  while (ret_val = msgctl(q_id, IPC_RMID, NULL)) {
		TEST_ERROR;
	}

  printf("\nThe queue %d is succesfully deallocated.\n",q_id);

  exit(EXIT_SUCCESS);
}

//Print queue status with useful informations
void print_info_stats(int q_id){
  struct msqid_ds stat;
  int ret_val;

  while (ret_val = msgctl(q_id, IPC_STAT, &stat)) {
		TEST_ERROR;
	}
  printf("\n----------------------\n");
  printf("Info about the queue: \n");
  printf("Queue dimension: %ld\n", stat.msg_qbytes); //Queue dimension
  printf("Number of messages in the queue: %ld\n", stat.msg_qnum); //Number of messages
  printf("Time of the last received message: %ld\n", stat.msg_stime); //Time of the last message sent
  printf("----------------------\n\n");
}