#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main() {
	int data_processed;
	int file_pipes[2];
	const char some_data[] = "estigrancazzi?\0";
	char buffer[BUFSIZ + 1];

	memset (buffer, '\0', sizeof(buffer));	// fills memory with 3 '\0's

	if ( pipe (file_pipes) == 0 ) {		// creates pipe
		data_processed = write (file_pipes[1], some_data, 
				strlen(some_data));
		printf ("wrote %d bytes\n", data_processed);
		data_processed = read (file_pipes[0], buffer, BUFSIZ);
		printf("read %d bytes: %s\n", data_processed, buffer);
		exit (EXIT_SUCCESS);
	}
	exit (EXIT_FAILURE);
}
