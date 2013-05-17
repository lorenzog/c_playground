#include <stdio.h>

int main (int argc, char *argv[], char *env[]) {
	puts ("Variabili d\'ambiente:");
	while ( *env != NULL )
		puts (*env++);
	return (0);
}
		
