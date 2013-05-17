/*
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
	int i;
	
	for ( i = 0 ; i < 2 ; i++ ) {
	printf("before fork; PID: %d\n", getpid());
	status = fork();
	printf("after fork; PID: %d status: %d\n", getpid(), status);
		if ( status == -1 )
			exit (EXIT_FAILURE);

		if ( status == 0 ) {
			status = fork();
	printf("\tcycle %d, after fork II (child) PID: %d parent: %d\n", 
					i, getpid(), getppid());
			sleep (3);
		} 
		else {
			status = fork();
	printf("\tcycle %d, after fork II (parent) PID: %d status: %d\n", 
					i, getpid(), status);
			sleep (7);
		}
	}
	
	wait(NULL);

	exit (EXIT_SUCCESS);
}
