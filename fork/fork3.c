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
	printf("my PID: %d\n", getpid());

	int level, nfork;
	level = nfork = 0;

	pid_t f1;

	while ( level < 2 && nfork < 2 ) {
		f1 = fork();
		if ( f1 != 0 ) {
			printf ("I\'m %d; my child is: %d\n",getpid(), f1);
			nfork++;
		}
		if ( f1 == 0 ) {
			printf("\tI\'m %d; my father is: %d\n", getpid(), getppid());
			sleep (1);
			level++;
		}
		sleep(2);
	}

	wait(NULL);
}
