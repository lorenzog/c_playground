/*
 * reverses a string
 * compilation: gcc -o reverse reverse.c
 */
#include <stdio.h>

int main (int argc, char *argv[]) {
	if ( argc == 1 )
		return (1);

	int length = 0;
	char stringa[255];
	while ( stringa[length] = *argv[1]++ )
		length++;
	for ( length ; length ; length-- )
		printf("%c", stringa[length-1]);
	printf("\n");
	return (0);
}
