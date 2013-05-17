#include <sys/time.h>
#include <time.h>
#include <stdio.h>
#include <math.h>

int main (int argc, char **argv) {
		/*
		struct timeval t1, t2;
		if ( gettimeofday(&t1, NULL) < 0 )
				perror ("err");
		printf("t1: %d(sec) %d(usec)\n",t1.tv_sec, t1.tv_usec );
		sleep(3);
		if ( gettimeofday(&t2, NULL) < 0 )
				perror ("err");
		printf("t2: %d(sec) %d(usec)\n",t2.tv_sec, t2.tv_usec );

		struct timeval res;

		res.tv_sec = t2.tv_sec - t1.tv_sec;
		res.tv_usec = t2.tv_usec - t1.tv_usec;


		printf("usec diff: %d\n", res.tv_usec);

		if ( t2.tv_usec < t1.tv_usec )
				res.tv_sec--;

		printf("diff: %d(sec) %d(usec)\n",res.tv_sec, res.tv_usec );

		double res2 = (double)res.tv_sec + ( (double)res.tv_usec / 1000000);

		printf("diff: %f\n", res2);

		printf("\n");
		*/

		double i = 15.999;
		int secs = (int)(floor(i));
		int usecs = (int)((i-floor(i))* 1000000) ;
		printf("i: %f, secs: %d, usecs: %d\n", i, secs, usecs);
		
		struct timeval t;
		gettimeofday(&t,NULL);
		sleep(5);
		t.tv_sec += secs;
		t.tv_usec += usecs;
		if ( usecs >= 1000000 )
		{
				secs++;
				usecs -= 1000000;
		}
		printf("add: %d(sec) %d(usec)\n", secs, usecs);

		return 0;

}
