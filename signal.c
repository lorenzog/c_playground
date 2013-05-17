#include <stdio.h>
#include <signal.h>

void handler(int sig)
{
	printf("Signal trapped: %d\n", sig);
	sleep(10);
	return;
}

int main()
{
	signal(1, handler);
	signal(2, handler);
	signal(3, handler);
	signal(6, handler);
	signal(9, handler);
	signal(13, handler);
	signal(15, handler);
	signal(19, handler);

	while (1);
}
