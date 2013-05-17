#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void ouch (int sig) {
	printf ("haha you can't kill me! sig: %d\n", sig);
}
int main () {
	struct sigaction act;

	act.sa_handler = ouch;
//	sigemtpyset(&act.sa_mask);
	act.sa_flags = 0;

	sigaction(SIGINT, &act, 0);
	sigaction(SIGTERM, &act, 0);
	sigaction(SIGKILL, &act, 0);

	while ( 1 ) {
		printf ("kill me kill me\n");
		sleep (1);
	}
}
