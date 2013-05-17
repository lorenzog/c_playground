#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main () {
	int data_processed;
	int file_pipes[2];
	const char data[] = "blabla";
	char buffer[BUFSIZ + 1];
	int fork_result;

	memset (buffer, '\1', sizeof(buffer));

	if ( pipe (file_pipes) == 0 ) {
		fork_result = fork();

		if ( fork_result == -1 ) { 
			fprintf(stderr, "fork failed");
			exit (EXIT_FAILURE);
		}

		// we're the child
		if ( fork_result ) { 	// fork_result == 0
			printf("child started\n");
			data_processed = read(file_pipes[0], buffer,
					BUFSIZ);
			printf("Read %d butes: %s\n", data_processed, buffer);
			exit (EXIT_SUCCESS);
		}

		// we're the parent
		else {
			printf("parent started\n");
			data_processed = write (file_pipes[1], data, 
					strlen(data));
			printf("Wrote %d bytes\n", data_processed);
		}
	} 
	exit (EXIT_SUCCESS);
}
