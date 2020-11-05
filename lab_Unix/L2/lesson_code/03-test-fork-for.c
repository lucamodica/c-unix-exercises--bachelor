#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


#define NUM_FORKS  4

int main() {
  int i;
  unsigned int my_pid, my_ppid, value;

  for (i=0; i<NUM_FORKS; i++) {

    value = fork();
    my_pid = getpid();
    my_ppid = getppid();
    printf("PID=%d, PPID=%d, i=%d, fork_value=%d\n", my_pid, my_ppid, i, value);
    sleep(0);
  }

  exit(EXIT_SUCCESS);
}
