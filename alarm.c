#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ding (int sig) {
	printf ("alarm ringing, sig: %d\n", sig);
}

int main() { 
	int pid;
	printf ("alarm starting\n");
	
	if ( ( pid = fork() ) == 0 ) {
		sleep (5);
		kill (getppid(), SIGALRM);
		exit (0);
	}
	printf ("waiting for alarm to go off\n");
	(void) signal(SIGALRM, ding);

	pause ();

	printf ("done\n");
	exit(0);
}
