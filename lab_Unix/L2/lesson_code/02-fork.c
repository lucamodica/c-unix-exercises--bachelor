#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


int main() {
  pid_t my_pid, my_ppid, value;

  int test_var=5;
  int *p_var=&test_var;

  switch (value = fork()) {
  case -1:
    /* Handle error */
    fprintf(stderr,"Error #%03d: %s\n", errno, strerror(errno));
    break;

  case 0:
    /* Perform actions specific to child */
    sleep(2);
    my_pid = getpid();
    my_ppid = getppid();
    printf("CHILD:  PID=%d, PPID=%d, fork_value=%d\n", my_pid, my_ppid, value);

    test_var++;
    printf("Child: test_var = %d\n\n",test_var);
    printf("Child: p_var = %p\n\n",p_var);

    *p_var=10;

    printf("Child: test_var = %d\n\n",test_var);
    printf("Child: p_var = %p\n\n",p_var);

    break;

  default:
    /* Perform actions specific to parent */
    my_pid = getpid();
    my_ppid = getppid();
    printf("PARENT: PID=%d, PPID=%d, fork_value=%d\n", my_pid, my_ppid, value);

    sleep(5);

    test_var++;
    printf("Parent:test_var = %d\n\n",test_var);
    printf("Parent: p_var = %p\n\n",p_var);
    break;
  }

  exit(EXIT_SUCCESS);
}
