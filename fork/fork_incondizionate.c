/*
 * fork
 * fork
 * parent -> child1, child2
 * child1 -> nephew1
 * child2 -> nephew2, nephew3
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
	pid_t status;
	status = fork();
	printf("after fork; PID: %d status: %d\n", getpid(), status);
	if ( status == -1 )
		exit (EXIT_FAILURE);
	if ( status == 0 ) {
		sleep (2);
	} 
	else {
		sleep (1);
	}

	printf ("\n");

	pid_t status2;
	status2 = fork();
	printf("after fork II; PID: %d status2: %d\n", getpid(), status2);
	if ( status2 == -1 )
		exit (EXIT_FAILURE);
	if ( status2 == 0 ) {
		sleep (4);
	}
	else {
		sleep (3);
	}

	printf ("\n");

	pid_t status3;
	status3 = fork();
	printf("after fork III; PID: %d status3: %d\n", getpid(), status3);
	if ( status3 == -1 )
		exit (EXIT_FAILURE);
	if ( status3 == 0 ) {
		sleep (6);
	}
	else {
		sleep (5);
	}

	printf ("\n");

	exit (EXIT_SUCCESS);
}
