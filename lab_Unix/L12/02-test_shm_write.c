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

  if (argc!=3) {
    printf("Uso: 01-test_shm_write shid valore");
    exit(EXIT_FAILURE);
  }

  shid=atoi(argv[1]);

  int *shared_data=shmat(shid, NULL, 0);
  if (errno) {
    fprintf(stderr, "%s: %d. Errore in shmat #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("Area di memoria condivisa agganciata.\n");

  *shared_data=atoi(argv[2]);
  printf("Aggiornato il valore a %d\n", *shared_data);

  //sleep(20);

  if (shmdt(shared_data) == -1) {
    fprintf(stderr, "%s: %d. Errore in shmdt #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("Area di memoria condivisa sganciata.\n");

  exit(EXIT_SUCCESS);
}
