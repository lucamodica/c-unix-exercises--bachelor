#include <stdio.h>
#include <stdlib.h>

void cleanup(void)
{
	/* Cleaning up */
	printf("Done with cleaning up\n");
}

void bye(void)
{
	printf("Game over!!\n");
}

int main (void)
{
	/* My code */
	atexit (bye);
	atexit (cleanup);
	exit (EXIT_SUCCESS);
}
