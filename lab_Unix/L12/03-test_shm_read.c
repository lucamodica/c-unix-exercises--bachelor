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

int stampaStatoMemoria(int shid);

int main(int argc, char *argv[]) {

  int shid;

  if (argc!=2) {
    printf("Uso: 01-test_shm_read shid\n");
    exit(EXIT_FAILURE);
  }

  shid=atoi(argv[1]);

  stampaStatoMemoria(shid);

  int *shared_data=shmat(shid, NULL, 0);
  if (errno) {
    fprintf(stderr, "%s: %d. Errore in shmat #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("Area di memoria condivisa agganciata.\n");

  stampaStatoMemoria(shid);

  printf("Il valore memorizzato è %d\n", *shared_data);

  //sleep(20);

  if (shmdt(shared_data) == -1) {
    fprintf(stderr, "%s: %d. Errore in shmdt #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    exit(EXIT_FAILURE);
  }
  printf("Area di memoria condivisa sganciata.\n");

  exit(EXIT_SUCCESS);
}

int stampaStatoMemoria(int shid) {

  struct shmid_ds buf;

  if (shmctl(shid,IPC_STAT,&buf)==-1) {
    fprintf(stderr, "%s: %d. Errore in shmctl #%03d: %s\n", __FILE__, __LINE__, errno, strerror(errno));
    return -1;
  } else {
    printf("\nSTATISTICHE\n");
    printf("AreaId: %d\n",shid);
    printf("Dimensione: %ld\n",buf.shm_segsz);
    printf("Ultima shmat: %s\n",ctime(&buf.shm_atime));
    printf("Ultima shmdt: %s\n",ctime(&buf.shm_dtime));
    printf("Ultimo processo shmat/shmdt: %d\n",buf.shm_lpid);
    printf("Processi connessi: %ld\n",buf.shm_nattch);
    printf("\n");
    return 0;
  }
}
