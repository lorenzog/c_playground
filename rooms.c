#include <stdio.h>
#include <stdlib.h>

static const int N = 10;

int main ( int argc, char **argv) {
	if ( argc < 2 )
		return -1;
	srand(atoi(argv[1]));
	int rooms[N];
	int choice, count = 0, i, untested = N;

	for ( i = 0 ; i < 10 ; i++ )
		rooms[i] = 0;

	while ( untested > 0 ) {
		choice = rand() % untested;
		//printf("choice: %d\n", choice);

		for ( i = 0 ; i < N ; i++ )
			if ( rooms[i] == 0 )
				if ( count++ == choice )
					break;
		rooms[i] = 1;
		count = 0;
		printf("%d ", i);

		untested--;
	}
	printf("\n");

}
