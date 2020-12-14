#include "ipc-msg-common.h"

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
