#include <stdlib.h>
#include <stdio.h>

typedef struct line {
	float	timeStamp;
	float	pos[6];
	float	vel[6];
} line;

int main (int argc, char* argv[]) {
	int i;
	struct line* dataLine = (line*) malloc(sizeof(line));

	dataLine->timeStamp = 100.0;
	for ( i = 0 ; i < 6 ; i++ )
	{
		dataLine->pos[i] = i;
		dataLine->vel[i] = i;
	}

	for ( i = 0 ; i < 6 ; i++ )
		printf("vel: %f, pos: %f, timestamp: %f\n", dataLine->vel[i], dataLine->pos[i], dataLine->timeStamp);

	free(dataLine);
}

