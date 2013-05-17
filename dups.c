#include <stdio.h>

int main ( int argc, char **argv ) {
	int dups[10] = { 0 };
	int i;

	for ( i = 1 ; i < argc ; i++ ) 
		dups[atoi(argv[i])]++;

	for ( i = 0 ; i < 10 ; i++ )
		printf("%d: %d\n", i, dups[i]);

	return 0;
}
