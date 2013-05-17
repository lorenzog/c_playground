#include	<stdio.h>
#include	<sys/types.h>

main (int argc, char *argv[]) {

	pid_t	status;		// data type pid_t

	if ( ( status = fork() ) == -1 )
		printf("fork() failed\n");

	if ( status == 0 ) { 
		sleep(5);
		printf ("\nChildren\n", status);
	} else {
		sleep(3);
		printf("Parent; children has PID=%d\n", status);
	}
}
		
