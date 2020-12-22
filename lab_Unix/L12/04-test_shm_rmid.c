#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

  int shid;

  if (argc!=2) {
    printf("Usage: 01-test_shm_rmid shid\n");
    exit(EXIT_FAILURE);
  }

  shid=atoi(argv[1]);

  if (shmctl(shid, 0, IPC_RMID) == -1) {
    fprintf(stderr, "%s: %d. Errore in semctl #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("%ld: shmctl completata! \n", (long) getpid());

  printf("Rimossa l'area di memoria condivisa con ID = %d \n", shid);

  exit(EXIT_SUCCESS);

}
