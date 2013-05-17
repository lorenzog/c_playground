#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main (int argc, char* argv[]) {
	float pos[] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
	float vel[] = { 0.1, 1.1, 2.1, 3.1, 4.1, 5.1 };
	float* container = (float*)malloc(12*sizeof(float));
	int count = 0;
	int i;

	for ( i = 0 ; i < 6 ; i++ )
		memcpy ( &container[count++], &pos[i], sizeof(float) );
	for ( i = 0 ; i < 6 ; i++ )
		memcpy ( &container[count++], &vel[i], sizeof(float) );

	printf("Done copying\n");

	for ( i = 0 ; i < 6 ; i++ )
	{
		pos[i] = 0;
		vel[i] = 0;
	}

	for ( i = 0 ; i < count ; i++ )
		printf("value %d: %f\n", i, container[i]);

	free(container);
	return (0);
}
