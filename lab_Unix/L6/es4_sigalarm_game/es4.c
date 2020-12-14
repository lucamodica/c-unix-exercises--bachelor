#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>

void alarmHandler(int sig) {
  printf("\nTempo scaduto bello! Riflessi pronti next time :')\n");
  exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[]) {

	//Signal error control
	if (signal(SIGALRM, alarmHandler)==SIG_ERR) {
	  printf("\n\nEohhhh! Il timer del gioco non funzia fratm\n");
	  exit(EXIT_SUCCESS);
	}

	if (argc != 3){
		printf("\n\nSenti fra, ti rinfresco come far partire il gioco:\n");
		printf("- ./<nome eseguibile> <max_number> <max_guess_time>\n");
	  	exit(EXIT_SUCCESS);
	}
	else{

		//Random number generator
		int num = *argv[1] - '0' + 1;
		srand(num);
		int rands = rand()%num;

		//Guess input
		int guess;
		printf("\nHo pensato a un numero fra 0 e %c, vedi di indovinarlo entro %c secondi\n", *argv[1], *argv[2]);
		printf("Your guess: ");

		

		do{

			//Setting the timer
			alarm(*argv[2] - '0');
			scanf("%d",&guess);

			if(rands == guess){
				printf("\nPotevi dirmelo prima che leggevi nel pensiero.");
				printf("\nHai vinto 'mbari, congrats.\n");
				exit(EXIT_SUCCESS);
			}
			else if(rands > guess){
				printf("\nPunta più in alto fro!");
				printf("\nYour guess: ");
			}
			else if(rands < guess){
				printf("\nSehhh vola basso bru!");
				printf("\nYour guess: ");
			}
			
			
		}while (guess != rands);
		

	}
	

}
