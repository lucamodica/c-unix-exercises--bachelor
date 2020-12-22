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
  int * shared_data;

  shid = shmget(IPC_PRIVATE, sizeof(int), S_IRUSR | S_IWUSR);
  if (shid == -1) {
    fprintf(stderr, "%s: %d. Errore in semget #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }

  printf("creata e inizializzata l'area di memoria condivisa con ID = %d\n", shid);

  exit(EXIT_SUCCESS);

}
