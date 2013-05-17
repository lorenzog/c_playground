#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void doubleToTimeval(double d, struct timeval *t) {
		t->tv_sec = (int)(floor(d));
		double dclean = ( d*1000000 - floor(d)*1000000 ) / 1000000 ;
		t->tv_usec = (int)((dclean-floor(dclean))*1000000);
}

int main ( int argc, char **argv) {
		assert(argc > 1);
		double d = atof(argv[1]);
		printf("double: %f\n", d);

		struct timeval t;

		doubleToTimeval(d, &t);

		printf("before add; secs: %d, usecs: %d\n", t.tv_sec, t.tv_usec);
		
		struct timeval t2;
		t2.tv_usec = 2;

		t.tv_usec += t2.tv_usec;
		printf("after add; secs: %d, usecs: %d\n", t.tv_sec, t.tv_usec);

		if ( t.tv_usec >= 1000000 )
		{
				t.tv_sec++;
				t.tv_usec-=1000000;
		}


		printf("after clean; secs: %d, usecs: %d\n", t.tv_sec, t.tv_usec);
		return 0;
}
