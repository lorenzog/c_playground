#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <assert.h>

void timeval_subtract(struct timeval *result, struct timeval *x, struct timeval *y) {
		if ( x->tv_usec < y->tv_usec) 
		{
				int nsec = ( y->tv_usec - x->tv_usec) / 1000000 + 1;
				y->tv_usec -= 1000000*nsec;
				y->tv_sec += nsec;
		}

		if ( x->tv_usec - y->tv_usec > 1000000) 
		{
				int nsec = ( y->tv_usec - x->tv_usec) / 1000000;
				y->tv_usec += 1000000 * nsec;
				y->tv_sec -= nsec;
		}

		result->tv_sec = x->tv_sec - y->tv_sec;
		result->tv_usec = x->tv_usec - y->tv_usec;
}

int main (int argc, char **argv) {
		assert(argc > 4);
		struct timeval x,y,result;

		x.tv_sec = atoi(argv[1]);
		x.tv_usec = atoi(argv[2]);
		y.tv_sec = atoi(argv[3]);
		y.tv_usec = atoi(argv[4]);

		timeval_subtract(&result, &x, &y);

		printf("result: %d(sec), %d(usec)\n", result.tv_sec, result.tv_usec);
		
		return 0;
}
