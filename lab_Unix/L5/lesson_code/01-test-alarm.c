#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

void alarmHandler(int sig) {
  printf("Allarme ricevuto e trattato\n");
  alarm(7);
}

int main() {

  if (signal(SIGALRM, alarmHandler)==SIG_ERR) {
    printf("\nErrore della disposizione dell'handler\n");
    exit(EXIT_SUCCESS);
  }

  alarm(7);

  printf("Quindi\n");

  while(1) {
    printf("tic\n");
    //printf("mancano %d secondi\n",alarm(0));
    sleep(5);
  };

  printf("FINE\n");

}
